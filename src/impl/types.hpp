#pragma once

#include <unordered_map>
#include <algorithm>
#include "termuxgui/activity.hpp"
#include "termuxgui/types.hpp"


namespace tgui::impl {
	
	template<typename K, typename V> static constexpr inline std::unordered_map<V, K> invert(std::unordered_map<K, V> original) {
		std::unordered_map<V, K> m;
		for (const std::pair<K, V>& pair : original) {
			m.insert({pair.second, pair.first});
		}
		return m;
	}
	
	
	
	
	
	static inline const std::unordered_map<tgui::Activity::Type, tgui::proto0::NewActivityRequest::ActivityType> ActivityTypePublicToPB = {
		{tgui::Activity::Type::NORMAL, tgui::proto0::NewActivityRequest::normal},
		{tgui::Activity::Type::DIALOG, tgui::proto0::NewActivityRequest::dialog},
		{tgui::Activity::Type::DIALOG_CANCEL_OUTSIDE, tgui::proto0::NewActivityRequest::dialogCancelOutside},
		{tgui::Activity::Type::PIP, tgui::proto0::NewActivityRequest::pip},
		{tgui::Activity::Type::LOCKSCREEN, tgui::proto0::NewActivityRequest::lockscreen},
		{tgui::Activity::Type::OVERLAY, tgui::proto0::NewActivityRequest::overlay},
	};
	static inline const std::unordered_map<tgui::proto0::NewActivityRequest::ActivityType, tgui::Activity::Type> ActivityTypePBToPublic = invert(ActivityTypePublicToPB);
	
	
	static inline const std::unordered_map<tgui::Activity::InputMode, tgui::proto0::SetInputModeRequest::InputMode> InputModePublicToPB = {
		{tgui::Activity::InputMode::PAN, tgui::proto0::SetInputModeRequest::pan},
		{tgui::Activity::InputMode::RESIZE, tgui::proto0::SetInputModeRequest::resize},
	};
	static inline const std::unordered_map<tgui::proto0::SetInputModeRequest::InputMode, tgui::Activity::InputMode> InputModePBToPublic = invert(InputModePublicToPB);
	
	
	
	static inline const std::unordered_map<tgui::Orientation, tgui::proto0::Orientation> OrientationPublicToPB = {
		{tgui::Orientation::BEHIND, tgui::proto0::behind},
		{tgui::Orientation::FULL_SENSOR, tgui::proto0::fullSensor},
		{tgui::Orientation::FULL_USER, tgui::proto0::fullUser},
		{tgui::Orientation::LANDSCAPE, tgui::proto0::landscape},
		{tgui::Orientation::LOCKED, tgui::proto0::locked},
		{tgui::Orientation::NOSENSOR, tgui::proto0::nosensor},
		{tgui::Orientation::PORTRAIT, tgui::proto0::portrait},
		{tgui::Orientation::REVERSE_LANDSCAPE, tgui::proto0::reverseLandscape},
		{tgui::Orientation::REVERSE_PORTRAIT, tgui::proto0::reversePortrait},
		{tgui::Orientation::SENSOR, tgui::proto0::sensor},
		{tgui::Orientation::SENSOR_LANDSCAPE, tgui::proto0::sensorLandscape},
		{tgui::Orientation::SENSOR_PORTRAIT, tgui::proto0::sensorPortrait},
		{tgui::Orientation::USER, tgui::proto0::user},
		{tgui::Orientation::USER_LANDSCAPE, tgui::proto0::userLandscape},
		{tgui::Orientation::USER_PORTRAIT, tgui::proto0::userPortrait},
	};
	static inline const std::unordered_map<tgui::proto0::Orientation, tgui::Orientation> OrientationPBToPublic = invert(OrientationPublicToPB);
	
	
	
	
	
	
	
	
	tgui::Configuration ConfigurationPBToPublic(const proto0::Configuration& c) {
		return {
				.dark_mode = c.darkmode(),
				.country = { c.country().at(0), c.country().at(1), '\0' },
				.language = { c.language().at(0), c.language().at(1), '\0' },
				.orientation = impl::OrientationPBToPublic.at(c.orientation()),
				.keyboardHidden = c.keyboardhidden(),
				.screenWidth = c.screenwidth(),
				.screenHeight = c.screenheight(),
				.fontScale = c.fontscale(),
				.density = c.density()
		};
	}
	
}
