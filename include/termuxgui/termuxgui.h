#pragma once

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
 * 
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

