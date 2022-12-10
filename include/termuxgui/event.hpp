#pragma once

#include <variant>
#include <memory>
#include <vector>
#include <string>

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
			/// @brief The id of the Activity.
			AID a;
			Configuration config;
		};
		struct Click {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			/// @brief Whether the View is checked, for CheckBox, RadioButton and Switch
			bool set;
		};
		struct LongClick {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
		};
		struct Focus {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			/// @brief Whether the View now has focus.
			bool focus;
		};
		struct Touch {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			enum class Action {
				DOWN = 0,
				UP = 1,
				POINTER_DOWN = 2,
				POINTER_UP = 3,
				CANCEL = 4,
				MOVE = 5,
			};
			Action action;
			struct Pointer {
				int x;
				int y;
				int id;
			};
			std::vector<std::vector<Pointer>> events;
		};
		struct Text {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			std::string text;
		};
		struct Refresh {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
		};
		struct Selected {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			int selected;
		};
		struct ItemSelected {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			int selected;
		};
		struct Back {
			/// @brief The id of the Activity.
			AID a;
		};
		struct WebViewNavigation {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			std::string url;
		};
		struct WebViewHTTPError {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			std::string url;
			
			int code;
		};
		struct WebViewError {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			std::string url;
		};
		struct WebViewDestroyed {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
		};
		struct WebViewProgress {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			unsigned int progress;
		};
		struct WebViewConsole {
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			std::string msg;
		};
		struct AirplaneMode {
			bool active;
		};
		struct Locale {
			std::string locale;
		};
		struct Timezone {
			std::string tz;
		};
		struct ScreenOff {
			
			
		};
		struct ScreenOn {
			
			
		};
		struct UserLeaveHint {
			/// @brief The id of the Activity.
			AID a;
			
		};
		struct PiP {
			/// @brief The id of the Activity.
			AID a;
			
			bool pip;
		};
		struct RemoteClick {
			RID rid;
			unsigned int id;
			
		};
		struct Notification {
			unsigned int id;
			
		};
		struct NotificationDismissed {
			unsigned int id;
			
		};
		struct NotificationAction {
			unsigned int id;
			unsigned int action;
		};
		struct OverlayScale {
			/// @brief The id of the Activity.
			AID a;
			
			float span;
		};
		struct Key {
			/**
			 * @brief All supported key modifiers.
			 */
			enum Modifier : unsigned int {
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
			/// @brief The id of the Activity the View is in.
			AID a;
			/// @brief The id of the View
			VID v;
			
			uint32_t code;
			Modifier mod;
			uint32_t codePoint;
		};
		struct DebugException {
			std::string stacktrace;
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
