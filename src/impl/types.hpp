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
		{tgui::Activity::Type::normal, tgui::proto0::NewActivityRequest::normal},
		{tgui::Activity::Type::dialog, tgui::proto0::NewActivityRequest::dialog},
		{tgui::Activity::Type::dialogCancelOutside, tgui::proto0::NewActivityRequest::dialogCancelOutside},
		{tgui::Activity::Type::pip, tgui::proto0::NewActivityRequest::pip},
		{tgui::Activity::Type::lockscreen, tgui::proto0::NewActivityRequest::lockscreen},
		{tgui::Activity::Type::overlay, tgui::proto0::NewActivityRequest::overlay},
	};
	static inline const std::unordered_map<tgui::proto0::NewActivityRequest::ActivityType, tgui::Activity::Type> ActivityTypePBToPublic = invert(ActivityTypePublicToPB);
	
	
	static inline const std::unordered_map<tgui::Activity::InputMode, tgui::proto0::SetInputModeRequest::InputMode> InputModePublicToPB = {
		{tgui::Activity::InputMode::pan, tgui::proto0::SetInputModeRequest::pan},
		{tgui::Activity::InputMode::resize, tgui::proto0::SetInputModeRequest::resize},
	};
	static inline const std::unordered_map<tgui::proto0::SetInputModeRequest::InputMode, tgui::Activity::InputMode> InputModePBToPublic = invert(InputModePublicToPB);
	
	
	
	static inline const std::unordered_map<tgui::Orientation, tgui::proto0::Orientation> OrientationPublicToPB = {
		{tgui::Orientation::unspecified, tgui::proto0::unspecified},
		{tgui::Orientation::behind, tgui::proto0::behind},
		{tgui::Orientation::fullSensor, tgui::proto0::fullSensor},
		{tgui::Orientation::fullUser, tgui::proto0::fullUser},
		{tgui::Orientation::landscape, tgui::proto0::landscape},
		{tgui::Orientation::locked, tgui::proto0::locked},
		{tgui::Orientation::noSensor, tgui::proto0::nosensor},
		{tgui::Orientation::portrait, tgui::proto0::portrait},
		{tgui::Orientation::reverseLandscape, tgui::proto0::reverseLandscape},
		{tgui::Orientation::reversePortrait, tgui::proto0::reversePortrait},
		{tgui::Orientation::sensor, tgui::proto0::sensor},
		{tgui::Orientation::sensorLandscape, tgui::proto0::sensorLandscape},
		{tgui::Orientation::sensorPortrait, tgui::proto0::sensorPortrait},
		{tgui::Orientation::user, tgui::proto0::user},
		{tgui::Orientation::userLandscape, tgui::proto0::userLandscape},
		{tgui::Orientation::userPortrait, tgui::proto0::userPortrait},
	};
	static inline const std::unordered_map<tgui::proto0::Orientation, tgui::Orientation> OrientationPBToPublic = invert(OrientationPublicToPB);
	
	static inline const std::unordered_map<tgui::Gravity, tgui::proto0::SetGravityRequest::Gravity> GravityPublicToPB = {
		{tgui::Gravity::center, tgui::proto0::SetGravityRequest::CENTER},
		{tgui::Gravity::leftTop, tgui::proto0::SetGravityRequest::LEFTTOP},
		{tgui::Gravity::rightBottom, tgui::proto0::SetGravityRequest::RIGHTBOTTOM},
	};
	static inline const std::unordered_map<tgui::proto0::SetGravityRequest::Gravity, tgui::Gravity> GravityPBToPublic = invert(GravityPublicToPB);
	
	
	static inline const std::unordered_map<tgui::Direction, tgui::proto0::Direction> DirectionPublicToPB = {
		{tgui::Direction::all, tgui::proto0::ALL},
		{tgui::Direction::top, tgui::proto0::TOP},
		{tgui::Direction::left, tgui::proto0::LEFT},
		{tgui::Direction::bottom, tgui::proto0::BOTTOM},
		{tgui::Direction::right, tgui::proto0::RIGHT},
		
	};
	static inline const std::unordered_map<tgui::proto0::Direction, tgui::Direction> DirectionPBToPublic = invert(DirectionPublicToPB);
	
	
	
	
	
	static inline tgui::Configuration ConfigurationPBToPublic(const proto0::Configuration& c) {
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
