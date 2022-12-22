#include "viewgroup.hpp"



namespace tgui::impl {
	
	ViewGroup::ViewGroup(std::shared_ptr<View> v) : wv{v} {}
	
	void ViewGroup::clearChildren() {
		auto view = View::viewOrThrow(wv);
		auto a = Activity::activityOrThrow(view->wa);
		auto c = Connection::connectionOrThrow(a->wc);
		proto0::DeleteChildrenRequest req;
		proto0::View v;
		v.set_aid(a->aid());
		v.set_id(view->id);
		*req.mutable_v() = v;
		proto0::Method m;
		*m.mutable_deletechildren() = req;
		c->sendMethodMessage(m);
		proto0::DeleteChildrenResponse res;
		c->readMessage(res);
		if (! res.success()) {
			throw MethodError();
		}
	}
	
	
	
	
}
