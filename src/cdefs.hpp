#pragma once

#include <functional>
#include <exception>

#include "common/connection.hpp"
#include "GUIProt0.pb.h"

using namespace tgui;
using namespace tgui::common;



struct tgui_connection_ {
	Connection c;
};


#include <termuxgui/termuxgui.h>



template<typename T> inline tgui_err exceptionToError(std::function<T()> f);

template<> inline tgui_err exceptionToError<tgui_err>(std::function<tgui_err()> f) {
	try {
		return f();
	} catch(std::bad_alloc) {
		return TGUI_ERR_NOMEM;
	} catch (ConnectionTimeoutException) {
		return TGUI_ERR_CONNECTION_LOST;
	} catch (std::system_error) {
		return TGUI_ERR_SYSTEM;
	} catch (MessageReadException) {
		return TGUI_ERR_MESSAGE;
	} catch (MessageWriteException) {
		return TGUI_ERR_MESSAGE;
	} catch (...) {
		return TGUI_ERR_EXCEPTION;
	}
}

template<> inline tgui_err exceptionToError<void>(std::function<void()> f) {
	return exceptionToError<tgui_err>([&]() -> tgui_err {
		f();
		return TGUI_ERR_OK;
	});
}

