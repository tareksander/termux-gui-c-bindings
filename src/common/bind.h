#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#ifdef __cplusplus
extern "C" {
#endif

// this is needed because there seems to be a name collision for bionic __bind and the definition in c++ <functional>
int termuxgui__bind(int fd, struct sockaddr_un* addr, socklen_t size);

#ifdef __cplusplus
}
#endif
