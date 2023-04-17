#pragma once

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif




/**
 * @brief Sets whether click events are send for a View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @param send Set to true if you want to get the event, false if not.
 * @return The error code. 
 */
tgui_err tgui_send_click_event(tgui_connection c, tgui_activity a, tgui_view v, bool send);

/**
 * @brief Sets whether long click events are send for a View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @param send Set to true if you want to get the event, false if not.
 * @return The error code. 
 */
tgui_err tgui_send_long_click_event(tgui_connection c, tgui_activity a, tgui_view v, bool send);

/**
 * @brief Sets whether focus change events are send for a View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @param send Set to true if you want to get the event, false if not.
 * @return The error code. 
 */
tgui_err tgui_send_focus_change_event(tgui_connection c, tgui_activity a, tgui_view v, bool send);

/**
 * @brief Sets whether touch events are send for a View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @param send Set to true if you want to get the event, false if not.
 * @return The error code. 
 */
tgui_err tgui_send_touch_event(tgui_connection c, tgui_activity a, tgui_view v, bool send);

/**
 * @brief Sets whether text events are send for a View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 *  - TGUI_ERR_VIEW_INVALID: Invalid view type.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The View.
 * @param send Set to true if you want to get the event, false if not.
 * @return The error code. 
 */
tgui_err tgui_send_text_event(tgui_connection c, tgui_activity a, tgui_view v, bool send);

/**
 * @brief Sets whether overlay touch events are send for an Activity.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The overlay Activity.
 * @param send Set to true if you want to get the event, false if not.
 * @return The error code. 
 */
tgui_err tgui_send_overlay_touch_event(tgui_connection c, tgui_activity a, bool send);






#ifdef __cplusplus
}
#endif
