#include "cdefs.hpp"

#include "types.hpp"

extern "C" {
	
	tgui_err tgui_notification_create_channel(tgui_connection c, const char* id, const char* name, tgui_importance imp) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::CreateNotificationChannelRequest r;
			r.set_id(id);
			r.set_name(name);
			r.set_importance(ImportancePublicToPB.at(imp));
			*m.mutable_createchannel() = r;
			
			proto0::CreateNotificationChannelResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	static void configNotificationRequest(proto0::CreateNotificationRequest& r, const tgui_notification_create_info* info) {
		r.set_channel(info->channel);
		r.set_ongoing(info->ongoing);
		if (info->timestamp != 0) {
			r.set_timestamp(info->timestamp);
		}
		r.set_showtimestamp(info->show_timestamp);
		r.set_alertonce(info->alert_once);
		if (info->update != NULL) {
			r.set_id(*info->update);
		}
		if (info->icon != NULL) {
			r.set_icon(info->icon, info->icon_length);
		}
		r.set_importance(ImportancePublicToPB.at(info->importance));
		if (info->actions != NULL) {
			for (int i = 0; i < info->actions_length; i++) {
				r.set_actions(i, info->actions[i]);
			}
		}
	}
	
	tgui_err tgui_notification_create_normal(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, const char* title, const char* content) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::CreateNotificationRequest r;
			configNotificationRequest(r, info);
			proto0::CreateNotificationRequest::NormalNotification rn;
			rn.set_title(title);
			rn.set_content(content);
			*r.mutable_normal() = rn;
			*m.mutable_createnotification() = r;
			
			proto0::CreateNotificationResponse res;
			c->c.sendReadMessage(m, res);
			if (res.id() == -1) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_notification_create_big_text(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, const char* title, const char* content) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::CreateNotificationRequest r;
			configNotificationRequest(r, info);
			proto0::CreateNotificationRequest::LongTextNotification rn;
			rn.set_title(title);
			rn.set_content(content);
			*r.mutable_longtext() = rn;
			*m.mutable_createnotification() = r;
			
			proto0::CreateNotificationResponse res;
			c->c.sendReadMessage(m, res);
			if (res.id() == -1) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_notification_big_image(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, const char* title, const char* content, const void* img, size_t img_length, bool thumbnail) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::CreateNotificationRequest r;
			configNotificationRequest(r, info);
			proto0::CreateNotificationRequest::BigImageNotification rn;
			rn.set_title(title);
			rn.set_content(content);
			rn.set_image(img, img_length);
			rn.set_asthumbnail(thumbnail);
			*r.mutable_bigimage() = rn;
			*m.mutable_createnotification() = r;
			
			proto0::CreateNotificationResponse res;
			c->c.sendReadMessage(m, res);
			if (res.id() == -1) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_notification_create_custom(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, tgui_remote_layout normal, tgui_remote_layout* expanded, tgui_remote_layout* hud) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::CreateNotificationRequest r;
			configNotificationRequest(r, info);
			proto0::CreateNotificationRequest::CustomNotification rn;
			rn.set_layout(normal);
			if (expanded != NULL) {
				rn.set_layoutexpanded(*expanded);
			}
			if (hud != NULL) {
				rn.set_layouthud(*hud);
			}
			*r.mutable_custom() = rn;
			*m.mutable_createnotification() = r;
			
			proto0::CreateNotificationResponse res;
			c->c.sendReadMessage(m, res);
			if (res.id() == -1) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_notification_dismiss(tgui_connection c, tgui_notification n) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::CancelNotificationRequest r;
			r.set_id(n);
			*m.mutable_cancelnotification() = r;
			
			proto0::CancelNotificationResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
}

