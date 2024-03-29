#pragma once



/**
 * \mainpage Termux:GUI C/C++ Bindings
 * 
 * This is the documentation for the Termux:GUI C/C++ bindings.  
 * 
 * See [termuxgui.h](termuxgui_8h.html) for the C documentation<!-- and the [tgui namespace](namespacetgui.html) for the C++ documentation-->.
 */


/**
 * @file
 * @brief This is the C API of the library.<br>For an introduction in how the use the API, see [the Tutorial](https://github.com/tareksander/termux-gui-c-bindings/blob/main/TUTORIAL.md#c-tutorial).<br>
 * 
 * @details
 * Functions return an error code. If the code is <= 0, the operation was a success and the out parameters are valid.
 * For codes > 0, the out parameters have to be treated as invalid.
 * <br><br>
 * Functions that get only value types, a tgui_connection or const pointers can be called concurrently.
 * Functions that get mutable pointers to different memory locations can be called concurrently.
 * One exception is tgui_connection_destroy, make sure no other thread uses the connection before calling.
 * <br><br>
 * See the included headers for documentation of the related functions.
 * 
 */

#include "types.h"

#include "connection.h"
#include "activity.h"
#include "create.h"
#include "views.h"
#include "webview.h"
#include "remote.h"
#include "notification.h"
#include "events.h"
#include "hardware_buffer.h"
