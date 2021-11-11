#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#include <random>
#include <string>
#include <vector>

//#include <nlohmann/json.hpp>
#include "json.hpp"
using json = nlohmann::json;

#include "termux-gui.h"
#include "termux-gui.hpp"

using namespace std;

static const char SOCKNAME_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
#define SOCKNAME_LENGTH 80

static struct sockaddr_un generateSocketName() {
    std::default_random_engine gen;
    gen.seed(getpid());
    std::uniform_int_distribution<int> randchar(0,sizeof(SOCKNAME_CHARS)-1); // -1 for the null byte at the end
    String name;
    for (int i = 0;i<SOCKNAME_LENGTH;i++) {
        name.append(randchar(gen));
    }
    struct sockaddr_un adr { AF_UNIX }; // sun_path is automatically zeroed
    String name = generateSocketName();
    strncpy(adr.sun_path+1, name.c_str(), SOCKNAME_LENGTH);
    return adr;
}

static int callAm(const char* mainname, const char* eventname) {
    pid_t ret = fork();
    if (ret == 0) {
        // if am doesn't not work, it's probably because it can't report to stdout
        fclose(stdout);
        fclose(stderr);
        const char* args[] = {
            "am",
            "broadcast",
            "-n",
            "com.termux.gui/.GUIReceiver",
            "--es",
            mainname,
            "--es",
            eventname,
            NULL
        }
        execvp("am", args);
        exit(1);
    } else {
        int status;
        waitpid(ret, &status, 0);
        return WEXITSTATUS(status);
    }
    return 1;
}


static int transmitbuffer(int fd,const void* buff,int len) {
    while (len > 0) {
        int ret = write(fd, buff, len);
        if (ret < 0) {
            return -1;
        }
        len -= ret;
        buff += ret;
    }
    return 0;
}


static int sendmessage(int fd, String msg) {
    uint32_t msgsize = htonl(msg.length());
    if (transmitbuffer(fd, &msgsize, 4) != 0) {
        return -1;
    }
    if (transmitbuffer(fd, msg.c_str(), msgsize) != 0) {
        return -1;
    }
    return 0;
}




// TODO instead uf using a vector, use a string, size it correctly and fill the data into c_str
static String receiveMessage(int fd, bool* success) {
    vector<uint8_t> buff;
    uint32_t size;
    void* buffp = &size;
    int togo = 4;
    while (togo > 0) {
        site_t ret = read(fd, buffp, togo);
        if (ret != 0) {
            success = false;
            return "";
        }
        togo -= ret;
        buffp += ret;
    }
    int read = 0;
    size = ntohl(size);
    togo = size;
    buff.resize(togo);
    buffp = buff.data();
    while (togo > 0) {
        site_t ret = read(fd, buffp, togo);
        if (ret != 0) {
            success = false;
            return "";
        }
        togo -= ret;
        buffp += ret;
    }
    success = true;
    return String(reinterpret_cast<char*>(buffp), 0, size);
}





// C++ interface
namespace termuxgui {
    
    int connect(int* mainSocket, int* eventSocket) {
        return termuxgui_connect(mainSocket, eventSocket);
    }
    
    
    
    
    
    
}


// C interface
extern "C" {
    
    int connect(int* mainSocket, int* eventSocket) {
        // create 2 Unix sockets
        int mainfd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (mainfd == -1) {
            return -1;
        }
        int eventfd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (eventfd == -1) {
            close(mainfd);
            return -1;
        }
        // try to bind them to a name
        struct sockaddr_un adr mainname;
        struct sockaddr_un adr eventname;
        int tries = 0;
        while (true) {
            if (tries >= 10) {
                close(mainfd);
                close(eventfd);
                return -1;
            }
            mainname = generateSocketName();
            if (bind(mainfd, mainname, sizeof(struct sockaddr_un)) == 0) {
                break;
            } else {
                if (errno == EBADF || errno == EINVAL || ENOTSOCK) {
                    close(mainfd);
                    close(eventfd);
                    return -1;
                }
            }
            tries++;
        }
        tries = 0;
        while (true) {
            if (tries >= 10) {
                close(mainfd);
                close(eventfd);
                return -1;
            }
            eventname = generateSocketName();
            if (bind(eventfd, eventname, sizeof(struct sockaddr_un)) == 0) {
                break;
            } else {
                if (errno == EBADF || errno == EINVAL || ENOTSOCK) {
                    close(mainfd);
                    close(eventfd);
                    return -1;
                }
            }
            tries++;
        }
        // listen on the sockets
        if (listen(mainfd, 1) == -1) {
            close(mainfd);
            close(eventfd);
            return -1;
        }
        if (listen(eventfd, 1) == -1) {
            close(mainfd);
            close(eventfd);
            return -1;
        }
        // contact the plugin via a broadcast
        if (callAm(mainname.sun_path+1, eventname.sun_path+1) != 0) {
            close(mainfd);
            close(eventfd);
            return -1;
        }
        // accept the connection
        *mainSocket = accept(mainfd, NULL, NULL, 0);
        if (*mainSocket == -1) {
            close(mainfd);
            close(eventfd);
            return -1;
        }
        *eventSocket = accept(eventfd, NULL, NULL, 0);
        if (*eventSocket == -1) {
            close(*mainSocket);
            close(mainfd);
            close(eventfd);
            return -1;
        }
        // check if it is really the plugin that has connected (same UID)
        struct ucred cred;
        if (getsockopt(*mainSocket, SOL_SOCKET, SO_PEERCRED, &cred, sizeof(struct ucred)) == -1 || cred.uid != getuid()) {
            close(*mainSocket);
            close(*eventSocket);
            close(mainfd);
            close(eventfd);
            return -1;
        }
        if (getsockopt(*eventSocket, SOL_SOCKET, SO_PEERCRED, &cred, sizeof(struct ucred)) == -1 || cred.uid != getuid()) {
            close(*mainSocket);
            close(*eventSocket);
            close(mainfd);
            close(eventfd);
            return -1;
        }
        // set the protocol
        const uni8_t protocol = 1;
        int ret;
        while ((ret = write(*mainSocket, &protcol, 1)) == 0) {}
        if (ret == -1) {
            close(*mainSocket);
            close(*eventSocket);
            close(mainfd);
            close(eventfd);
            return -1;
        }
        // and discard the response
        uint8_t b;
        while ((ret = write(*mainSocket, &b, 1)) == 0) {}
        if (ret == -1) {
            close(*mainSocket);
            close(*eventSocket);
            close(mainfd);
            close(eventfd);
            return -1;
        }
        // close the server sockets
        close(mainfd);
        close(eventfd);
        return 0;
    }
    
    
    
    
}

