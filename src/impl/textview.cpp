#include "textview.hpp"



namespace tgui::impl {
	
	TextView::TextView(std::shared_ptr<View> v) : v{v} {}
	
	void TextView::setTextColor(tgui::Color col) {
		auto view = this->v;
		auto a = Activity::activityOrThrow(view->wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetTextColorRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(view->id);
		*req.mutable_v() = v;
		req.set_color(col);
		proto0::Method m;
		*m.mutable_settextcolor() = req;
		c->sendMethodMessage(m);
		proto0::SetTextColorResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void TextView::setText(std::string text) {
		auto view = this->v;
		auto a = Activity::activityOrThrow(view->wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetTextRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(view->id);
		*req.mutable_v() = v;
		req.set_text(text);
		proto0::Method m;
		*m.mutable_settext() = req;
		c->sendMethodMessage(m);
		proto0::SetTextResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void TextView::setGravity(proto0::SetGravityRequest::Gravity horizontal,
			proto0::SetGravityRequest::Gravity vertical) {
		auto view = this->v;
		auto a = Activity::activityOrThrow(view->wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetGravityRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(view->id);
		*req.mutable_v() = v;
		req.set_horizontal(horizontal);
		req.set_vertical(vertical);
		proto0::Method m;
		*m.mutable_setgravity() = req;
		c->sendMethodMessage(m);
		proto0::SetGravityResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void TextView::setTextSize(proto0::Size s) {
		auto view = this->v;
		auto a = Activity::activityOrThrow(view->wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetTextSizeRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(view->id);
		*req.mutable_v() = v;
		*req.mutable_s() = s;
		proto0::Method m;
		*m.mutable_settextsize() = req;
		c->sendMethodMessage(m);
		proto0::SetTextSizeResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	std::string TextView::getText() {
		auto view = this->v;
		auto a = Activity::activityOrThrow(view->wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::GetTextRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(view->id);
		*req.mutable_v() = v;
		proto0::Method m;
		*m.mutable_gettext() = req;
		c->sendMethodMessage(m);
		proto0::GetTextResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
		return res.text();
	}
	
	
	
	
}
