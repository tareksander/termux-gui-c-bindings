#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// this is in C because there is some kind of error with bind in C++
int bindsocket(int socket, struct sockaddr_un *adr) {
    return bind(socket, (struct sockaddr *) adr, sizeof(sa_family_t) + strnlen(adr->sun_path+1 ,100) + 1);
}



