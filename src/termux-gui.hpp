/// @file termux-gui.hpp

#ifndef __TERMUX_GUI_HPP__
#define __TERMUX_GUI_HPP__


#include <string>

// include nlohmann-json if available

#if __has_include(<nlohmann/json.hpp>)
#include <nlohmann/json.hpp>
#endif

#if __has_include("json.hpp")
#include "json.hpp"
#endif

namespace tg {
    
    class Event {
    public:
        static const std::string CREATE;
        static const std::string START;
        static const std::string RESUME;
        static const std::string PAUSE;
        static const std::string STOP;
        static const std::string DESTROY;
        
        std::string type;
        std::string aid;
        int id;
        bool finishing;
        
        
        
        
    };
    
    
    /** This class represents a connection to the plugin. The connection is automatically closed when the object is destroyed. */
    class Connection {
    private:
        int mainfd = 0;
        int eventfd = 0;
        Connection(const Connection&);
        Connection& operator=(const Connection&);
    public:
        /**
         * Creates a connection to the plugin.
         * Throws a std::runtime_error if the connection fails.
         */
        Connection();
        
        
        /** Closes the connection. */
        ~Connection();
        
        /**
         * Brings Termux to the foreground by forking and calling \p am \p start .
         */
        void totermux();
        
        
        /** Sends a Toast. Set \p longer to true if you want to display the text for longer. */
        void toast(std::string& text, bool longer);
        
        /** Blocks until an Event is available and returns it. */
        Event event();
    };
    
    
    
    class Activity {
    private:
        
    public:
        
        
        
    };
    
    
    
}


#endif
