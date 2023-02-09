#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <SDL2/SDL.h>

int main() {
    
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error connection\n");
        exit(1);
    }
    
    tgui_activity a;
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_NORMAL, NULL, false) != 0) {
        puts("error activity\n");
        exit(1);
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        puts("error sdl\n");
        exit(1);
    }
    
    tgui_view iv = -1;
    
    tgui_buffer b = {
        .width = 500,
        .height = 500,
        .format = TGUI_BUFFER_FORMAT_ARGB8888
    };
    
    if (tgui_add_buffer(c, &b) != 0) {
        puts("error buffer\n");
        exit(1);
    }
    
    SDL_Surface* bs = SDL_CreateRGBSurfaceFrom(b.data, b.width, b.height, 32, 4*b.width, 0xff, 0xff << 8, 0xff << 16, 0xff << 24);
    if (bs == NULL) {
        puts("error surface\n");
        exit(1);
    }
    SDL_FillRect(bs, NULL, 0xffffff);
    
    
    int prog = 0;
    
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
                if (iv == -1) {
                    if (tgui_create_image_view(c, a, &iv, NULL, TGUI_VIS_VISIBLE, false) != 0) {
                        puts("error imageview\n");
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
        if (time(NULL) - start >= 10) break;
        if (iv != -1 && ! paused) {
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
            SDL_FillRect(bs, &rect, 0xff);
            if (tgui_blit_buffer(c, &b) != 0 || tgui_refresh_image_view(c, a, iv) != 0) {
                puts("error blit\n");
                exit(1);
            }
        }
        usleep(10000);
    }
    
    tgui_connection_destroy(c);
    SDL_Quit();
    
    return 0;
}




