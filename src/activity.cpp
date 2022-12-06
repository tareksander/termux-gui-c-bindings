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

static inline constexpr tgui::proto0::SetInputModeRequest::InputMode publicToPBType(tgui::Activity::InputMode m) {
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




namespace tgui {
	Activity::Activity(Connection& c, Type type, bool interceptBackButton, Task task) {
		a = rethrow<std::shared_ptr<impl::Activity>(void)>([&]() {
			return make_shared<impl::Activity>(c.c, publicToPBType(type), interceptBackButton, task);
		})();
	}
	
	Activity::~Activity() {}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}










