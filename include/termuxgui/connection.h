#pragma once

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif





/**
 * @brief Brings Termux to the foreground.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_SYSTEM: `am` executable not found.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @return The error code.
 */
tgui_err tgui_to_termux();

/**
 * @brief Creates a connection to the Termux:GUI plugin.
 * Waits up to 6 seconds for the plugin to connect.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_SYSTEM: The socket creation failed.
 *  - TGUI_ERR_CONNECTION_LOST: The timeout was exceeded.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param[out] c The newly created connection, if no error occurred.
 * @return The error code.
 */
tgui_err tgui_connection_create(tgui_connection* c);

/**
 * @brief Gets the version code of the plugin app. Can be used to disable features not supported by the plugin version.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] v The version code
 * @return The error code.
 */
tgui_err tgui_get_version(tgui_connection c, int* v);

/**
 * @brief Sends a [toast](https://developer.android.com/guide/topics/ui/notifiers/toasts) using the connection.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[in] text The text to display.
 * @param l `true` if the toast should be displayed for a long time, `false` for a short time.
 * @return The error code.
 */
tgui_err tgui_toast(tgui_connection c, const char* text, bool l);


/**
 * @brief Turns the screen on.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @return The error code.
 */
tgui_err tgui_turn_screen_on(tgui_connection c);

/**
 * @brief Checks whether the screen is locked.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] locked A pointer where the status should be put.
 * @return The error code.
 */
tgui_err tgui_is_locked(tgui_connection c, bool* locked);

/**
 * @brief Requests a lockscreen unlock. When the lockscreen isn't protected, unlocks it.
 * When the lockscreen is protected, brings up the UI for the user to unlock it.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity that wants to unlock the screen.
 * @return The error code.
 */
tgui_err tgui_request_unlock(tgui_connection c, tgui_activity a);


/**
 * @brief Waits for an event from the plugin and returns it. Events have to be destroyed with `tgui_event_destroy`.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] event The event from the plugin.
 * @return The error code.
 */
tgui_err tgui_wait_event(tgui_connection c, tgui_event* event);

/**
 * @brief Returns an event from the plugin if one is available without blocking. Events have to be destroyed with `tgui_event_destroy`.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] event The event from the plugin.
 * @param[out] available Set to true if an event was available. If false, event is invalid and doesn't need to be destroyed.
 * @return The error code.
 */
tgui_err tgui_poll_event(tgui_connection c, tgui_event* event, bool* available);



/**
 * @brief Frees the memory of an event.
 * Some events fill the union with pointers to dynamic memory, which have to be freed.
 * 
 * 
 * @param c The connection to use.
 * @param event The event to free.
 * @return The error code.
 */
void tgui_event_destroy(tgui_event* event);


/**
 * @brief Closes a connection and frees the resources (all objects created with the connection still have to be destroyed).
 * All open Activities will be closed by the plugin automatically.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to close.
 */
void tgui_connection_destroy(tgui_connection c);





#ifdef __cplusplus
}
#endif
