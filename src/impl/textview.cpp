#include "textview.hpp"



namespace tgui::impl {
	
	TextView::TextView(std::shared_ptr<View> v) : wv{v} {}
	
	void TextView::setTextColor(tgui::Color col) {
		
	}
	
	void TextView::setText(std::string text) {
		
	}
	
	void TextView::setGravity(proto0::SetGravityRequest::Gravity horizontal,
		proto0::SetGravityRequest::Gravity vertical) {
		
	}
	
	void TextView::setTextSize(proto0::Size s) {
		
	}
	
	std::string TextView::getText() {
		return "";
	}
	
	
	
	
}
