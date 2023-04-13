#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif




/**
 * @brief Creates a new Activity.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] a A pointer to the Activity to be created.
 * @param type The type the Activity should be.
 * @param[inout] t The Task in which to put the Activity. Use `NULL` for a new Task. After calling it will contain the Task the Activity was created in.
 * @param intercept Whether or not to intercept back button events. See `tgui_activity_intercept_back_button` for more information.
 * @return The error code.
 */
tgui_err tgui_activity_create(tgui_connection c, tgui_activity* a, tgui_activity_type type, tgui_task* t, bool intercept);






/**
 * @brief Moves to Task of the Activity to the back, making it not visible anymore.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @return The error code.
 */
tgui_err tgui_activity_task_to_back(tgui_connection c, tgui_activity a);


/**
 * @brief Sets the color palette for the Activity. The text color is only changed for Views created after this call.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param status_bar_color The color for the status bar.
 * @param primary_color The primary color.
 * @param accent_color The accent color.
 * @param window_background The Activity background color.
 * @param text_color The text color.
 * @return The error code.
 */
tgui_err tgui_activity_set_theme(tgui_connection c, tgui_activity a, tgui_color status_bar_color, tgui_color primary_color, tgui_color accent_color, tgui_color window_background, tgui_color text_color);


/**
 * @brief Sets the label and icon for the Task of the Activity, if the Activity is the first one in the Task.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param[in] img The image in PNG or JPEG format.
 * @param img_size The size of the image in bytes.
 * @param[in] label The label for the Task.
 * @return The error code.
 */
tgui_err tgui_activity_set_task_description(tgui_connection c, tgui_activity a, const void* img, size_t img_size, const char* label);


/**
 * @brief Sets the aspect ration for picture-in-picture mode.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param num Numerator of the aspect ratio.
 * @param den Denominator of the aspect ratio.
 * @return The error code.
 */
tgui_err tgui_activity_set_pip_params(tgui_connection c, tgui_activity a, unsigned int num, unsigned int den);


/**
 * @brief Causes an Activity to enter or leave picture-in-picture mode.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param pip Whether picture-in-picture mode should be enabled or disabled.
 * @return The error code.
 */
tgui_err tgui_activity_set_pip_mode(tgui_connection c, tgui_activity a, bool pip);


/**
 * @brief Sets whether an Activity should automatically go into picture-in-picture mode when the user is leaving.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param automatic Whether to automatically go into picture-in-picture mode.
 * @return The error code.
 */
tgui_err tgui_activity_set_pip_mode_auto(tgui_connection c, tgui_activity a, bool automatic);


/**
 * @brief Sets how the Activity reacts to the soft keyboard being shown.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param mode How the Activity should react.
 * @return The error code.
 */
tgui_err tgui_activity_set_input_mode(tgui_connection c, tgui_activity a, tgui_activity_input_mode mode);


/**
 * @brief Sets whether the Activity being visible should keep the screen from turning off.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param keep Whether to keep the screen on or not.
 * @return The error code.
 */
tgui_err tgui_activity_set_keep_screen_on(tgui_connection c, tgui_activity a, bool keep);


/**
 * @brief Sets the orientation for an Activity.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param o The new orientation.
 * @return The error code.
 */
tgui_err tgui_activity_set_orientation(tgui_connection c, tgui_activity a, tgui_orientation o);


/**
 * @brief Sets the position of the Activity on screen if it's an overlay.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param x The x position in pixels.
 * @param y The y position in pixels.
 * @return The error code.
 */
tgui_err tgui_activity_set_position(tgui_connection c, tgui_activity a, unsigned int x, unsigned int y);


/**
 * @brief Gets the current Activity configuration.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param[out] conf The configuration is put here.
 * @return The error code.
 */
tgui_err tgui_activity_get_configuration(tgui_connection c, tgui_activity a, tgui_activity_configuration* conf);


/**
 * @brief Hides the soft keyboard.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @return The error code.
 */
tgui_err tgui_activity_hide_soft_keyboard(tgui_connection c, tgui_activity a);


/**
 * @brief Sets whether the user pressing the back button should finish the Activity (default action) or intercept that and send the `TGUI_EVENT_BACK` event instead.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param intercept Whether to intercept the back button press.
 * @return The error code.
 */
tgui_err tgui_activity_intercept_back_button(tgui_connection c, tgui_activity a, bool intercept);


/**
 * @brief Sets the secure flag for the Activity. Disables screenshots and shows a blank Activity in the task switcher if enabled.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity.
 * @param secure The secure flag setting.
 * @return The error code.
 */
tgui_err tgui_activity_set_secure(tgui_connection c, tgui_activity a, bool secure);




/**
 * @brief Brings the Task to the front (make it visible to the user as if they opened it).
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param t
 * @return The error code.
 */
tgui_err tgui_task_to_front(tgui_connection c, tgui_task t);

/**
 * @brief Finishes the Task, closing all Activities in it.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param t The Task.
 * @return The error code.
 */
tgui_err tgui_task_finish(tgui_connection c, tgui_task t);





#ifdef __cplusplus
}
#endif
