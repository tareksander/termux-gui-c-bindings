#include "view.hpp"
#include "viewgroup.hpp"


namespace tgui::impl {
	
	
	View::View(std::shared_ptr<Activity> a, tgui::Vid id) : id{id}, wa{a} {}
	
	
	void View::setLinearLayoutParams(float weight, int position) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetLinearLayoutParamsRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_weight(weight);
		req.set_position(position);
		proto0::Method m;
		*m.mutable_setlinearlayout() = req;
		c->sendMethodMessage(m);
		proto0::SetLinearLayoutParamsResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setGridLayoutParams(int row, int col, int rowSize, int colSize,
			proto0::SetGridLayoutParamsRequest::Alignment rowAlign,
			proto0::SetGridLayoutParamsRequest::Alignment colAlign) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetGridLayoutParamsRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_row(row);
		req.set_col(col);
		req.set_rowsize(rowSize);
		req.set_colsize(colSize);
		req.set_rowalign(rowAlign);
		req.set_colalign(colAlign);
		proto0::Method m;
		*m.mutable_setgridlayout() = req;
		c->sendMethodMessage(m);
		proto0::SetGridLayoutParamsResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setLocation(proto0::Size::Unit unit, int x, int y, bool top) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetViewLocationRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_unit(unit);
		req.set_x(x);
		req.set_y(y);
		req.set_top(top);
		proto0::Method m;
		*m.mutable_setlocation() = req;
		c->sendMethodMessage(m);
		proto0::SetViewLocationResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setRelativeLayoutParams() {
		
	}
	
	void View::setVisibility(proto0::Visibility vis) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetVisibilityRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_vis(vis);
		proto0::Method m;
		*m.mutable_setvisibility() = req;
		c->sendMethodMessage(m);
		proto0::SetVisibilityResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setWidth(proto0::ViewSize s) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetWidthRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		*req.mutable_s() = s;
		proto0::Method m;
		*m.mutable_setwidth() = req;
		c->sendMethodMessage(m);
		proto0::SetWidthResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setHeight(proto0::ViewSize s) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetHeightRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		*req.mutable_s() = s;
		proto0::Method m;
		*m.mutable_setheight() = req;
		c->sendMethodMessage(m);
		proto0::SetHeightResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::getDimensions(proto0::Size::Unit u, tgui::Point& p) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::GetDimensionsRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_unit(u);
		proto0::Method m;
		*m.mutable_getdimensions() = req;
		c->sendMethodMessage(m);
		proto0::GetDimensionsResponse res;
		c->readMessage(res);
		if (! res.width() < 0 || res.height() < 0) {
			throw MethodError();
		}
		p.x = res.width();
		p.y = res.height();
	}
	
	void View::destroy() {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::DeleteViewRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		proto0::Method m;
		*m.mutable_deleteview() = req;
		c->sendMethodMessage(m);
		proto0::DeleteViewResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
		destroyed = true;
	}
	
	void View::setMargin(proto0::Size s, proto0::Direction dir) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetMarginRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		*req.mutable_s() = s;
		req.set_dir(dir);
		proto0::Method m;
		*m.mutable_setmargin() = req;
		c->sendMethodMessage(m);
		proto0::SetMarginResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setPadding(proto0::Size s, proto0::Direction dir) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetPaddingRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		*req.mutable_s() = s;
		req.set_dir(dir);
		proto0::Method m;
		*m.mutable_setpadding() = req;
		c->sendMethodMessage(m);
		proto0::SetPaddingResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setBackgroundColor(tgui::Color col) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetBackgroundColorRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_color(col);
		proto0::Method m;
		*m.mutable_setbackgroundcolor() = req;
		c->sendMethodMessage(m);
		proto0::SetBackgroundColorResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::focus(bool forceSoft) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::RequestFocusRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_forcesoft(forceSoft);
		proto0::Method m;
		*m.mutable_requestfocus() = req;
		c->sendMethodMessage(m);
		proto0::RequestFocusResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::setClickable(bool clickable) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SetClickableRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_clickable(clickable);
		proto0::Method m;
		*m.mutable_setclickable() = req;
		c->sendMethodMessage(m);
		proto0::SetClickableResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	void View::sendClickEvents(bool send) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SendClickEventRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_send(send);
		proto0::Method m;
		*m.mutable_sendclickevent() = req;
		c->sendMethodMessage(m);
		proto0::SendClickEventResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::sendLongClickEvents(bool send) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SendLongClickEventRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_send(send);
		proto0::Method m;
		*m.mutable_sendlongclickevent() = req;
		c->sendMethodMessage(m);
		proto0::SendLongClickEventResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::sendFocusChangeEvents(bool send) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SendFocusChangeEventRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_send(send);
		proto0::Method m;
		*m.mutable_sendfocuschangeevent() = req;
		c->sendMethodMessage(m);
		proto0::SendFocusChangeEventResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	void View::sendTouchEvents(bool send) {
		auto a = Activity::activityOrThrow(wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::SendTouchEventRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(id);
		*req.mutable_v() = v;
		req.set_send(send);
		proto0::Method m;
		*m.mutable_sendtouchevent() = req;
		c->sendMethodMessage(m);
		proto0::SendTouchEventResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
}
