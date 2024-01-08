#include "cdefs.hpp"


extern "C" {
	
	
	tgui_err tgui_send_click_event(tgui_connection c, tgui_activity a, tgui_view v, bool send) {
		VIEW_METHOD_PRE(SendClickEvent)
		r.set_send(send);
        *m.mutable_sendclickevent() = r;
		VIEW_METHOD_POST(SendClickEvent)
	}
	
	
	tgui_err tgui_send_long_click_event(tgui_connection c, tgui_activity a, tgui_view v, bool send) {
		VIEW_METHOD_PRE(SendLongClickEvent)
		r.set_send(send);
        *m.mutable_sendlongclickevent() = r;
		VIEW_METHOD_POST(SendLongClickEvent)
	}
	
	
	tgui_err tgui_send_focus_change_event(tgui_connection c, tgui_activity a, tgui_view v, bool send) {
		VIEW_METHOD_PRE(SendFocusChangeEvent)
		r.set_send(send);
        *m.mutable_sendfocuschangeevent() = r;
		VIEW_METHOD_POST(SendFocusChangeEvent)
	}
	
	
	tgui_err tgui_send_touch_event(tgui_connection c, tgui_activity a, tgui_view v, bool send) {
		VIEW_METHOD_PRE(SendTouchEvent)
		r.set_send(send);
        *m.mutable_sendtouchevent() = r;
		VIEW_METHOD_POST(SendTouchEvent)
	}
	
	
	tgui_err tgui_send_text_event(tgui_connection c, tgui_activity a, tgui_view v, bool send) {
		VIEW_METHOD_PRE(SendTextEvent)
		r.set_send(send);
        *m.mutable_sendtextevent() = r;
		VIEW_METHOD_POST(SendTextEvent)
	}
	
	
	tgui_err tgui_send_overlay_touch_event(tgui_connection c, tgui_activity a, bool send) {
		METHOD_PRE(SendOverlayTouchEvent)
		r.set_aid(a);
		r.set_send(send);
        *m.mutable_sendoverlaytouch() = r;
		METHOD_POST(SendOverlayTouchEvent)
	}
	
	
	
	
}

