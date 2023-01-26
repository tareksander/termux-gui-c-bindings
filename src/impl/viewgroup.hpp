#pragma once

#include <memory>
#include <vector>

#include "activity.hpp"
#include "connection.hpp"
#include "view.hpp"

namespace tgui::impl {
	class ViewGroup final {
		public:
		
		ViewGroup(std::shared_ptr<View> v);
		
		void clearChildren();
		
		
		
		
		const std::shared_ptr<View> v;
		
		private:
		ViewGroup(const ViewGroup&) = delete;
		ViewGroup(const ViewGroup&&) = delete;
		ViewGroup& operator=(const ViewGroup&) = delete;
		ViewGroup& operator=(const ViewGroup&&) = delete;
		ViewGroup() = delete;
	};
}
