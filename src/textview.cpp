#include "termuxgui/textview.hpp"

#include "impl/textview.hpp"
#include "impl/view.hpp"
#include "impl/viewgroup.hpp"
#include "termuxgui/viewgroup.hpp"
#include "rethrow.h"

#include "GUIProt0.pb.h"

#include "impl/types.hpp"

namespace tgui {
	
	
	TextView::TextView(Activity& a, ViewGroup* parent, std::string text, bool selectableText, bool clickableLinks) {
		rethrow<void(void)>([&] {
			auto c = impl::Connection::connectionOrThrow(a.a->wc);
			std::shared_ptr<impl::ViewGroup> pg = nullptr;
			if (parent != nullptr) {
				pg = parent->vg;
			}
			proto0::CreateTextViewRequest req;
			proto0::Create data;
			data.set_aid(a.getID());
			if (pg == nullptr) {
				data.set_parent(-1);
			} else {
				data.set_parent(pg->v->id);
			}
			data.set_v(proto0::visible);
			*req.mutable_data() = data;
			req.set_text(text);
			req.set_selectabletext(selectableText);
			req.set_clickablelinks(clickableLinks);
			proto0::Method m;
			*m.mutable_createtextview() = req;
			c->sendMethodMessage(m);
			proto0::CreateTextViewResponse res;
			
			c->readMessage(res);
			
			if (res.id() < 0) {
				throw MethodError();
			}
			v = std::make_shared<impl::View>(a.a, res.id());
			tv = std::make_shared<impl::TextView>(v);
		})();
	}
	
	
	TextView::~TextView() {}
	
	
	
	
	void TextView::setTextColor(tgui::Color col) {
		rethrow<void(void)>([&] {
			tv->setTextColor(col);
		})();
	}
	
	void TextView::setText(std::string text) {
		rethrow<void(void)>([&] {
			tv->setText(text);
		})();
	}
	
	void TextView::setGravity(Gravity horizontal, Gravity vertical) {
		rethrow<void(void)>([&] {
			tv->setGravity(impl::GravityPublicToPB.at(horizontal), impl::GravityPublicToPB.at(vertical));
		})();
	}
	
	void TextView::setTextSize(Size s) {
		rethrow<void(void)>([&] {
			tv->setTextSize(impl::SizePublicToPB(s));
		})();
	}
	
	std::string TextView::getText() {
		return rethrow<std::string(void)>([&] {
			return tv->getText();
		})();
	}
	
	
	
	
	
	
}






