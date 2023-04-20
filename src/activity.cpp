#include "cdefs.hpp"

#include "types.hpp"

extern "C" {
	tgui_err tgui_activity_create(tgui_connection c, tgui_activity* a, tgui_activity_type type, tgui_task* t, bool intercept) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::NewActivityRequest r;
			if (t == NULL) {
				r.set_tid(-1);
			} else {
				r.set_tid(*t);
			}
			r.set_type(tgui::ActivityTypePublicToPB.at(type));
			r.set_interceptbackbutton(intercept);
			*m.mutable_newactivity() = r;
			
			proto0::NewActivityResponse res;
			c->c.sendReadMessage(m, res);
			if (res.aid() == -1) return TGUI_ERR_MESSAGE;
			if (t != NULL && *t == -1) {
				*t = res.tid();
			}
			*a = res.aid();
			return TGUI_ERR_OK;
		});
	}
	
	
	
	tgui_err tgui_activity_task_to_back(tgui_connection c, tgui_activity a) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::MoveTaskToBackRequest r;
			r.set_aid(a);
			*m.mutable_movetasktoback() = r;
			
			proto0::MoveTaskToBackResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_theme(tgui_connection c, tgui_activity a, tgui_color status_bar_color, tgui_color primary_color, tgui_color accent_color, tgui_color window_background, tgui_color text_color) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetThemeRequest r;
			r.set_aid(a);
			r.set_statusbarcolor(status_bar_color);
			r.set_colorprimary(primary_color);
			r.set_windowbackground(window_background);
			r.set_textcolor(text_color);
			r.set_coloraccent(accent_color);
			*m.mutable_settheme() = r;
			
			proto0::SetThemeResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_task_description(tgui_connection c, tgui_activity a, const void* img, size_t img_size, const char* label) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetTaskDescriptionRequest r;
			r.set_aid(a);
			r.set_img(img, img_size);
			r.set_label(label);
			*m.mutable_settaskdescription() = r;
			
			proto0::SetTaskDescriptionResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_pip_params(tgui_connection c, tgui_activity a, unsigned int num, unsigned int den) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetPiPParamsRequest r;
			r.set_aid(a);
			r.set_num(num);
			r.set_den(den);
			*m.mutable_setpipparams() = r;
			
			proto0::SetPiPParamsResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_pip_mode(tgui_connection c, tgui_activity a, bool pip) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetPiPModeRequest r;
			r.set_aid(a);
			r.set_pip(pip);
			*m.mutable_setpipmode() = r;
			
			proto0::SetPiPModeResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_activity_set_pip_mode_auto(tgui_connection c, tgui_activity a, bool automatic) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetPiPModeAutoRequest r;
			r.set_aid(a);
			r.set_pip(automatic);
			*m.mutable_setpipmodeauto() = r;
			
			proto0::SetPiPModeAutoResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_input_mode(tgui_connection c, tgui_activity a, tgui_activity_input_mode mode) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetInputModeRequest r;
			r.set_aid(a);
			r.set_mode(tgui::InputModePublicToPB.at(mode));
			*m.mutable_setinputmode() = r;
			
			proto0::SetInputModeResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_keep_screen_on(tgui_connection c, tgui_activity a, bool keep) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::KeepScreenOnRequest r;
			r.set_aid(a);
			r.set_on(keep);
			*m.mutable_keepscreenon() = r;
			
			proto0::KeepScreenOnResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_orientation(tgui_connection c, tgui_activity a, tgui_orientation o) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetOrientationRequest r;
			r.set_aid(a);
			r.set_orientation(tgui::OrientationPublicToPB.at(o));
			*m.mutable_setorientation() = r;
			
			proto0::SetOrientationResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_position(tgui_connection c, tgui_activity a, unsigned int x, unsigned int y) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetPositionRequest r;
			r.set_aid(a);
			r.set_x(x);
			r.set_y(y);
			*m.mutable_setposition() = r;
			
			proto0::SetPositionResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_get_configuration(tgui_connection c, tgui_activity a, tgui_activity_configuration* conf) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::GetConfigurationRequest r;
			r.set_aid(a);
			
			*m.mutable_getconfiguration() = r;
			
			proto0::GetConfigurationResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			*conf = tgui::ConfigurationPBToPublic(res.configuration());
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_hide_soft_keyboard(tgui_connection c, tgui_activity a) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::HideSoftKeyboardRequest r;
			r.set_aid(a);
			*m.mutable_hidesoftkeyboard() = r;
			
			proto0::HideSoftKeyboardResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_intercept_back_button(tgui_connection c, tgui_activity a, bool intercept) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::InterceptBackButtonRequest r;
			r.set_aid(a);
			r.set_intercept(intercept);
			*m.mutable_interceptbackbutton() = r;
			
			proto0::InterceptBackButtonResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_activity_set_secure(tgui_connection c, tgui_activity a, bool secure) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetSecureFlagRequest r;
			r.set_aid(a);
			r.set_secure(secure);
			*m.mutable_setsecure() = r;
			
			proto0::SetSecureFlagResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_task_to_front(tgui_connection c, tgui_task t) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::BringTaskToFrontRequest r;
			r.set_tid(t);
			*m.mutable_bringtasktofront() = r;
			
			proto0::BringTaskToFrontResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_task_finish(tgui_connection c, tgui_task t) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::FinishTaskRequest r;
			r.set_tid(t);
			*m.mutable_finishtask() = r;
			
			proto0::FinishTaskResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
}

