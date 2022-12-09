#include "termuxgui/activity.hpp"

#include "impl/activity.hpp"
#include "rethrow.h"

#include "GUIProt0.pb.h"

using namespace std;

static inline constexpr tgui::proto0::NewActivityRequest::ActivityType publicToPBType(tgui::Activity::Type t) {
	using namespace tgui::proto0;
	using Type = tgui::Activity::Type;
	switch (t) {
		case Type::NORMAL:
			return NewActivityRequest::normal;
		case Type::DIALOG:
			return NewActivityRequest::dialog;
		case Type::DIALOG_CANCEL_OUTSIDE:
			return NewActivityRequest::dialogCancelOutside;
		case Type::PIP:
			return NewActivityRequest::pip;
		case Type::LOCKSCREEN:
			return NewActivityRequest::lockscreen;
		case Type::OVERLAY:
			return NewActivityRequest::overlay;
		default:
			return NewActivityRequest::normal;
	}
}

static inline constexpr tgui::proto0::SetInputModeRequest::InputMode publicToPBMode(tgui::Activity::InputMode m) {
	using namespace tgui::proto0;
	using Mode = tgui::Activity::InputMode;
	switch (m) {
		case Mode::RESIZE:
			return SetInputModeRequest::resize;
		case Mode::PAN:
			return SetInputModeRequest::pan;
		default:
			return SetInputModeRequest::resize;
	}
}

static inline constexpr tgui::proto0::Orientation publicToPBOrientation(tgui::Orientation m) {
	using namespace tgui::proto0;
	using Or = tgui::Orientation;
	switch (m) {
		case Or::BEHIND:
			return Orientation::behind;
		case Or::FULL_SENSOR:
			return Orientation::fullSensor;
		case Or::FULL_USER:
			return Orientation::fullUser;
		case Or::LANDSCAPE:
			return Orientation::landscape;
		case Or::LOCKED:
			return Orientation::locked;
		case Or::NOSENSOR:
			return Orientation::nosensor;
		case Or::PORTRAIT:
			return Orientation::portrait;
		case Or::REVERSE_LANDSCAPE:
			return Orientation::reverseLandscape;
		case Or::REVERSE_PORTRAIT:
			return Orientation::reversePortrait;
		case Or::SENSOR:
			return Orientation::sensor;
		case Or::SENSOR_LANDSCAPE:
			return Orientation::sensorLandscape;
		case Or::SENSOR_PORTRAIT:
			return Orientation::sensorPortrait;
		case Or::USER:
			return Orientation::user;
		case Or::USER_LANDSCAPE:
			return Orientation::userLandscape;
		case Or::USER_PORTRAIT:
			return Orientation::userPortrait;
		default:
			return Orientation::unspecified;
	}
}



namespace tgui {
	Activity::Activity(Connection& c, Type type, bool interceptBackButton, Task task) {
		a = rethrow<std::shared_ptr<impl::Activity>(void)>([&]() {
			return make_shared<impl::Activity>(c.c, publicToPBType(type), interceptBackButton, task);
		})();
	}
	
	Activity::~Activity() {}
	
	void Activity::finish() {
		a->finish();
	}
	
	
	Configuration Activity::getConfiguration() {
		auto pc = a->getConfiguration();
		auto c = Configuration();
		
		return c;
	}
	
	
	void Activity::hideSoftKeyboard() {
		a->hideSoftKeyboard();
	}
	
	
	
	void Activity::interceptBackButton(bool intercept) {
		a->interceptBackButton(intercept);
	}
	
	
	void Activity::keepScreenOn(bool on) {
		a->keepScreenOn(on);
	}
	
	
	
	void Activity::moveToBack() {
		a->moveToBack();
	}
	
	
	
	void Activity::requestUnlock() {
		a->requestUnlock();
	}
	
	
	
	void Activity::sendOverlayEvents(bool send) {
		a->sendOverlayEvents(send);
	}
	
	
	
	void Activity::setInputMode(InputMode m) {
		a->setInputMode(publicToPBMode(m));
	}
	
	
	
	
	void Activity::setOrientation(Orientation o) {
		a->setOrientation(publicToPBOrientation(o));
	}
	
	
	
	
	void Activity::setPiPMode(bool pip) {
		a->setPiPMode(pip);
	}
	
	
	
	
	void Activity::setPiPModeAuto(bool pipAuto) {
		a->setPiPModeAuto(pipAuto);
	}
	
	
	
	
	void Activity::setPiPParams(int numerator, int denominator) {
		a->setPiPParams(numerator, denominator);
	}
	
	
	
	
	void Activity::setPosition(int x, int y) {
		a->setPosition(x, y);
	}
	
	
	
	
	void Activity::setTaskDescription(std::string label, const void* img, size_t imgSize) {
		a->setTaskDescription(label, img, imgSize);
	}
	
	
	
	void Activity::setTheme(Color primaryColor, Color accentColor, Color windowBackground, Color statusBarColor, Color textColor) {
		a->setTheme(primaryColor, accentColor, windowBackground, statusBarColor, textColor);
	}
	
	
	
	
	
	
}










