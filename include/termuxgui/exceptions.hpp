#pragma once

#include <exception>
#include <system_error>

namespace tgui {
	
	
	/**
	 * @brief Base class for all exceptions.
	 */
	class TermuxGUIException : public std::exception {};
	
	/**
	 * @brief Signifies that the desired protocol or protocol version was unavailable. The plugin has to be updated.
	 */
	class ProtocolUnavailableException : public TermuxGUIException {};
	
	/**
	 * @brief The timeout expired while trying to establish the connection.
	 */
	class ConnectionTimeoutException : public TermuxGUIException {};
	
	/**
	 * @brief You tried to use an object from a connection that is already closed.
	 */
	class ConnectionClosedException : public TermuxGUIException {};
	
	/**
	 * @brief You tried to use an object from an Activity that is already destroyed.
	 */
	class ActivityDestroyedException : public TermuxGUIException {};
	
	/**
	 * @brief You tried to use an object from a View that is already destroyed.
	 */
	class ViewDestroyedException : public TermuxGUIException {};
	
	/**
	 * @brief The plugin doesn't have the same UID as the program, meaning the connection can't be trusted.
	 */
	class PluginUIDException : public TermuxGUIException {};
	
	/**
	 * @brief A protobuf message could not be read.
	 */
	class MessageReadException : public TermuxGUIException {};
	
	/**
	 * @brief A protobuf message could not be written.
	 */
	class MessageWriteException : public TermuxGUIException {};
	
	
	/**
	 * @brief A plugin method was not successful.
	 */
	class MethodError : public TermuxGUIException {};
	
	/**
	 * @brief An `std::system_error` was caught.
	 */
	class SystemException : public TermuxGUIException {
		public:
		
		/**
		 * @brief The caught `std::system_error`
		 */
		const std::system_error e;
		
		SystemException(const std::system_error e) : e{e} {}
	};
	
	
	/**
	 * @brief A generic `std::exception` was caught.
	 */
	class UncaughtExceptionException : public TermuxGUIException {
		public:
		
		/**
		 * @brief The caught `std::exception`.
		 */
		const std::exception e;
		
		UncaughtExceptionException(const std::exception e) : e{e} {}
	};
	
	
	
	
	
	
	
	
	
	
}



