/// @file termux-gui.h

#ifndef __TERMUX_GUI_H__
#define __TERMUX_GUI_H__

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

/** All possible event types. */
enum tg_event_t {
    TG_EVENT_INVALID, ///< This marks that the event had an unsupported type
    TG_EVENT_CREATE, ///< valid event parameters: \p aid
    TG_EVENT_START, ///< valid event parameters: \p aid
    TG_EVENT_RESUME, ///< valid event parameters: \p aid
    TG_EVENT_PAUSE, ///< valid event parameters: \p aid , \p finishing
    TG_EVENT_STOP, ///< valid event parameters: \p aid , \p finishing
    TG_EVENT_DESTROY ///< valid event parameters: \p aid , \p finishing
};

typedef struct {
    enum tg_event_t type;
    union {
        struct {
            char* aid; ///< The Activity id as a string. If this field is valid, it has to be freed with free().
            bool finishing; ///< determines if the Activity is finishing. Is only guranteed to be accurate for \p TG_EVENT_DESTROY .
        };
    };
} tg_event;



/**
Opens a connection to the plugin. The socket file descriptors will be placed in \p mainSocket and \p eventSocket respectively.  
Returns 0 on success, a non-zero value on error. In case of an error, the values in mainSocket and eventSocket are undefined.  
The sockets have to be manually closed with close() if the call succeeded.  
Errors:  
-1: Could not connect to the plugin.  
-2: The plugin doesn't have the same user id as the running program.
*/
int tg_connect(int* mainSocket, int* eventSocket);



/**
Brings Termux to the foreground by forking and calling \p am \p start .
*/
void tg_totermux();



/** Sends a Toast. Set \p longer to true if you want to display the text for longer. */
void tg_toast(int mainfd, const char* text, bool longer);

/** Blocks until an event is available. */
tg_event tg_getevent(int eventfd);












#ifdef __cplusplus
}
#endif

#endif
