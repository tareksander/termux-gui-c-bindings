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
#include <stdexcept>


#include "json.hpp"
using json = nlohmann::json;

#include "termux-gui.h"
#include "termux-gui.hpp"
#include "connection.hpp"


using namespace std;

static const char SOCKNAME_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
#define SOCKNAME_LENGTH 80



static struct sockaddr_un generateSocketName() {
    std::default_random_engine gen;
    gen.seed(getpid());
    std::uniform_int_distribution<int> randchar(0,sizeof(SOCKNAME_CHARS)-1); // -1 for the null byte at the end
    string name;
    for (int i = 0;i<SOCKNAME_LENGTH;i++) {
        name += SOCKNAME_CHARS[randchar(gen)];
    }
    struct sockaddr_un adr { AF_UNIX }; // sun_path is automatically zeroed
    strncpy(adr.sun_path+1, name.c_str(), SOCKNAME_LENGTH);
    return adr;
}

static int callAm(char* const mainname, char* const eventname) {
    pid_t ret = fork();
    if (ret == 0) {
        // if am doesn't not work, it's probably because it can't report to stdout
        fclose(stdout);
        fclose(stderr);
        const char* const args[] = {
            "am",
            "broadcast",
            "-n",
            "com.termux.gui/.GUIReceiver",
            "--es",
            mainname,
            "--es",
            eventname,
            NULL
        };
        execvp("am", const_cast<char* const*>(args));
        exit(1);
    } else {
        int status;
        waitpid(ret, &status, 0);
        return WEXITSTATUS(status);
    }
    return 1;
}


static int transmitbuffer(int fd, const void* buffp, int len) {
    const char* buff = reinterpret_cast<const char*>(buffp);
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


int sendMessage(int fd, const void* msg, int len) {
    uint32_t msgsize = htonl(len);
    if (transmitbuffer(fd, &msgsize, 4) != 0) {
        return -1;
    }
    if (transmitbuffer(fd, msg, len) != 0) {
        return -1;
    }
    return 0;
}

void sendMessageJSON(int fd, json msg) {
    string msg_str = msg.dump();
    if (sendMessage(fd, msg_str.c_str(), msg_str.length()) != 0) {
        throw runtime_error("Could not send message");
    }
}


// returns 0 on success, -1 if data could not be read from the socket and -2 if the buffer was too small
int receiveMessage(int fd, char* buff, int buffsize) {
    volatile uint32_t size;
    volatile char* buffp = reinterpret_cast<volatile char*>(&size);
    int togo = 4;
    while (togo > 0) {
        size_t ret = read(fd, const_cast<char*>(buffp), togo);
        if (ret != 0) {
            return 1;
        }
        togo -= ret;
        buffp += ret;
    }
    size = ntohl(size);
    togo = size;
    if (togo >= buffsize) { // >= because there has to be a null byte, because it is a string
        return 2;
    }
    buffp = buff;
    while (togo > 0) {
        size_t ret = read(fd, const_cast<char*>(buffp), togo);
        if (ret != 0) {
            return 1;
        }
        togo -= ret;
        buffp += ret;
    }
    *buffp = '\0'; // buffp now points to the character after the message, so we have to end the string with a null byte
    return 0;
}

json receiveMessageJSON(int fd) {
    static char buff[1024*64]; // 64KiB should be enough for any JSON message from the plugin
    int ret = receiveMessage(fd, buff, sizeof(buff));
    switch (ret) {
        case 0:
            return json::parse(buff);
        case 2:
            throw runtime_error("Message buffer too small");
        default:
            throw runtime_error("Could not receive Message");
    }
}



json sendReceiveMessageJSON(int fd, json msg) {
    sendMessageJSON(fd, msg);
    return receiveMessageJSON(fd);
}


extern "C" {
    int termuxgui_connect(int* mainSocket, int* eventSocket) {
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
        struct sockaddr_un mainname;
        struct sockaddr_un eventname;
        int tries = 0;
        while (true) {
            if (tries >= 10) {
                close(mainfd);
                close(eventfd);
                return -1;
            }
            mainname = generateSocketName();
            if (bind(mainfd, reinterpret_cast<struct sockaddr*>(&mainname), sizeof(struct sockaddr_un)) == 0) {
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
            if (bind(eventfd, reinterpret_cast<struct sockaddr*>(&eventname), sizeof(struct sockaddr_un)) == 0) {
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
        *mainSocket = accept(mainfd, NULL, NULL);
        if (*mainSocket == -1) {
            close(mainfd);
            close(eventfd);
            return -1;
        }
        *eventSocket = accept(eventfd, NULL, NULL);
        if (*eventSocket == -1) {
            close(*mainSocket);
            close(mainfd);
            close(eventfd);
            return -1;
        }
        socklen_t optlen = sizeof(struct ucred);
        // check if it is really the plugin that has connected (same UID)
        struct ucred cred;
        if (getsockopt(*mainSocket, SOL_SOCKET, SO_PEERCRED, &cred, &optlen) == -1 || cred.uid != getuid()) {
            close(*mainSocket);
            close(*eventSocket);
            close(mainfd);
            close(eventfd);
            return -2;
        }
        if (getsockopt(*eventSocket, SOL_SOCKET, SO_PEERCRED, &cred, &optlen) == -1 || cred.uid != getuid()) {
            close(*mainSocket);
            close(*eventSocket);
            close(mainfd);
            close(eventfd);
            return -2;
        }
        // set the protocol
        const uint8_t protocol = 1;
        int ret;
        while ((ret = write(*mainSocket, &protocol, 1)) == 0) {}
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




namespace termuxgui {
    Connection::Connection() {
        int ret = termuxgui_connect(&this->mainfd, &this->eventfd);
        switch (ret) {
            case 0:
                return;
            case -2:
                throw runtime_error("The plugin doesn't have the same uid.");
            default:
                throw runtime_error("Could not connect to the plugin.");
        }
    }
    
    Connection::~Connection() {
        if (this->mainfd != 0) {
            close(this->mainfd);
        }
        if (this->eventfd != 0) {
            close(this->eventfd);
        }
    }
    
    
}






