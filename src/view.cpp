#include "cdefs.hpp"

#include "types.hpp"

#include <sys/mman.h>
#include <unistd.h>

extern "C" {
	
	
	tgui_err tgui_show_cursor(tgui_connection c, tgui_activity a, tgui_view v, bool show);



/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_linear_params(tgui_connection c, tgui_activity a, tgui_view v, float weight, int position);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_grid_params(tgui_connection c, tgui_activity a, tgui_view v, tgui_grid_alignment row_align, tgui_grid_alignment col_align);



/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_view_location(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float x, float y);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_relative_params(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_visibility(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_visibility vis);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_delete_view(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_delete_children(tgui_connection c, tgui_activity a, tgui_view v);



/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_set_margin(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_set_padding(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_background_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color);



/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_text_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_progress(tgui_connection c, tgui_activity a, tgui_view v, unsigned char progress);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_refreshing(tgui_connection c, tgui_activity a, tgui_view v, bool refreshing);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_set_text(tgui_connection c, tgui_activity a, tgui_view v, const char* text);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_set_gravity(tgui_connection c, tgui_activity a, tgui_view v, tgui_gravity horizontal, tgui_gravity vertical);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_text_size(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @param[out] text The text of the View. When successful, this has to be freed with free().
 * @return tgui_err 
 */
tgui_err tgui_get_text(tgui_connection c, tgui_activity a, tgui_view v, char** text);



/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_set_checked(tgui_connection c, tgui_activity a, tgui_view v, bool checked);



/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_focus(tgui_connection c, tgui_activity a, tgui_view v, bool focus);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_get_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float* x, float* y);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_set_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size x, tgui_size y, bool smooth);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @param[in] list A NULL terminated list of pointers to strings.
 * @return tgui_err 
 */
tgui_err tgui_set_list(tgui_connection c, tgui_activity a, tgui_view v, const char* const* list);



/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @return tgui_err 
 */
tgui_err tgui_set_image(tgui_connection c, tgui_activity a, tgui_view v, const void* img, size_t length);

	
	
	tgui_err tgui_add_buffer(tgui_connection c, tgui_buffer* buffer) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::AddBufferRequest r;
			r.set_f(tgui::BufferFormatPublicToPB.at(buffer->format));
			r.set_width(buffer->width);
			r.set_height(buffer->height);
			*m.mutable_addbuffer() = r;
			
			int size = buffer->width * buffer->height * tgui::BufferFormatBytesPerPixel.at(buffer->format);
			
			c->c.sendMethodMessage(m);
			
			tgui::common::Connection::Buffer b = c->c.addBuffer();
			
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
			*width = res.width();
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

