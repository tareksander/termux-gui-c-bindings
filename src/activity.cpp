#include <unistd.h>

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <stdexcept>

#include "json.hpp"
using json = nlohmann::json;

#include "termux-gui.h"
#include "termux-gui.hpp"
#include "connection.hpp"


using namespace std;






extern "C" {
    
    
    char* tg_activity(int mainfd, int* tid, int flags) {
        json args = json::object();
        if (tid != NULL && *tid != 0) {
            args["tid"] = *tid;
        }
        if (flags & TG_ACTIVITY_DIALOG) {
            args["dialog"] = true;
        }
        if (flags & TG_ACTIVITY_PIP) {
            args["pip"] = true;
        }
        if (flags & TG_ACTIVITY_LOCKSCREEN) {
            args["lockscreen"] = true;
        }
        if (flags & TG_ACTIVITY_CANCELOUTSIDE) {
            args["canceloutside"] = true;
        }
        if (flags & TG_ACTIVITY_OVERLAY) {
            args["overlay"] = true;
        }
        json ret = sendReceiveMessageJSON(mainfd, constructMessage("newActivity", args));
        if (tid != NULL && *tid != 0) {
            return strdup(ret.get<string>().c_str());
        } else {
            if (tid != NULL) {
                *tid = ret[1].get<int>();
            }
            return strdup(ret[0].get<string>().c_str());
        }
    }
    
    
    void tg_finish_activity(int mainfd, char* aid) {
        sendMessageJSON(mainfd, constructMessage("finishActivity", {{"aid", aid}}));
    }
    
    
    
    
}



namespace tg {
    
    
    
    
    
}


