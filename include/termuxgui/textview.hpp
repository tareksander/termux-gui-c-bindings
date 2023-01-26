#pragma once

#include <memory>
#include "view.hpp"
#include "activity.hpp"
#include "viewgroup.hpp"

namespace tgui {
	
	namespace impl {
		class TextView;
	}
	
	class TextView : public View {
		public:
		
		TextView(Activity& a, ViewGroup* parent = nullptr, std::string text = "", bool selectableText = true, bool clickableLinks = false);
		
		
		virtual ~TextView();
		
		
		
		void setTextColor(tgui::Color col);
		
		void setText(std::string text);
		
		void setGravity(Gravity horizontal, Gravity vertical);
		
		void setTextSize(Size s);
		
		std::string getText();
		
		
		
		protected:
		
		std::shared_ptr<impl::TextView> tv;
		
	};
}

