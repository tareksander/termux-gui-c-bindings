

#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>


int main() {
    
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error");
        exit(1);
    }
    
    // Create a normal activity, in no existing task (there is none)
    // that doesn't intercept the back button (and lets the activity exit then by default).
    tgui_activity a;
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_NORMAL, NULL, false) != 0) {
        puts("error");
        exit(1);
    }
    
    // Go into an event loop
    while (true) {
        tgui_event e;
        // Polling for events blocks until one is available
        tgui_wait_event(c, &e);
        
        // If it's a destroy event, our Activity was destroyed by the user, and we should exit.
        if (e.type == TGUI_EVENT_DESTROY) {
            exit(0);
        }
        
        // Always destroy the event, in case the event type used dynamically allocated memory.
        tgui_event_destroy(&e);
    }
    
    tgui_connection_destroy(c);
    
    return 0;
}




