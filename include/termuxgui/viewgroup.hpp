#pragma once

#include <memory>
#include "view.hpp"
#include "activity.hpp"

namespace tgui {
	
	namespace impl {
		class ViewGroup;
	}
	
	class ViewGroup : public View {
		public:
		
		
		
		virtual ~ViewGroup() = 0;
		
		//void clearChildren();
		
		
		
		
		
		protected:
		
		std::shared_ptr<impl::ViewGroup> vg;
		
		friend class TextView;
	};
}

