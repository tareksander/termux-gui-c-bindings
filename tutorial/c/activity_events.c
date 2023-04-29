

#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>


int main() {
    
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error create connection");
        exit(1);
    }
    
    
    // The last parameter specifies that back button presses should be intercepted
    tgui_activity a;
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_NORMAL, NULL, true) != 0) {
        puts("error create activity");
        exit(1);
    }
    
    
    
    while (true) {
        tgui_event e;
        tgui_wait_event(c, &e);
        
        
        if (e.type == TGUI_EVENT_DESTROY) {
            exit(0);
        }
        
        if (e.type == TGUI_EVENT_START) {
            // intercept both volume up and down
            if (tgui_activity_intercept_volume_buttons(c, a, true, true) != 0) {
                puts("error intercept volume");
                exit(1);
            }
            // hide the top and bottom bars, and show them temporarily on a swipe
            if (tgui_activity_configure_insets(c, a, TGUI_INSET_NONE, TGUI_INSET_BEHAVIOUR_TRANSIENT) != 0) {
                puts("error configure insets");
                exit(1);
            }
        }
        
        if (e.type == TGUI_EVENT_BACK) {
            printf("Back button pressed!\n");
        }
        if (e.type == TGUI_EVENT_VOLUME) {
            if (e.volume.released) {
                if (e.volume.volume_up) {
                    printf("Volume up released!\n");
                } else {
                    printf("Volume down released!\n");
                }
            } else {
                if (e.volume.volume_up) {
                    printf("Volume up pressed!\n");
                } else {
                    printf("Volume down pressed!\n");
                }
            }
        }
        
        tgui_event_destroy(&e);
    }
    
    tgui_connection_destroy(c);
    
    return 0;
}




