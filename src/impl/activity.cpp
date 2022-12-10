
#include "activity.hpp"

#include "termuxgui/exceptions.hpp"

namespace tgui::impl {
	Activity::Activity(std::shared_ptr<Connection> c, proto0::NewActivityRequest::ActivityType type, bool interceptBackButton, Task task) : wc{c}, t{task} {
		proto0::NewActivityRequest req;
		req.set_tid(task);
		req.set_type(type);
		req.set_interceptbackbutton(interceptBackButton);
		proto0::Method m;
		*m.mutable_newactivity() = req;
		c->sendMethodMessage(m);
		proto0::NewActivityResponse res;
		c->readMessage(res);
		if (res.aid() == -1) {
			throw MethodError();
		}
		t = res.tid();
		a = res.aid();
	}
	
	
	void Activity::finish() {
		auto c = Connection::connectionOrThrow(wc);
		proto0::FinishActivityRequest req;
		req.set_aid(a);
		proto0::Method m;
		*m.mutable_finishactivity() = req;
		c->sendMethodMessage(m);
		proto0::FinishActivityResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	proto0::Configuration Activity::getConfiguration() const {
		auto c = Connection::connectionOrThrow(wc);
		proto0::GetConfigurationRequest req;
		req.set_aid(a);
		proto0::Method m;
		*m.mutable_getconfiguration() = req;
		c->sendMethodMessage(m);
		proto0::GetConfigurationResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
		return res.configuration();
	}
	
	
	void Activity::hideSoftKeyboard() {
		auto c = Connection::connectionOrThrow(wc);
		proto0::HideSoftKeyboardRequest req;
		req.set_aid(a);
		proto0::Method m;
		*m.mutable_hidesoftkeyboard() = req;
		c->sendMethodMessage(m);
		proto0::HideSoftKeyboardResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	void Activity::interceptBackButton(bool intercept) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::InterceptBackButtonRequest req;
		req.set_aid(a);
		req.set_intercept(intercept);
		proto0::Method m;
		*m.mutable_interceptbackbutton() = req;
		c->sendMethodMessage(m);
		proto0::InterceptBackButtonResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	void Activity::keepScreenOn(bool on) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::KeepScreenOnRequest req;
		req.set_aid(a);
		req.set_on(on);
		proto0::Method m;
		*m.mutable_keepscreenon() = req;
		c->sendMethodMessage(m);
		proto0::KeepScreenOnResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	void Activity::moveToBack() {
		auto c = Connection::connectionOrThrow(wc);
		proto0::MoveTaskToBackRequest req;
		req.set_aid(a);
		proto0::Method m;
		*m.mutable_movetasktoback() = req;
		c->sendMethodMessage(m);
		proto0::MoveTaskToBackResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	void Activity::requestUnlock() {
		auto c = Connection::connectionOrThrow(wc);
		proto0::RequestUnlockRequest req;
		req.set_aid(a);
		proto0::Method m;
		*m.mutable_requestunlock() = req;
		c->sendMethodMessage(m);
		proto0::RequestUnlockResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	void Activity::sendOverlayEvents(bool send) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SendOverlayTouchEventRequest req;
		req.set_aid(a);
		req.set_send(send);
		proto0::Method m;
		*m.mutable_sendoverlaytouch() = req;
		c->sendMethodMessage(m);
		proto0::SendOverlayTouchEventResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	void Activity::setInputMode(proto0::SetInputModeRequest::InputMode mode) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetInputModeRequest req;
		req.set_aid(a);
		req.set_mode(mode);
		proto0::Method m;
		*m.mutable_setinputmode() = req;
		c->sendMethodMessage(m);
		proto0::SetInputModeResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	
	void Activity::setOrientation(proto0::Orientation o) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetOrientationRequest req;
		req.set_aid(a);
		req.set_orientation(o);
		proto0::Method m;
		*m.mutable_setorientation() = req;
		c->sendMethodMessage(m);
		proto0::SetOrientationResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	
	void Activity::setPiPMode(bool pip) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetPiPModeRequest req;
		req.set_aid(a);
		req.set_pip(pip);
		proto0::Method m;
		*m.mutable_setpipmode() = req;
		c->sendMethodMessage(m);
		proto0::SetPiPModeResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	
	void Activity::setPiPModeAuto(bool pipAuto) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetPiPModeAutoRequest req;
		req.set_aid(a);
		req.set_pip(pipAuto);
		proto0::Method m;
		*m.mutable_setpipmodeauto() = req;
		c->sendMethodMessage(m);
		proto0::SetPiPModeAutoResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	
	void Activity::setPiPParams(int numerator, int denominator) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetPiPParamsRequest req;
		req.set_aid(a);
		req.set_num(numerator);
		req.set_den(denominator);
		proto0::Method m;
		*m.mutable_setpipparams() = req;
		c->sendMethodMessage(m);
		proto0::SetPiPParamsResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	
	void Activity::setPosition(int x, int y) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetPositionRequest req;
		req.set_aid(a);
		req.set_x(x);
		req.set_y(y);
		proto0::Method m;
		*m.mutable_setposition() = req;
		c->sendMethodMessage(m);
		proto0::SetPositionResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	
	void Activity::setTaskDescription(std::string label, const void* img, size_t imgSize) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetTaskDescriptionRequest req;
		req.set_aid(a);
		req.set_label(label);
		req.set_img(img, imgSize);
		proto0::Method m;
		*m.mutable_settaskdescription() = req;
		c->sendMethodMessage(m);
		proto0::SetTaskDescriptionResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	void Activity::setTheme(Color primaryColor, Color accentColor, Color windowBackground, Color statusBarColor, Color textColor) {
		auto c = Connection::connectionOrThrow(wc);
		proto0::SetThemeRequest req;
		req.set_aid(a);
		req.set_colorprimary(primaryColor);
		req.set_coloraccent(accentColor);
		req.set_windowbackground(windowBackground);
		req.set_statusbarcolor(statusBarColor);
		req.set_textcolor(textColor);
		proto0::Method m;
		*m.mutable_settheme() = req;
		c->sendMethodMessage(m);
		proto0::SetThemeResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
}







