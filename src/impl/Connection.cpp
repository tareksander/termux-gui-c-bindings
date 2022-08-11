#include "connection.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <poll.h>

#include <random>
#include <string>

#include <errno.h>
#include <unistd.h>

#include <memory>
#include <utility>

#include <google/protobuf/util/delimited_message_util.h>

using namespace std;


namespace tgui::impl {
	
	
	Connection::SocketInputStream::SocketInputStream() {}
	Connection::SocketInputStream::~SocketInputStream() {}
	bool Connection::SocketInputStream::Next(const void** data, int* size) {
		if (err) return false;
		if (again != 0) {
			// buffer.data()+BUFFERSIZE is one over the buffer so go again bytes back
			*data = buffer.data()+BUFFERSIZE-again;
			*size = again;
			count += again;
			again = 0;
			return true;
		}
		int ret = read(fd, buffer.data(), BUFFERSIZE);
		if (ret <= 0) {
			err = true;
			return false;
		}
		*data = buffer.data();
		*size = ret;
		count += ret;
		return true;
	}
	void Connection::SocketInputStream::BackUp(int count) {
		again = count;
		this->count -= again;
	}
	bool Connection::SocketInputStream::Skip(int count) {
		while (count > BUFFERSIZE) {
			int ret = read(fd, buffer.data(), BUFFERSIZE);
			if (ret <= 0) {
				err = true;
				return false;
			}
			count -= ret;
		}
		while(count > 0) {
			int ret = read(fd, buffer.data(), count);
			if (ret <= 0) {
				err = true;
				return false;
			}
			count -= ret;
		}
		this->count += count;
		return true;
	}
	int64_t Connection::SocketInputStream::ByteCount() const {
		return count;
	}
	
	
	
	Connection::SocketOutputStream::SocketOutputStream() {}
	Connection::SocketOutputStream::~SocketOutputStream() {}
	bool Connection::SocketOutputStream::Next(void** data, int* size) {
		if (err) return false;
		if (towrite != 0) {
			if (writeRaw(buffer.data(), towrite)) {
				err = true;
				return false;
			}
			towrite = 0;
		}
		*data = buffer.data();
		*size = BUFFERSIZE;
		towrite = BUFFERSIZE;
		count += BUFFERSIZE;
		return true;
	}
	void Connection::SocketOutputStream::BackUp(int count) {
		towrite -= count;
		this->count -= count;
	}
	int64_t Connection::SocketOutputStream::ByteCount() const {
		return count;
	}
	bool Connection::SocketOutputStream::WriteAliasedRaw(const void* data, int size) {
		if (writeRaw((const uint8_t*) data, size)) {
			err = true;
			return false;
		}
		return true;
	}
	bool Connection::SocketOutputStream::AllowsAliasing() const {
		return true;
	}
	bool Connection::SocketOutputStream::writeRaw(const uint8_t* buffer, int size) {
		while (size > 0) {
			int ret = send(fd, buffer, size, MSG_NOSIGNAL);
			if (ret == -1) {
				return false;
			}
			buffer += ret;
			size -= ret;
		}
		return true;
	}
	
	
	
	Connection::Connection() {
		// create sockets
		mainfd = socket(AF_UNIX, SOCK_STREAM|SOCK_NONBLOCK|SOCK_CLOEXEC, 0);
		if (mainfd == -1) {
			throw system_error(error_code(errno, system_category()));
		}
		eventfd = socket(AF_UNIX, SOCK_STREAM|SOCK_NONBLOCK|SOCK_CLOEXEC, 0);
		if (eventfd == -1) {
			close(mainfd);
			throw system_error(error_code(errno, system_category()));
		}
		
		// generate names
		string mainname, eventname;
		try {
			random_device r;
			default_random_engine rng(r());
			static const string randchars ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			uniform_int_distribution<int> dist(0, randchars.length()-1);
			
			for (int i = 0;i<50;i++) {
				mainname += randchars.at(dist(rng));
				eventname += randchars.at(dist(rng));
			}
		} catch (exception& e) {
			close(mainfd);
			close(eventfd);
			throw e;
		}
		
		// bind names
		sockaddr_un adr{};
		adr.sun_family = AF_UNIX;
		
		memcpy(adr.sun_path+1, mainname.c_str(), min(mainname.length(), sizeof(adr.sun_path)-2));
		if (bind(mainfd, reinterpret_cast<sockaddr*>(&adr), sizeof(adr)) != 0) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		
		memcpy(adr.sun_path+1, eventname.c_str(), min(eventname.length(), sizeof(adr.sun_path)-2));
		if (bind(eventfd, reinterpret_cast<sockaddr*>(&adr), sizeof(adr)) != 0) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		
		// listen
		if (listen(mainfd, 50) != 0) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		
		if (listen(eventfd, 50) != 0) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		
		// accept connections
		pollfd p;
		p.fd = mainfd;
		p.events = POLLIN;
		
		if (poll(&p, 1, 5000) == -1) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		if (! (p.revents & POLLIN)) {
			close(mainfd);
			close(eventfd);
			throw ConnectionTimeoutException();
		}
		int tmp = accept(mainfd, NULL, NULL);
		if (tmp == -1) {
			close(mainfd);
			close(eventfd);
			throw ConnectionTimeoutException();
		}
		close(mainfd);
		mainfd = tmp;
		
		p.fd = eventfd;
		if (poll(&p, 1, 1000) == -1) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		if (! (p.revents & POLLIN)) {
			close(mainfd);
			close(eventfd);
			throw ConnectionTimeoutException();
		}
		tmp = accept(eventfd, NULL, NULL);
		if (tmp == -1) {
			close(mainfd);
			close(eventfd);
			throw ConnectionTimeoutException();
		}
		close(eventfd);
		eventfd = tmp;
		
		// check uid
		
		ucred cred;
		cred.uid = 1;
		socklen_t len = sizeof(cred);
		if (getsockopt(mainfd, SOL_SOCKET, SO_PEERCRED, &cred, &len) == -1) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		if (cred.uid != getuid()) {
			close(mainfd);
			close(eventfd);
			throw PluginUIDException();
		}
		
		cred.uid = 1;
		len = sizeof(cred);
		if (getsockopt(eventfd, SOL_SOCKET, SO_PEERCRED, &cred, &len) == -1) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		if (cred.uid != getuid()) {
			close(mainfd);
			close(eventfd);
			throw PluginUIDException();
		}
		
		
		
		// set protocol
		
		uint8_t protocol = 1;
		if (send(mainfd, &protocol, 1, MSG_NOSIGNAL) == -1) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		
		uint8_t resp = 0;
		if (read(mainfd, &protocol, 1) == -1) {
			close(mainfd);
			close(eventfd);
			throw system_error(error_code(errno, system_category()));
		}
		if (resp != 0) {
			close(mainfd);
			close(eventfd);
			throw ProtocolUnavailableException();
		}
		
		
		in.fd = mainfd;
		out.fd = mainfd;
		event.fd = eventfd;
	}
	
	Connection::~Connection() {
		close(mainfd);
		close(eventfd);
		close(eventfd);
	}
	
	
	
	void Connection::sendMethodMessage(tgui::proto0::Method& m) {
		if (! google::protobuf::util::SerializeDelimitedToCodedStream(m, &outC)) {
			throw MessageWriteException();
		}
	}
	
	void Connection::readMessage(google::protobuf::MessageLite& m) {
		if (! google::protobuf::util::ParseDelimitedFromCodedStream(&m, &inC, NULL)) {
			throw MessageReadException();
		}
	}
	
	
	tgui::proto0::Event Connection::receiveEvent() {
		tgui::proto0::Event e;
		if (! google::protobuf::util::ParseDelimitedFromCodedStream(&e, &eventC, NULL)) {
			throw MessageReadException();
		}
		return e;
	}
	
	
	
}


