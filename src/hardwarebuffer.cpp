#include "cdefs.hpp"

#include "types.hpp"

#include <android/api-level.h>

#include <dlfcn.h>

#include <mutex>

namespace {
	struct LibAndroid {
		void* lib = NULL;
		
		void (*release)(AHardwareBuffer*) = NULL;
		int (*recv)(int fd, AHardwareBuffer**) = NULL;
		
		
		
		LibAndroid() {
			if (android_get_device_api_level() < 26) return;
			lib = dlopen("libandroid.so", RTLD_LAZY | RTLD_LOCAL);
			if (lib != NULL) {
				release = (void (*)(AHardwareBuffer*)) dlsym(lib, "AHardwareBuffer_release");
				recv = (int (*)(int, AHardwareBuffer**)) dlsym(lib, "AHardwareBuffer_recvHandleFromUnixSocket");
			}
		}
		
		~LibAndroid() {
			if (lib != NULL)
				dlclose(lib);
			lib = NULL;
			release = NULL;
			recv = NULL;
		}
		
		
		
		
	};
	static LibAndroid libandroid;
}

extern "C" {
	
	
	tgui_err tgui_hardware_buffer_create(tgui_connection c, tgui_hardware_buffer* buffer, tgui_hardware_buffer_format format, uint32_t width, uint32_t height, tgui_hardware_buffer_cpu_frequency read, tgui_hardware_buffer_cpu_frequency write) {
		if (libandroid.recv == NULL) return TGUI_ERR_API_LEVEL;
		return exceptionToError<tgui_err>([&]() {
			proto0::CreateHardwareBufferRequest r;
			r.set_width(width);
			r.set_height(height);
			r.set_format(HardwareBufferFormatPublicToPB.at(format));
			r.set_cpuread(HardwareBufferCPUPublicToPB.at(read));
			r.set_cpuwrite(HardwareBufferCPUPublicToPB.at(write));
			
			int32_t id = c->c.receiveHardwareBuffer(r, libandroid.recv, &(buffer->buffer));
			if (id == -1) return TGUI_ERR_MESSAGE;
			buffer->id = id;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_hardware_buffer_destroy(tgui_connection c, tgui_hardware_buffer* buffer) {
		if (libandroid.release == NULL) return TGUI_ERR_API_LEVEL;
		libandroid.release(buffer->buffer);
		METHOD_PRE(DestroyHardwareBuffer)
		r.set_buffer(buffer->id);
		*m.mutable_destroyhardwarebuffer() = r;
		METHOD_POST(DestroyHardwareBuffer)
	}
	
	
	tgui_err tgui_surface_view_set_buffer(tgui_connection c, tgui_activity a, tgui_view v, tgui_hardware_buffer* buffer) {
		VIEW_METHOD_PRE(SurfaceViewSetBuffer)
		r.set_buffer(buffer->id);
		*m.mutable_setsurfacebuffer() = r;
		VIEW_METHOD_POST(SurfaceViewSetBuffer)
	}
	
	tgui_err tgui_surface_view_config(tgui_connection c, tgui_activity a, tgui_view v, tgui_color background_color, tgui_surface_view_dimension_mismatch x, tgui_surface_view_dimension_mismatch y, float framerate) {
		VIEW_METHOD_PRE(SurfaceViewConfig)
		r.set_backgroundcolor(background_color);
		r.set_xmismatch(DimensionMismatchPublicToPB.at(x));
		r.set_ymismatch(DimensionMismatchPublicToPB.at(y));
		r.set_framerate(framerate);
		*m.mutable_surfaceconfig() = r;
		VIEW_METHOD_POST(SurfaceViewConfig)
	}
	
	
	
}