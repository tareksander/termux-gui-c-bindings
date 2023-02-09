

#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>


int main() {
    
    // Create a connection to the plugin
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error");
        exit(1);
    }
    
    // Display a hello world message
    tgui_toast(c, "Hello World!", false);
    
    // Destroy the connection, although that's not needed when you exit after that,
    // the plugin cleans up after exited programs itself.
    tgui_connection_destroy(c);
    
    return 0;
}




