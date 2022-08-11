#pragma once

/**
 * @file
 * \brief This is the C API of the library.
 * 
 * 
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif



/// opaque struct for type safety.
struct termuxgui_connection_;

/**
 * Represents a connection to the Termux:GUI plugin.
 */
typedef termuxgui_connection_* termuxgui_connection;

/// opaque struct for type safety.
struct termuxgui_activity_;

/**
 * Represents an Android Activity.
 */
typedef termuxgui_activity_* termuxgui_activity;

/// opaque struct for type safety.
struct termuxgui_task_;

/**
 * Represents an Android Task.
 */
typedef termuxgui_task_* termuxgui_task;











/**
 * Status codes for all functions in the library.
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
	
} termuxgui_err;


/**
 * All possible types of Activities.
 */
typedef enum {
	/// Standard fullscreen Activity.
	TERMUXGUI_ACTIVITY_NORMAL = 0,
	/// 
	TERMUXGUI_ACTIVITY_DIALOG = 1,
	/// 
	TERMUXGUI_ACTIVITY_DIALOG_CANCELOUTSIDE = 2,
	/// 
	TERMUXGUI_ACTIVITY_PIP = 3,
	/// 
	TERMUXGUI_ACTIVITY_LOCKSCREEN = 4,
	/// 
	TERMUXGUI_ACTIVITY_OVERLAY = 5,
} termuxgui_activity_type;


/**
 * 
 */
typedef enum {
	///
	TERMUXGUI_ACTIVITY_UNSPECIFIED = 0,
	///
	TERMUXGUI_ACTIVITY_BEHIND = 1,
	///
	TERMUXGUI_ACTIVITY_FULL_SENSOR = 2,
	///
	TERMUXGUI_ACTIVITY_FULL_USER = 3,
	///
	TERMUXGUI_ACTIVITY_LANDSCAPE = 4,
	///
	TERMUXGUI_ACTIVITY_LOCKED = 5,
	///
	TERMUXGUI_ACTIVITY_NOSENSOR = 6,
	///
	TERMUXGUI_ACTIVITY_PORTRAIT = 7,
	///
	TERMUXGUI_ACTIVITY_REVERSE_LANDSCAPE = 8,
	///
	TERMUXGUI_ACTIVITY_REVERSE_PORTRAIT = 9,
	///
	TERMUXGUI_ACTIVITY_SENSOR = 10,
	///
	TERMUXGUI_ACTIVITY_SENSOR_LANDSCAPE = 11,
	///
	TERMUXGUI_ACTIVITY_SENSOR_PORTRAIT = 12,
	///
	TERMUXGUI_ACTIVITY_USER = 13,
	///
	TERMUXGUI_ACTIVITY_USER_LANDSCAPE = 14,
	///
	TERMUXGUI_ACTIVITY_USER_PORTRAIT = 15,
} termuxgui_activity_orientation;


/**
 * 
 */
typedef enum {
	/// 
	pan = 0,
	/// 
	resize = 1,
} termuxgui_activity_input_mode;

/**
 * 
 */
typedef struct {
	///
	bool dark_mode;
	///
	char country[2];
	///
	char language[2];
	///
	termuxgui_activity_orientation orientation;
	///
	bool keyboard_hidden;
	///
	unsigned int screen_width;
	///
	unsigned int screen_height;
	///
	double font_scale;
	///
	double density;
} termuxgui_activity_configuration;


/**
 * 
 */
typedef enum {
	TERMUXGUI_EVENT_CREATE = 0,
	TERMUXGUI_EVENT_START = 1,
	TERMUXGUI_EVENT_RESUME = 2,
	TERMUXGUI_EVENT_PAUSE = 3,
	TERMUXGUI_EVENT_STOP = 4,
	TERMUXGUI_EVENT_DESTROY = 5,
	TERMUXGUI_EVENT_CONFIG = 6,
	TERMUXGUI_EVENT_CLICK = 7,
	TERMUXGUI_EVENT_LONG_CLICK = 8,
	TERMUXGUI_EVENT_FOCUS = 9,
	TERMUXGUI_EVENT_TOUCH = 10,
	TERMUXGUI_EVENT_TEXT = 11,
	TERMUXGUI_EVENT_REFRESH = 12,
	TERMUXGUI_EVENT_SELECTED = 13,
	TERMUXGUI_EVENT_ITEM_SELECTED = 14,
	TERMUXGUI_EVENT_AIRPLANE = 15,
	TERMUXGUI_EVENT_LOCALE = 16,
	TERMUXGUI_EVENT_TIMEZONE = 17,
	TERMUXGUI_EVENT_SCREEN_OFF = 18,
	TERMUXGUI_EVENT_SCREEN_ON = 19,
	TERMUXGUI_EVENT_USER_LEAVE_HINT = 20,
	TERMUXGUI_EVENT_PIP = 21,
	TERMUXGUI_EVENT_BACK = 22,
	TERMUXGUI_EVENT_REMOTE_CLICK = 23,
	TERMUXGUI_EVENT_NOTIFICATION = 24,
	TERMUXGUI_EVENT_NOTIFICATION_ACTION = 25,
	
	
	TERMUXGUI_EVENT_DEBUG_EXCEPTION = 1000,
	// TODO event types
} termuxgui_event_type;


/**
 * 
 */
typedef enum {
	TERMUXGUI_TOUCH_DOWN = 0,
	TERMUXGUI_TOUCH_UP = 1,
	TERMUXGUI_TOUCH_POINTER_DOWN = 2,
	TERMUXGUI_TOUCH_POINTER_UP = 3,
	TERMUXGUI_TOUCH_CANCEL = 4,
	TERMUXGUI_TOUCH_MOVE = 5,
} termuxgui_touch_action;


/**
 * 
 */
typedef struct {
	int x, y, id;
} termuxgui_touch_pointer;



/**
 * 
 */
typedef struct {
	/// The event type specifies which entry in the union is valid.
	termuxgui_event_type type;
	termuxgui_activity activity; /// Most events are specific for an Activity. In that case, this field isn't NULL
	union {
		/**
		 * 
		 */
		bool finishing;
		/// Valid when type == TERMUXGUI_EVENT_CONFIG
		termuxgui_activity_configuration configuration;
		///
		struct {
			int id;
			/// For ImageView only
			int x, y;
			/// For CheckBox, Switch and ToggleButton
			bool set;
		} click;
		struct {
			int id;
		} longClick;
		struct {
			int id;
			bool focus;
		} focus;
		struct {
			int id;
			termuxgui_touch_action action;
			/**
			 * 
			 * Note: This is only valid until the next touch event is received.
			 */
			// TODO use static memory for pointer array, but watch out for overflows
			termuxgui_touch_pointer** pointers;
			uint32_t index;
			uint64_t time;
		} touch;
		struct {
			int id;
			/**
			 * 
			 * Note: This has to be freed with free() if not NULL after you're done with the event.
			 * Accidental memory leaks from ignoring this event shouldn't happen, as you have to explicitly
			 * enable it to get it.
			 */
			char* text;
		} text;
		struct {
			int id;
		} refresh;
		struct {
			int id;
			int selected;
		} selected;
		struct {
			int id;
			/**
			 * Note: If not NULL, this has to be freed with free()
			 */
			char* selected;
		} itemSelected;
		struct {
			int id;
			int tab;
		} tabSelected;
		bool airplane;
		const char* locale;
		const char* timezone;
		struct {
			bool pip;
		} pip;
		struct {
			int rid;
			int id;
		} remoteClick;
		struct {
			int id;
			int action;
		} action;
		/**
		 * 
		 * Note: If not NULL, this has to be freed with free()
		 */
		char* stacktrace;
	};
} termuxgui_event;





/**
 * Creates a connection to the Termux:GUI plugin.
 * Waits up to 6 seconds for the plugin to connect.
 * 
 * ### Errors
 *  - TERMUXGUI_ERR_SYSTEM: The socket creation failed.
 *  - TERMUXGUI_ERR_CONNECTION_LOST: The timeout was exceeded.
 * 
 * @param c The newly created connection, if no error occurred.
 * @return The error code.
 */
termuxgui_err termuxgui_connection_create(termuxgui_connection* c);


/**
 * Sends a [toast](https://developer.android.com/guide/topics/ui/notifiers/toasts) using the connection.
 * 
 * @param c The connection to use.
 * @param text The text to display.
 * @param l `true` if the toast should be displayed for a long time, `false` for a short time.
 * @return The error code.
 */
termuxgui_err termuxgui_toast(termuxgui_connection c, char* text, bool l);


/**
 * 
 * @param c
 * @return The error code.
 */
termuxgui_err termuxgui_turn_screen_on(termuxgui_connection c);

/**
 * 
 * @param c
 * @param locked
 * @return The error code.
 */
termuxgui_err termuxgui_is_locked(termuxgui_connection c, bool* locked);

/**
 * 
 * @param c
 * @return The error code.
 */
termuxgui_err termuxgui_request_unlock(termuxgui_connection c);



/**
 * Closes a connection and frees the resources (all objects created with the connection still have to be destroyed).
 * 
 * All open Activities will be closed by the plugin automatically.
 * 
 * @param c The connection to close.
 */
void termuxgui_connection_destroy(termuxgui_connection c);



/**
 * 
 * @param c
 * @param a
 * @param type
 * @param t
 * @return The error code.
 */
termuxgui_err termuxgui_activity_create(termuxgui_connection c, termuxgui_activity* a, termuxgui_activity_type type, termuxgui_task t);


/**
 * Gets the Task of an Activity. The returned Task has to be freed with `termuxgui_task_destroy`.
 * 
 * @param a
 * @param t
 * @return The error code.
 */
termuxgui_err termuxgui_activity_get_task(termuxgui_activity a, termuxgui_task* t);


/**
 * Brings the Task of an Activity to the front (make it visible to the user as if they opened it).
 * @param a
 * @return The error code.
 */
termuxgui_err termuxgui_activity_task_to_front(termuxgui_activity a);



/**
 * 
 * @param a
 * @return The error code.
 */
termuxgui_err termuxgui_activity_task_to_back(termuxgui_activity a);


/**
 * 
 * @param a
 * @param status_bar_color
 * @param primary_color
 * @param accent_color
 * @param window_background
 * @param text_color
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_theme(termuxgui_activity a, uint32_t status_bar_color, uint32_t primary_color, uint32_t accent_color, uint32_t window_background, uint32_t text_color);


/**
 * 
 * @param a
 * @param img
 * @param img_size
 * @param label
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_task_description(termuxgui_activity a, void* img, size_t img_size, char* label);


/**
 * 
 * @param a
 * @param num
 * @param den
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_pip_params(termuxgui_activity a, unsigned int num, unsigned int den);


/**
 * 
 * @param a
 * @param pip
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_pip_mode(termuxgui_activity a, bool pip);


/**
 * 
 * @param a
 * @param automatic
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_pip_mode_auto(termuxgui_activity a, bool automatic);


/**
 * 
 * @param a
 * @param mode 
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_input_mode(termuxgui_activity a, termuxgui_activity_input_mode mode);


/**
 * 
 * @param a
 * @param keep
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_keep_screen_on(termuxgui_activity a, bool keep);


/**
 * 
 * @param a
 * @param o
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_orientation(termuxgui_activity a, termuxgui_activity_orientation o);


/**
 * 
 * @param a
 * @param x
 * @param y
 * @return The error code.
 */
termuxgui_err termuxgui_activity_set_position(termuxgui_activity a, unsigned int x, unsigned int y);


/**
 * 
 * @param a
 * @param conf
 * @return The error code.
 */
termuxgui_err termuxgui_activity_get_configuration(termuxgui_activity a, termuxgui_activity_configuration* conf);


/**
 * 
 * @param a
 * @return The error code.
 */
termuxgui_err termuxgui_activity_hide_soft_keyboard(termuxgui_activity a);


/**
 * 
 * @param a
 * @param intercept
 * @return The error code.
 */
termuxgui_err termuxgui_activity_intercept_back_button(termuxgui_activity a, bool intercept);



/**
 * 
 * @param a
 */
void termuxgui_activity_destroy(termuxgui_activity a);




/**
 * Finishes the Task, closing all Activities in it. The Activities and Task still have to be freed with `termuxgui_activity_destroy` and `termuxgui_task_destroy`.
 * 
 * @param t
 * @return The error code.
 */
termuxgui_err termuxgui_task_finish(termuxgui_task t);


/**
 * Frees the memory of the Task. The Task will not be closed.
 * @param t The Task.
 */
void termuxgui_task_destroy(termuxgui_task t);





























#ifdef __cplusplus
}
#endif

