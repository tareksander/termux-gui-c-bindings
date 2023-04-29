

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
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_NORMAL, NULL, false) != TGUI_ERR_OK) {
        puts("error");
        exit(1);
    }
    tgui_view l = -1, tv = -1, button = -1;
    
    
    while (true) {
        tgui_event e;
        
        tgui_wait_event(c, &e);
        if (e.type == TGUI_EVENT_RESUME) {
            // create the TextView, Button and layout
            tgui_err ret;
            // the LinearLayout can display views in a horizontal or vertical list
            ret = tgui_create_linear_layout(c, a, &l, NULL, TGUI_VIS_VISIBLE, false);
            if (ret != TGUI_ERR_OK) {
                printf("error: %d\n", ret);
            }
            ret = tgui_create_text_view(c, a, &tv, &l, TGUI_VIS_VISIBLE, "Hello world!", false, false);
            if (ret != TGUI_ERR_OK) {
                printf("error: %d\n", ret);
            }
            ret = tgui_create_button(c, a, &button, &l, TGUI_VIS_VISIBLE, "Press me!");
            if (ret != TGUI_ERR_OK) {
                printf("error: %d\n", ret);
            }
        }
        // If the event is click event and the button is the View...
        if (e.type == TGUI_EVENT_CLICK && e.click.id == button) {
            // ... change the text to "Goodbye world!"
            tgui_set_text(c, a, tv, "Goodbye world!");
        }
        if (e.type == TGUI_EVENT_DESTROY) {
            exit(0);
        }
        
        
        tgui_event_destroy(&e);
    }
    
    tgui_connection_destroy(c);
    
    return 0;
}




