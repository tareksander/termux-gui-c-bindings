#include "cdefs.hpp"

#include "types.hpp"


#define REMOTE_CREATE_PRE(name) \
return exceptionToError<tgui_err>([&]() {\
proto0::Method m;\
proto0::name ## Request r;\
r.set_rid(layout);\
if (parent != NULL) r.set_parent(*parent); else r.set_parent(-1);

#define REMOTE_CREATE_POST(name) \
proto0::name ## Response res;\
c->c.sendReadMessage(m, res);\
if (res.id() == -1) return TGUI_ERR_MESSAGE;\
return TGUI_ERR_OK;\
});


#define REMOTE_METHOD_PRE(name) \
return exceptionToError<tgui_err>([&]() {\
proto0::Method m;\
proto0::name ## Request r;\
r.set_rid(layout);\
r.set_id(v);

#define REMOTE_METHOD_POST(name) \
proto0::name ## Response res;\
c->c.sendReadMessage(m, res);\
if (! res.success()) return TGUI_ERR_MESSAGE;\
return TGUI_ERR_OK;\
});


extern "C" {
	
	
	
	
	
	tgui_err tgui_remote_layout_create(tgui_connection c, tgui_remote_layout* layout) {
		METHOD_PRE(CreateRemoteLayout)
		METHOD_POST_NONSTANDARD(CreateRemoteLayout)
		if (res.rid() == -1) return TGUI_ERR_MESSAGE;
		*layout = res.rid();
		METHOD_POST_NONSTANDARD2()
	}
	
	
	tgui_err tgui_remote_layout_destroy(tgui_connection c, tgui_remote_layout layout) {
		METHOD_PRE(DeleteRemoteLayout)
		r.set_rid(layout);
		METHOD_POST(DeleteRemoteLayout)
	}
	
	
	tgui_err tgui_remote_create_frame_layout(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v) {
		REMOTE_CREATE_PRE(AddRemoteFrameLayout)
		REMOTE_CREATE_POST(AddRemoteFrameLayout)
	}
	
	
	tgui_err tgui_remote_create_linear_layout(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v, bool horizontal) {
		REMOTE_CREATE_PRE(AddRemoteLinearLayout)
		r.set_horizontal(horizontal);
		REMOTE_CREATE_POST(AddRemoteLinearLayout)
	}
	
	
	tgui_err tgui_remote_create_text_view(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v) {
		REMOTE_CREATE_PRE(AddRemoteTextView)
		REMOTE_CREATE_POST(AddRemoteTextView)
	}
	
	
	tgui_err tgui_remote_create_button(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v) {
		REMOTE_CREATE_PRE(AddRemoteButton)
		REMOTE_CREATE_POST(AddRemoteButton)
	}
	
	
	tgui_err tgui_remote_create_image_view(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v) {
		REMOTE_CREATE_PRE(AddRemoteImageView)
		REMOTE_CREATE_POST(AddRemoteImageView)
	}
	
	
	tgui_err tgui_remote_create_progress_bar(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v) {
		REMOTE_CREATE_PRE(AddRemoteProgressBar)
		REMOTE_CREATE_POST(AddRemoteProgressBar)
	}
	
	
	tgui_err tgui_remote_set_background_color(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_color color) {
		REMOTE_METHOD_PRE(SetRemoteBackgroundColor)
		r.set_color(color);
		REMOTE_METHOD_POST(SetRemoteBackgroundColor)
	}
	
	
	tgui_err tgui_remote_set_progress(tgui_connection c, tgui_remote_layout layout, tgui_view v, unsigned char progress) {
		REMOTE_METHOD_PRE(SetRemoteProgressBar)
		r.set_max(100);
		r.set_progress(progress);
		REMOTE_METHOD_POST(SetRemoteProgressBar)
	}
	
	
	tgui_err tgui_remote_set_text(tgui_connection c, tgui_remote_layout layout, tgui_view v, const char* text) {
		REMOTE_METHOD_PRE(SetRemoteText)
		r.set_text(text);
		REMOTE_METHOD_POST(SetRemoteText)
	}
	
	
	tgui_err tgui_remote_set_text_size(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_size size) {
		REMOTE_METHOD_PRE(SetRemoteTextSize)
		*r.mutable_s() = SizePublicToPB(size);
		REMOTE_METHOD_POST(SetRemoteTextSize)
	}
	
	
	tgui_err tgui_remote_set_text_color(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_color color) {
		REMOTE_METHOD_PRE(SetRemoteTextColor)
		r.set_color(color);
		REMOTE_METHOD_POST(SetRemoteTextColor)
	}
	
	
	tgui_err tgui_remote_set_visibility(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_view_visibility vis) {
		REMOTE_METHOD_PRE(SetRemoteVisibility)
		r.set_v(VisibilityPublicToPB.at(vis));
		REMOTE_METHOD_POST(SetRemoteVisibility)
	}
	
	
	tgui_err tgui_remote_set_padding(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_size left, tgui_size top, tgui_size right, tgui_size bottom) {
		REMOTE_METHOD_PRE(SetRemotePadding)
		*r.mutable_left() = SizePublicToPB(left);
		*r.mutable_top() = SizePublicToPB(top);
		*r.mutable_right() = SizePublicToPB(right);
		*r.mutable_bottom() = SizePublicToPB(bottom);
		REMOTE_METHOD_POST(SetRemotePadding)
	}
	
	
	tgui_err tgui_remote_set_image(tgui_connection c, tgui_remote_layout layout, tgui_view v, const void* img, size_t length) {
		REMOTE_METHOD_PRE(SetRemoteImage)
		r.set_image(img, length);
		REMOTE_METHOD_POST(SetRemoteImage)
	}
	
	
	tgui_err tgui_remote_widget_layout(tgui_connection c, tgui_remote_layout layout, const char* wid) {
		METHOD_PRE(SetWidgetLayout)
		r.set_rid(layout);
		r.set_wid(wid);
		METHOD_POST(SetWidgetLayout)
	}

	
}

