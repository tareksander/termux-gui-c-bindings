#pragma once

#include <unordered_map>
#include <algorithm>
#include <utility>
#include <type_traits>
#include "termuxgui/activity.hpp"
#include "termuxgui/types.hpp"

namespace tgui::impl {
	
	template<typename K, typename V> constexpr inline std::unordered_map<V, K> invert(std::unordered_map<K, V> original) {
		std::unordered_map<V, K> m;
		for (const std::pair<K, V>& pair : original) {
			m.insert({pair.second, pair.first});
		}
		return m;
	}
	
	
	
	
	
	inline const std::unordered_map<tgui::Activity::Type, tgui::proto0::NewActivityRequest::ActivityType> ActivityTypePublicToPB = {
		{tgui::Activity::Type::normal, tgui::proto0::NewActivityRequest::normal},
		{tgui::Activity::Type::dialog, tgui::proto0::NewActivityRequest::dialog},
		{tgui::Activity::Type::dialogCancelOutside, tgui::proto0::NewActivityRequest::dialogCancelOutside},
		{tgui::Activity::Type::pip, tgui::proto0::NewActivityRequest::pip},
		{tgui::Activity::Type::lockscreen, tgui::proto0::NewActivityRequest::lockscreen},
		{tgui::Activity::Type::overlay, tgui::proto0::NewActivityRequest::overlay},
	};
	inline const std::unordered_map<tgui::proto0::NewActivityRequest::ActivityType, tgui::Activity::Type> ActivityTypePBToPublic = invert(ActivityTypePublicToPB);
	
	
	inline const std::unordered_map<tgui::Activity::InputMode, tgui::proto0::SetInputModeRequest::InputMode> InputModePublicToPB = {
		{tgui::Activity::InputMode::pan, tgui::proto0::SetInputModeRequest::pan},
		{tgui::Activity::InputMode::resize, tgui::proto0::SetInputModeRequest::resize},
	};
	inline const std::unordered_map<tgui::proto0::SetInputModeRequest::InputMode, tgui::Activity::InputMode> InputModePBToPublic = invert(InputModePublicToPB);
	
	
	
	inline const std::unordered_map<tgui::Orientation, tgui::proto0::Orientation> OrientationPublicToPB = {
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
	inline const std::unordered_map<tgui::proto0::Orientation, tgui::Orientation> OrientationPBToPublic = invert(OrientationPublicToPB);
	
	inline const std::unordered_map<tgui::Gravity, tgui::proto0::SetGravityRequest::Gravity> GravityPublicToPB = {
		{tgui::Gravity::center, tgui::proto0::SetGravityRequest::CENTER},
		{tgui::Gravity::leftTop, tgui::proto0::SetGravityRequest::LEFTTOP},
		{tgui::Gravity::rightBottom, tgui::proto0::SetGravityRequest::RIGHTBOTTOM},
	};
	inline const std::unordered_map<tgui::proto0::SetGravityRequest::Gravity, tgui::Gravity> GravityPBToPublic = invert(GravityPublicToPB);
	
	
	inline const std::unordered_map<tgui::Direction, tgui::proto0::Direction> DirectionPublicToPB = {
		{tgui::Direction::all, tgui::proto0::ALL},
		{tgui::Direction::top, tgui::proto0::TOP},
		{tgui::Direction::left, tgui::proto0::LEFT},
		{tgui::Direction::bottom, tgui::proto0::BOTTOM},
		{tgui::Direction::right, tgui::proto0::RIGHT},
		
	};
	inline const std::unordered_map<tgui::proto0::Direction, tgui::Direction> DirectionPBToPublic = invert(DirectionPublicToPB);
	
	
	
	inline const std::unordered_map<tgui::Visibility, tgui::proto0::Visibility> VisibilityPublicToPB = {
		{tgui::Visibility::visible, tgui::proto0::visible},
		{tgui::Visibility::hidden, tgui::proto0::hidden},
		{tgui::Visibility::gone, tgui::proto0::gone},
	};
	inline const std::unordered_map<tgui::proto0::Visibility, tgui::Visibility> VisibilityPBToPublic = invert(VisibilityPublicToPB);
	
	
	inline const std::unordered_map<tgui::LockState, tgui::proto0::IsLockedResponse::Locked> LockStatePublicToPB = {
		{tgui::LockState::unknown, tgui::proto0::IsLockedResponse::UNKNOWN},
		{tgui::LockState::locked, tgui::proto0::IsLockedResponse::LOCKED},
		{tgui::LockState::unlocked, tgui::proto0::IsLockedResponse::UNLOCKED},
	};
	inline const std::unordered_map<tgui::proto0::IsLockedResponse::Locked, tgui::LockState> LockStatePBToPublic = invert(LockStatePublicToPB);
	
	
	inline const std::unordered_map<tgui::Size::Unit, tgui::proto0::Size::Unit> UnitPublicToPB = {
		{tgui::Size::Unit::dp, tgui::proto0::Size::dp},
		{tgui::Size::Unit::sp, tgui::proto0::Size::sp},
		{tgui::Size::Unit::px, tgui::proto0::Size::px},
		{tgui::Size::Unit::mm, tgui::proto0::Size::mm},
		{tgui::Size::Unit::in, tgui::proto0::Size::in},
		{tgui::Size::Unit::pt, tgui::proto0::Size::pt},
	};
	inline const std::unordered_map<tgui::proto0::Size::Unit, tgui::Size::Unit> UnitPBToPublic = invert(UnitPublicToPB);
	
	
	inline const std::unordered_map<tgui::ViewSizeConstant, tgui::proto0::ViewSize::Constant> ViewSizeConstantPublicToPB = {
		{tgui::ViewSizeConstant::matchParent, tgui::proto0::ViewSize::MATCH_PARENT},
		{tgui::ViewSizeConstant::wrapContent, tgui::proto0::ViewSize::WRAP_CONTENT},
	};
	inline const std::unordered_map<tgui::proto0::ViewSize::Constant, tgui::ViewSizeConstant> ViewSizeConstantPBToPublic = invert(ViewSizeConstantPublicToPB);
	
	
	
	
	
	
	
	inline tgui::Size SizePBToPublic(proto0::Size s) {
		return {
			.value = s.value(),
			.unit = UnitPBToPublic.at(s.unit())
		};
	}
	
	inline proto0::Size SizePublicToPB(tgui::Size s) {
		proto0::Size ret;
		ret.set_value(s.value);
		ret.set_unit(UnitPublicToPB.at(s.unit));
		return ret;
	}
	
	inline tgui::ViewSize ViewSizePBToPublic(proto0::ViewSize s) {
		switch (s.value_case()) {
			case proto0::ViewSize::kConstant:
				return ViewSizeConstantPBToPublic.at(s.constant());
			case proto0::ViewSize::kSize:
				return SizePBToPublic(s.size());
			default:
				throw MethodError();
		}
	}
	
	template<class> inline constexpr bool always_false_v = false;
	
	inline proto0::ViewSize ViewSizePublicToPB(tgui::ViewSize s) {
		proto0::ViewSize ret;
		std::visit([&] (auto&& arg) {
			using T = std::decay_t<decltype(arg)>;
			if constexpr (std::is_same_v<T, ViewSizeConstant>) {
				ret.set_constant(ViewSizeConstantPublicToPB.at(arg));
			} else if constexpr (std::is_same_v<T, Size>) {
				*ret.mutable_size() = SizePublicToPB(arg);
			} else {
				static_assert(always_false_v<T>, "non-exhaustive visitor!");
			}
		}, s);
		return ret;
	}
	
	
	inline tgui::Configuration ConfigurationPBToPublic(const proto0::Configuration& c) {
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
