#pragma once

#include <memory>

#include "activity.hpp"
#include "connection.hpp"
#include "termuxgui/types.hpp"
#include "view.hpp"

namespace tgui::impl {
	class TextView {
		public:
		
		TextView(std::shared_ptr<View> v);
		
		void setTextColor(tgui::Color col);
		
		void setText(std::string text);
		
		void setGravity(proto0::SetGravityRequest::Gravity horizontal,
			proto0::SetGravityRequest::Gravity vertical);
		
		void setTextSize(proto0::Size s);
		
		std::string getText();
		
		
		const std::shared_ptr<View> v;
		private:
		TextView(const TextView&) = delete;
		TextView(const TextView&&) = delete;
		TextView& operator=(const TextView&) = delete;
		TextView& operator=(const TextView&&) = delete;
		TextView() = delete;
		
	};
}
