#pragma once

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif




/**
 * @brief Creates a LinearLayout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param horizontal Whether the LinearLayout should place its children vertically or horizontally.
 * @return tgui_err 
 */
tgui_err tgui_create_linear_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool horizontal);


/**
 * @brief Creates a FrameLayout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_frame_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);


/**
 * @brief Creates a SwipeRefreshLayout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_swipe_refresh_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);


/**
 * @brief Creates a TextView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param[in] text The initial text. NULL is the same as the empty string.
 * @param selectableText Whether the text is selectable by the user.
 * @param clickableLinks Whether links are clickable and open a browser.
 * @return tgui_err 
 */
tgui_err tgui_create_text_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, bool selectableText, bool clickableLinks);


/**
 * @brief 
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param[in] text The initial text. NULL is the same as the empty string.
 * @param type The input type. This adjusts the soft keyboard to show relevant keys.
 * @param noline By default a line is shown under the text in an EditText. This parameter can be used to prevent that.
 * @return tgui_err 
 */
tgui_err tgui_create_edit_text(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, tgui_edit_text_type type, bool noLine);


/**
 * @brief Creates a Button.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param[in] text The text. NULL is the same as the empty string.
 * @return tgui_err 
 */
tgui_err tgui_create_button(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text);


/**
 * @brief Creates an ImageView
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param keyboard Whether the ImageView should get events from the keyboard.
 * @return tgui_err 
 */
tgui_err tgui_create_image_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool keyboard);


/**
 * @brief Creates a Space (invisible View for layout purposes).
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_space(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);


/**
 * @brief Creates a NestedScrollView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param snapping Whether the View snaps to the nearest child.
 * @param noBar Whether to show the scrollbar.
 * @return tgui_err 
 */
tgui_err tgui_create_nested_scroll_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool snapping, bool noBar, bool fillViewport);


/**
 * @brief Creates a HorizontalScrollView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param snapping Whether the View snaps to the nearest child.
 * @param noBar Whether to show the scrollbar.
 * @return tgui_err 
 */
tgui_err tgui_create_horizontal_scroll_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool snapping, bool noBar, bool fillViewport);


/**
 * @brief Creates a RadioGroup.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_radio_group(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);


/**
 * @brief Creates a RadioButton.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param[in] text The text. NULL is the same as the empty string.
 * @param checked Whether the View should be created checked or unchecked.
 * @return tgui_err 
 */
tgui_err tgui_create_radio_button(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, bool checked);


/**
 * @brief Creates a CheckBox.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param[in] text The text. NULL is the same as the empty string.
 * @param checked Whether the View should be created checked or unchecked.
 * @return tgui_err 
 */
tgui_err tgui_create_checkbox(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, const char* text, bool checked);


/**
 * @brief Creates a ToggleButton.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param checked Whether the View should be created checked or unchecked.
 * @return tgui_err 
 */
tgui_err tgui_create_toggle_button(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool checked);


/**
 * @brief Creates a Switch.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param checked Whether the View should be created checked or unchecked.
 * @return tgui_err 
 */
tgui_err tgui_create_switch(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, bool checked);


/**
 * @brief Creates a Spinner.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_spinner(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);


/**
 * @brief Creates a ProgressBar.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_progress_bar(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);


/**
 * @brief Creates a TabLayout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_tab_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);


/**
 * @brief Creates a GridLayout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @param rows The number of rows.
 * @param col The number of columns.
 * @return tgui_err 
 */
tgui_err tgui_create_grid_layout(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis, uint32_t rows, uint32_t cols);


/**
 * @brief Creates a WebView.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 *  - TGUI_ERR_ACTIVITY_DESTROYED: The Activity was already closed.
 * 
 * @param c The connection to use.
 * @param a The Activity the new View should be in.
 * @param[out] v The new View.
 * @param parent The optional parent layout of the View.
 * @return tgui_err 
 */
tgui_err tgui_create_web_view(tgui_connection c, tgui_activity a, tgui_view* v, const tgui_view* parent, tgui_view_visibility vis);






#ifdef __cplusplus
}
#endif
