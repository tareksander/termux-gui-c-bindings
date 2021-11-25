/// @file termux-gui.h

#ifndef __TERMUX_GUI_H__
#define __TERMUX_GUI_H__

#ifdef __cplusplus
extern "C" {
#endif


/**
Opens a connection to the plugin. The socket file descriptors will be placed in \p mainSocket and \p eventSocket respectively.  
Returns 0 on success, a non-zero value on error. In case of an error, the values in mainSocket and eventSocket are undefined.  
The sockets have to be manually closed with close() if the call succeeded.  
Errors:  
-1: Could not connect to the plugin.  
-2: The plugin doesn't have the same user id as the running program.
*/
int termuxgui_connect(int* mainSocket, int* eventSocket);






















#ifdef __cplusplus
}
#endif

#endif
