#pragma once

/**
 * @file
 * @brief This file contains all functions related to WebViews.
 * 
 * 
 */

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif



/**
 * @brief Sets whether Javascript execution is allowed in a WebView. The user is asked for confirmation to enable.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @param allow Whether to enable or disable Javascript execution.
 * @return The error code. 
 */
tgui_err tgui_webview_allow_javascript(tgui_connection c, tgui_activity a, tgui_view v, bool allow);


/**
 * @brief Sets whether the WebView is allowed to load content URIs.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @param allow Whether to enable or disable content:// URIs.
 * @return The error code. 
 */
tgui_err tgui_webview_allow_content_uri(tgui_connection c, tgui_activity a, tgui_view v, bool allow);


/**
 * @brief Sets the displayed data of a WebView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @param data The data as a base64 encoded string.
 * @param mime The MIME type of the data. Usually "text/html".
 * @return The error code. 
 */
tgui_err tgui_webview_set_data(tgui_connection c, tgui_activity a, tgui_view v, const char* data, const char* mime);


/**
 * @brief Loads content from a URI.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @param uri The URI to load.
 * @return The error code. 
 */
tgui_err tgui_webview_load_uri(tgui_connection c, tgui_activity a, tgui_view v, const char* uri);


/**
 * @brief By default the user cannot navigate to other pages in the WebView. This can enable navigation.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @param allow Whether to enable or disable navigation by the user.
 * @return The error code. 
 */
tgui_err tgui_webview_allow_navigation(tgui_connection c, tgui_activity a, tgui_view v, bool allow);


/**
 * @brief Goes back to the last page.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @return The error code. 
 */
tgui_err tgui_webview_go_back(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief Goes forward to the next page.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @return The error code. 
 */
tgui_err tgui_webview_go_forward(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief Allows you to execute Javascript inside the WebView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param a The Activity the View is in.
 * @param v The WebView id.
 * @param source The Javascript source you want to execute.
 * @return The error code. 
 */
tgui_err tgui_webview_eval_js(tgui_connection c, tgui_activity a, tgui_view v, const char* source);





#ifdef __cplusplus
}
#endif
