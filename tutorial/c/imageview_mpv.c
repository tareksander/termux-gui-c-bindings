

#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>


#include <mpv/client.h>
#include <mpv/render.h>


mpv_render_context* mpv_rd;


void render(void* ctx) {
    uint64_t flags = mpv_render_context_update(&mpv_rd);
    if (flags & MPV_RENDER_UPDATE_FRAME) {
        
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        puts("error");
        exit(1);
    }
    
    // initialize libmpv
    mpv_handle* mpv = mpv_create();
    if (mpv == NULL) {
        puts("error");
        exit(1);
    }
    
    if (mpv_initialize(mpv) < 0) {
        puts("error");
        exit(1);
    }
    
    // create a software renderer
    mpv_render_param params[] = {
        {MPV_RENDER_PARAM_API_TYPE, MPV_RENDER_API_TYPE_SW},
        {MPV_RENDER_PARAM_ADVANCED_CONTROL, &(int){1}},
        {0}
    };
    
    if (mpv_render_context_create(&mpv_rd, mpv, params) < 0) {
        puts("error");
        exit(1);
    }
    
    
    mpv_render_context_set_update_callback(&mpv_rd, render, NULL);
    
    const char* cmd[] = {"loadfile", argv[1], NULL};
    mpv_command_async(mpv, 0, cmd);
    
    
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error");
        exit(1);
    }
    
    // Create a pip activity
    tgui_activity a;
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_PIP, NULL, false) != 0) {
        puts("error");
        exit(1);
    }
    
    tgui_activity_set_pip_mode_auto(c, a, true);
    
    tgui_view_size match_parent = {.type = TGUI_VIEW_MATCH_PARENT};
    tgui_view iv;
    if (tgui_create_image_view(c, a, &iv, NULL, TGUI_VIS_VISIBLE, false) != 0) {
        puts("error");
        exit(1);
    }
    if (tgui_set_width(c, a, iv, match_parent) != 0) {
        puts("error");
        exit(1);
    }
    
    if (tgui_set_height(c, a, iv, match_parent) != 0) {
        puts("error");
        exit(1);
    }
    
    // Go into an event loop
    while (true) {
        tgui_event e;
        bool available;
        
        tgui_poll_event(c, &e, &available);
        
        while (available) {
            // If it's a stop event, the pip window was closed
            if (e.type == TGUI_EVENT_STOP) {
                exit(0);
            }
            
            tgui_event_destroy(&e);
            tgui_poll_event(c, &e, &available);
        }
    }
    
    tgui_connection_destroy(c);
    
    return 0;
}




