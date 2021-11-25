/// @file termux-gui.hpp

#ifndef __TERMUX_GUI_HPP__
#define __TERMUX_GUI_HPP__


// include nlohmann-json if available

#if __has_include(<nlohmann/json.hpp>)
#include <nlohmann/json.hpp>
#endif

#if __has_include("json.hpp")
#include "json.hpp"
#endif

namespace termuxgui {
    /** This class represents a connection to the plugin. The connection is automatically closed when the object is destroyed. */
    class Connection {
    private:
        int mainfd = 0;
        int eventfd = 0;
        Connection(const Connection&);
        Connection& operator=(const Connection&);
    public:
        /// Creates a connection to the plugin.
        /// Throws a std::runtime_error if the connection fails.
        Connection();
        
        
        /** Closes the connection. */
        ~Connection();
        
        
        
    };
    
    
}


#endif
