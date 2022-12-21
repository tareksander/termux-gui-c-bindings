#pragma once

#include <memory>
#include "view.hpp"
#include "activity.hpp"

namespace tgui {
	
	namespace impl {
		class TextView;
	}
	
	class TextView : public View {
		public:
		
		TextView(Activity& a, View* parent = nullptr, std::string text = "", bool selectableText = true, bool clickableLinks = false);
		
		
		virtual ~TextView();
		
		
		
		
		
		
		
		protected:
		
		std::shared_ptr<impl::TextView> tv;
		
	};
}

