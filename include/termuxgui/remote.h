#pragma once

/**
 * @file
 * @brief This file contains all functions related to remote layouts and widgets.
 * 
 * 
 */


#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Creates a remote layout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] layout Will contain the remote layout id if successful.
 * @return The error code. 
 */
tgui_err tgui_remote_layout_create(tgui_connection c, tgui_remote_layout* layout);


/**
 * @brief Destroys a remote layout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The layout to destroy.
 * @return The error code. 
 */
tgui_err tgui_remote_layout_destroy(tgui_connection c, tgui_remote_layout layout);


/**
 * @brief Create a remote FrameLayout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param[in] parent The optional parent View.
 * @param[out] v Will contain the remote view id if successful.
 * @return The error code. 
 */
tgui_err tgui_remote_create_frame_layout(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v);


/**
 * @brief Create a remote LinearLayout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param[in] parent The optional parent View.
 * @param[out] v Will contain the remote view id if successful.
 * @param horizontal Whether the LinearLayout should place its children vertically or horizontally.
 * @return The error code. 
 */
tgui_err tgui_remote_create_linear_layout(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v, bool horizontal);


/**
 * @brief Create a remote TextView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param[in] parent The optional parent View.
 * @param[out] v Will contain the remote view id if successful.
 * @return The error code. 
 */
tgui_err tgui_remote_create_text_view(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v);


/**
 * @brief Create a remote Button.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param[in] parent The optional parent View.
 * @param[out] v Will contain the remote view id if successful.
 * @return The error code. 
 */
tgui_err tgui_remote_create_button(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v);


/**
 * @brief Create a remote ImageView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param[in] parent The optional parent View.
 * @param[out] v Will contain the remote view id if successful.
 * @return The error code. 
 */
tgui_err tgui_remote_create_image_view(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v);


/**
 * @brief Create a remote ProgressBar.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param[in] parent The optional parent View.
 * @param[out] v Will contain the remote view id if successful.
 * @return The error code. 
 */
tgui_err tgui_remote_create_progress_bar(tgui_connection c, tgui_remote_layout layout, const tgui_view* parent, tgui_view* v);

/**
 * @brief Sets the background color of a remote View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param color The color.
 * @return The error code. 
 */
tgui_err tgui_remote_set_background_color(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_color color);


/**
 * @brief Sets the progress of a remote ProgressBar.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param progress The progress from 0 to 100 (inclusive).
 * @return The error code. 
 */
tgui_err tgui_remote_set_progress(tgui_connection c, tgui_remote_layout layout, tgui_view v, unsigned char progress);


/**
 * @brief Sets the text of a remote View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param text The text to use.
 * @return The error code. 
 */
tgui_err tgui_remote_set_text(tgui_connection c, tgui_remote_layout layout, tgui_view v, const char* text);


/**
 * @brief Sets the text size of a remote View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param size The size.
 * @return The error code. 
 */
tgui_err tgui_remote_set_text_size(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_size size);



/**
 * @brief Sets the text color of a remote View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param color The color.
 * @return The error code. 
 */
tgui_err tgui_remote_set_text_color(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_color color);



/**
 * @brief Sets the visibility of a remote View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param vis The visibility.
 * @return The error code. 
 */
tgui_err tgui_remote_set_visibility(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_view_visibility vis);



/**
 * @brief Sets the padding of a remote View.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param left The left padding.
 * @param top The top padding.
 * @param right The right padding.
 * @param bottom The bottom padding.
 * @return The error code. 
 */
tgui_err tgui_remote_set_padding(tgui_connection c, tgui_remote_layout layout, tgui_view v, tgui_size left, tgui_size top, tgui_size right, tgui_size bottom);



/**
 * @brief Sets the image of a remote ImageView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param v The View.
 * @param[in] img The image data as PGN or JPEG.
 * @param length The length of the image data.
 * @return The error code. 
 */
tgui_err tgui_remote_set_image(tgui_connection c, tgui_remote_layout layout, tgui_view v, const void* img, size_t length);



/**
 * @brief Sets a widget to the specified remote layout. The widget id is obtained when the user creates the widget.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param layout The remote layout to use.
 * @param[in] wid The widget id as a string.
 * @return The error code. 
 */
tgui_err tgui_remote_widget_layout(tgui_connection c, tgui_remote_layout layout, const char* wid);






#ifdef __cplusplus
}
#endif
