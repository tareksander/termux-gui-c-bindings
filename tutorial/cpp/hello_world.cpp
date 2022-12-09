
#include <termuxgui/termuxgui.hpp>

#include <unistd.h>

int main(int argc, char** argv) {
    
    
    tgui::Connection c;
	
    tgui::Activity a{c};
	a.setPiPModeAuto(true);
    
	while (true) {
		tgui::Event e;
		c.receiveEvent(e);
		if (std::holds_alternative<tgui::Events::Destroy>(e)) {
			return 0;
		}
	}
	
	
    
    return 0;
}




