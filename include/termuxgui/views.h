#pragma once

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif




/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_show_cursor(tgui_connection c, tgui_activity a, tgui_view v, bool show);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_linear_params(tgui_connection c, tgui_activity a, tgui_view v, float weight, int position);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_grid_params(tgui_connection c, tgui_activity a, tgui_view v, tgui_grid_alignment row_align, tgui_grid_alignment col_align);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_view_location(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float x, float y);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_relative_params(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_visibility(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_visibility vis);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_width(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_size width);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_height(tgui_connection c, tgui_activity a, tgui_view v, tgui_view_size height);

/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_get_dimensions(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float* width, float* height);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_delete_view(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_delete_children(tgui_connection c, tgui_activity a, tgui_view v);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_margin(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_padding(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size, tgui_direction dir);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_background_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_text_color(tgui_connection c, tgui_activity a, tgui_view v, tgui_color color);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_progress(tgui_connection c, tgui_activity a, tgui_view v, unsigned char progress);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_refreshing(tgui_connection c, tgui_activity a, tgui_view v, bool refreshing);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_text(tgui_connection c, tgui_activity a, tgui_view v, const char* text);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_gravity(tgui_connection c, tgui_activity a, tgui_view v, tgui_gravity horizontal, tgui_gravity vertical);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_text_size(tgui_connection c, tgui_activity a, tgui_view v, tgui_size size);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_get_text(tgui_connection c, tgui_activity a, tgui_view v, char** text);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_checked(tgui_connection c, tgui_activity a, tgui_view v, bool checked);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_focus(tgui_connection c, tgui_activity a, tgui_view v, bool focus);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_get_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size_unit unit, float* x, float* y);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_scroll_position(tgui_connection c, tgui_activity a, tgui_view v, tgui_size x, tgui_size y, bool smooth);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_list(tgui_connection c, tgui_activity a, tgui_view v, const char* const* list);


/**
 * @brief 
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
 * @return tgui_err 
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
 * @return tgui_err 
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
 * @return tgui_err 
 */
tgui_err tgui_delete_buffer(tgui_connection c, tgui_buffer* buffer);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_blit_buffer(tgui_connection c, const tgui_buffer* buffer);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_buffer(tgui_connection c, tgui_activity a, tgui_view v, const tgui_buffer* buffer);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_refresh_image_view(tgui_connection c, tgui_activity a, tgui_view v);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_select_tab(tgui_connection c, tgui_activity a, tgui_view v, unsigned int index);


/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_select_item(tgui_connection c, tgui_activity a, tgui_view v, unsigned int index);



/**
 * @brief 
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
 * @return tgui_err 
 */
tgui_err tgui_set_clickable(tgui_connection c, tgui_activity a, tgui_view v, bool clickable);






#ifdef __cplusplus
}
#endif
