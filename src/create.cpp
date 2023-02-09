#include "cdefs.hpp"
#include "types.hpp"

extern "C" {
		
	
	tgui_err tgui_create_image_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool keyboard) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::CreateImageViewRequest r;
			proto0::Create pc;
			pc.set_aid(a);
			if (parent != NULL) {
				pc.set_parent(*parent);
			} else {
				pc.set_parent(-1);
			}
			pc.set_v(tgui::VisibilityPublicToPB.at(vis));
			
			*r.mutable_data() = pc;
			r.set_keyboard(keyboard);
			
			*m.mutable_createimageview() = r;
			
			proto0::CreateImageViewResponse res;
			c->c.sendReadMessage(m, res);
			if (res.id() == -1) return TGUI_ERR_MESSAGE;
			*v = res.id();
			return TGUI_ERR_OK;
		});
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

