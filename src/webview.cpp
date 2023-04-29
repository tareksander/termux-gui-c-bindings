#include "cdefs.hpp"

#include "types.hpp"

extern "C" {
	
	
	
	tgui_err tgui_webview_allow_javascript(tgui_connection c, tgui_activity a, tgui_view v, bool allow) {
		VIEW_METHOD_PRE(AllowJavascript)
		r.set_allow(allow);
		VIEW_METHOD_POST(AllowJavascript)
	}
	
	
	tgui_err tgui_webview_allow_content_uri(tgui_connection c, tgui_activity a, tgui_view v, bool allow) {
		VIEW_METHOD_PRE(AllowContentURI)
		r.set_allow(allow);
		VIEW_METHOD_POST(AllowContentURI)
	}
	
	
	tgui_err tgui_webview_set_data(tgui_connection c, tgui_activity a, tgui_view v, const char* data, const char* mime) {
		VIEW_METHOD_PRE(SetData)
		r.set_data(data);
		r.set_base64(true);
		r.set_mime(mime);
		VIEW_METHOD_POST(SetData)
	}
	
	
	tgui_err tgui_webview_load_uri(tgui_connection c, tgui_activity a, tgui_view v, const char* uri) {
		VIEW_METHOD_PRE(LoadURI)
		r.set_uri(uri);
		VIEW_METHOD_POST(LoadURI)
	}
	
	
	tgui_err tgui_webview_allow_navigation(tgui_connection c, tgui_activity a, tgui_view v, bool allow) {
		VIEW_METHOD_PRE(AllowNavigation)
		r.set_allow(allow);
		VIEW_METHOD_POST(AllowNavigation)
	}
	
	
	tgui_err tgui_webview_go_back(tgui_connection c, tgui_activity a, tgui_view v) {
		VIEW_METHOD_PRE(GoBack)
		VIEW_METHOD_POST(GoBack)
	}
	
	
	tgui_err tgui_webview_go_forward(tgui_connection c, tgui_activity a, tgui_view v) {
		VIEW_METHOD_PRE(GoForward)
		VIEW_METHOD_POST(GoForward)
	}
	
	
	tgui_err tgui_webview_eval_js(tgui_connection c, tgui_activity a, tgui_view v, const char* source) {
		VIEW_METHOD_PRE(EvaluateJS)
		r.set_code(source);
		VIEW_METHOD_POST(EvaluateJS)
	}
	
	
	
}

