
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

#include <exception>
#include <utility>

#include <termuxgui/connection.hpp>

#include "GUIProt0.pb.h"

#include "impl/connection.hpp"
#include "impl/types.hpp"
#include "rethrow.h"

tgui::Connection::Connection() : c{
	rethrow<std::shared_ptr<impl::Connection>(void)>([&] () {
		return std::make_shared<impl::Connection>();
	})()} {}

tgui::Connection::~Connection() {}



void tgui::Connection::receiveEvent(Event& eRet) {
	rethrow<void(void)>([&] {
		proto0::Event e = c->receiveEvent();
		if (e.has_create()) {
			const auto& v = e.create();
			eRet = tgui::Events::Create{ .a = v.aid() };
			return;
		}
		if (e.has_start()) {
			const auto& v = e.start();
			eRet = tgui::Events::Start{ .a = v.aid() };
			return;
		}
		if (e.has_resume()) {
			const auto& v = e.resume();
			eRet = tgui::Events::Resume{ .a = v.aid() };
			return;
		}
		if (e.has_pause()) {
			const auto& v = e.pause();
			eRet = tgui::Events::Pause{ .a = v.aid(), .finishing = v.finishing() };
			return;
		}
		if (e.has_stop()) {
			const auto& v = e.stop();
			eRet = tgui::Events::Stop{ .a = v.aid(), .finishing = v.finishing() };
			return;
		}
		if (e.has_destroy()) {
			const auto& v = e.destroy();
			eRet = tgui::Events::Destroy{ .a = v.aid(), .finishing = v.finishing() };
			return;
		}
		if (e.has_config()) {
			const auto& v = e.config();
			eRet = tgui::Events::Config{ .a = v.aid(), .config = impl::ConfigurationPBToPublic(v.configuration())};
			return;
		}
		if (e.has_click()) {
			const auto& v = e.click();
			eRet = tgui::Events::Click{ .a = v.v().aid(), .v = v.v().id(), .set = v.set()};
			return;
		}
		if (e.has_longclick()) {
			const auto& v = e.longclick();
			eRet = tgui::Events::LongClick{ .a = v.v().aid(), .v = v.v().id()};
			return;
		}
		if (e.has_focuschange()) {
			const auto& v = e.focuschange();
			eRet = tgui::Events::Focus{ .a = v.v().aid(), .v = v.v().id(), .focus = v.focus()};
			return;
		}
		if (e.has_touch()) {
			const auto& v = e.touch();
			std::vector<std::vector<tgui::Events::Touch::Pointer>> pointers(v.touches_size());
			for (const auto& touch : v.touches()) {
				std::vector<tgui::Events::Touch::Pointer> ps(touch.pointers_size());
				for (const auto& pointer : touch.pointers()) {
					ps.push_back({
						.x = pointer.x(),
						.y = pointer.y(),
						.id = pointer.id()
					});
				}
				pointers.push_back(std::move(ps));
			}
			eRet = tgui::Events::Touch{ .a = v.v().aid(), .v = v.v().id(), .events = std::move(pointers)};
			return;
		}
		if (e.has_text()) {
			const auto& v = e.text();
			eRet = tgui::Events::Text{ .a = v.v().aid(), .v = v.v().id(), .text = v.text()};
			return;
		}
		if (e.has_refresh()) {
			const auto& v = e.refresh();
			eRet = tgui::Events::Refresh{ .a = v.v().aid(), .v = v.v().id()};
			return;
		}
		if (e.has_selected()) {
			const auto& v = e.selected();
			eRet = tgui::Events::Selected{ .a = v.v().aid(), .v = v.v().id(), .selected = v.selected()};
			return;
		}
		if (e.has_itemselected()) {
			const auto& v = e.itemselected();
			eRet = tgui::Events::ItemSelected{ .a = v.v().aid(), .v = v.v().id(), .selected = v.selected()};
			return;
		}
		if (e.has_back()) {
			const auto& v = e.back();
			eRet = tgui::Events::Back{ .a = v.aid() };
			return;
		}
		if (e.has_webnavigation()) {
			const auto& v = e.webnavigation();
			eRet = tgui::Events::WebViewNavigation{ .a = v.v().aid(), .v = v.v().id(), .url = v.url()};
			return;
		}
		if (e.has_webhttperror()) {
			const auto& v = e.webhttperror();
			eRet = tgui::Events::WebViewHTTPError{ .a = v.v().aid(), .v = v.v().id(), .url = v.url(), .code = v.code()};
			return;
		}
		if (e.has_weberror()) {
			const auto& v = e.weberror();
			eRet = tgui::Events::WebViewError{ .a = v.v().aid(), .v = v.v().id(), .url = v.url()};
			return;
		}
		if (e.has_webdestroyed()) {
			const auto& v = e.webdestroyed();
			eRet = tgui::Events::WebViewDestroyed{ .a = v.v().aid(), .v = v.v().id()};
			return;
		}
		if (e.has_webprogress()) {
			const auto& v = e.webprogress();
			eRet = tgui::Events::WebViewProgress{ .a = v.v().aid(), .v = v.v().id(), .progress = v.progress()};
			return;
		}
		if (e.has_webconsolemessage()) {
			const auto& v = e.webconsolemessage();
			eRet = tgui::Events::WebViewConsole{ .a = v.v().aid(), .v = v.v().id(), .msg = v.message()};
			return;
		}
		if (e.has_airplane()) {
			const auto& v = e.airplane();
			eRet = tgui::Events::AirplaneMode{ .active = v.active() };
			return;
		}
		if (e.has_locale()) {
			const auto& v = e.locale();
			eRet = tgui::Events::Locale{ .locale = v.locale() };
			return;
		}
		if (e.has_timezone()) {
			const auto& v = e.timezone();
			eRet = tgui::Events::Timezone{ .tz = v.tz() };
			return;
		}
		if (e.has_screenoff()) {
			const auto& v = e.screenoff();
			eRet = tgui::Events::ScreenOff{};
			return;
		}
		if (e.has_screenon()) {
			const auto& v = e.screenon();
			eRet = tgui::Events::ScreenOn{};
			return;
		}
		if (e.has_userleavehint()) {
			const auto& v = e.userleavehint();
			eRet = tgui::Events::UserLeaveHint{ .a = v.aid() };
			return;
		}
		if (e.has_pip()) {
			const auto& v = e.pip();
			eRet = tgui::Events::PiP{ .a = v.aid(), .pip = v.pip() };
			return;
		}
		if (e.has_remoteclick()) {
			const auto& v = e.remoteclick();
			eRet = tgui::Events::RemoteClick{ .rid = v.rid(), .id = v.id() };
			return;
		}
		if (e.has_notification()) {
			const auto& v = e.notification();
			eRet = tgui::Events::Notification{ .id = v.id() };
			return;
		}
		if (e.has_notificationdismissed()) {
			const auto& v = e.notificationdismissed();
			eRet = tgui::Events::NotificationDismissed{ .id = v.id() };
			return;
		}
		if (e.has_notificationaction()) {
			const auto& v = e.notificationaction();
			eRet = tgui::Events::NotificationAction{ .id = v.id(), .action = v.action() };
			return;
		}
		if (e.has_overlayscale()) {
			const auto& v = e.overlayscale();
			eRet = tgui::Events::OverlayScale{ .a = v.aid(), .span = v.span() };
			return;
		}
		if (e.has_keyevent()) {
			const auto& v = e.keyevent();
			eRet = tgui::Events::Key{ .a = v.v().aid(), .v = v.v().id(), .code = v.code(), .mod = static_cast<tgui::Events::Key::Modifier>(v.modifiers()), .codePoint = v.codepoint() };
			return;
		}
		if (e.has_exception()) {
			const auto& v = e.exception();
			eRet = tgui::Events::DebugException{ .stacktrace = v.stacktrace() };
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





