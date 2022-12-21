#pragma once

#include <stdint.h>
#include <variant>


namespace tgui {
	
	/**
	 * @brief Specifies the orientation you can set an Activity to.
	 * 
	 */
	enum class Orientation : uint8_t {
		/// Lets the system choose the orientation.
		unspecified = 0,
		/// The same orientation as the Activity behind in the Activity stack.
		behind = 1,
		/// Orientation determined by the orientation sensor. All 4 orientations are possible.
		fullSensor = 2,
		/// Respect the users option to lock the rotation, but allow all 4 possible rotations if enabled.
		fullUser = 3,
		/// Lock the orientation to landscape. 
		landscape = 4,
		/// Lock the orientation to the current one.
		locked = 5,
		/// Ignore the orientation sensor.
		noSensor = 6,
		/// Lock the orientation to portrait.
		portrait = 7,
		/// Lock the orientation to the opposite landscape mode.
		reverseLandscape = 8,
		/// Lock the orientation to the opposite portrait mode.
		reversePortrait = 9,
		/// Determine the orientation with the sensor.
		sensor = 10,
		/// Use landscape, but can be changed with the sensor.
		sensorLandscape = 11,
		/// Use portrait, but can be changed with the sensor.
		sensorPortrait = 12,
		/// Use the users preferred orientation.
		user = 13,
		/// Use landscape, but can be changed with the sensor if the user allowed it.
		userLandscape = 14,
		///Use portrait, but can be changed with the sensor if the user allowed it.
		userPortrait = 15,
	};
	
	
	/**
	 * @brief Provides information on the current device and Activity configuration.
	 */
	struct Configuration {
		/// Whether dark mode is enabled. Always false on Android < 10.
		bool dark_mode;
		/// The 2 letter country code. A NULL terminator is included for convenience.
		char country[3];
		/// The 2 letter language code. A NULL terminator is included for convenience.
		char language[3];
		/// The current Activity orientation. Only `landscape`, `reverseLandscape`, `portrait`, `reversePortrait` and `unspecified` are possible values.
		Orientation orientation;
		/// Whether the soft keyboard is currently shown.
		bool keyboardHidden;
		/// The current Activity width in dp.
		int screenWidth;
		/// The current Activity height in dp.
		int screenHeight;
		/// The current font scale.
		double fontScale;
		/// The display density, such that screenwidth * density = screenwidth_in_px.
		double density;
	};
	
	enum class Gravity : uint8_t {
		center = 0,
		leftTop = 1,
		rightBottom = 2,
	};
	
	
	enum class Direction : uint8_t {
		all = 0,
		top = 1,
		left = 2,
		bottom = 3,
		right = 4,
	};
	
	enum class Importance : uint8_t {
		normal = 0,
		min = 1,
		low = 2,
		high = 3,
		max = 4,
	};
	
	enum class LockState : uint8_t {
		unknown = 0,
		locked = 1,
		unlocked = 2,
	};
	
	
	
	/// @brief Activity id type
	using Aid = int32_t;
	
	using Vid = int32_t;
	
	using Rid = uint32_t;
	
	
	using Task = int32_t;
	
	
	using Color = uint32_t;
	
	enum class ViewSizeConstant {
		matchParent = 0,
		wrapContent = 1,
	};
	
	
	
	struct Size {
		/**
		 * @brief All supported size units.
		 * 
		 * See <a href="https://developer.android.com/guide/topics/resources/more-resources.html#Dimension">the Android documentation</a> for more information.
		 * 
		 */
		enum class Unit : uint8_t {
			/// density-pixels unit
			dp = 0,
			/// scale-pixels unit
			sp = 1,
			/// pixels unit
			px = 2,
			/// millimeters unit
			mm = 3,
			/// inches unit
			in = 4,
			/// points unit
			pt = 5,
		};
		
		float value;
		Unit unit;
	};
	
	
	using ViewSize = std::variant<Size, ViewSizeConstant>;
	
	/**
	 * @brief All possible View visibility states.
	 */
	enum class Visibility : uint8_t {
		/// Completely visible.
		visible = 0,
		/// Invisible, but takes up it's space in the layout.
		hidden = 1,
		/// Invisible and takes up no space in the layout.
		gone = 3,
	};
	
	
	struct Point {
		float x;
		float y;
		Point(float x, float y) : x{x}, y{y} {}
	};
	
	
}