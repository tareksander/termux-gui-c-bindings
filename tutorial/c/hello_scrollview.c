

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
    tgui_view l = -1, scroll = -1;
    
    
    while (true) {
        tgui_event e;
        
        tgui_wait_event(c, &e);
        if (e.type == TGUI_EVENT_RESUME) {
            tgui_err ret;
            // a NestedScrollView can make a contained LinearLayout scrollable
            ret = tgui_create_nested_scroll_view(c, a, &scroll, NULL, TGUI_VIS_VISIBLE, false, false, false);
            if (ret != TGUI_ERR_OK) {
                printf("error: %d\n", ret);
            }
            ret = tgui_create_linear_layout(c, a, &l, &scroll, TGUI_VIS_VISIBLE, false);
            if (ret != TGUI_ERR_OK) {
                printf("error: %d\n", ret);
            }
            // generate some TextViews
            for (int i = 0; i< 80; i++) {
                tgui_view tv;
                char buffer[50];
                snprintf(buffer, sizeof(buffer), "Item #%d", i);
                ret = tgui_create_text_view(c, a, &tv, &l, TGUI_VIS_VISIBLE, buffer, false, false);
                if (ret != TGUI_ERR_OK) {
                    printf("error: %d\n", ret);
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




