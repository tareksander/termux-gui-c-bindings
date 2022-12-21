#pragma once

#include <memory>
#include <string>
#include <stdint.h>

#include "connection.hpp"
#include "types.hpp"

namespace tgui {
	
	namespace impl {
		class Activity;
	}
	
	
	
	/**
	 * @brief Represents an Android Activity.
	 * 
	 */
	class Activity final {
		public:
		
		enum class Type : uint8_t {
			normal = 0,
			dialog = 1,
			dialogCancelOutside = 2,
			pip = 3,
			lockscreen = 4,
			overlay = 5,
		};
		
		enum class InputMode : uint8_t {
			pan = 0,
    		resize = 1,
		};
		
		
		
		Activity(Connection& c, Type type = Type::normal, bool interceptBackButton = false, Task task = -1);
		virtual ~Activity();
		
		
		/**
		 * @brief Finishes the Activity.
		 */
		void finish();
		
		
		/**
		 * @brief Gets the configuration of the Activity.
		 * 
		 * @return The configuration.
		 */
		Configuration getConfiguration() const;
		
		
		/**
		 * @brief Hides the software keyboard.
		 * 
		 */
		void hideSoftKeyboard();
		
		
		/**
		 * @brief Sets whether the back button is allowed to finish the Activity or if an event should be send instead.
		 * 
		 * @param intercept Set to true if you want to intercept back button presses and get events instead for this Activity.
		 */
		void interceptBackButton(bool intercept);
		
		/**
		 * @brief Sets whether the screen should be kept on while this Activity is shown.
		 * 
		 * @param on Whether to keep the screen on.
		 */
		void keepScreenOn(bool on);
		
		
		/**
		 * @brief Hides this Activity.
		 */
		void moveToBack();
		
		
		/**
		 * @brief Request to unlock the screen from this Activity.
		 */
		void requestUnlock();
		
		
		/**
		 * @brief Sets whether to send overlay events for the Activity if it's an overlay.
		 * 
		 * @param send True if you want overlay events.
		 */
		void sendOverlayEvents(bool send);
		
		
		
		void setInputMode(InputMode m);
		
		
		
		
		void setOrientation(Orientation o);
		
		
		
		
		void setPiPMode(bool pip);
		
		
		
		
		void setPiPModeAuto(bool pipAuto);
		
		
		
		
		void setPiPParams(int numerator, int denominator);
		
		
		
		
		void setPosition(int x, int y);
		
		
		
		
		void setTaskDescription(std::string label, const void* img, size_t imgSize);
		
		
		
		void setTheme(Color primaryColor, Color accentColor, Color windowBackground, Color statusBarColor, Color textColor);
		
		
		
		Task getTask();
		
		
		Aid getID();
		
		
		private:
		
		const std::shared_ptr<impl::Activity> a;
		Activity() = delete;
		
		
		friend class TextView;
	};
	
	
	
	
	
	
}


