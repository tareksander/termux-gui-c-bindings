#include "cdefs.hpp"

#include "types.hpp"

#include <sys/mman.h>
#include <unistd.h>

extern "C" {
	
	
	
	
	
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
	
	
	
	
	
	
	
	
	
	
}

