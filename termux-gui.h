



// opens a connection to the plugin. The socket file descriptors will be placed in mainSocket and eventSocket respectively.
// returns 0 on success, -1 on error. In case of an error, the values in mainSocket and eventSocket are undefined.
// The sockets have to be manually closed with close().
int termuxgui_connect(int* mainSocket, int* eventSocket);





















