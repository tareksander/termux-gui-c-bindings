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
#include <stdexcept>

//#include <nlohmann/json.hpp>
#include "json.hpp"
using json = nlohmann::json;

#include "termux-gui.h"
#include "termux-gui.hpp"


using namespace std;









