#pragma once

#include <memory>

#include "activity.hpp"
#include "connection.hpp"
#include "termuxgui/types.hpp"

namespace tgui::impl {
	class View final {
		public:
		
		View(std::shared_ptr<Activity> a, tgui::Vid id);
		
		
		void setLinearLayoutParams(float weight = -1, int position = 0);
		
		void setGridLayoutParams(int row, int col, int rowSize = 1, int colSize = 1,
			proto0::SetGridLayoutParamsRequest::Alignment rowAlign = proto0::SetGridLayoutParamsRequest::CENTER,
			proto0::SetGridLayoutParamsRequest::Alignment colAlign = proto0::SetGridLayoutParamsRequest::CENTER);
		
		void setLocation(proto0::Size::Unit unit, int x, int y, bool top);
		
		void setRelativeLayoutParams();
		
		void setVisibility(proto0::Visibility v);
		
		void setWidth(proto0::ViewSize s);
		
		void setHeight(proto0::ViewSize s);
		
		void getDimensions(proto0::Size::Unit u, tgui::Point& p);
		
		void destroy();
		
		void setMargin(proto0::Size s, proto0::Direction dir);
		
		void setPadding(proto0::Size s, proto0::Direction dir);
		
		void setBackgroundColor(tgui::Color c);
		
		void focus(bool forceSoft);
		
		void setClickable(bool clickable);
		
		
		
		void sendClickEvents(bool send);
		
		void sendLongClickEvents(bool send);
		
		void sendFocusChangeEvents(bool send);
		
		void sendTouchEvents(bool send);
		
		
		
		const tgui::Vid id;
		const std::weak_ptr<Activity> wa;
		
		private:
		View(const View&) = delete;
		View(const View&&) = delete;
		View& operator=(const View&) = delete;
		View& operator=(const View&&) = delete;
		View() = delete;
		
	};
}
