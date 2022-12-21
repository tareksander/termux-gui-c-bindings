#include "view.hpp"



namespace tgui::impl {
	
	
	View::View(std::shared_ptr<Activity> a, tgui::Vid id) : id{id}, wa{a} {}
	
	
	void View::setLinearLayoutParams(float weight, int position) {
		
	}
	
	void View::setGridLayoutParams(int row, int col, int rowSize, int colSize,
		proto0::SetGridLayoutParamsRequest::Alignment rowAlign,
		proto0::SetGridLayoutParamsRequest::Alignment colAlign) {
		
	}
	
	void View::setLocation(proto0::Size::Unit unit, int x, int y, bool top) {
		
	}
	
	void View::setRelativeLayoutParams() {
		
	}
	
	void View::setVisibility(proto0::Visibility v) {
		
	}
	
	void View::setWidth(proto0::ViewSize s) {
		
	}
	
	void View::setHeight(proto0::ViewSize s) {
		
	}
	
	void View::getDimensions(proto0::Size::Unit u, tgui::Point& p) {
		
	}
	
	void View::destroy() {
		
	}
	
	void View::setMargin(proto0::Size s, proto0::Direction dir) {
		
	}
	
	void View::setPadding(proto0::Size s, proto0::Direction dir) {
		
	}
	
	void View::setBackgroundColor(tgui::Color c) {
		
	}
	
	void View::focus(bool forceSoft) {
		
	}
	
	void View::setClickable(bool clickable) {
		
	}
	
	
	
	void View::sendClickEvents(bool send) {
		
	}
	
	void View::sendLongClickEvents(bool send) {
		
	}
	
	void View::sendFocusChangeEvents(bool send) {
		
	}
	
	void View::sendTouchEvents(bool send) {
		
	}
	
	
	
}
