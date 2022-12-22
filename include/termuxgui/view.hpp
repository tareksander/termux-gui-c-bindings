#pragma once

#include <memory>
#include "types.hpp"

namespace tgui {
	
	namespace impl {
		class View;
	}
	
	class View {
		public:
		
		
		void setLinearLayoutParams(float weight = -1, int position = 0);
		
		// void setGridLayoutParams(int row, int col, int rowSize = 1, int colSize = 1,
		// 	tgui::Alignment rowAlign = proto0::SetGridLayoutParamsRequest::CENTER,
		// 	proto0::SetGridLayoutParamsRequest::Alignment colAlign = proto0::SetGridLayoutParamsRequest::CENTER);
		
		void setLocation(Size::Unit unit, int x, int y, bool top);
		
		void setRelativeLayoutParams();
		
		void setVisibility(Visibility vis);
		
		void setWidth(ViewSize s);
		
		void setHeight(ViewSize s);
		
		void getDimensions(Size::Unit u, Point& p);
		
		void destroy();
		
		void setMargin(Size s, Direction dir);
		
		void setPadding(Size s, Direction dir);
		
		void setBackgroundColor(Color col);
		
		void focus(bool forceSoft);
		
		void setClickable(bool clickable);
		
		
		
		void sendClickEvents(bool send);
		
		void sendLongClickEvents(bool send);
		
		void sendFocusChangeEvents(bool send);
		
		void sendTouchEvents(bool send);
		
		
		Vid getID();
		
		
		protected:
		View() = default;
		
		std::shared_ptr<impl::View> v;
		
	};
}

