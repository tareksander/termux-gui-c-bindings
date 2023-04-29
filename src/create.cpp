#include "cdefs.hpp"
#include "types.hpp"


static proto0::Create createInfo(tgui_activity a, const tgui_view* parent, tgui_view_visibility vis) {
	proto0::Create pc;
	pc.set_aid(a);
	if (parent != NULL) {
		pc.set_parent(*parent);
	} else {
		pc.set_parent(-1);
	}
	pc.set_v(tgui::VisibilityPublicToPB.at(vis));
	return pc;
}



#define CREATE_VIEW_PRE(name) \
return exceptionToError<tgui_err>([&]() {\
proto0::Method m;\
proto0::Create ## name ## Request r;\
*r.mutable_data() = createInfo(a, parent, vis);

#define CREATE_VIEW_POST(name) \
proto0::Create ## name ## Response res;\
c->c.sendReadMessage(m, res);\
if (res.id() == -1) return TGUI_ERR_MESSAGE;\
*v = res.id();\
return TGUI_ERR_OK;\
});




extern "C" {
	
	tgui_err tgui_create_linear_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool horizontal) {
		CREATE_VIEW_PRE(LinearLayout)
		r.set_horizontal(horizontal);
		*m.mutable_createlinearlayout() = r;
		CREATE_VIEW_POST(LinearLayout)
	}
	
	
	tgui_err tgui_create_frame_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(FrameLayout)
		*m.mutable_createframelayout() = r;
		CREATE_VIEW_POST(FrameLayout)
	}
	
	
	tgui_err tgui_create_swipe_refresh_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(SwipeRefreshLayout)
		*m.mutable_createswiperefreshlayout() = r;
		CREATE_VIEW_POST(SwipeRefreshLayout)
	}
	
	
	tgui_err tgui_create_text_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, bool selectableText, bool clickableLinks) {
		CREATE_VIEW_PRE(TextView)
		r.set_selectabletext(selectableText);
		r.set_clickablelinks(clickableLinks);
		if (text != NULL)
			r.set_text(text);
		*m.mutable_createtextview() = r;
		CREATE_VIEW_POST(TextView)
	}
	
	
	tgui_err tgui_create_edit_text(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, tgui_edit_text_type type, bool noLine) {
		CREATE_VIEW_PRE(EditText)
		r.set_noline(noLine);
		r.set_type(tgui::EditTextTypePublicToPB.at(type));
		if (text != NULL)
			r.set_txt(text);
		*m.mutable_createedittext() = r;
		CREATE_VIEW_POST(EditText)
	}
	
	
	tgui_err tgui_create_button(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text) {
		CREATE_VIEW_PRE(Button)
		if (text != NULL)
			r.set_text(text);
		*m.mutable_createbutton() = r;
		CREATE_VIEW_POST(Button)
	}
	
	
	tgui_err tgui_create_image_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool keyboard) {
		CREATE_VIEW_PRE(ImageView)
		r.set_keyboard(keyboard);
		*m.mutable_createimageview() = r;
		CREATE_VIEW_POST(ImageView)
	}
	
	tgui_err tgui_create_space(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(Space)
		*m.mutable_createspace() = r;
		CREATE_VIEW_POST(Space)
	}
	
	
	tgui_err tgui_create_nested_scroll_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool snapping, bool noBar, bool fillViewport) {
		CREATE_VIEW_PRE(NestedScrollView)
		r.set_snapping(snapping);
		r.set_nobar(noBar);
		r.set_fillviewport(fillViewport);
		*m.mutable_createnestedscrollview() = r;
		CREATE_VIEW_POST(NestedScrollView)
	}
	
	
	tgui_err tgui_create_horizontal_scroll_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool snapping, bool noBar, bool fillViewport) {
		CREATE_VIEW_PRE(HorizontalScrollView)
		r.set_snapping(snapping);
		r.set_nobar(noBar);
		r.set_fillviewport(fillViewport);
		*m.mutable_createhorizontalscrollview() = r;
		CREATE_VIEW_POST(HorizontalScrollView)
	}
	
	tgui_err tgui_create_radio_group(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(RadioGroup)
		*m.mutable_createradiogroup() = r;
		CREATE_VIEW_POST(RadioGroup)
	}
	
	
	tgui_err tgui_create_radio_button(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, bool checked) {
		CREATE_VIEW_PRE(RadioButton)
		r.set_checked(checked);
		if (text != NULL)
			r.set_text(text);
		*m.mutable_createradiobutton() = r;
		CREATE_VIEW_POST(RadioButton)
	}
	
	
	tgui_err tgui_create_checkbox(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, bool checked) {
		CREATE_VIEW_PRE(Checkbox)
		r.set_checked(checked);
		if (text != NULL)
			r.set_text(text);
		*m.mutable_createcheckbox() = r;
		CREATE_VIEW_POST(Checkbox)
	}
	
	
	tgui_err tgui_create_toggle_button(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool checked) {
		CREATE_VIEW_PRE(ToggleButton)
		r.set_checked(checked);
		*m.mutable_createtogglebutton() = r;
		CREATE_VIEW_POST(ToggleButton)
	}
	
	
	tgui_err tgui_create_switch(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool checked) {
		CREATE_VIEW_PRE(Switch)
		r.set_checked(checked);
		*m.mutable_createswitch() = r;
		CREATE_VIEW_POST(Switch)
	}
	
	
	tgui_err tgui_create_spinner(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(Spinner)
		*m.mutable_createspinner() = r;
		CREATE_VIEW_POST(Spinner)
	}
	
	
	tgui_err tgui_create_progress_bar(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(ProgressBar)
		*m.mutable_createprogressbar() = r;
		CREATE_VIEW_POST(ProgressBar)
	}
	
	
	tgui_err tgui_create_tab_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(TabLayout)
		*m.mutable_createtablayout() = r;
		CREATE_VIEW_POST(TabLayout)
	}
	
	
	tgui_err tgui_create_grid_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, uint32_t rows, uint32_t cols) {
		CREATE_VIEW_PRE(GridLayout)
		r.set_rows(rows);
		r.set_cols(cols);
		*m.mutable_creategridlayout() = r;
		CREATE_VIEW_POST(GridLayout)
	}
	
	
	tgui_err tgui_create_web_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis) {
		CREATE_VIEW_PRE(WebView)
		*m.mutable_createwebview() = r;
		CREATE_VIEW_POST(WebView)
	}
	
	
	tgui_err tgui_create_surface_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool keyboard) {
		CREATE_VIEW_PRE(SurfaceView)
		r.set_keyboard(keyboard);
		*m.mutable_createsurfaceview() = r;
		CREATE_VIEW_POST(SurfaceView)
	}
	
	
	
}

