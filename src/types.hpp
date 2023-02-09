#pragma once

#include <unordered_map>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <string.h>

#include <termuxgui/termuxgui.h>

namespace tgui {
	
	template<typename K, typename V> constexpr inline std::unordered_map<V, K> invert(std::unordered_map<K, V> original) {
		std::unordered_map<V, K> m;
		for (const std::pair<K, V>& pair : original) {
			m.insert({pair.second, pair.first});
		}
		return m;
	}
	
	
	inline const std::unordered_map<tgui_activity_type, tgui::proto0::NewActivityRequest::ActivityType> ActivityTypePublicToPB = {
		{TGUI_ACTIVITY_NORMAL, tgui::proto0::NewActivityRequest::normal},
		{TGUI_ACTIVITY_DIALOG, tgui::proto0::NewActivityRequest::dialog},
		{TGUI_ACTIVITY_DIALOG_CANCELOUTSIDE, tgui::proto0::NewActivityRequest::dialogCancelOutside},
		{TGUI_ACTIVITY_PIP, tgui::proto0::NewActivityRequest::pip},
		{TGUI_ACTIVITY_LOCKSCREEN, tgui::proto0::NewActivityRequest::lockscreen},
		{TGUI_ACTIVITY_OVERLAY, tgui::proto0::NewActivityRequest::overlay},
	};
	
	
	inline const std::unordered_map<tgui_activity_input_mode, tgui::proto0::SetInputModeRequest::InputMode> InputModePublicToPB = {
		{TGUI_ACTIVITY_INPUT_MODE_PAN, tgui::proto0::SetInputModeRequest::pan},
		{TGUI_ACTIVITY_INPUT_MODE_RESIZE, tgui::proto0::SetInputModeRequest::resize},
	};
	
	
	
	inline const std::unordered_map<tgui_orientation, tgui::proto0::Orientation> OrientationPublicToPB = {
		{TGUI_ORIENTATION_UNSPECIFIED, tgui::proto0::unspecified},
		{TGUI_ORIENTATION_BEHIND, tgui::proto0::behind},
		{TGUI_ORIENTATION_FULL_SENSOR, tgui::proto0::fullSensor},
		{TGUI_ORIENTATION_FULL_USER, tgui::proto0::fullUser},
		{TGUI_ORIENTATION_LANDSCAPE, tgui::proto0::landscape},
		{TGUI_ORIENTATION_LOCKED, tgui::proto0::locked},
		{TGUI_ORIENTATION_NOSENSOR, tgui::proto0::nosensor},
		{TGUI_ORIENTATION_PORTRAIT, tgui::proto0::portrait},
		{TGUI_ORIENTATION_REVERSE_LANDSCAPE, tgui::proto0::reverseLandscape},
		{TGUI_ORIENTATION_REVERSE_PORTRAIT, tgui::proto0::reversePortrait},
		{TGUI_ORIENTATION_SENSOR, tgui::proto0::sensor},
		{TGUI_ORIENTATION_SENSOR_LANDSCAPE, tgui::proto0::sensorLandscape},
		{TGUI_ORIENTATION_SENSOR_PORTRAIT, tgui::proto0::sensorPortrait},
		{TGUI_ORIENTATION_USER, tgui::proto0::user},
		{TGUI_ORIENTATION_USER_LANDSCAPE, tgui::proto0::userLandscape},
		{TGUI_ORIENTATION_USER_PORTRAIT, tgui::proto0::userPortrait},
	};
	inline const std::unordered_map<tgui::proto0::Orientation, tgui_orientation> OrientationPBToPublic = invert(OrientationPublicToPB);
	
	
	inline const std::unordered_map<tgui_view_visibility, tgui::proto0::Visibility> VisibilityPublicToPB = {
		{TGUI_VIS_VISIBLE, tgui::proto0::visible},
		{TGUI_VIS_HIDDEN, tgui::proto0::hidden},
		{TGUI_VIS_GONE, tgui::proto0::gone},
	};
	inline const std::unordered_map<tgui::proto0::Visibility, tgui_view_visibility> VisibilityPBToPublic = invert(VisibilityPublicToPB);
	
	
	inline const std::unordered_map<tgui_size_unit, tgui::proto0::Size::Unit> UnitPublicToPB = {
		{TGUI_UNIT_DP, tgui::proto0::Size::dp},
		{TGUI_UNIT_SP, tgui::proto0::Size::sp},
		{TGUI_UNIT_PX, tgui::proto0::Size::px},
		{TGUI_UNIT_MM, tgui::proto0::Size::mm},
		{TGUI_UNIT_IN, tgui::proto0::Size::in},
		{TGUI_UNIT_PT, tgui::proto0::Size::pt},
	};
	inline const std::unordered_map<tgui::proto0::Size::Unit, tgui_size_unit> UnitPBToPublic = invert(UnitPublicToPB);
	
	
	inline const std::unordered_map<tgui_touch_action, tgui::proto0::TouchEvent::Action> TouchActionPublicToPB = {
		{TGUI_TOUCH_DOWN, tgui::proto0::TouchEvent::down},
		{TGUI_TOUCH_UP, tgui::proto0::TouchEvent::up},
		{TGUI_TOUCH_POINTER_DOWN, tgui::proto0::TouchEvent::pointerDown},
		{TGUI_TOUCH_POINTER_UP, tgui::proto0::TouchEvent::pointerUp},
		{TGUI_TOUCH_CANCEL, tgui::proto0::TouchEvent::cancel},
		{TGUI_TOUCH_MOVE, tgui::proto0::TouchEvent::move},
	};
	inline const std::unordered_map<tgui::proto0::TouchEvent::Action, tgui_touch_action> TouchActionPBToPublic = invert(TouchActionPublicToPB);
	
	
	inline const std::unordered_map<tgui_gravity, tgui::proto0::SetGravityRequest::Gravity> GravityPublicToPB = {
		{TGUI_GRAV_CENTER, tgui::proto0::SetGravityRequest::CENTER},
		{TGUI_GRAV_LEFTTOP, tgui::proto0::SetGravityRequest::LEFTTOP},
		{TGUI_GRAV_RIGHTBOTTOM, tgui::proto0::SetGravityRequest::RIGHTBOTTOM},
	};
	
	
	inline const std::unordered_map<tgui_direction, tgui::proto0::Direction> DirectionPublicToPB = {
		{TGUI_DIR_ALL, tgui::proto0::ALL},
		{TGUI_DIR_TOP, tgui::proto0::TOP},
		{TGUI_DIR_LEFT, tgui::proto0::LEFT},
		{TGUI_DIR_BOTTOM, tgui::proto0::BOTTOM},
		{TGUI_DIR_RIGHT, tgui::proto0::RIGHT},
		
	};
	inline const std::unordered_map<tgui::proto0::Direction, tgui_direction> DirectionPBToPublic = invert(DirectionPublicToPB);
	
	
	inline const std::unordered_map<tgui_importance, tgui::proto0::Importance> ImportancePublicToPB = {
		{TGUI_IMP_DEFAULT, tgui::proto0::DEFAULT},
		{TGUI_IMP_MIN, tgui::proto0::MIN},
		{TGUI_IMP_LOW, tgui::proto0::LOW},
		{TGUI_IMP_HIGH, tgui::proto0::HIGH},
		{TGUI_IMP_MAX, tgui::proto0::MAX},
		
	};
	inline const std::unordered_map<tgui::proto0::Importance, tgui_importance> ImportancePBToPublic = invert(ImportancePublicToPB);
	
	
	inline const std::unordered_map<tgui_buffer_format, tgui::proto0::AddBufferRequest::Format> BufferFormatPublicToPB = {
		{TGUI_BUFFER_FORMAT_ARGB8888, tgui::proto0::AddBufferRequest::ARGB8888},
		
	};
	
	inline const std::unordered_map<tgui_buffer_format, int> BufferFormatBytesPerPixel = {
		{TGUI_BUFFER_FORMAT_ARGB8888, 4},
		
	};
	
	
	inline proto0::ViewSize ViewSizePublicToPB(const tgui_view_size& s) {
		proto0::ViewSize ret;
		if (s.type == TGUI_VIEW_MATCH_PARENT) {
			ret.set_constant(proto0::ViewSize::MATCH_PARENT);
		} else if (s.type == TGUI_VIEW_WRAP_CONTENT) {
			ret.set_constant(proto0::ViewSize::WRAP_CONTENT);
		} else {
			proto0::Size ps;
			ps.set_unit(UnitPublicToPB.at(s.value.unit));
			ps.set_value(s.value.value);
			*ret.mutable_size() = ps;
		}
		return ret;
	}
	
	
	
	inline tgui_activity_configuration ConfigurationPBToPublic(const proto0::Configuration& c) {
		tgui_activity_configuration conf = {
				.dark_mode = c.darkmode(),
				.orientation = OrientationPBToPublic.at(c.orientation()),
				.keyboard_hidden = c.keyboardhidden(),
				.screen_width = c.screenwidth(),
				.screen_height = c.screenheight(),
				.font_scale = c.fontscale(),
				.density = c.density()
		};
		strncpy(conf.country, c.country().c_str(), sizeof(conf.country));
		strncpy(conf.language, c.language().c_str(), sizeof(conf.language));
		conf.country[sizeof(conf.country)-1] = '\0';
		conf.language[sizeof(conf.language)-1] = '\0';
		return conf;
	}
	
	
	
	
	
	
	
	
	
}


