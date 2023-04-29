#pragma once

#include "types.h"

/**
 * @file
 * @brief This file contains functions related to accelerated rendering using SurfaceViews.
 * 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif



/**
 * @brief Create an AHardwareBuffer shared with the plugin.
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
 * @param[out] buffer The buffer to create.
 * @param format The pixel format for the buffer.
 * @param width The width of the buffer.
 * @param height The height of the buffer.
 * @param read How often the CPU will read the buffer.
 * @param write How often the CPU will write to the buffer.
 * @return tgui_err The error code. 
 */
tgui_err tgui_hardware_buffer_create(tgui_connection c, tgui_hardware_buffer* buffer, tgui_hardware_buffer_format format, uint32_t width, uint32_t height, tgui_hardware_buffer_cpu_frequency read, tgui_hardware_buffer_cpu_frequency write);


/**
 * @brief Destroys a shared AHardwareBuffer. You also have to destroy any EGLImages or other mappings.
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
 * @param[out] buffer The buffer to destroy.
 * @return tgui_err The error code. 
 */
tgui_err tgui_hardware_buffer_destroy(tgui_connection c, tgui_hardware_buffer* buffer);





/**
 * @brief Sets the buffer displayed in a SurfaceView.
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
 * @param v The SurfaceView.
 * @param[in] buffer The buffer to show.
 * @return tgui_err The error code. 
 */
tgui_err tgui_surface_view_set_buffer(tgui_connection c, tgui_activity a, tgui_view v, tgui_hardware_buffer* buffer);


/**
 * @brief Configures the behaviour of a SurfaceView.
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
 * @param v The SurfaceView.
 * @param background_color The color that fills the rest of the SurfaceView in case the buffer is too small.
 * @param x The behaviour on x axis buffer size mismatch.
 * @param y The behaviour on y axis buffer size mismatch.
 * @param framerate The targeted framerate, for Android 11 and higher.
 * @return tgui_err The error code. 
 */
tgui_err tgui_surface_view_config(tgui_connection c, tgui_activity a, tgui_view v, tgui_color background_color, tgui_surface_view_dimension_mismatch x, tgui_surface_view_dimension_mismatch y, float framerate);








#ifdef __cplusplus
}
#endif

