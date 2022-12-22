#include "termuxgui/view.hpp"

#include "impl/view.hpp"
#include "impl/types.hpp"

#include "rethrow.h"

namespace tgui {
	
	Vid View::getID() {
		return v->id;
	}
	
	
	void View::setLinearLayoutParams(float weight, int position) {
		rethrow<void(void)>([&]() {
			v->setLinearLayoutParams(weight, position);
		})();
	}
	
	// void View::setGridLayoutParams(int row, int col, int rowSize = 1, int colSize = 1,
	// 	tgui::Alignment rowAlign = proto0::SetGridLayoutParamsRequest::CENTER,
	// 	proto0::SetGridLayoutParamsRequest::Alignment colAlign = proto0::SetGridLayoutParamsRequest::CENTER);
	
	void View::setLocation(Size::Unit unit, int x, int y, bool top) {
		rethrow<void(void)>([&]() {
			v->setLocation(impl::UnitPublicToPB.at(unit), x, y, top);
		})();
	}
	
	void View::setRelativeLayoutParams() {
		
	}
	
	void View::setVisibility(Visibility vis) {
		rethrow<void(void)>([&]() {
			v->setVisibility(impl::VisibilityPublicToPB.at(vis));
		})();
	}
	
	void View::setWidth(ViewSize s) {
		rethrow<void(void)>([&]() {
			v->setWidth(impl::ViewSizePublicToPB(s));
		})();
	}
	
	void View::setHeight(ViewSize s) {
		rethrow<void(void)>([&]() {
			v->setHeight(impl::ViewSizePublicToPB(s));
		})();
	}
	
	void View::getDimensions(Size::Unit u, Point& p) {
		rethrow<void(void)>([&]() {
			v->getDimensions(impl::UnitPublicToPB.at(u), p);
		})();
	}
	
	void View::destroy() {
		rethrow<void(void)>([&]() {
			v->destroy();
		})();
	}
	
	void View::setMargin(Size s, Direction dir) {
		rethrow<void(void)>([&]() {
			v->setMargin(impl::SizePublicToPB(s), impl::DirectionPublicToPB.at(dir));
		})();
	}
	
	void View::setPadding(Size s, Direction dir) {
		rethrow<void(void)>([&]() {
			v->setPadding(impl::SizePublicToPB(s), impl::DirectionPublicToPB.at(dir));
		})();
	}
	
	void View::setBackgroundColor(Color col) {
		rethrow<void(void)>([&]() {
			v->setBackgroundColor(col);
		})();
	}
	
	void View::focus(bool forceSoft) {
		rethrow<void(void)>([&]() {
			v->focus(forceSoft);
		})();
	}
	
	void View::setClickable(bool clickable) {
		rethrow<void(void)>([&]() {
			v->setClickable(clickable);
		})();
	}
	
	
	
	void View::sendClickEvents(bool send) {
		rethrow<void(void)>([&]() {
			v->sendClickEvents(send);
		})();
	}
	
	void View::sendLongClickEvents(bool send) {
		rethrow<void(void)>([&]() {
			v->sendLongClickEvents(send);
		})();
	}
	
	void View::sendFocusChangeEvents(bool send) {
		rethrow<void(void)>([&]() {
			v->sendFocusChangeEvents(send);
		})();
	}
	
	void View::sendTouchEvents(bool send) {
		rethrow<void(void)>([&]() {
			v->sendTouchEvents(send);
		})();
	}
	
}

