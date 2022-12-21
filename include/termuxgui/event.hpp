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
			Aid a;
		};
		struct Start {
			/// @brief The id of the started Activity.
			Aid a;
		};
		struct Resume {
			/// @brief The id of the resumed Activity.
			Aid a;
		};
		struct Pause {
			/// @brief The id of the paused Activity.
			Aid a;
			/// @brief Whether the Activity is finishing. Only accurate for Destroy.
			bool finishing;
		};
		struct Stop {
			/// @brief The id of the stopped Activity.
			Aid a;
			/// @brief Whether the Activity is finishing. Only accurate for Destroy.
			bool finishing;
		};
		struct Destroy {
			/// @brief The id of the destroyed Activity.
			Aid a;
			/// @brief Whether the Activity is finishing. Only accurate for Destroy.
			bool finishing;
		};
		struct Config {
			/// @brief The id of the Activity.
			Aid a;
			Configuration config;
		};
		struct Click {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			/// @brief Whether the View is checked, for CheckBox, RadioButton and Switch
			bool set;
		};
		struct LongClick {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
		};
		struct Focus {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			/// @brief Whether the View now has focus.
			bool focus;
		};
		struct Touch {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			enum class Action : uint8_t {
				down = 0,
				up = 1,
				pointerDown = 2,
				pointerUp = 3,
				cancel = 4,
				move = 5,
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
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			std::string text;
		};
		struct Refresh {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
		};
		struct Selected {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			int selected;
		};
		struct ItemSelected {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			int selected;
		};
		struct Back {
			/// @brief The id of the Activity.
			Aid a;
		};
		struct WebViewNavigation {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			std::string url;
		};
		struct WebViewHTTPError {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			std::string url;
			
			int code;
		};
		struct WebViewError {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			std::string url;
		};
		struct WebViewDestroyed {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
		};
		struct WebViewProgress {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			unsigned int progress;
		};
		struct WebViewConsole {
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
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
			Aid a;
			
		};
		struct PiP {
			/// @brief The id of the Activity.
			Aid a;
			
			bool pip;
		};
		struct RemoteClick {
			Rid rid;
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
			Aid a;
			
			float span;
		};
		struct Key {
			/**
			 * @brief All supported key modifiers.
			 */
			enum class Modifier : uint32_t {
				none = 0,
				lShift = 1,
				rShift = 2,
				lCtrl = 4,
				rCtrl = 8,
				alt = 16,
				fn = 32,
				capsLock = 64,
				altGr = 128,
				numLock = 256,
			};
			/// @brief The id of the Activity the View is in.
			Aid a;
			/// @brief The id of the View
			Vid v;
			
			uint32_t code;
			Modifier mod;
			uint32_t codePoint;
		};
		struct DebugException {
			std::string stacktrace;
		};
		
		
		
		
		
		
		
		
		
		
		
		
		inline Key::Modifier operator|(Key::Modifier lhs, Key::Modifier rhs) {
			return static_cast<Key::Modifier>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
		}
		inline Key::Modifier operator&(Key::Modifier lhs, Key::Modifier rhs) {
			return static_cast<Key::Modifier>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
		}
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
