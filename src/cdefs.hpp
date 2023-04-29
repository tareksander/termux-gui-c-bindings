#pragma once

#include <functional>
#include <exception>

#include "common/connection.hpp"
#include "includeproto.h"

using namespace tgui;
using namespace tgui::common;


#define VIEW_METHOD_PRE(name) \
return exceptionToError<tgui_err>([&]() {\
proto0::Method m;\
proto0::name ## Request r;\
proto0::View pv;\
pv.set_aid(a);\
pv.set_id(v);\
*r.mutable_v() = pv;

#define VIEW_METHOD_POST(name) \
proto0::name ## Response res;\
c->c.sendReadMessage(m, res);\
if (! res.success()) return TGUI_ERR_MESSAGE;\
return TGUI_ERR_OK;\
});


#define METHOD_PRE(name) \
return exceptionToError<tgui_err>([&]() {\
proto0::Method m;\
proto0::name ## Request r;

#define METHOD_POST(name) \
proto0::name ## Response res;\
c->c.sendReadMessage(m, res);\
if (! res.success()) return TGUI_ERR_MESSAGE;\
return TGUI_ERR_OK;\
});

#define METHOD_POST_NONSTANDARD(name) \
proto0::name ## Response res;\
c->c.sendReadMessage(m, res);

#define METHOD_POST_NONSTANDARD2() \
return TGUI_ERR_OK;\
});


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

