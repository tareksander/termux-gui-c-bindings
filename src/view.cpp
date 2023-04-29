#include "cdefs.hpp"

#include "types.hpp"

#include <sys/mman.h>
#include <unistd.h>

extern "C" {
	
	
	tgui_err tgui_show_cursor(tgui_connection c, tgui_activity a, tgui_view v, bool show) {
		VIEW_METHOD_PRE(ShowCursor)
		r.set_show(show);
		*m.mutable_showcursor() = r;
		VIEW_METHOD_POST(ShowCursor)
	}
	
	
	tgui_err tgui_linear_params(tgui_connection c, tgui_activity a, tgui_view v, float weight, int position) {
		VIEW_METHOD_PRE(SetLinearLayoutParams)
		r.set_weight(weight);
		r.set_position(position);
		*m.mutable_setlinearlayout() = r;
		VIEW_METHOD_POST(SetLinearLayoutParams)
	}
	
	
	
	tgui_err tgui_grid_params(tgui_connection c, tgui_activity a, tgui_view v, size_t row, size_t col, size_t row_size, size_t col_size, tgui_grid_alignment row_align, tgui_grid_alignment col_align) {
		VIEW_METHOD_PRE(SetGridLayoutParams)
		r.set_row(row);
		r.set_col(col);
		r.set_rowsize(row_size);
		r.set_colsize(col_size);
		r.set_rowalign(GridAlignmentPublicToPB.at(row_align));
		r.set_colalign(GridAlignmentPublicToPB.at(col_align));
		*m.mutable_setgridlayout() = r;
		VIEW_METHOD_POST(SetGridLayoutParams)
	}
	
	
	
	
	tgui_err tgui_view_location(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float x, float y, bool top) {
		VIEW_METHOD_PRE(SetViewLocation)
		r.set_unit(UnitPublicToPB.at(unit));
		r.set_x(x);
		r.set_y(y);
		r.set_top(top);
		*m.mutable_setlocation() = r;
		VIEW_METHOD_POST(SetViewLocation)
	}
	
	
	
	tgui_err tgui_relative_params(tgui_connection c, tgui_activity a, tgui_view v) {
		return TGUI_ERR_OK;
	}
	
	
	
	tgui_err tgui_visibility(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_visibility vis) {
		VIEW_METHOD_PRE(SetVisibility)
		r.set_vis(VisibilityPublicToPB.at(vis));
		*m.mutable_setvisibility() = r;
		VIEW_METHOD_POST(SetVisibility)
	}
	
	
	
	tgui_err tgui_delete_view(tgui_connection c, tgui_activity a, tgui_view v) {
		VIEW_METHOD_PRE(DeleteView)
		*m.mutable_deleteview() = r;
		VIEW_METHOD_POST(DeleteView)
	}
	
	
	
	tgui_err tgui_delete_children(tgui_connection c, tgui_activity a, tgui_view v) {
		VIEW_METHOD_PRE(DeleteChildren)
		*m.mutable_deletechildren() = r;
		VIEW_METHOD_POST(DeleteChildren)
	}
	
	
	
	
	tgui_err tgui_set_margin(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir) {
		VIEW_METHOD_PRE(SetMargin)
		*r.mutable_s() = SizePublicToPB(size);
		r.set_dir(DirectionPublicToPB.at(dir));
		*m.mutable_setmargin() = r;
		VIEW_METHOD_POST(SetMargin)
	}
	
	
	
	tgui_err tgui_set_padding(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir) {
		VIEW_METHOD_PRE(SetPadding)
		*r.mutable_s() = SizePublicToPB(size);
		r.set_dir(DirectionPublicToPB.at(dir));
		*m.mutable_setpadding() = r;
		VIEW_METHOD_POST(SetPadding)
	}
	
	
	
	tgui_err tgui_background_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color) {
		VIEW_METHOD_PRE(SetBackgroundColor)
		r.set_color(color);
		*m.mutable_setbackgroundcolor() = r;
		VIEW_METHOD_POST(SetBackgroundColor)
	}
	
	
	
	
	tgui_err tgui_text_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color) {
		VIEW_METHOD_PRE(SetTextColor)
		r.set_color(color);
		*m.mutable_settextcolor() = r;
		VIEW_METHOD_POST(SetTextColor)
	}
	
	
	
	tgui_err tgui_progress(tgui_connection c, tgui_activity a, tgui_view v, unsigned char progress) {
		VIEW_METHOD_PRE(SetProgress)
		r.set_progress(progress);
		*m.mutable_setprogress() = r;
		VIEW_METHOD_POST(SetProgress)
	}
	
	
	
	tgui_err tgui_refreshing(tgui_connection c, tgui_activity a, tgui_view v, bool refreshing) {
		VIEW_METHOD_PRE(SetRefreshing)
		r.set_refreshing(refreshing);
		*m.mutable_setrefreshing() = r;
		VIEW_METHOD_POST(SetRefreshing)
	}
	
	
	
	tgui_err tgui_set_text(tgui_connection c, tgui_activity a, tgui_view v, const char* text) {
		VIEW_METHOD_PRE(SetText)
		r.set_text(text);
		*m.mutable_settext() = r;
		VIEW_METHOD_POST(SetText)
	}
	
	
	
	tgui_err tgui_set_gravity(tgui_connection c, tgui_activity a, tgui_view v, tgui_gravity horizontal, tgui_gravity vertical) {
		VIEW_METHOD_PRE(SetGravity)
		r.set_horizontal(GravityPublicToPB.at(horizontal));
		r.set_vertical(GravityPublicToPB.at(vertical));
		*m.mutable_setgravity() = r;
		VIEW_METHOD_POST(SetGravity)
	}
	
	
	
	tgui_err tgui_text_size(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size) {
		VIEW_METHOD_PRE(SetTextSize)
		*r.mutable_s() = SizePublicToPB(size);
		*m.mutable_settextsize() = r;
		VIEW_METHOD_POST(SetTextSize)
	}
	
	
	
	tgui_err tgui_get_text(tgui_connection c, tgui_activity a, tgui_view v, char** text) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::GetTextRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*m.mutable_gettext() = r;
			
			proto0::GetTextResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			if (text != NULL)
				*text = strdup(res.text().c_str());
			return TGUI_ERR_OK;
		});
	}
	
	
	
	
	tgui_err tgui_set_checked(tgui_connection c, tgui_activity a, tgui_view v, bool checked) {
		VIEW_METHOD_PRE(SetChecked)
		r.set_checked(checked);
		*m.mutable_setchecked() = r;
		VIEW_METHOD_POST(SetChecked)
	}
	
	
	
	
	tgui_err tgui_focus(tgui_connection c, tgui_activity a, tgui_view v, bool force_soft) {
		VIEW_METHOD_PRE(RequestFocus)
		r.set_forcesoft(force_soft);
		*m.mutable_requestfocus() = r;
		VIEW_METHOD_POST(RequestFocus)
	}
	
	
	
	tgui_err tgui_get_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float* x, float* y) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::GetScrollPositionRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			r.set_unit(UnitPublicToPB.at(unit));
			*m.mutable_getscrollposition() = r;
			
			proto0::GetScrollPositionResponse res;
			c->c.sendReadMessage(m, res);
			if (res.x() < 0 || res.y() < 0) return TGUI_ERR_MESSAGE;
			if (x != NULL)
				*x = res.x();
			if (y != NULL)
			*y = res.y();
			return TGUI_ERR_OK;
		});
	}
	
	
	
	tgui_err tgui_set_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size x, tgui_size y, bool smooth) {
		VIEW_METHOD_PRE(SetScrollPosition)
		*r.mutable_x() = SizePublicToPB(x);
		*r.mutable_y() = SizePublicToPB(y);
		r.set_smooth(smooth);
		*m.mutable_setscrollposition() = r;
		VIEW_METHOD_POST(SetScrollPosition)
	}
	
	
	
	tgui_err tgui_set_list(tgui_connection c, tgui_activity a, tgui_view v, const char* const* list) {
		VIEW_METHOD_PRE(SetList)
		if (list != NULL) {
			const char* const* c = list;
			while (*c != NULL) {
				r.add_list(*c);
				c++;
			}
		}
		*m.mutable_setlist() = r;
		VIEW_METHOD_POST(SetList)
	}
	
	
	
	
	tgui_err tgui_set_image(tgui_connection c, tgui_activity a, tgui_view v, const void* img, size_t length) {
		VIEW_METHOD_PRE(SetImage)
		r.set_image(img, length);
		*m.mutable_setimage() = r;
		VIEW_METHOD_POST(SetImage)
	}
	
	
	tgui_err tgui_add_buffer(tgui_connection c, tgui_buffer* buffer) {
		return exceptionToError<tgui_err>([&]() {
			proto0::AddBufferRequest r;
			r.set_f(tgui::BufferFormatPublicToPB.at(buffer->format));
			r.set_width(buffer->width);
			r.set_height(buffer->height);
			
			int size = buffer->width * buffer->height * tgui::BufferFormatBytesPerPixel.at(buffer->format);
			
			tgui::common::Connection::Buffer b = c->c.addBuffer(r);
			
			if (b.fd == -1) {
				return TGUI_ERR_MESSAGE;
			}
			buffer->id = b.id;
			buffer->fd = b.fd;
			buffer->data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, buffer->fd, 0);
			
			if (buffer->data == MAP_FAILED) {
				close(buffer->fd);
				return TGUI_ERR_SYSTEM;
			}
			return TGUI_ERR_OK;
		});
	}
	
	
	
	
	
	
	tgui_err tgui_delete_buffer(tgui_connection c, tgui_buffer* buffer) {
		return exceptionToError<tgui_err>([&]() {
			if (buffer->fd != -1) {
				close(buffer->fd);
				buffer->fd = -1;
			}
			if (buffer->data != MAP_FAILED) {
				munmap(buffer->data, buffer->width * buffer->height * tgui::BufferFormatBytesPerPixel.at(buffer->format));
				buffer->data = MAP_FAILED;
			}
			
			if (buffer->id != -1) {
				proto0::Method m;
				proto0::DeleteBufferRequest r;
				r.set_buffer(buffer->id);
				*m.mutable_deletebuffer() = r;
				
				proto0::DeleteBufferResponse res;
				c->c.sendReadMessage(m, res);
				if (! res.success()) return TGUI_ERR_MESSAGE;
				buffer->id = -1;
			}
			return TGUI_ERR_OK;
		});
	}
	
	
	
	tgui_err tgui_blit_buffer(tgui_connection c, const tgui_buffer* buffer) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::BlitBufferRequest r;
			r.set_buffer(buffer->id);
			*m.mutable_blitbuffer() = r;
			
			proto0::BlitBufferResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	
	tgui_err tgui_set_buffer(tgui_connection c, tgui_activity a, tgui_view v, const tgui_buffer* buffer) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetBufferRequest r;
			r.set_buffer(buffer->id);
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			*m.mutable_setbuffer() = r;
			
			proto0::SetBufferResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	
	
	tgui_err tgui_refresh_image_view(tgui_connection c, tgui_activity a, tgui_view v) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::RefreshImageViewRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			*m.mutable_refreshimageview() = r;
			
			proto0::RefreshImageViewResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_set_width(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_size width) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetWidthRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			*r.mutable_s() = tgui::ViewSizePublicToPB(width);
			*m.mutable_setwidth() = r;
			
			proto0::SetWidthResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_set_height(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_size height) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetHeightRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			*r.mutable_s() = tgui::ViewSizePublicToPB(height);
			*m.mutable_setheight() = r;
			
			proto0::SetHeightResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_get_dimensions(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float* width, float* height) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::GetDimensionsRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			r.set_unit(tgui::UnitPublicToPB.at(unit));
			*m.mutable_getdimensions() = r;
			
			proto0::GetDimensionsResponse res;
			c->c.sendReadMessage(m, res);
			if (res.width() < 0) return TGUI_ERR_MESSAGE;
			if (width != NULL)
				*width = res.width();
			if (height != NULL)
				*height = res.height();
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_select_tab(tgui_connection c, tgui_activity a, tgui_view v, unsigned int index) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SelectTabRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			r.set_tab(index);
			*m.mutable_selecttab() = r;
			
			proto0::SelectTabResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_select_item(tgui_connection c, tgui_activity a, tgui_view v, unsigned int index) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SelectItemRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			r.set_item(index);
			*m.mutable_selectitem() = r;
			
			proto0::SelectItemResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	
	tgui_err tgui_set_clickable(tgui_connection c, tgui_activity a, tgui_view v, bool clickable) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetClickableRequest r;
			proto0::View pv;
			pv.set_aid(a);
			pv.set_id(v);
			*r.mutable_v() = pv;
			r.set_clickable(clickable);
			*m.mutable_setclickable() = r;
			
			proto0::SetClickableResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	
	
	
	
	
	
}

