#include "termuxgui/activity.hpp"

#include "impl/activity.hpp"
#include "impl/types.hpp"
#include "rethrow.h"

#include "GUIProt0.pb.h"

using namespace std;




namespace tgui {
	Activity::Activity(Connection& c, Type type, bool interceptBackButton, Task task) : a{
		rethrow<std::shared_ptr<impl::Activity>(void)>([&]() {
			return make_shared<impl::Activity>(c.c, impl::ActivityTypePublicToPB.at(type), interceptBackButton, task);
		})()} {}
	
	Activity::~Activity() {}
	
	void Activity::finish() {
		rethrow<void(void)>([&] {
			a->finish();
		})();
	}
	
	
	Configuration Activity::getConfiguration() const {
		return rethrow<Configuration(void)>([&] {
			return impl::ConfigurationPBToPublic(a->getConfiguration());
		})();
	}
	
	
	void Activity::hideSoftKeyboard() {
		rethrow<void(void)>([&] {
			a->hideSoftKeyboard();
		})();
	}
	
	
	
	void Activity::interceptBackButton(bool intercept) {
		rethrow<void(void)>([&] {
			a->interceptBackButton(intercept);
		})();
	}
	
	
	void Activity::keepScreenOn(bool on) {
		rethrow<void(void)>([&] {
			a->keepScreenOn(on);
		})();
	}
	
	
	
	void Activity::moveToBack() {
		rethrow<void(void)>([&] {
			a->moveToBack();
		})();
	}
	
	
	
	void Activity::requestUnlock() {
		rethrow<void(void)>([&] {
			a->requestUnlock();
		})();
	}
	
	
	
	void Activity::sendOverlayEvents(bool send) {
		rethrow<void(void)>([&] {
			a->sendOverlayEvents(send);
		})();
	}
	
	
	
	void Activity::setInputMode(InputMode m) {
		rethrow<void(void)>([&] {
			a->setInputMode(impl::InputModePublicToPB.at(m));
		})();
	}
	
	
	
	
	void Activity::setOrientation(Orientation o) {
		rethrow<void(void)>([&] {
			a->setOrientation(impl::OrientationPublicToPB.at(o));
		})();
	}
	
	
	
	
	void Activity::setPiPMode(bool pip) {
		rethrow<void(void)>([&] {
			a->setPiPMode(pip);
		})();
	}
	
	
	
	
	void Activity::setPiPModeAuto(bool pipAuto) {
		rethrow<void(void)>([&] {
			a->setPiPModeAuto(pipAuto);
		})();
	}
	
	
	
	
	void Activity::setPiPParams(int numerator, int denominator) {
		rethrow<void(void)>([&] {
			a->setPiPParams(numerator, denominator);
		})();
	}
	
	
	
	
	void Activity::setPosition(int x, int y) {
		rethrow<void(void)>([&] {
			a->setPosition(x, y);
		})();
	}
	
	
	
	
	void Activity::setTaskDescription(std::string label, const void* img, size_t imgSize) {
		rethrow<void(void)>([&] {
			a->setTaskDescription(label, img, imgSize);
		})();
	}
	
	
	
	void Activity::setTheme(Color primaryColor, Color accentColor, Color windowBackground, Color statusBarColor, Color textColor) {
		rethrow<void(void)>([&] {
			a->setTheme(primaryColor, accentColor, windowBackground, statusBarColor, textColor);
		})();
	}
	
	
	Task Activity::getTask() {
		return a->tid();
	}
	
	
	AID Activity::getID() {
		return a->aid();
	}
	
	
	
}










