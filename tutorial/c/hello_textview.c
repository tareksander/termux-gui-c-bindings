

#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>


int main() {
    
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error");
        exit(1);
    }
    
    
    tgui_activity a;
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_NORMAL, NULL, false) != 0) {
        puts("error");
        exit(1);
    }
    
    // A variable to hold the TextView id.
    // IDs are never negative, so you can use that for an invalid id.
    tgui_view tv = -1;
    while (true) {
        tgui_event e;
        tgui_wait_event(c, &e);
        
        // When the Activity is created, we can start putting Views in it
        if (e.type == TGUI_EVENT_CREATE) {
            if (tv == -1) {
                // Create a TextView with text "Hello World!"
                if (tgui_create_text_view(c, a, &tv, NULL, TGUI_VIS_VISIBLE, "Hello World!", false, false) != 0) {
                    puts("error");
                    exit(1);
                }
            }
        }
        
        if (e.type == TGUI_EVENT_DESTROY) {
            exit(0);
        }
        
        tgui_event_destroy(&e);
    }
    
    tgui_connection_destroy(c);
    
    return 0;
}




