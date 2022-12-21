#include "termuxgui/textview.hpp"

#include "impl/textview.hpp"
#include "impl/view.hpp"
#include "rethrow.h"

#include "GUIProt0.pb.h"



namespace tgui {
	
	
	TextView::TextView(Activity& a, View* parent, std::string text, bool selectableText, bool clickableLinks) {
		rethrow<void(void)>([&] {
			auto c = impl::Connection::connectionOrThrow(a.a->wc);
			Vid p = -1;
			if (parent != nullptr) {
				p = parent->getID();
			}
			proto0::CreateTextViewRequest req;
			proto0::Create data;
			data.set_aid(a.getID());
			data.set_parent(p);
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
	
	
	
	
	
	
	
	
	
	
	
}






