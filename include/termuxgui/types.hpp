#pragma once

#include <stdint.h>

namespace tgui {
	
	/**
	 * @brief Specifies the orientation you can set an Activity to.
	 * 
	 */
	enum class Orientation{
		/// Lets the system choose the orientation.
		UNSPECIFIED = 0,
		/// The same orientation as the Activity behind in the Activity stack.
		BEHIND = 1,
		/// Orientation determined by the orientation sensor. All 4 orientations are possible.
		FULL_SENSOR = 2,
		/// Respect the users option to lock the rotation, but allow all 4 possible rotations if enabled.
		FULL_USER = 3,
		/// Lock the orientation to landscape. 
		LANDSCAPE = 4,
		/// Lock the orientation to the current one.
		LOCKED = 5,
		/// Ignore the orientation sensor.
		NOSENSOR = 6,
		/// Lock the orientation to portrait.
		PORTRAIT = 7,
		/// Lock the orientation to the opposite landscape mode.
		REVERSE_LANDSCAPE = 8,
		/// Lock the orientation to the opposite portrait mode.
		REVERSE_PORTRAIT = 9,
		/// Determine the orientation with the sensor.
		SENSOR = 10,
		/// Use landscape, but can be changed with the sensor.
		SENSOR_LANDSCAPE = 11,
		/// Use portrait, but can be changed with the sensor.
		SENSOR_PORTRAIT = 12,
		/// Use the users preferred orientation.
		USER = 13,
		/// Use landscape, but can be changed with the sensor if the user allowed it.
		USER_LANDSCAPE = 14,
		///Use portrait, but can be changed with the sensor if the user allowed it.
		USER_PORTRAIT = 15,
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
		/// The current Activity orientation. Only `LANDSCAPE`, `REVERSE_LANDSCAPE`, `PORTRAIT`, `REVERSE_PORTRAIT` and `UNSPECIFIED` are possible values.
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
	
	enum class Gravity {
		CENTER = 0,
		LEFT_TOP = 1,
		RIGHT_BOTTOM = 2,
	};
	
	
	enum class Direction {
		ALL = 0,
		TOP = 1,
		LEFT = 2,
		BOTTOM = 3,
		RIGHT = 4,
	};
	
	
	
	/// @brief Activity id type
	using AID = int32_t;
	
	using VID = int32_t;
	
	using RID = uint32_t;
	
	
	using Task = int32_t;
	
	
	using Color = uint32_t;
	
	
	
	struct Size {
		/**
		 * @brief All supported size units.
		 * 
		 * See <a href="https://developer.android.com/guide/topics/resources/more-resources.html#Dimension">the Android documentation</a> for more information.
		 * 
		 */
		enum class Unit {
			/// density-pixels unit
			DP = 0,
			/// scale-pixels unit
			SP = 1,
			/// pixels unit
			PX = 2,
			/// millimeters unit
			MM = 3,
			/// inches unit
			IN = 4,
			/// points unit
			PT = 5,
		};
		
		float value;
		Unit unit;
	};
	
	
	/**
	 * @brief All possible View visibility states.
	 */
	enum class Visibility {
		/// Completely visible.
		VISIBLE = 0,
		/// Invisible, but takes up it's space in the layout.
		HIDDEN = 1,
		/// Invisible and takes up no space in the layout.
		GONE = 3,
	};
	
	
	struct Point {
		float x;
		float y;
		Point(float x, float y) : x{x}, y{y} {}
	};
	
	
}