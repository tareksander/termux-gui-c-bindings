#pragma once

#include <string>

#include <memory>

#include "event.hpp"


namespace tgui {
	
	namespace impl {
		class Connection;
	}
	
	/**
	 * @brief Represents a connection to the Termux:GUI plugin.
	 * 
	 */
	class Connection {
	public:
		
		
		
		Connection();
		virtual ~Connection();
		
		
		/**
		 * @brief Blocks until an Event is available and returns it.
		 * 
		 * @param eRet The Event to write to.
		 */
		void receiveEvent(Event& eRet);
		
		
		/**
		 * @brief Checks if calling `receiveEvent()` would block.
		 * 
		 * @details
		 * WARNING: If you poll events from multiple threads, `receiveEvent()` can still block event if `checkEvent()` returns true
		 * if there is a race condition. If this is unacceptable, you have to synchronize the threads yourself.
		 * 
		 * @return True if an event is available, false if not.
		 */
		bool checkEvent();
		
		
		/**
		 * @brief Gets the version of the plugin.
		 * 
		 * @return The version code.
		 */
		int getVersion();
		
		
		/**
		 * @brief Checks if the screen is locked.
		 * 
		 * @return Whether the screen is locked or not.
		 */
		bool isLocked();
		
		
		/**
		 * @brief Sends a toast.
		 * 
		 * @param msg The message to display.
		 */
		void toast(std::string msg);
		
		
		
		/**
		 * @brief Turns the screen on.
		 */
		void turnScreenOn();
		
		
		/**
		 * @brief A helper function that brings Termux to the foreground.
		 */
		static void toTermux();
		
		
	private:
		
		const std::shared_ptr<impl::Connection> c;
		
		friend class Activity;
	};
	
}



