#pragma once

#include <exception>

namespace tgui {
	
	
	/**
	 * Signifies that the desired protocol or protocol version was unavailable. The plugin has to be updated.
	 */
	class ProtocolUnavailableException : public std::exception {};
	
	/**
	 * The timeout expired while trying to establish the connection.
	 */
	class ConnectionTimeoutException : public std::exception {};
	
	/**
	 * The plugin doesn't have the same UID as the program, meaning the connection can't be trusted.
	 */
	class PluginUIDException : public std::exception {};
	
	/**
	 * A protobuf message could not be read.
	 */
	class MessageReadException : public std::exception {};
	
	/**
	 * A protobuf message could not be written.
	 */
	class MessageWriteException : public std::exception {};
	
	
	
	
	
}



