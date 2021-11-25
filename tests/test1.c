
#include <termux-gui.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int mainfd, eventfd;
    
    if (tg_connect(&mainfd, &eventfd) != 0) {
        perror("Could not connect to the plugin");
        exit(0);
    }
    
    tg_activity(mainfd, NULL, 0);
    
    
    sleep(5);
    
    return 0;
}




 
