#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "json.hpp"
using json = nlohmann::json;


int sendMessage(int fd, const void* msg, int len);

void sendMessageJSON(int fd, json msg);


int receiveMessage(int fd, char* buff, int buffsize);

json receiveMessageJSON(int fd);


json sendReceiveMessageJSON(int fd, json msg);



#endif
