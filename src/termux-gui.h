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
 * Opens a connection to the plugin. The socket file descriptors will be placed in \p mainSocket and \p eventSocket respectively.  
 * Returns 0 on success, a non-zero value on error. In case of an error, the values in mainSocket and eventSocket are undefined.  
 * The sockets have to be manually closed with close() if the call succeeded.  
 * Errors:  
 * -1: Could not connect to the plugin.  
 * -2: The plugin doesn't have the same user id as the running program.
 */
int tg_connect(int* mainSocket, int* eventSocket);



/**
 * Brings Termux to the foreground by forking and calling \p am \p start .
 */
void tg_totermux();



/** Sends a Toast. Set \p longer to true if you want to display the text for longer. */
void tg_toast(int mainfd, const char* text, bool longer);

/** Blocks until an event is available. */
tg_event tg_getevent(int eventfd);




#define TG_ACTIVITY_DIALOG 1 ///< This makes the Activity a dialog
#define TG_ACTIVITY_PIP (1<<1) ///< This starts the Activity in picture-in-picture mode
#define TG_ACTIVITY_LOCKSCREEN (1<<2) ///< This makes the Activity available on the lockscreen
#define TG_ACTIVITY_CANCELOUTSIDE (1<<3) ///< This makes the Activity finish itself when a touch outside of it is detected if it is a dialog
#define TG_ACTIVITY_OVERLAY (1<<4) ///< This makes the Activity an overlay over everything


/**
 * Creates an activity and returns the id as a string. Returns NULL on failure.
 * The string has to be freed with free().
 * If the Activity should be started in an existing Task, use the Task id for \p tid , otherwise set \p tid to NULL.
 * If \p tid is not NULL and \p *tid is 0, the Task id will be placed in \p tid.
 * Use \p flags to configure the Activity, use a bitwise-or of the TG_ACTIVITY_* values.
 */
char* tg_activity(int mainfd, int* tid, int flags);


/** Finishes the Activity with the given Activity id. */
void tg_finish_activity(int mainfd, char* aid);






#ifdef __cplusplus
}
#endif

#endif
