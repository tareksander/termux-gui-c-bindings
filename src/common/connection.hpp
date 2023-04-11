#pragma once

#include <system_error>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include "../includeproto.h"

#include "exceptions.hpp"
#include <stdint.h>

#include <array>
#include <mutex>
#include <memory>

namespace tgui::common {
	
	class Connection {
	public:
		struct Buffer {
			int id, fd;
		};
		
		
		inline static std::shared_ptr<Connection> connectionOrThrow(const std::weak_ptr<Connection>& p) {
			auto shared = p.lock();
			if (shared == nullptr) {
				throw ConnectionClosedException();
			}
			return shared;
		}
		
		Connection();
		~Connection();
		
		
		
		void sendMethodMessage(proto0::Method& m);
		
		
		void sendReadMessage(google::protobuf::MessageLite& send, google::protobuf::MessageLite& read);
		
		
		proto0::Event receiveEvent();
		std::unique_ptr<proto0::Event> pollEvent();
		
		
		bool checkEvent();
		
		Buffer addBuffer();
		
		
	private:
		
		Connection(const Connection&) = delete;
		Connection(const Connection&&) = delete;
		Connection& operator=(const Connection&) = delete;
		Connection& operator=(const Connection&&) = delete;
		
		int mainfd, eventfd;
		
		class SocketInputStream : public google::protobuf::io::ZeroCopyInputStream {
		public:
			
			static constexpr size_t BUFFERSIZE = 1024;
			
			SocketInputStream();
			SocketInputStream(SocketInputStream&&) = delete;
			SocketInputStream& operator=(SocketInputStream&&) = delete;
			
			SocketInputStream& operator=(SocketInputStream) = delete;
			SocketInputStream& operator=(const SocketInputStream&) = delete;
			SocketInputStream(const SocketInputStream&) = delete;
			
			virtual ~SocketInputStream();
			
			
			// https://developers.google.com/protocol-buffers/docs/reference/cpp/google.protobuf.io.zero_copy_stream#ZeroCopyInputStream
			virtual bool Next(const void** data, int* size) override;
			virtual void BackUp(int count) override;
			virtual bool Skip(int count) override;
			virtual int64_t ByteCount() const override;
			
			void raiseError();
			
			int fd = -1;
		private:
			std::array<uint8_t, BUFFERSIZE> buffer;
			int lastsize = 0;
			bool err = false;
			int64_t count = 0;
			int again = 0;
			
			
		};
		
		class SocketOutputStream : public google::protobuf::io::ZeroCopyOutputStream {
		public:
			
			static constexpr size_t BUFFERSIZE = 1024;
			
			SocketOutputStream();
			SocketOutputStream(SocketOutputStream&&) = delete;
			SocketOutputStream& operator=(SocketOutputStream&&) = delete;
			
			SocketOutputStream& operator=(SocketOutputStream) = delete;
			SocketOutputStream& operator=(const SocketOutputStream&) = delete;
			SocketOutputStream(const SocketOutputStream&) = delete;
			
			virtual ~SocketOutputStream();
			
			void flush();
			
			
			// https://developers.google.com/protocol-buffers/docs/reference/cpp/google.protobuf.io.zero_copy_stream#ZeroCopyOutputStream
			virtual bool Next(void** data, int* size) override;
			virtual void BackUp(int count) override;
			virtual int64_t ByteCount() const override;
			virtual bool WriteAliasedRaw(const void* data, int size) override;
			virtual bool AllowsAliasing() const override;
			
			
			int fd = -1;
		private:
			std::array<uint8_t, BUFFERSIZE>  buffer;
			bool err = false;
			int64_t count = 0;
			int towrite = 0;
			
			
			bool writeRaw(const uint8_t* buffer, int size);
			
		};
		
		std::mutex mainMutex;
		std::mutex eventMutex;
		
		SocketInputStream in;
		SocketOutputStream out;
		SocketInputStream event;
		
		
		
	};
	
}


