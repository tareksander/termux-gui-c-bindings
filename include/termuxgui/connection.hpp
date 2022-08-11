#pragma once

#include <memory>


namespace tgui {
	
	namespace impl {
		class Connection;
	}
	
	class Connection {
	public:
		
		
		
		Connection();
		~Connection();
		
		
		
		
		
		
	private:
		
		std::unique_ptr<impl::Connection> c;
		
		
		
		
		
		
		
	};
	
}



