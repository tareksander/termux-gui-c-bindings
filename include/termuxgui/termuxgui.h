#pragma once

/**
 * @file
 * @brief This is the C API of the library.<br>For an introduction in how the use the API, see <a href="https://github.com/tareksander/termux-gui-c-bindings/blob/main/TUTORIAL.md#c-tutorial">the Tutorial</a>.<br>
 * 
 * Functions return an error code. If the code is <= 0, the operation was a success and the out parameters are valid.
 * For codes > 0, the out parameters have to be treated as invalid.
 * <br><br>
 * 
 * 
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif



struct termuxgui_connection_;

/**
 * @brief Represents a connection to the Termux:GUI plugin.
 */
typedef termuxgui_connection_* termuxgui_connection;


struct termuxgui_activity_;

/**
 * @brief Represents an Android Activity.
 */
typedef termuxgui_activity_* termuxgui_activity;


struct termuxgui_task_;

/**
 * @brief Represents an Android Task.
 */
typedef termuxgui_task_* termuxgui_task;


struct termuxgui_view_;

/**
 * @brief Represents an Android View.
 */
typedef termuxgui_view_* termuxgui_view;








/**
 * @brief Status codes for all functions in the library.
 */
typedef enum {
	/// Operation was successful.
	TERMUXGUI_ERR_OK = 0,
	/// An error occurred in the system library. Check `errno` to get the exact error.
	TERMUXGUI_ERR_SYSTEM = 1,
	/// The connection to the plugin was lost. All further operations on this connection except destroy operations will fail with this error.
	TERMUXGUI_ERR_CONNECTION_LOST = 2,
	/// The Activity the function tried to act on no longer exists.
	TERMUXGUI_ERR_ACTIVITY_DESTROYED = 3,
	/// A protocol buffer message could not be read or written.
	TERMUXGUI_ERR_MESSAGE = 4,
    
} termuxgui_err;


/**
 * @brief All possible types of Activities.
 */
typedef enum {
	/// Standard fullscreen Activity.
	TERMUXGUI_ACTIVITY_NORMAL = 0,
	/// Activity is started in a dialog.
	TERMUXGUI_ACTIVITY_DIALOG = 1,
	/// Activity is started in a dialog, but touching outside the dialog cancels it.
	TERMUXGUI_ACTIVITY_DIALOG_CANCELOUTSIDE = 2,
	/// The Activity is started in picture-in-picture mode.
	TERMUXGUI_ACTIVITY_PIP = 3,
	/// The activity will show on the lockscreen.
	TERMUXGUI_ACTIVITY_LOCKSCREEN = 4,
	/// The Activity will be started as an overlay over everything else.
	TERMUXGUI_ACTIVITY_OVERLAY = 5,
} termuxgui_activity_type;


/**
 * @brief Specifies the orientation you can set an Activity to.
 * 
 */
typedef enum {
	/// Lets the system choose the orientation.
	TERMUXGUI_ACTIVITY_UNSPECIFIED = 0,
	/// The same orientation as the Activity behind in the Activity stack.
	TERMUXGUI_ACTIVITY_BEHIND = 1,
	/// Orientation determined by the orientation sensor. All 4 orientations are possible.
	TERMUXGUI_ACTIVITY_FULL_SENSOR = 2,
	/// Respect the users option to lock the rotation, but allow all 4 possible rotations if enabled.
	TERMUXGUI_ACTIVITY_FULL_USER = 3,
	/// Lock the orientation to landscape. 
	TERMUXGUI_ACTIVITY_LANDSCAPE = 4,
	/// Lock the orientation to the current one.
	TERMUXGUI_ACTIVITY_LOCKED = 5,
	/// Ignore the orientation sensor.
	TERMUXGUI_ACTIVITY_NOSENSOR = 6,
	/// Lock the orientation to portrait.
	TERMUXGUI_ACTIVITY_PORTRAIT = 7,
	/// Lock the orientation to the opposite landscape mode.
	TERMUXGUI_ACTIVITY_REVERSE_LANDSCAPE = 8,
	/// Lock the orientation to the opposite portrait mode.
	TERMUXGUI_ACTIVITY_REVERSE_PORTRAIT = 9,
	/// Determine the orientation with the sensor.
	TERMUXGUI_ACTIVITY_SENSOR = 10,
	/// Use landscape, but can be changed with the sensor.
	TERMUXGUI_ACTIVITY_SENSOR_LANDSCAPE = 11,
	/// Use portrait, but can be changed with the sensor.
	TERMUXGUI_ACTIVITY_SENSOR_PORTRAIT = 12,
	/// Use the users preferred orientation.
	TERMUXGUI_ACTIVITY_USER = 13,
	/// Use landscape, but can be changed with the sensor if the user allowed it.
	TERMUXGUI_ACTIVITY_USER_LANDSCAPE = 14,
	///Use portrait, but can be changed with the sensor if the user allowed it.
	TERMUXGUI_ACTIVITY_USER_PORTRAIT = 15,
} termuxgui_activity_orientation;


/**
 * @brief Determines how an Activity reacts when the soft keyboard is opened.
 */
typedef enum {
	/// Pan the Activity up to make room for the soft keyboard.
	pan = 0,
	/// Resizes the Activity to fit the smaller size.
	resize = 1,
} termuxgui_activity_input_mode;

/**
 * @brief The types an EditText can be. See <a href="https://developer.android.com/reference/android/widget/TextView#attr_android:inputType">the Android documentation</a> for more information.
 */
typedef enum {
    /// Normal text input.
	TERMUXGUI_EDIT_TEXT_TEXT = 0,
    /// Multiline text input.
    TERMUXGUI_EDIT_TEXT_TEXT_MULTILINE = 1,
    /// Phone number input.
    TERMUXGUI_EDIT_TEXT_PHONE = 3,
    /// Date input.
    TERMUXGUI_EDIT_TEXT_DATE = 4,
    /// Time input.
    TERMUXGUI_EDIT_TEXT_TIME = 5,
    /// Date and time input.
    TERMUXGUI_EDIT_TEXT_DATETIME = 6,
    /// Number input.
    TERMUXGUI_EDIT_TEXT_NUMBER = 7,
    /// Decimal number input.
    TERMUXGUI_EDIT_TEXT_NUMBER_DECIMAL = 8,
    /// Password number input.
    TERMUXGUI_EDIT_TEXT_NUMBER_PASSWORD = 9,
    /// Signed number input.
    TERMUXGUI_EDIT_TEXT_NUMBER_SIGNED = 10,
    /// Signed decimal number input.
    TERMUXGUI_EDIT_TEXT_NUMBER_DECIMAL_SIGNED = 11,
    /// Email address input.
    TERMUXGUI_EDIT_TEXT_TEXT_EMAIL_ADDRESS = 12,
    /// Password input.
    TERMUXGUI_EDIT_TEXT_TEXT_PASSWORD = 13,
} termuxgui_edit_text_type;




/**
 * @brief Provides information on the current device and Activity configuration.
 */
typedef struct {
	/// Whether dark mode is enabled. Always false on Android < 10.
	bool dark_mode;
	/// The 2 letter country code. A NULL terminator is included for convenience.
	char country[3];
	/// The 2 letter language code. A NULL terminator is included for convenience.
	char language[3];
	/// The current Activity orientation. Only `TERMUXGUI_ACTIVITY_LANDSCAPE`, `TERMUXGUI_ACTIVITY_REVERSE_LANDSCAPE`, `TERMUXGUI_ACTIVITY_PORTRAIT`, `TERMUXGUI_ACTIVITY_REVERSE_PORTRAIT` and `TERMUXGUI_ACTIVITY_UNSPECIFIED` are possible values.
	termuxgui_activity_orientation orientation;
	/// Whether the soft keyboard is currently shown.
	bool keyboard_hidden;
	/// The current Activity width in dp.
	unsigned int screen_width;
	/// The current Activity height in dp.
	unsigned int screen_height;
	/// The current font scale.
	double font_scale;
	/// The display density, such that screenwidth * density = screenwidth_in_px.
	double density;
} termuxgui_activity_configuration;


/**
 * @brief All possible event types.
 */
typedef enum {
    /// Send when an Activity is created. See <a href="https://developer.android.com/guide/components/activities/activity-lifecycle">the Android documentation for Activity lifecycle</a> for more information.
	TERMUXGUI_EVENT_CREATE = 0,
    /// Send when an Activity is started. See <a href="https://developer.android.com/guide/components/activities/activity-lifecycle">the Android documentation for Activity lifecycle</a> for more information.
	TERMUXGUI_EVENT_START = 1,
    /// Send when an Activity is resumed. See <a href="https://developer.android.com/guide/components/activities/activity-lifecycle">the Android documentation for Activity lifecycle</a> for more information.
	TERMUXGUI_EVENT_RESUME = 2,
    /// Send when an Activity is paused. See <a href="https://developer.android.com/guide/components/activities/activity-lifecycle">the Android documentation for Activity lifecycle</a> for more information.
	TERMUXGUI_EVENT_PAUSE = 3,
    /// Send when an Activity is stopped. See <a href="https://developer.android.com/guide/components/activities/activity-lifecycle">the Android documentation for Activity lifecycle</a> for more information.
	TERMUXGUI_EVENT_STOP = 4,
    /// Send when an Activity is destroyed. See <a href="https://developer.android.com/guide/components/activities/activity-lifecycle">the Android documentation for Activity lifecycle</a> for more information.
	TERMUXGUI_EVENT_DESTROY = 5,
    /// Send when the configuration for an activity changes, i.e. because the Activity is rotated or dark mode is switched on.
	TERMUXGUI_EVENT_CONFIG = 6,
    /// Send when a View is clicked.
	TERMUXGUI_EVENT_CLICK = 7,
    /// Send when pressing and holding a View.
	TERMUXGUI_EVENT_LONG_CLICK = 8,
    /// Send when a View gains focus.
	TERMUXGUI_EVENT_FOCUS = 9,
    /// Send when a view is touched.
	TERMUXGUI_EVENT_TOUCH = 10,
    /// Send when the text of a TextView changes.
	TERMUXGUI_EVENT_TEXT = 11,
    /// Send when a refresh is triggered on a SwipeRefreshLayout.
	TERMUXGUI_EVENT_REFRESH = 12,
    /// Send when a RadioButton in a RadioGroup has been selected.
	TERMUXGUI_EVENT_SELECTED = 13,
    /// Send when an option is selected in a Spinner or a tab in a TabLayout.
	TERMUXGUI_EVENT_ITEM_SELECTED = 14,
    /// Send when the user presses the back button.
    TERMUXGUI_EVENT_BACK = 15,
    /// Send when Javascript or the user tries to navigate to a different page in a WebView.
    TERMUXGUI_EVENT_WEBVIEW_NAVIGATION = 16,
    /// Send when a WebView encounters a HTTP error when fetching a resource.
    TERMUXGUI_EVENT_WEBVIEW_HTTP_ERROR = 17,
    /// Send when a WebView encounters an internal error when fetching a resource, like a SSL error loss of connection.
    TERMUXGUI_EVENT_WEBVIEW_ERROR = 18,
    /// Send when a WebView rednerer was destroyed by the system, resulting in the corresponding WebView being removed.
    TERMUXGUI_EVENT_WEBVIEW_DESTROYED = 19,
    /// Send when the loading progress in a WebView updates.
    TERMUXGUI_EVENT_WEBVIEW_PROGRESS = 20,
    /// Send when Javascript tries to print to the console in a WebView.
    TERMUXGUI_EVENT_WEBVIEW_CONSOLE = 21,
    /// Send when the airplane mode changes.
	TERMUXGUI_EVENT_AIRPLANE = 22,
    /// Send when the locale changes.
	TERMUXGUI_EVENT_LOCALE = 23,
    /// Send when the timezone changes.
	TERMUXGUI_EVENT_TIMEZONE = 24,
    /// Send when the screen is turned off.
	TERMUXGUI_EVENT_SCREEN_OFF = 25,
    /// Send when the screen is turned on.
	TERMUXGUI_EVENT_SCREEN_ON = 26,
    /// Send when the user leaves an Activity.
	TERMUXGUI_EVENT_USER_LEAVE_HINT = 27,
    /// Send when an Activity enters or loaves picture-in-picture mode
	TERMUXGUI_EVENT_PIP = 28,
    /// Send when a click is registered in a remote layout.
	TERMUXGUI_EVENT_REMOTE_CLICK = 29,
    /// Send when a notification is clicked.
	TERMUXGUI_EVENT_NOTIFICATION = 30,
    /// Send when a notification is swiped away by the user.
	TERMUXGUI_EVENT_NOTIFICATION_DISMISSED = 31,
    /// Send when a notification action is clicked.
	TERMUXGUI_EVENT_NOTIFICATION_ACTION = 32,
    /// Send when a scale gesture was made on an overlay Activity.
	TERMUXGUI_EVENT_OVERLAY_SCALE = 33,
	
    /// Send when an exception happens in the plugin.
	TERMUXGUI_EVENT_DEBUG_EXCEPTION = 1000,
} termuxgui_event_type;


/**
 * @brief Possible causes for touch events.
 */
typedef enum {
    /// Send when the first pointer touches.
	TERMUXGUI_TOUCH_DOWN = 0,
    /// Send when the last pointer goes up.
	TERMUXGUI_TOUCH_UP = 1,
    /// Send when an additional pointer touches.
	TERMUXGUI_TOUCH_POINTER_DOWN = 2,
    /// Send when an additional pointer goes up.
	TERMUXGUI_TOUCH_POINTER_UP = 3,
    /// Like `TOUCH_UP`, but the gesture was cancelled.
	TERMUXGUI_TOUCH_CANCEL = 4,
    /// Send when pointers have been moved.
	TERMUXGUI_TOUCH_MOVE = 5,
} termuxgui_touch_action;


/**
 * @brief A single pointer of a touch event.
 */
typedef struct {
	int x, y, id;
} termuxgui_touch_pointer;



/**
 * @brief Represents an event send from the plugin. A union is used so that all events can still have a single type.
 */
typedef struct {
	/// The event type specifies which entry in the union is valid.
	termuxgui_event_type type;
    /// Most events are specific to an Activity. In that case, this field isn't NULL
	termuxgui_activity activity;
	union {
		/**
		 * @brief Whether the Activity is finishing.<br>
         * Valid for: `TERMUXGUI_EVENT_PAUSE`, `TERMUXGUI_EVENT_STOP` and `TERMUXGUI_EVENT_DESTROY`.
		 */
		bool finishing;
		/// Valid for `TERMUXGUI_EVENT_CONFIG`.
		termuxgui_activity_configuration configuration;
		/// Valid for `TERMUXGUI_EVENT_CLICK`.
		struct {
            /// The id of the View.
			int id;
			/// For ImageView only.
			int x;
            /// For ImageView only.
            int y;
			/// For CheckBox, Switch and ToggleButton.
			bool set;
		} click;
        /// Valid for `TERMUXGUI_EVENT_LONG_CLICK`.
		struct {
            /// The id of the View.
			int id;
		} longClick;
        /// Valid for `TERMUXGUI_EVENT_FOCUS`.
		struct {
            /// The id of the View.
			int id;
            /// Whether the View now has focus or not.
			bool focus;
		} focus;
        /// Valid for `TERMUXGUI_EVENT_TOUCH`.
		struct {
            /// The id of the View.
			int id;
            /// The type of touch event.
			termuxgui_touch_action action;
			/**
			 * The pointers of the touch event.<br>
			 * Note: This is only valid until the next touch event is received.
			 */
			// TODO use static memory for pointer array, but watch out for overflows
			termuxgui_touch_pointer** pointers;
            /// index of the pointer added or removed.
			uint32_t index;
            /// Timestamp of the event.
			uint64_t time;
		} touch;
        /// Valid for `TERMUXGUI_EVENT_TEXT`.
		struct {
            /// The id of the TextView.
			int id;
			/// The new text of the TextView
            // TODO use static memory here.
			char* text;
		} text;
        /// Valid for `TERMUXGUI_EVENT_REFRESH`.
		struct {
            /// The id of the SwipeRefreshLayout.
			int id;
		} refresh;
        /// Valid for `TERMUXGUI_EVENT_SELECTED`.
		struct {
            /// The id of the RadioGroup.
			int id;
            /// The id of the selected RadioButton.
			int selected;
		} selected;
        /// Valid for `TERMUXGUI_EVENT_ITEM_SELECTED`.
		struct {
            /// The id of the Spinner or TabLayout.
			int id;
			/// The index of the selected element or tab, starting at 0.
			int selected;
		} itemSelected;
        /// Valid for `TERMUXGUI_EVENT_WEBVIEW_NAVIGATION`.
        struct {
            /// The id of the WebView.
            int id;
            /// The URL that was tried to navigate to.
            //TODO use static memory here
            char* url;
        } webNavigation;
        /// Valid for `TERMUXGUI_EVENT_WEBVIEW_HTTP_ERROR`.
        struct {
            /// The id of the WebView.
            int id;
            /// The URL the HTTP error came from.
            //TODO use static memory here
            char* url;
            /// The HTTP error code.
            int code;
        } webHTTPError;
        /// Valid for `TERMUXGUI_EVENT_WEBVIEW_ERROR`.
        struct {
            /// The id of the WebView.
            int id;
            /// The URL the error was encountered with.
            //TODO use static memory here
            char* url;
        } webError;
        /// Valid for `TERMUXGUI_EVENT_WEBVIEW_DESTROYED`.
        struct {
            /// The id of the WebView.
            int id;
        } webDestroyed;
        /// Valid for `TERMUXGUI_EVENT_WEBVIEW_PROGRESS`.
        struct {
            /// The id of the WebView.
            int id;
            /// The progress of the site loading in percent.
            int progress;
        } webProgress;
        /// Valid for `TERMUXGUI_EVENT_WEBVIEW_CONSOLE`.
        struct {
            /// The id of the WebView.
            int id;
            /// The console message.
            //TODO use static memory here
            char* msg;
        } webConsole;
        /**
         * @brief The current state of airplane mode.<br>
         * Valid for `TERMUXGUI_EVENT_AIRPLANE`.
         */
		bool airplane;
        /**
         * @brief The current locale.<br>
         * Valid for `TERMUXGUI_EVENT_LOCALE`.
         */
		const char* locale;
        /**
         * @brief The current timezone.<br>
         * Valid for `TERMUXGUI_EVENT_TIMEZONE`.
         */
		const char* timezone;
        /// Valid for `TERMUXGUI_EVENT_PIP`.
		struct {
            /// The current state of picture-in-picture mode.
			bool pip;
		} pip;
        /// Valid for `TERMUXGUI_EVENT_REMOTE_CLICK`.
		struct {
            /// The id of the remote layout.
			int rid;
            /// The id of the View.
			int id;
		} remoteClick;
        /// Valid for `TERMUXGUI_EVENT_NOTIFICATION_ACTION`.
		struct {
            /// The id of the notification.
			int id;
            /// The index of the action, starting at 0.
			int action;
		} action;
        /// Valid for `TERMUXGUI_EVENT_OVERLAY_SCALE`.
        struct {
            /// The new distance between the 2 pointers.
            float span;
        } overlayScale;
		/**
		 * @brief Valid for `TERMUXGUI_EVENT_DEBUG_EXCEPTION`.<br>
		 * Note: If not NULL, this has to be freed with free()
		 */
		char* stacktrace;
	};
} termuxgui_event;





/**
 * @brief Creates a connection to the Termux:GUI plugin.
 * Waits up to 6 seconds for the plugin to connect.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_SYSTEM: The socket creation failed.
 *  - TERMUXGUI_ERR_CONNECTION_LOST: The timeout was exceeded.
 * 
 * @param[out] c The newly created connection, if no error occurred.
 * @return The error code.
 */
termuxgui_err termuxgui_connection_create(termuxgui_connection* c);

/**
 * @brief Gets the version code of the plugin app. Can be used to disable features not supported by the plugin version.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param c The connection to use.
 * @param[out] v The version code
 * @return The error code.
 */
termuxgui_err termuxgui_get_version(termuxgui_connection c, int* v);

/**
 * @brief Sends a [toast](https://developer.android.com/guide/topics/ui/notifiers/toasts) using the connection.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param c The connection to use.
 * @param text The text to display.
 * @param l `true` if the toast should be displayed for a long time, `false` for a short time.
 * @return The error code.
 */
termuxgui_err termuxgui_toast(termuxgui_connection c, char* text, bool l);


/**
 * @brief Turns the screen on.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param c The connection to use.
 * @return The error code.
 */
termuxgui_err termuxgui_turn_screen_on(termuxgui_connection c);

/**
 * @brief Checks whether the screen is locked.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param c The connection to use.
 * @param locked A pointer where the status should be put.
 * @return The error code.
 */
termuxgui_err termuxgui_is_locked(termuxgui_connection c, bool* locked);

/**
 * @brief Requests a lockscreen unlock. When the lockscreen isn't protected, unlocks it.
 * When the lockscreen is protected, brings up the UI for the user to unlock it.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param c The connection to use.
 * @return The error code.
 */
termuxgui_err termuxgui_request_unlock(termuxgui_connection c);



/**
 * @brief Closes a connection and frees the resources (all objects created with the connection still have to be destroyed).
 * All open Activities will be closed by the plugin automatically.
 * 
 * @param c The connection to close.
 */
void termuxgui_connection_destroy(termuxgui_connection c);



/**
 * @briefCreates a new Activity.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param c The connection to use.
 * @param[out] a A pointer to the Activity to be created.
 * @param type The type the Activity should be.
 * @param t The Task in which to put the Activity. use `NULL` for a new Task.
 * @param intercept Whether or not to intercept back button events. See `termuxgui_activity_intercept_back_button` for more information.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_create(termuxgui_connection c, termuxgui_activity* a, termuxgui_activity_type type, termuxgui_task t, bool intercept);


/**
 * @brief Gets the Task of an Activity. The returned Task has to be freed with `termuxgui_task_destroy`.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param[out] t The Task of the Activity.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_get_task(termuxgui_activity a, termuxgui_task* t);




/**
 * @brief Moves to Task of the Activity to the back, making it not visible anymore.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_task_to_back(termuxgui_activity a);


/**
 * @brief Sets the color palette for the Activity. The text color is only changed for Views created after this call.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param status_bar_color The color for the status bar.
 * @param primary_color The primary color.
 * @param accent_color The accent color.
 * @param window_background The Activity background color.
 * @param text_color The text color.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_theme(termuxgui_activity a, uint32_t status_bar_color, uint32_t primary_color, uint32_t accent_color, uint32_t window_background, uint32_t text_color);


/**
 * @brief Sets the label and icon for the Task of the Activity, if the Activity is the first one in the Task.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param img The image in PNG or JPEG format.
 * @param img_size The size of the image in bytes.
 * @param label The label for the Task.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_task_description(termuxgui_activity a, void* img, size_t img_size, char* label);


/**
 * @brief Sets the aspect ration for picture-in-picture mode.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param num Numerator of the aspect ratio.
 * @param den Denominator of the aspect ratio.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_pip_params(termuxgui_activity a, unsigned int num, unsigned int den);


/**
 * @brief Causes an Activity to enter or leave picture-in-picture mode.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param pip Whether picture-in-picture mode should be enabled or disabled.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_pip_mode(termuxgui_activity a, bool pip);


/**
 * @brief Sets whether an Activity should automatically go into picture-in-picture mode when the user is leaving.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param automatic Whether to automatically go into picture-in-picture mode.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_pip_mode_auto(termuxgui_activity a, bool automatic);


/**
 * @brief Sets how the Activity reacts to the soft keyboard being shown.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param mode How the Activity should react.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_input_mode(termuxgui_activity a, termuxgui_activity_input_mode mode);


/**
 * @brief Sets whether the Activity being visible should keep the screen from turning off.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param keep Whether to keep the screen on or not.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_keep_screen_on(termuxgui_activity a, bool keep);


/**
 * @brief Sets the orientation for an Activity.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param o The new orientation.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_orientation(termuxgui_activity a, termuxgui_activity_orientation o);


/**
 * @brief Sets the position of the Activity on screen if it's an overlay.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param x The x position in pixels.
 * @param y The y position in pixels.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_position(termuxgui_activity a, unsigned int x, unsigned int y);


/**
 * @brief Gets the current Activity configuration.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param[out] conf The configuration is put here.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_get_configuration(termuxgui_activity a, termuxgui_activity_configuration* conf);


/**
 * @brief Hides the soft keyboard.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_hide_soft_keyboard(termuxgui_activity a);


/**
 * @brief Sets whether the user pressing the back button should finish the Activity (default action) or intercept that and send the `TERMUXGUI_EVENT_BACK` event instead.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @param intercept Whether to intercept the back button press.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_intercept_back_button(termuxgui_activity a, bool intercept);



/**
 * @brief Finishes an Activity if not already finished and releases resources.
 * The memory is freed regardless of the error code.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity.
 * @return The error code.
 */
termuxgui_err termuxgui_activity_destroy(termuxgui_activity a);




/**
 * @brief Brings the Task to the front (make it visible to the user as if they opened it).
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param t
 * @return The error code.
 */
termuxgui_err termuxgui_task_to_front(termuxgui_task t);

/**
 * @brief Finishes the Task, closing all Activities in it. The Activities and Task still have to be freed with `termuxgui_activity_destroy` and `termuxgui_task_destroy`.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param t The Task.
 * @return The error code.
 */
termuxgui_err termuxgui_task_finish(termuxgui_task t);


/**
 * @brief Frees the memory of the Task. The Task will not be closed.
 * @param t The Task.
 */
void termuxgui_task_destroy(termuxgui_task t);








// View creation functions

/**
 * @brief Creates a LinearLayout.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param horizontal Whether the LinearLayout should place its children vertically or horizontally.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_linear_layout(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, bool horizontal);


/**
 * @brief Creates a FrameLayout.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_frame_layout(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a SwipeRefreshLayout.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_swipe_refresh_layout(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a TextView.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param text The initial text. NULL is the same as the empty string.
 * @param selectableText Whether the text is selectable by the user.
 * @param clickableLinks Whether links are clickable and open a browser.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_text_view(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, const char* text, bool selectableText, bool clickableLinks);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param text The initial text. NULL is the same as the empty string.
 * @param type The input type. This adjusts the soft keyboard to show relevant keys.
 * @param noline By default a line is shown under the text in an EditText. This parameter can be used to prevent that.
 * @param blockInput Currently unused.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_edit_text(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, const char* text, termuxgui_edit_text_type type, bool noLine, bool blockInput);


/**
 * @brief Creates a Button.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param text The text. NULL is the same as the empty string.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_button(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, const char* text);


/**
 * @brief Creates an ImageView
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_image_view(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a Space (invisible View for layout purposes).
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_space(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a NestedScrollView.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param snapping Whether the View snaps to the nearest child.
 * @param noBar Whether to show the scrollbar.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_nested_scroll_view(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, bool snapping, bool noBar);


/**
 * @brief Creates a HorizontalScrollView.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param snapping Whether the View snaps to the nearest child.
 * @param noBar Whether to show the scrollbar.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_horizontal_scroll_view(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, bool snapping, bool noBar);


/**
 * @brief Creates a RadioGroup.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_radio_group(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a RadioButton.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param text The text. NULL is the same as the empty string.
 * @param checked Whether the View should be created checked or unchecked.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_radio_button(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, const char* text, bool checked);


/**
 * @brief Creates a CheckBox.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param text The text. NULL is the same as the empty string.
 * @param checked Whether the View should be created checked or unchecked.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_checkbox(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, const char* text, bool checked);


/**
 * @brief Creates a ToggleButton.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param checked Whether the View should be created checked or unchecked.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_toggle_button(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, bool checked);


/**
 * @brief Creates a Switch.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param checked Whether the View should be created checked or unchecked.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_switch(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, bool checked);


/**
 * @brief Creates a Spinner.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_spinner(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a ProgressBar.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_progress_bar(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a TabLayout.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_tab_layout(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);


/**
 * @brief Creates a GridLayout.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param rows The number of rows.
 * @param col The number of columns.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_grid_layout(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent, uint32_t rows, uint32_t cols);


/**
 * @brief Creates a WebView.
 * 
 * @details
 * ### Errors
 *  - TERMUXGUI_ERR_MESSAGE: Protobuf I/O error.
 * 
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return termuxgui_err 
 */
termuxgui_err termuxgui_create_web_view(termuxgui_activity a, termuxgui_view* v, termuxgui_view parent);





















#ifdef __cplusplus
}
#endif

