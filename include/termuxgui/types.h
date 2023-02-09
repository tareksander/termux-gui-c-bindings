#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif





struct tgui_connection_;

/**
 * @brief Represents a connection to the Termux:GUI plugin.
 */
typedef struct tgui_connection_* tgui_connection;



/**
 * @brief Represents an Android Activity.
 */
typedef int32_t tgui_activity;



/**
 * @brief Represents an Android Task.
 */
typedef int32_t tgui_task;



/**
 * @brief Represents an Android View.
 */
typedef int32_t tgui_view;


/**
 * @brief An RGBA8888 color code.
 * 
 * RR is the least significant byte. In a hex literal, write `0xaabbggrr`.
 */
typedef uint32_t tgui_color;





/**
 * @brief Status codes for all functions in the library.
 */
typedef enum {
	/// Operation was successful.
	TGUI_ERR_OK = 0,
	/// An error occurred in the system library. Check `errno` to get the exact error.
	TGUI_ERR_SYSTEM = 1,
	/// The connection to the plugin was lost. All further operations on this connection except destroy operations will fail with this error.
	TGUI_ERR_CONNECTION_LOST = 2,
	/// The Activity the function tried to act on no longer exists.
	TGUI_ERR_ACTIVITY_DESTROYED = 3,
	/// A protocol buffer message could not be read or written.<br>
	/// This is usually an error on the plugin side and should be treated as fatal, and the connection should be closed.
	TGUI_ERR_MESSAGE = 4,
	/// There is not enough memory to complete an operation.
	TGUI_ERR_NOMEM = 5,
	/// An exception was thrown in the C++ part that could not be mapped to other errors.
	TGUI_ERR_EXCEPTION = 6,
	/// The View used was invalid or of a wrong type.
	TGUI_ERR_VIEW_INVALID = 3,
	
	/// Maximum value for future binary compatibility.
	TGUI_ERR_MAX = 1000,
	/// Minimum value for future binary compatibility.
	TGUI_ERR_MIN = -1000,
} tgui_err;


/**
 * @brief All possible types of Activities.
 */
typedef enum {
	/// Standard fullscreen Activity.
	TGUI_ACTIVITY_NORMAL = 0,
	/// Activity is started in a dialog.
	TGUI_ACTIVITY_DIALOG = 1,
	/// Activity is started in a dialog, but touching outside the dialog cancels it.
	TGUI_ACTIVITY_DIALOG_CANCELOUTSIDE = 2,
	/// The Activity is started in picture-in-picture mode.
	TGUI_ACTIVITY_PIP = 3,
	/// The activity will show on the lockscreen.
	TGUI_ACTIVITY_LOCKSCREEN = 4,
	/// The Activity will be started as an overlay over everything else.
	TGUI_ACTIVITY_OVERLAY = 5,
} tgui_activity_type;


/**
 * @brief Specifies the orientation you can set an Activity to.
 * 
 */
typedef enum {
	/// Lets the system choose the orientation.
	TGUI_ORIENTATION_UNSPECIFIED = 0,
	/// The same orientation as the Activity behind in the Activity stack.
	TGUI_ORIENTATION_BEHIND = 1,
	/// Orientation determined by the orientation sensor. All 4 orientations are possible.
	TGUI_ORIENTATION_FULL_SENSOR = 2,
	/// Respect the users option to lock the rotation, but allow all 4 possible rotations if enabled.
	TGUI_ORIENTATION_FULL_USER = 3,
	/// Lock the orientation to landscape. 
	TGUI_ORIENTATION_LANDSCAPE = 4,
	/// Lock the orientation to the current one.
	TGUI_ORIENTATION_LOCKED = 5,
	/// Ignore the orientation sensor.
	TGUI_ORIENTATION_NOSENSOR = 6,
	/// Lock the orientation to portrait.
	TGUI_ORIENTATION_PORTRAIT = 7,
	/// Lock the orientation to the opposite landscape mode.
	TGUI_ORIENTATION_REVERSE_LANDSCAPE = 8,
	/// Lock the orientation to the opposite portrait mode.
	TGUI_ORIENTATION_REVERSE_PORTRAIT = 9,
	/// Determine the orientation with the sensor.
	TGUI_ORIENTATION_SENSOR = 10,
	/// Use landscape, but can be changed with the sensor.
	TGUI_ORIENTATION_SENSOR_LANDSCAPE = 11,
	/// Use portrait, but can be changed with the sensor.
	TGUI_ORIENTATION_SENSOR_PORTRAIT = 12,
	/// Use the users preferred orientation.
	TGUI_ORIENTATION_USER = 13,
	/// Use landscape, but can be changed with the sensor if the user allowed it.
	TGUI_ORIENTATION_USER_LANDSCAPE = 14,
	///Use portrait, but can be changed with the sensor if the user allowed it.
	TGUI_ORIENTATION_USER_PORTRAIT = 15,
} tgui_orientation;


/**
 * @brief Determines how an Activity reacts when the soft keyboard is opened.
 */
typedef enum {
	/// Pan the Activity up to make room for the soft keyboard.
	TGUI_ACTIVITY_INPUT_MODE_PAN = 0,
	/// Resizes the Activity to fit the smaller size.
	TGUI_ACTIVITY_INPUT_MODE_RESIZE = 1,
} tgui_activity_input_mode;

/**
 * @brief The types an EditText can be. See [the Android documentation](https://developer.android.com/reference/android/widget/TextView#attr_android:inputType) for more information.
 */
typedef enum {
	/// Normal text input.
	TGUI_EDIT_TEXT_TEXT = 0,
	/// Multiline text input.
	TGUI_EDIT_TEXT_TEXT_MULTILINE = 1,
	/// Phone number input.
	TGUI_EDIT_TEXT_PHONE = 3,
	/// Date input.
	TGUI_EDIT_TEXT_DATE = 4,
	/// Time input.
	TGUI_EDIT_TEXT_TIME = 5,
	/// Date and time input.
	TGUI_EDIT_TEXT_DATETIME = 6,
	/// Number input.
	TGUI_EDIT_TEXT_NUMBER = 7,
	/// Decimal number input.
	TGUI_EDIT_TEXT_NUMBER_DECIMAL = 8,
	/// Password number input.
	TGUI_EDIT_TEXT_NUMBER_PASSWORD = 9,
	/// Signed number input.
	TGUI_EDIT_TEXT_NUMBER_SIGNED = 10,
	/// Signed decimal number input.
	TGUI_EDIT_TEXT_NUMBER_DECIMAL_SIGNED = 11,
	/// Email address input.
	TGUI_EDIT_TEXT_TEXT_EMAIL_ADDRESS = 12,
	/// Password input.
	TGUI_EDIT_TEXT_TEXT_PASSWORD = 13,
} tgui_edit_text_type;




/**
 * @brief Provides information on the current device and Activity configuration.
 */
typedef struct {
	/// Whether dark mode is enabled. Always false on Android < 10.
	bool dark_mode;
	/// The country code. A NULL terminator is included for convenience.
	char country[10];
	/// The language code. A NULL terminator is included for convenience.
	char language[10];
	/// The current Activity orientation. Only `TGUI_ACTIVITY_LANDSCAPE`, `TGUI_ACTIVITY_REVERSE_LANDSCAPE`, `TGUI_ACTIVITY_PORTRAIT`, `TGUI_ACTIVITY_REVERSE_PORTRAIT` and `TGUI_ACTIVITY_UNSPECIFIED` are possible values.
	tgui_orientation orientation;
	/// Whether the soft keyboard is currently shown.
	bool keyboard_hidden;
	/// The current Activity width in dp.
	int screen_width;
	/// The current Activity height in dp.
	int screen_height;
	/// The current font scale.
	double font_scale;
	/// The display density, such that screenwidth * density = screenwidth_in_px.
	double density;
} tgui_activity_configuration;


/**
 * @brief All possible event types.
 */
typedef enum {
	/// Send when an Activity is created. See [the Android documentation for Activity lifecycle](https://developer.android.com/guide/components/activities/activity-lifecycle) for more information.
	TGUI_EVENT_CREATE = 0,
	/// Send when an Activity is started. See [the Android documentation for Activity lifecycle](https://developer.android.com/guide/components/activities/activity-lifecycle) for more information.
	TGUI_EVENT_START = 1,
	/// Send when an Activity is resumed. See [the Android documentation for Activity lifecycle](https://developer.android.com/guide/components/activities/activity-lifecycle) for more information.
	TGUI_EVENT_RESUME = 2,
	/// Send when an Activity is paused. See [the Android documentation for Activity lifecycle](https://developer.android.com/guide/components/activities/activity-lifecycle) for more information.
	TGUI_EVENT_PAUSE = 3,
	/// Send when an Activity is stopped. See [the Android documentation for Activity lifecycle](https://developer.android.com/guide/components/activities/activity-lifecycle) for more information.
	TGUI_EVENT_STOP = 4,
	/// Send when an Activity is destroyed. See [the Android documentation for Activity lifecycle](https://developer.android.com/guide/components/activities/activity-lifecycle) for more information.
	TGUI_EVENT_DESTROY = 5,
	/// Send when the configuration for an activity changes, i.e. because the Activity is rotated or dark mode is switched on.
	TGUI_EVENT_CONFIG = 6,
	/// Send when a View is clicked.
	TGUI_EVENT_CLICK = 7,
	/// Send when pressing and holding a View.
	TGUI_EVENT_LONG_CLICK = 8,
	/// Send when a View gains focus.
	TGUI_EVENT_FOCUS = 9,
	/// Send when a view is touched.
	TGUI_EVENT_TOUCH = 10,
	/// Send when the text of a TextView changes.
	TGUI_EVENT_TEXT = 11,
	/// Send when a refresh is triggered on a SwipeRefreshLayout.
	TGUI_EVENT_REFRESH = 12,
	/// Send when a RadioButton in a RadioGroup has been selected.
	TGUI_EVENT_SELECTED = 13,
	/// Send when an option is selected in a Spinner or a tab in a TabLayout.
	TGUI_EVENT_ITEM_SELECTED = 14,
	/// Send when the user presses the back button.
	TGUI_EVENT_BACK = 15,
	/// Send when Javascript or the user tries to navigate to a different page in a WebView.
	TGUI_EVENT_WEBVIEW_NAVIGATION = 16,
	/// Send when a WebView encounters a HTTP error when fetching a resource.
	TGUI_EVENT_WEBVIEW_HTTP_ERROR = 17,
	/// Send when a WebView encounters an internal error when fetching a resource, like a SSL error loss of connection.
	TGUI_EVENT_WEBVIEW_ERROR = 18,
	/// Send when a WebView renderer was destroyed by the system, resulting in the corresponding WebView being removed.
	TGUI_EVENT_WEBVIEW_DESTROYED = 19,
	/// Send when the loading progress in a WebView updates.
	TGUI_EVENT_WEBVIEW_PROGRESS = 20,
	/// Send when Javascript tries to print to the console in a WebView.
	TGUI_EVENT_WEBVIEW_CONSOLE = 21,
	/// Send when the airplane mode changes.
	TGUI_EVENT_AIRPLANE = 22,
	/// Send when the locale changes.
	TGUI_EVENT_LOCALE = 23,
	/// Send when the timezone changes.
	TGUI_EVENT_TIMEZONE = 24,
	/// Send when the screen is turned off.
	TGUI_EVENT_SCREEN_OFF = 25,
	/// Send when the screen is turned on.
	TGUI_EVENT_SCREEN_ON = 26,
	/// Send when the user leaves an Activity.
	TGUI_EVENT_USER_LEAVE_HINT = 27,
	/// Send when an Activity enters or loaves picture-in-picture mode
	TGUI_EVENT_PIP = 28,
	/// Send when a click is registered in a remote layout.
	TGUI_EVENT_REMOTE_CLICK = 29,
	/// Send when a notification is clicked.
	TGUI_EVENT_NOTIFICATION = 30,
	/// Send when a notification is swiped away by the user.
	TGUI_EVENT_NOTIFICATION_DISMISSED = 31,
	/// Send when a notification action is clicked.
	TGUI_EVENT_NOTIFICATION_ACTION = 32,
	/// Send when a scale gesture was made on an overlay Activity.
	TGUI_EVENT_OVERLAY_SCALE = 33,
	/// A key was pressed when an ImageView or GLSurfaceView with soft keyboard support was focused.
	TGUI_EVENT_KEY = 34,
	
	/// Send when an exception happens in the plugin.
	TGUI_EVENT_DEBUG_EXCEPTION = 1000,
	
	/// Maximum value for future binary compatibility.
	TGUI_EVENT_TYPE_MAX = 1 << 31,
} tgui_event_type;




/**
 * @brief All supported key modifiers.
 */
typedef enum {
	/// No modifier pressed.
	TGUI_MOD_NONE = 0,
	/// Left shift pressed.
	TGUI_MOD_LSHIFT = 1,
	/// Right shift pressed.
	TGUI_MOD_RSHIFT = 2,
	/// Left ctrl pressed.
	TGUI_MOD_LCTRL = 4,
	/// Right ctrl pressed.
	TGUI_MOD_RCTRL = 8,
	/// Alt pressed.
	TGUI_MOD_ALT = 16,
	/// Fn pressed.
	TGUI_MOD_FN = 32,
	/// Caps lock pressed.
	TGUI_MOD_CAPS_LOCK = 64,
	/// Alt gr pressed.
	TGUI_MOD_ALT_GR = 128,
	/// Num lock pressed.
	TGUI_MOD_NUM_LOCK = 256,
	
	/// Maximum modifier value, for future binary compatibility.
	TGUI_MOD_MAX = 1 << 31,
} tgui_key_modifier;


/**
 * @brief All possible View visibility states.
 */
typedef enum {
	/// Completely visible.
	TGUI_VIS_VISIBLE = 0,
	/// Invisible, but takes up it's space in the layout.
	TGUI_VIS_HIDDEN = 1,
	/// Invisible and takes up no space in the layout.
	TGUI_VIS_GONE = 3,
} tgui_view_visibility;


/**
 * @brief The direction for margins and paddings.
 * 
 */
typedef enum {
	/// @brief All set for directions.
	TGUI_DIR_ALL = 0,
	/// @brief Set for the top.
	TGUI_DIR_TOP = 1,
	/// @brief Set for the left.
	TGUI_DIR_LEFT = 2,
	/// @brief Set for the bottom.
	TGUI_DIR_BOTTOM = 3,
	/// @brief Set for the right.
	TGUI_DIR_RIGHT = 4,
} tgui_direction;


typedef enum {
	TGUI_IMP_DEFAULT = 0,
	TGUI_IMP_MIN = 1,
	TGUI_IMP_LOW = 2,
	TGUI_IMP_HIGH = 3,
	TGUI_IMP_MAX = 4,
} tgui_importance;




/**
 * @brief All supported size units.
 * 
 * See [the Android documentation](https://developer.android.com/guide/topics/resources/more-resources.html#Dimension) for more information.
 * 
 */
typedef enum {
	/// density-pixels unit
	TGUI_UNIT_DP = 0,
	/// scale-pixels unit
	TGUI_UNIT_SP = 1,
	/// pixels unit
	TGUI_UNIT_PX = 2,
	/// millimeters unit
	TGUI_UNIT_MM = 3,
	/// inches unit
	TGUI_UNIT_IN = 4,
	/// points unit
	TGUI_UNIT_PT = 5,
} tgui_size_unit;



/**
 * @brief A value in a size unit.
 * 
 */
typedef struct {
	/// @brief The measurement unit.
	tgui_size_unit unit;
	/// @brief The value.
	float value;
} tgui_size;


/**
 * @brief The types with which a View size can be specified.
 * 
 */
typedef enum {
	/// @brief Match the parent view size.
	TGUI_VIEW_MATCH_PARENT = 0,
	/// @brief Match the content size.
	TGUI_VIEW_WRAP_CONTENT = 1,
	/// @brief Use the provided size.
	TGUI_VIEW_SIZE = 2,
} tgui_view_size_type;




/**
 * @brief Defines a View's size.
 * 
 */
typedef struct {
	/// @brief The size specifier.
	tgui_view_size_type type;
	/// @brief The size, when `TGUI_VIEW_SIZE` is used as the type.
	tgui_size value;
} tgui_view_size;


/**
 * @brief The View alignment in a GridLayout.
 * 
 */
typedef enum {
	/// @brief Align to cell center.
	TGUI_GRID_CENTER = 0,
	/// @brief Align to cell top.
	TGUI_GRID_TOP = 1,
	/// @brief Align to cell bottom.
	TGUI_GRID_BOTTOM = 2,
	/// @brief Align to cell left.
	TGUI_GRID_LEFT = 3,
	/// @brief Align to cell right.
	TGUI_GRID_RIGHT = 4,
	/// @brief Align to cell the baseline.
	TGUI_GRID_BASELINE = 5,
	/// @brief Fill the whole cell.
	TGUI_GRID_FILL = 6,
} tgui_grid_alignment;


/**
 * @brief Gravity of text in a TextView.
 * 
 */
typedef enum {
	/// @brief Center.
	TGUI_GRAV_CENTER = 0,
	/// @brief Top or left.
	TGUI_GRAV_LEFTTOP = 1,
	/// @brief Right or bottom.
	TGUI_GRAV_RIGHTBOTTOM = 2,
} tgui_gravity;


/**
 * @brief Formats for shared image buffers.
 * 
 */
typedef enum {
	/// @brief The shared buffer wil be in ARGB8888 format.
	TGUI_BUFFER_FORMAT_ARGB8888 = 0,
    /// @brief The maximum buffer format, for future binary compatibility.
    TGUI_BUFFER_FORMAT_MAX = 100,
} tgui_buffer_format;


/**
 * @brief A shared memory buffer for images.
 * 
 */
typedef struct {
    /// @brief The buffer id for using the buffer with the plugin. -1 indicates the buffer is deleted.
    int id;
    /// @brief The buffer file descriptor used for mapping the buffer. -1 indicates the buffer is deleted.
    int fd;
    /// @brief The width in pixels.
    const uint32_t width;
    /// @brief The height in pixels.
    const uint32_t height;
    /// @brief The buffer format. Determines the color channels, their order and the bytes per pixel.
    const tgui_buffer_format format;
    /// @brief The buffer data mapped in memory. MAP_FAILED (from <sys/mman.h>) indicates the buffer is deleted.
    void* data;
} tgui_buffer;















/**
 * @brief Possible causes for touch events.
 */
typedef enum {
	/// Send when the first pointer touches.
	TGUI_TOUCH_DOWN = 0,
	/// Send when the last pointer goes up.
	TGUI_TOUCH_UP = 1,
	/// Send when an additional pointer touches.
	TGUI_TOUCH_POINTER_DOWN = 2,
	/// Send when an additional pointer goes up.
	TGUI_TOUCH_POINTER_UP = 3,
	/// Like `TOUCH_UP`, but the gesture was cancelled.
	TGUI_TOUCH_CANCEL = 4,
	/// Send when pointers have been moved.
	TGUI_TOUCH_MOVE = 5,
} tgui_touch_action;


/**
 * @brief A single pointer of a touch event.
 */
typedef struct {
	/// @brief The x coordinate in the View.
	int x;
	/// @brief The y coordinate in the View.
	int y;
	/// @brief The pointer id. Is guaranteed to stay the same for as long as the pointer is down.
	int id;
} tgui_touch_pointer;





/**
 * @brief Represents an event send from the plugin. A union is used so that all events can still have a single type.
 */
typedef struct {
	/// The event type specifies which entry in the union is valid.
	tgui_event_type type;
	/// Most events are specific to an Activity. If the event belongs to an Activity, this field isn't -1.
	tgui_activity activity;
	union {
		/**
		 * @brief Whether the Activity is finishing.<br>
		 * Valid for: `TGUI_EVENT_PAUSE`, `TGUI_EVENT_STOP` and `TGUI_EVENT_DESTROY`.
		 */
		bool finishing;
		/// Valid for `TGUI_EVENT_CONFIG`.
		tgui_activity_configuration configuration;
		/// Valid for `TGUI_EVENT_CLICK`.
		struct {
			/// The id of the View.
			int id;
			/// For CheckBox, Switch and ToggleButton.
			bool set;
		} click;
		/// Valid for `TGUI_EVENT_LONG_CLICK`.
		struct {
			/// The id of the View.
			int id;
		} longClick;
		/// Valid for `TGUI_EVENT_FOCUS`.
		struct {
			/// The id of the View.
			int id;
			/// Whether the View now has focus or not.
			bool focus;
		} focus;
		/// Valid for `TGUI_EVENT_TOUCH`.
		struct {
			/// The id of the View.
			int id;
			/// The type of touch event.
			tgui_touch_action action;
			/**
			 * The pointers of the touch event.
			 */
			tgui_touch_pointer** pointers;
			/// @brief The number of batched move events (size of the first dimension of the pointers array).
			uint32_t events;
			/// @brief Number of pointers for each event in the pointers array.
			uint32_t num_pointers;
			/// index of the pointer added or removed.
			uint32_t index;
			/// Timestamp of the event.
			uint64_t time;
		} touch;
		/// Valid for `TGUI_EVENT_TEXT`.
		struct {
			/// The id of the TextView.
			int id;
			/// The new text of the TextView
			char* text;
		} text;
		/// Valid for `TGUI_EVENT_REFRESH`.
		struct {
			/// The id of the SwipeRefreshLayout.
			int id;
		} refresh;
		/// Valid for `TGUI_EVENT_SELECTED`.
		struct {
			/// The id of the RadioGroup.
			int id;
			/// The id of the selected RadioButton.
			int selected;
		} selected;
		/// Valid for `TGUI_EVENT_ITEM_SELECTED`.
		struct {
			/// The id of the Spinner or TabLayout.
			int id;
			/// The index of the selected element or tab, starting at 0.
			int selected;
		} itemSelected;
		/// Valid for `TGUI_EVENT_WEBVIEW_NAVIGATION`.
		struct {
			/// The id of the WebView.
			int id;
			/// The URL that was tried to navigate to.
			char* url;
		} webNavigation;
		/// Valid for `TGUI_EVENT_WEBVIEW_HTTP_ERROR`.
		struct {
			/// The id of the WebView.
			int id;
			/// The URL the HTTP error came from.
			char* url;
			/// The HTTP error code.
			int code;
		} webHTTPError;
		/// Valid for `TGUI_EVENT_WEBVIEW_ERROR`.
		struct {
			/// The id of the WebView.
			int id;
			/// The URL the error was encountered with.
			char* url;
		} webError;
		/// Valid for `TGUI_EVENT_WEBVIEW_DESTROYED`.
		struct {
			/// The id of the WebView.
			int id;
		} webDestroyed;
		/// Valid for `TGUI_EVENT_WEBVIEW_PROGRESS`.
		struct {
			/// The id of the WebView.
			int id;
			/// The progress of the site loading in percent.
			int progress;
		} webProgress;
		/// Valid for `TGUI_EVENT_WEBVIEW_CONSOLE`.
		struct {
			/// The id of the WebView.
			int id;
			/// The console message.
			char* msg;
		} webConsole;
		/**
		 * @brief The current state of airplane mode.<br>
		 * Valid for `TGUI_EVENT_AIRPLANE`.
		 */
		bool airplane;
		/**
		 * @brief The current locale.<br>
		 * Valid for `TGUI_EVENT_LOCALE`.
		 */
		char locale[10];
		/**
		 * @brief The current timezone.<br>
		 * Valid for `TGUI_EVENT_TIMEZONE`.
		 */
		char timezone[10];
		/// Valid for `TGUI_EVENT_PIP`.
		struct {
			/// The current state of picture-in-picture mode.
			bool pip;
		} pip;
		/// Valid for `TGUI_EVENT_REMOTE_CLICK`.
		struct {
			/// The id of the remote layout.
			int rid;
			/// The id of the View.
			int id;
		} remoteClick;
		/// Valid for `TGUI_EVENT_NOTIFICATION_ACTION`.
		struct {
			/// The id of the notification.
			int id;
			/// The index of the action, starting at 0.
			int action;
		} action;
		/// Valid for `TGUI_EVENT_OVERLAY_SCALE`.
		struct {
			/// The new distance between the 2 pointers.
			float span;
		} overlayScale;
		/// Valid for `TGUI_EVENT_KEY`.
		struct {
			/// The active modifiers.
			tgui_key_modifier mod;
			/// The [Android key code](https://developer.android.com/reference/android/view/KeyEvent).
			uint32_t code;
			/// The unicode code point.
			uint32_t codePoint;
		} key;
		/**
		 * @brief Valid for `TGUI_EVENT_DEBUG_EXCEPTION`.
		 */
		char* stacktrace;
		
		/// For future ABI compatibility, to force double alignment and bigger size
		double _dummy[20];
	};
} tgui_event;






#ifdef __cplusplus
}
#endif
