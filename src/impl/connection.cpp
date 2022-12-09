#include "connection.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <poll.h>

#include <random>
#include <string>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

#include <memory>
#include <utility>

#include "bind.h"

#include <google/protobuf/util/delimited_message_util.h>

using namespace std;




namespace tgui::impl {
	
	
	Connection::SocketInputStream::SocketInputStream() {}
	Connection::SocketInputStream::~SocketInputStream() {
		err = true;
		if (fd != -1)
			close(fd);
		fd = -1;
	}
	bool Connection::SocketInputStream::Next(const void** data, int* size) {
		if (err) return false;
		if (again != 0) {
			// buffer.data()+lastsize is one over the last return, so go again bytes back
			*data = buffer.data()+lastsize-again;
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
		lastsize = ret;
		count += ret;
		return true;
	}
	void Connection::SocketInputStream::BackUp(int count) {
		again = count;
		this->count -= again;
	}
	bool Connection::SocketInputStream::Skip(int count) {
		if (err) return false;
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
	Connection::SocketOutputStream::~SocketOutputStream() {
		if (towrite != 0) {
			writeRaw(buffer.data(), towrite);
		}
		err = true;
		if (fd != -1)
			close(fd);
		fd = -1;
	}
	void Connection::SocketOutputStream::flush() {
		if (towrite != 0) {
			if (! writeRaw(buffer.data(), towrite)) {
				err = true;
			}
			towrite = 0;
		}
	}
	bool Connection::SocketOutputStream::Next(void** data, int* size) {
		if (err) return false;
		if (towrite != 0) {
			if (! writeRaw(buffer.data(), towrite)) {
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
		if (! writeRaw(buffer.data(), towrite)) {
			err = true;
		}
		towrite = 0;
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
		if (err) return false;
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
		mainfd = -1;
		eventfd = -1;
		// generate names
		try {
			string mainName, eventName;
			random_device r;
			default_random_engine rng(r());
			static const string randchars ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			uniform_int_distribution<int> dist(0, randchars.length()-1);
			
			for (int i = 0;i<50;i++) {
				mainName += randchars.at(dist(rng));
				eventName += randchars.at(dist(rng));
			}
			
			// create sockets
			mainfd = socket(AF_UNIX, SOCK_STREAM|SOCK_NONBLOCK|SOCK_CLOEXEC, 0);
			if (mainfd == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			eventfd = socket(AF_UNIX, SOCK_STREAM|SOCK_NONBLOCK|SOCK_CLOEXEC, 0);
			if (eventfd == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			
			// bind names
			sockaddr_un adr{};
			adr.sun_family = AF_UNIX;
			
			memcpy(adr.sun_path+1, mainName.c_str(), min(mainName.length(), sizeof(adr.sun_path)-2));
			if (termuxgui__bind(mainfd, &adr, sizeof(adr) - sizeof(adr.sun_path) + mainName.length()+1) != 0) {
				throw system_error(error_code(errno, system_category()));
			}
			
			memcpy(adr.sun_path+1, eventName.c_str(), min(eventName.length(), sizeof(adr.sun_path)-2));
			if (termuxgui__bind(eventfd, &adr, sizeof(adr) - sizeof(adr.sun_path) + eventName.length()+1) != 0) {
				throw system_error(error_code(errno, system_category()));
			}
			
			// listen
			if (listen(mainfd, 50) != 0) {
				throw system_error(error_code(errno, system_category()));
			}
			
			if (listen(eventfd, 50) != 0) {
				throw system_error(error_code(errno, system_category()));
			}
			
			int fpid = fork();
			if (fpid == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			if (fpid == 0) {
				// redirect stdin and stdout to /dev/null
				int null = open("/dev/null", O_RDWR);
				if (null == -1) {
					std::perror("open /dev/null");
					exit(1);
				}
				if (dup2(null, 0) == -1) {
					std::perror("dup2 0");
					exit(1);
				}
				if (dup2(null, 1) == -1) {
					std::perror("dup2 1");
					exit(1);
				}
				
				close(null);
				
				execlp("termux-am", "termux-am", "broadcast", "-n", "com.termux.gui/.GUIReceiver",
					"--es", "mainSocket", mainName.c_str(),
					"--es", "eventSocket", eventName.c_str(), (char*) NULL);
				execlp("am", "am", "broadcast", "-n", "com.termux.gui/.GUIReceiver",
					"--es", "mainSocket", mainName.c_str(),
					"--es", "eventSocket", eventName.c_str(), (char*) NULL);
				std::perror("execlp");
				exit(1);
			}
			
			
			// accept connections
			pollfd p;
			p.fd = mainfd;
			p.events = POLLIN;
			
			if (poll(&p, 1, 5000) == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			if (! (p.revents & POLLIN)) {
				throw ConnectionTimeoutException();
			}
			int tmp = accept4(mainfd, NULL, NULL, SOCK_CLOEXEC);
			if (tmp == -1) {
				throw ConnectionTimeoutException();
			}
			close(mainfd);
			mainfd = tmp;
			
			p.fd = eventfd;
			if (poll(&p, 1, 1000) == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			if (! (p.revents & POLLIN)) {
				throw ConnectionTimeoutException();
			}
			tmp = accept4(eventfd, NULL, NULL, SOCK_CLOEXEC);
			if (tmp == -1) {
				throw ConnectionTimeoutException();
			}
			close(eventfd);
			eventfd = tmp;
			
			// check uid
			
			ucred cred;
			cred.uid = 1;
			socklen_t len = sizeof(cred);
			if (getsockopt(mainfd, SOL_SOCKET, SO_PEERCRED, &cred, &len) == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			if (cred.uid != getuid()) {
				throw PluginUIDException();
			}
			
			cred.uid = 1;
			len = sizeof(cred);
			if (getsockopt(eventfd, SOL_SOCKET, SO_PEERCRED, &cred, &len) == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			if (cred.uid != getuid()) {
				throw PluginUIDException();
			}
			
			
			
			// set protocol
			
			uint8_t protocol = 0;
			if (send(mainfd, &protocol, 1, MSG_NOSIGNAL) == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			
			uint8_t resp = 0;
			if (read(mainfd, &protocol, 1) == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			if (resp != 0) {
				throw ProtocolUnavailableException();
			}
			
			
			in.fd = mainfd;
			out.fd = dup(mainfd);
			if (out.fd == -1) {
				throw system_error(error_code(errno, system_category()));
			}
			event.fd = eventfd;
		} catch (std::exception& e) {
			if (mainfd != -1) {
				close(mainfd);
			}
			if (eventfd != -1) {
				close(eventfd);
			}
			throw e;
		}
	}
	
	Connection::~Connection() {
	}
	
	
	
	void Connection::sendMethodMessage(tgui::proto0::Method& m) {
		unique_lock l{outMutex};
		if (! google::protobuf::util::SerializeDelimitedToZeroCopyStream(m, &out)) {
			throw MessageWriteException();
		}
		out.flush();
	}
	
	void Connection::readMessage(google::protobuf::MessageLite& m) {
		unique_lock l{inMutex};
		if (! google::protobuf::util::ParseDelimitedFromZeroCopyStream(&m, &in, NULL)) {
			throw MessageReadException();
		}
	}
	
	
	proto0::Event Connection::receiveEvent() {
		unique_lock l{eventMutex};
		tgui::proto0::Event e;
		if (! google::protobuf::util::ParseDelimitedFromZeroCopyStream(&e, &event, NULL)) {
			throw MessageReadException();
		}
		return e;
	}
	
	bool Connection::checkEvent() {
		pollfd p;
		p.fd = eventfd;
		p.events = POLLIN;
		if (poll(&p, 1, 0) != -1 && p.revents & POLLIN) {
			return true;
		} else {
			return false;
		}
	}
	
	
}

