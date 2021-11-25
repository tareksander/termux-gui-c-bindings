#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>


int bindsocket(int socket, struct sockaddr_un *adr) {
    return bind(socket, (struct sockaddr *) adr, sizeof(struct sockaddr_un));
}



