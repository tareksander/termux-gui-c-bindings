
#include <termuxgui/termuxgui.hpp>

#include <termuxgui/textview.hpp>

#include <unistd.h>

#include <iostream>

int main(int argc, char** argv) {
    
    
    tgui::Connection c;
	
    tgui::Activity a{c};
	
	tgui::TextView tv(a, nullptr, "Hello World!");
    
	while (true) {
		tgui::Event e;
		c.receiveEvent(e);
		if (std::holds_alternative<tgui::Events::Destroy>(e)) {
			return 0;
		}
	}
	
	
    
    return 0;
}




