
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

#include <exception>

#include <termuxgui/connection.hpp>

#include "GUIProt0.pb.h"

#include "impl/connection.hpp"
#include "rethrow.h"

tgui::Connection::Connection() {
	c = rethrow<std::shared_ptr<impl::Connection>(void)>([&] () {
		return std::make_shared<impl::Connection>();
	})();
}

tgui::Connection::~Connection() {}



void tgui::Connection::receiveEvent(Event& eRet) {
	rethrow<void(void)>([&] {
		proto0::Event e = c->receiveEvent();
		if (e.has_create()) {
			auto v = e.create();
			eRet = tgui::Events::Create{ .a = v.aid() };
			return;
		}
		if (e.has_start()) {
			auto v = e.start();
			eRet = tgui::Events::Start{ .a = v.aid() };
			return;
		}
		if (e.has_resume()) {
			auto v = e.resume();
			eRet = tgui::Events::Resume{ .a = v.aid() };
			return;
		}
		if (e.has_pause()) {
			auto v = e.pause();
			eRet = tgui::Events::Pause{ .a = v.aid(), .finishing = v.finishing() };
			return;
		}
		if (e.has_stop()) {
			auto v = e.stop();
			eRet = tgui::Events::Stop{ .a = v.aid(), .finishing = v.finishing() };
			return;
		}
		if (e.has_destroy()) {
			auto v = e.destroy();
			eRet = tgui::Events::Destroy{ .a = v.aid(), .finishing = v.finishing() };
			return;
		}
		eRet = Event();
	})();
}



bool tgui::Connection::checkEvent() {
	return rethrow<bool(void)>([&] {
		return c->checkEvent();
	})();
}


int tgui::Connection::getVersion() {
	return rethrow<int(void)>([&] {
		proto0::Method m;
		*m.mutable_version() = proto0::GetVersionRequest();
		c->sendMethodMessage(m);
		proto0::GetVersionResponse res;
		c->readMessage(res);
		return res.versioncode();
	})();
}


bool tgui::Connection::isLocked() {
	return rethrow<bool(void)>([&] {
		proto0::Method m;
		*m.mutable_islocked() = proto0::IsLockedRequest();
		c->sendMethodMessage(m);
		proto0::IsLockedResponse res;
		c->readMessage(res);
		if (! (res.locked() == proto0::IsLockedResponse::UNKNOWN)) {
			throw MethodError();
		}
		return res.locked() == proto0::IsLockedResponse::LOCKED;
	})();
}



void tgui::Connection::toast(std::string msg) {
	rethrow<void(void)>([&] {
		proto0::ToastRequest toast;
		*toast.mutable_text() = msg;
		proto0::Method m;
		*m.mutable_toast() = toast;
		c->sendMethodMessage(m);
		proto0::ToastResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	})();
}


void tgui::Connection::toTermux() {
	rethrow<void(void)>([&] {
		int fpid = fork();
		if (fpid == -1) {
			throw std::system_error(std::error_code(errno, std::system_category()));
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
			
			execlp("termux-am", "termux-am", "start", "-n", "com.termux/.app.TermuxActivity", (char*) NULL);
			execlp("am", "am", "start", "-n", "com.termux/.app.TermuxActivity", (char*) NULL);
			std::perror("execlp");
			exit(1);
		}
	})();
}


void tgui::Connection::turnScreenOn() {
	rethrow<void(void)>([&] {
		proto0::Method m;
		*m.mutable_turnscreenon() = proto0::TurnScreenOnRequest();
		c->sendMethodMessage(m);
		proto0::TurnScreenOnResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	})();
}





