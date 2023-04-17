#pragma once

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif




/**
 * @brief Sets whether an EditText shows the cursor or not.
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
 * @param show Whether to show the cursor or not.
 * @return tgui_err The error code. 
 */
tgui_err tgui_show_cursor(tgui_connection c, tgui_activity a, tgui_view v, bool show);



/**
 * @brief Sets the parameters for a View in a LinearLayout.
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
 * @param weight The layout weight. Use a negative number to keep the current weight.
 * @param position the position in the View. Use 0 to keep the position.
 * @return tgui_err The error code. 
 */
tgui_err tgui_linear_params(tgui_connection c, tgui_activity a, tgui_view v, float weight, int position);


/**
 * @brief Sets the parameters for a View in a GridLayout.
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
 * @param row The row position.
 * @param col. The column position.
 * @param row_size How many rows the View occupies.
 * @param col_size How many columns the View occupies.
 * @param row_align The alignment in the row.
 * @param col_align The alignment in the column.
 * @return tgui_err The error code. 
 */
tgui_err tgui_grid_params(tgui_connection c, tgui_activity a, tgui_view v, size_t row, size_t col, size_t row_size, size_t col_size, tgui_grid_alignment row_align, tgui_grid_alignment col_align);



/**
 * @brief Sets the location of the View manually. Useful for FrameLayout. Can also make it display on top of its siblings.
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
 * @param unit The unit for x and y.
 * @param x The horizontal position.
 * @param y The vertical position.
 * @param top Set to true if you want to move the View on top of its siblings.
 * @return tgui_err The error code. 
 */
tgui_err tgui_view_location(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float x, float y, bool top);


/**
 * @brief Sets the parameters for a View in a RelativeLayout. NOT IMPLEMENTED!
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
 * @return tgui_err The error code. 
 */
tgui_err tgui_relative_params(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief Sets the visibility of a View.
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
 * @param vis The visibility.
 * @return tgui_err The error code. 
 */
tgui_err tgui_visibility(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_visibility vis);


/**
 * @brief Sets the width of a View.
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
 * @param width The width.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_width(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_size width);


/**
 * @brief Sets the height of a View.
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
 * @param height The height.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_height(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_size height);

/**
 * @brief Gets the dimensions of a View.
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
 * @param unit The unit of the returned dimensions.
 * @param[out] width If successful, will contain the View width in the desired unit.
 * @param[out] height If successful, will contain the View height in the desired unit.
 * @return tgui_err The error code. 
 */
tgui_err tgui_get_dimensions(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float* width, float* height);


/**
 * @brief Deletes a View.
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
 * @return tgui_err The error code. 
 */
tgui_err tgui_delete_view(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief Deletes the children of a View.
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
 * @return tgui_err The error code. 
 */
tgui_err tgui_delete_children(tgui_connection c, tgui_activity a, tgui_view v);



/**
 * @brief Sets the margins for a View.
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
 * @param size The margin size.
 * @param dir The direction(s) to apply the margin.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_margin(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir);


/**
 * @brief Sets the padding for a View.
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
 * @param size The padding size.
 * @param dir The direction(s) to apply the padding.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_padding(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir);


/**
 * @brief Sets the background color of a View.
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
 * @param color The color.
 * @return tgui_err The error code. 
 */
tgui_err tgui_background_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color);



/**
 * @brief Sets the text color of a View.
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
 * @param color The text color.
 * @return tgui_err The error code. 
 */
tgui_err tgui_text_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color);


/**
 * @brief Sets the progress of a ProgressBar
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
 * @param progress The progress from 0 to 100(inclusive).
 * @return tgui_err The error code. 
 */
tgui_err tgui_progress(tgui_connection c, tgui_activity a, tgui_view v, unsigned char progress);


/**
 * @brief Set whether a SwipeRefreshLayout is in the refreshing state.
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
 * @param refreshing The refreshing state.
 * @return tgui_err The error code. 
 */
tgui_err tgui_refreshing(tgui_connection c, tgui_activity a, tgui_view v, bool refreshing);


/**
 * @brief Sets the Text of a View.
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
 * @param text The text.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_text(tgui_connection c, tgui_activity a, tgui_view v, const char* text);


/**
 * @brief Sets the gravity of the text in a View.
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
 * @param horizontal The horizontal gravity.
 * @param vertical The vertical gravity.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_gravity(tgui_connection c, tgui_activity a, tgui_view v, tgui_gravity horizontal, tgui_gravity vertical);


/**
 * @brief Sets the text size of a View.
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
 * @param size The text size.
 * @return tgui_err The error code. 
 */
tgui_err tgui_text_size(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size);


/**
 * @brief Gets the text of a View.
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
 * @param[out] text The text of the View. When successful, this has to be freed with free().
 * @return tgui_err The error code. 
 */
tgui_err tgui_get_text(tgui_connection c, tgui_activity a, tgui_view v, char** text);



/**
 * @brief Sets whether a View is checked.
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
 * @param checked The new checked status.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_checked(tgui_connection c, tgui_activity a, tgui_view v, bool checked);



/**
 * @brief Sets the focus to a View.
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
 * @param force_soft If true, forces the software keyboard to open.
 * @return tgui_err The error code. 
 */
tgui_err tgui_focus(tgui_connection c, tgui_activity a, tgui_view v, bool force_soft);


/**
 * @brief Gets the scroll position of a View.
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
 * @param unit The unit for x and y.
 * @param[out] x The x scroll position.
 * @param[out] y The y scroll position.
 * @return tgui_err The error code. 
 */
tgui_err tgui_get_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float* x, float* y);


/**
 * @brief Sets the scroll position for a View.
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
 * @param x The x scroll position.
 * @param y The y scroll position.
 * @param smooth Whether to jump or scroll smoothly.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size x, tgui_size y, bool smooth);


/**
 * @brief Sets the list of a Spinner.
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
 * @param[in] list A NULL terminated list of pointers to strings.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_list(tgui_connection c, tgui_activity a, tgui_view v, const char* const* list);


/**
 * @brief Sets the image of an ImageView.
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
 * @param img The image data in PGN/JPEG.
 * @param length The length of the image data.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_image(tgui_connection c, tgui_activity a, tgui_view v, const void* img, size_t length);



/**
 * @brief Creates a memory buffer shared with the plugin and maps it.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_SYSTEM: mmap failed
 * 
 * @param c The connection to use.
 * @param[in] buffer A buffer with the width and height fields > 0 and a valid format field. The data, id and fd fields are filled out if successful.
 * @return tgui_err The error code. 
 */
tgui_err tgui_add_buffer(tgui_connection c, tgui_buffer* buffer);





/**
 * @brief Deletes the buffer in the plugin, closes the file descriptor and removes the memory mapping.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * 
 * @param c The connection to use.
 * @return tgui_err The error code. 
 */
tgui_err tgui_delete_buffer(tgui_connection c, tgui_buffer* buffer);


/**
 * @brief Blits a buffer in the plugin, making the image available to ImageViews on the next refresh.
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
 * @param[in] buffer The buffer to blit.
 * @return tgui_err The error code. 
 */
tgui_err tgui_blit_buffer(tgui_connection c, const tgui_buffer* buffer);


/**
 * @brief Sets an ImageVIew to display the contents of a buffer.
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
 * @param[in] buffer The buffer to set.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_buffer(tgui_connection c, tgui_activity a, tgui_view v, const tgui_buffer* buffer);



/**
 * @brief Refreshes an ImageView after blitting the contents of its buffer.
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
 * @return tgui_err The error code. 
 */
tgui_err tgui_refresh_image_view(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief Selects a tab in a TabLayout.
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
 * @param index The tab to select.
 * @return tgui_err The error code. 
 */
tgui_err tgui_select_tab(tgui_connection c, tgui_activity a, tgui_view v, unsigned int index);


/**
 * @brief Selects an item in a Spinner.
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
 * @param index The item to select.
 * @return tgui_err The error code. 
 */
tgui_err tgui_select_item(tgui_connection c, tgui_activity a, tgui_view v, unsigned int index);



/**
 * @brief Sets whether a View is clickable by the user.
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
 * @param clickable The new clickable state.
 * @return tgui_err The error code. 
 */
tgui_err tgui_set_clickable(tgui_connection c, tgui_activity a, tgui_view v, bool clickable);






#ifdef __cplusplus
}
#endif
