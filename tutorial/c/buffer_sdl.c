#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <SDL2/SDL.h>

int main() {
    
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error connection create\n");
        exit(1);
    }
    
    tgui_activity a;
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_NORMAL, NULL, false) != 0) {
        puts("error activity create\n");
        exit(1);
    }
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        puts("error sdl init\n");
        exit(1);
    }
    
    tgui_view iv = -1;
    // Create a buffer description for a 500x500 buffer with the ARGB8888 format.
    tgui_buffer b = {
        .width = 500,
        .height = 500,
        .format = TGUI_BUFFER_FORMAT_ARGB8888
    };
    // Create the buffer
    if (tgui_add_buffer(c, &b) != 0) {
        puts("error addbuffer\n");
        exit(1);
    }
    // Create a SDL_Surface with the buffer as the backing storage
    SDL_Surface* bs = SDL_CreateRGBSurfaceFrom(b.data, b.width, b.height, 32, 4*b.width, 0xff, 0xff << 8, 0xff << 16, 0xff << 24);
    if (bs == NULL) {
        puts("error sdl surface\n");
        exit(1);
    }
    // clear the buffer
    SDL_FillRect(bs, NULL, 0xffffff);
    
    // animation progress
    int prog = 0;
    
    // pause when the Activity isn't visible
    bool paused = true;
    time_t start = time(NULL);
    while (true) {
        tgui_event e;
        bool available;
        if (tgui_poll_event(c, &e, &available) != 0) {
            puts("error poll\n");
            exit(1);
        }
        if (available) {
            
            if (e.type == TGUI_EVENT_CREATE) {
                // Activity created, we can create the ImageView and set the buffer now
                if (iv == -1) {
                    if (tgui_create_image_view(c, a, &iv, NULL, TGUI_VIS_VISIBLE, false) != 0) {
                        puts("error create imageview\n");
                        exit(1);
                    }
                    if (tgui_set_buffer(c, a, iv, &b) != 0) {
                        puts("error setbuffer\n");
                        exit(1);
                    }
                }
                paused = false;
            }
            if (e.type == TGUI_EVENT_PAUSE) {
                paused = true;
            }
            
            if (e.type == TGUI_EVENT_DESTROY) {
                exit(0);
            }
            
            tgui_event_destroy(&e);
        }
        // Exit after 10 seconds
        if (time(NULL) - start >= 10) break;
        // if the ImageVIew is created and we aren't paused, render the animation
        if (iv != -1 && ! paused) {
            // let a red rectangle travel from the upper left corner to the lower right and back
            int posOld;
            if (prog < 400) {
                posOld = prog;
            } else {
                posOld = 800 - prog;
            }
            const SDL_Rect rectOld = {
                .x = posOld,
                .y = posOld,
                .w = 50,
                .h = 50,
            };
            prog++;
            prog = prog % 800;
            // erase the old rectangle
            SDL_FillRect(bs, &rectOld, 0xffffff);
            int pos;
            if (prog < 400) {
                pos = prog;
            } else {
                pos = 800 - prog;
            }
            const SDL_Rect rect = {
                .x = pos,
                .y = pos,
                .w = 50,
                .h = 50,
            };
            // draw the new rectangle
            SDL_FillRect(bs, &rect, 0xff);
            // show the buffer in the ImageView
            if (tgui_blit_buffer(c, &b) != 0 || tgui_refresh_image_view(c, a, iv) != 0) {
                puts("error buffer blit\n");
                exit(1);
            }
        }
        usleep(10000);
    }
    
    tgui_connection_destroy(c);
    SDL_Quit();
    
    return 0;
}




