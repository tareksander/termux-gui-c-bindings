#pragma once

#include <functional>
#include <exception>
#include <termuxgui/exceptions.hpp>

template<typename T> std::function<T> rethrow(std::function<T> f) {
	return [f] () {
		try {
			return f();
		} catch (const tgui::TermuxGUIException& e) {
			throw e;
		} catch (const std::exception& e) {
			throw tgui::UncaughtExceptionException(e);
		}
	};
}


