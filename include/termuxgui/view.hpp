#pragma once

#include <memory>
#include "types.hpp"

namespace tgui {
	
	namespace impl {
		class View;
	}
	
	class View {
		public:
		
		
		
		
		
		VID getID();
		
		
		protected:
		View() = default;
		
		std::shared_ptr<impl::View> v;
		
	};
}

