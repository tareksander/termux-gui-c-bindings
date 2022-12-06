
#include "bind.h"


int termuxgui__bind(int fd, struct sockaddr_un* addr, socklen_t size) {
    return bind(fd, (struct sockaddr*) addr, size);
}

