

#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>


#include <mpv/client.h>
#include <mpv/render.h>


mpv_render_context* mpv_rd;
tgui_connection c;
tgui_activity a;
tgui_view iv = -1;
tgui_buffer b = {
    .width = 500,
    .height = 500,
    .format = TGUI_BUFFER_FORMAT_ARGB8888
};


void render(void* ctx) {
    uint64_t flags = mpv_render_context_update(mpv_rd);
    if (flags & MPV_RENDER_UPDATE_FRAME) {
        int stride = 500*4;
        mpv_render_param params[] = {
            {MPV_RENDER_PARAM_SW_SIZE, (int[2]){500, 500}},
            {MPV_RENDER_PARAM_SW_FORMAT, "0bgr"},
            {MPV_RENDER_PARAM_SW_STRIDE, &stride},
            {MPV_RENDER_PARAM_SW_POINTER, b.data},
            {0}
        };
        if (mpv_render_context_render(mpv_rd, params) < 0) {
            puts("error render\n");
            exit(1);
        }
        if (tgui_blit_buffer(c, &b) != 0 || tgui_refresh_image_view(c, a, iv) != 0) {
            puts("error blit\n");
            exit(1);
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        puts("error args");
        exit(1);
    }
    
    // initialize libmpv
    mpv_handle* mpv = mpv_create();
    if (mpv == NULL) {
        puts("error mpv");
        exit(1);
    }
    
    if (mpv_initialize(mpv) < 0) {
        puts("error mpvi");
        exit(1);
    }
    
    // create a software renderer
    mpv_render_param params[] = {
        {MPV_RENDER_PARAM_API_TYPE, MPV_RENDER_API_TYPE_SW},
        {MPV_RENDER_PARAM_ADVANCED_CONTROL, &(int){1}},
        {0}
    };
    
    if (mpv_render_context_create(&mpv_rd, mpv, params) < 0) {
        puts("error rc");
        exit(1);
    }
    
    
    mpv_render_context_set_update_callback(mpv_rd, render, NULL);
    
    const char* cmd[] = {"loadfile", argv[1], NULL};
    mpv_command_async(mpv, 0, cmd);
    
    
    if (tgui_connection_create(&c) != 0) {
        puts("error c");
        exit(1);
    }
    
    // Create a pip activity
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_PIP, NULL, false) != 0) {
        puts("error a");
        exit(1);
    }
    
    tgui_activity_set_pip_mode_auto(c, a, true);
    
    
    if (tgui_add_buffer(c, &b) != 0) {
        puts("error buffer\n");
        exit(1);
    }
    
    
    // Go into an event loop
    while (true) {
        tgui_event e;
        bool available;
        
        tgui_poll_event(c, &e, &available);
        
        while (available) {
            if (e.type == TGUI_EVENT_CREATE) {
                if (iv == -1) {
                    if (tgui_create_image_view(c, a, &iv, NULL, TGUI_VIS_VISIBLE, false) != 0) {
                        puts("error imageview");
                        exit(1);
                    }
                    if (tgui_set_buffer(c, a, iv, &b) != 0) {
                        puts("error setbuffer\n");
                        exit(1);
                    }
                }
            }
            
            
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




