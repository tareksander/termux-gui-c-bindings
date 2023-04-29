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
	
	
	inline const std::unordered_map<tgui_edit_text_type, tgui::proto0::CreateEditTextRequest::Type> EditTextTypePublicToPB = {
		{TGUI_EDIT_TEXT_TEXT, tgui::proto0::CreateEditTextRequest::text},
		{TGUI_EDIT_TEXT_TEXT_MULTILINE, tgui::proto0::CreateEditTextRequest::textMultiLine},
		{TGUI_EDIT_TEXT_PHONE, tgui::proto0::CreateEditTextRequest::phone},
		{TGUI_EDIT_TEXT_DATE, tgui::proto0::CreateEditTextRequest::date},
		{TGUI_EDIT_TEXT_TIME, tgui::proto0::CreateEditTextRequest::time},
		{TGUI_EDIT_TEXT_DATETIME, tgui::proto0::CreateEditTextRequest::datetime},
		{TGUI_EDIT_TEXT_NUMBER, tgui::proto0::CreateEditTextRequest::number},
		{TGUI_EDIT_TEXT_NUMBER_DECIMAL, tgui::proto0::CreateEditTextRequest::numberDecimal},
		{TGUI_EDIT_TEXT_NUMBER_PASSWORD, tgui::proto0::CreateEditTextRequest::numberPassword},
		{TGUI_EDIT_TEXT_NUMBER_SIGNED, tgui::proto0::CreateEditTextRequest::numberSigned},
		{TGUI_EDIT_TEXT_NUMBER_DECIMAL_SIGNED, tgui::proto0::CreateEditTextRequest::numberDecimalSigned},
		{TGUI_EDIT_TEXT_TEXT_EMAIL_ADDRESS, tgui::proto0::CreateEditTextRequest::textEmailAddress},
		{TGUI_EDIT_TEXT_TEXT_PASSWORD, tgui::proto0::CreateEditTextRequest::textPassword},
	};
	
	
	inline const std::unordered_map<tgui_grid_alignment, tgui::proto0::SetGridLayoutParamsRequest::Alignment> GridAlignmentPublicToPB = {
		{TGUI_GRID_CENTER, tgui::proto0::SetGridLayoutParamsRequest::CENTER},
		{TGUI_GRID_TOP, tgui::proto0::SetGridLayoutParamsRequest::TOP},
		{TGUI_GRID_BOTTOM, tgui::proto0::SetGridLayoutParamsRequest::BOTTOM},
		{TGUI_GRID_LEFT, tgui::proto0::SetGridLayoutParamsRequest::LEFT},
		{TGUI_GRID_RIGHT, tgui::proto0::SetGridLayoutParamsRequest::RIGHT},
		{TGUI_GRID_BASELINE, tgui::proto0::SetGridLayoutParamsRequest::BASELINE},
		{TGUI_GRID_FILL, tgui::proto0::SetGridLayoutParamsRequest::FILL},
	};
	
	
	inline const std::unordered_map<tgui_inset, tgui::proto0::ConfigureInsetsRequest::Bars> BarsPublicToPB = {
		{TGUI_INSET_NONE, tgui::proto0::ConfigureInsetsRequest::NO_BAR},
		{TGUI_INSET_NAVIGATION_BAR, tgui::proto0::ConfigureInsetsRequest::NAVIGATION_BAR},
		{TGUI_INSET_STATUS_BAR, tgui::proto0::ConfigureInsetsRequest::STATUS_BAR},
		{TGUI_INSET_BOTH, tgui::proto0::ConfigureInsetsRequest::BOTH_BARS},
	};
	inline const std::unordered_map<tgui::proto0::ConfigureInsetsRequest::Bars, tgui_inset> BarsPBToPublic = invert(BarsPublicToPB);
	
	inline const std::unordered_map<tgui_inset_behaviour, tgui::proto0::ConfigureInsetsRequest::BarBehaviour> BarBehaviourPublicToPB = {
		{TGUI_INSET_BEHAVIOUR_DEFAULT, tgui::proto0::ConfigureInsetsRequest::BAR_BEHAVIOUR_DEFAULT},
		{TGUI_INSET_BEHAVIOUR_TRANSIENT, tgui::proto0::ConfigureInsetsRequest::BAR_BEHAVIOUR_TRANSIENT},
	};
	
	
	
	inline const std::unordered_map<tgui_hardware_buffer_format, tgui::proto0::CreateHardwareBufferRequest::Format> HardwareBufferFormatPublicToPB = {
		{TGUI_HARDWARE_BUFFER_FORMAT_RGBA8888, tgui::proto0::CreateHardwareBufferRequest::RGBA8888},
		{TGUI_HARDWARE_BUFFER_FORMAT_RGBX8888, tgui::proto0::CreateHardwareBufferRequest::RGBX8888},
		{TGUI_HARDWARE_BUFFER_FORMAT_RGB888, tgui::proto0::CreateHardwareBufferRequest::RGB888},
		{TGUI_HARDWARE_BUFFER_FORMAT_RGB565, tgui::proto0::CreateHardwareBufferRequest::RGB565},
	};
	
	inline const std::unordered_map<tgui_hardware_buffer_cpu_frequency, tgui::proto0::CreateHardwareBufferRequest::CPUUsage> HardwareBufferCPUPublicToPB = {
		{TGUI_HARDWARE_BUFFER_CPU_NEVER, tgui::proto0::CreateHardwareBufferRequest::never},
		{TGUI_HARDWARE_BUFFER_CPU_RARELY, tgui::proto0::CreateHardwareBufferRequest::rarely},
		{TGUI_HARDWARE_BUFFER_CPU_OFTEN, tgui::proto0::CreateHardwareBufferRequest::often},
	};
	
	
	inline const std::unordered_map<tgui_surface_view_dimension_mismatch, tgui::proto0::SurfaceViewConfigRequest::OnDimensionMismatch> DimensionMismatchPublicToPB = {
		{TGUI_MISMATCH_STICK_TOPLEFT, tgui::proto0::SurfaceViewConfigRequest::STICK_TOPLEFT},
		{TGUI_MISMATCH_CENTER_AXIS, tgui::proto0::SurfaceViewConfigRequest::CENTER_AXIS}
	};
	
	
	inline proto0::Size SizePublicToPB(const tgui_size& s) {
		proto0::Size ps;
		ps.set_unit(UnitPublicToPB.at(s.unit));
		ps.set_value(s.value);
		return ps;
	}
	
	inline proto0::ViewSize ViewSizePublicToPB(const tgui_view_size& s) {
		proto0::ViewSize ret;
		if (s.type == TGUI_VIEW_MATCH_PARENT) {
			ret.set_constant(proto0::ViewSize::MATCH_PARENT);
		} else if (s.type == TGUI_VIEW_WRAP_CONTENT) {
			ret.set_constant(proto0::ViewSize::WRAP_CONTENT);
		} else {
			*ret.mutable_size() = SizePublicToPB(s.value);
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


