#pragma once

#include <variant>
#include <memory>

#include <stdint.h>

#include "types.hpp"

namespace tgui {
	
	/**
	 * @brief Event types are encapsulated here to not make the main namespace too full.
	 * 
	 */
	namespace Events {
		struct Create {
			/// @brief The id of the created Activity.
			AID a;
		};
		struct Start {
			/// @brief The id of the started Activity.
			AID a;
		};
		struct Resume {
			/// @brief The id of the resumed Activity.
			AID a;
		};
		struct Pause {
			/// @brief The id of the paused Activity.
			AID a;
			/// @brief Whether the Activity is finishing. Only accurate for Destroy.
			bool finishing;
		};
		struct Stop {
			/// @brief The id of the stopped Activity.
			AID a;
			/// @brief Whether the Activity is finishing. Only accurate for Destroy.
			bool finishing;
		};
		struct Destroy {
			/// @brief The id of the destroyed Activity.
			AID a;
			/// @brief Whether the Activity is finishing. Only accurate for Destroy.
			bool finishing;
		};
		struct Config {
			
			
		};
		struct Click {
			
			
		};
		struct LongClick {
			
			
		};
		struct Focus {
			
			
		};
		struct Touch {
			
			
		};
		struct Text {
			
			
		};
		struct Refresh {
			
			
		};
		struct Selected {
			
			
		};
		struct ItemSelected {
			
			
		};
		struct Back {
			
			
		};
		struct WebViewNavigation {
			
			
		};
		struct WebViewHTTPError {
			
			
		};
		struct WebViewError {
			
			
		};
		struct WebViewDestroyed {
			
			
		};
		struct WebViewProgress {
			
			
		};
		struct WebViewConsole {
			
			
		};
		struct AirplaneMode {
			
			
		};
		struct Locale {
			
			
		};
		struct Timezone {
			
			
		};
		struct ScreenOff {
			
			
		};
		struct ScreenOn {
			
			
		};
		struct UserLeaveHint {
			
			
		};
		struct PiP {
			
			
		};
		struct RemoteClick {
			
			
		};
		struct Notification {
			
			
		};
		struct NotificationDismissed {
			
			
		};
		struct NotificationAction {
			
			
		};
		struct OverlayScale {
			
			
		};
		struct Key {
			/**
			 * @brief All supported key modifiers.
			 */
			enum Modifier {
				MOD_NONE = 0,
				MOD_LSHIFT = 1,
				MOD_RSHIFT = 2,
				MOD_LCTRL = 4,
				MOD_RCTRL = 8,
				MOD_ALT = 16,
				MOD_FN = 32,
				MOD_CAPS_LOCK = 64,
				MOD_ALT_GR = 128,
				MOD_NUM_LOCK = 256,
			};
			
		};
		struct DebugException {
			
			
		};
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	using Event = std::variant<std::monostate,
	Events::Create,
	Events::Start,
	Events::Resume,
	Events::Pause,
	Events::Stop,
	Events::Destroy,
	Events::Config,
	Events::Click,
	Events::LongClick,
	Events::Focus,
	Events::Touch,
	Events::Text,
	Events::Refresh,
	Events::Selected,
	Events::ItemSelected,
	Events::Back,
	Events::WebViewNavigation,
	Events::WebViewHTTPError,
	Events::WebViewError,
	Events::WebViewDestroyed,
	Events::WebViewProgress,
	Events::WebViewConsole,
	Events::AirplaneMode,
	Events::Locale,
	Events::Timezone,
	Events::ScreenOff,
	Events::ScreenOn,
	Events::UserLeaveHint,
	Events::PiP,
	Events::RemoteClick,
	Events::Notification,
	Events::NotificationDismissed,
	Events::NotificationAction,
	Events::OverlayScale,
	Events::Key,
	Events::DebugException>;
	
}
