#include "cdefs.hpp"

#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "types.hpp"



extern "C" {
	tgui_err tgui_to_termux() {
		return exceptionToError<tgui_err>([&]() {
			int fpid = fork();
			if (fpid == -1) {
				return TGUI_ERR_SYSTEM;
			}
			if (fpid == 0) {
				// redirect stdin and stdout to /dev/null
				int null = open("/dev/null", O_RDWR);
				if (null == -1) {
					std::perror("open /dev/null");
					exit(1);
				}
				if (dup2(null, 0) == -1) {
					std::perror("dup2 0");
					exit(1);
				}
				if (dup2(null, 1) == -1) {
					std::perror("dup2 1");
					exit(1);
				}
				
				close(null);
				
				execlp("termux-am", "termux-am", "start", "-n", "com.termux/.app.TermuxActivity", (char*) NULL);
				std::perror("execlp");
				exit(1);
			}
			// wait up to 5 seconds for am
			int status;
			bool expired = true;
			bool started = false;
			for (int i = 0; i < 100; i++) {
				int pid = waitpid(fpid, &status, WNOHANG);
				if (pid == -1 && errno != EINTR) {
					return TGUI_ERR_SYSTEM;
				}
				if (pid == fpid) {
					if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
						started = true;
					}
					expired = false;
					break;
				}
				usleep(1000 * 50);
			}
			if (expired) {
				return TGUI_ERR_CONNECTION_LOST;
			}
			if (! started) {
				int fpid = fork();
				if (fpid == -1) {
					return TGUI_ERR_SYSTEM;
				}
				if (fpid == 0) {
					// redirect stdin and stdout to /dev/null
					int null = open("/dev/null", O_RDWR);
					if (null == -1) {
						std::perror("open /dev/null");
						exit(1);
					}
					if (dup2(null, 0) == -1) {
						std::perror("dup2 0");
						exit(1);
					}
					if (dup2(null, 1) == -1) {
						std::perror("dup2 1");
						exit(1);
					}
					
					close(null);
					
					execlp("am", "am", "start", "-n", "com.termux/.app.TermuxActivity", (char*) NULL);
					std::perror("execlp");
					exit(1);
				}
				// wait up to 5 seconds for am
				int status;
				bool expired = true;
				bool started = false;
				for (int i = 0; i < 100; i++) {
					int pid = waitpid(fpid, &status, WNOHANG);
					if (pid == -1 && errno != EINTR) {
						return TGUI_ERR_SYSTEM;
					}
					if (pid == fpid) {
						if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
							started = true;
						}
						expired = false;
						break;
					}
					usleep(1000 * 50);
				}
				if (expired || ! started) {
					return TGUI_ERR_CONNECTION_LOST;
				}
			}
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_connection_create(tgui_connection* c) {
		return exceptionToError<void>([&]() {
			*c = new tgui_connection_();
		});
	}
	
	void tgui_connection_destroy(tgui_connection c) {
		delete c;
	}
	
	tgui_err tgui_get_version(tgui_connection c, int* v) {
		return exceptionToError<void>([&]() {
			proto0::Method m;
			proto0::GetVersionRequest r = proto0::GetVersionRequest();
			*m.mutable_version() = r;
			proto0::GetVersionResponse res;
			c->c.sendReadMessage(m, res);
			*v = res.versioncode();
		});
	}
	
	tgui_err tgui_set_log_level(tgui_connection c, int level) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::SetLogLevelRequest r = proto0::SetLogLevelRequest();
			r.set_level(level);
			*m.mutable_setloglevel() = r;
			proto0::SetLogLevelResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_get_log(tgui_connection c, bool clear, char** log) {
		return exceptionToError<tgui_err>([&]() {
			*log = NULL;
			proto0::Method m;
			proto0::GetLogRequest r = proto0::GetLogRequest();
			r.set_clear(clear);
			*m.mutable_getlog() = r;
			proto0::GetLogResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			*log = strdup(res.log().c_str());
			if (*log == NULL) return TGUI_ERR_NOMEM;
			return TGUI_ERR_OK;
		});
	}
	
	
	tgui_err tgui_toast(tgui_connection c, const char* text, bool l) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::ToastRequest r;
			r.set_text(text);
			r.set_long_(l);
			*m.mutable_toast() = r;
			
			proto0::ToastResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_turn_screen_on(tgui_connection c) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::TurnScreenOnRequest r;
			*m.mutable_turnscreenon() = r;
			
			proto0::TurnScreenOnResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_is_locked(tgui_connection c, bool* locked) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::IsLockedRequest r;
			*m.mutable_islocked() = r;
			
			proto0::IsLockedResponse res;
			c->c.sendReadMessage(m, res);
			if (res.locked() == proto0::IsLockedResponse::UNKNOWN) return TGUI_ERR_MESSAGE;
			if (res.locked() == proto0::IsLockedResponse::LOCKED) {
				*locked = true;
			} else {
				*locked = false;
			}
			return TGUI_ERR_OK;
		});
	}
	
	tgui_err tgui_request_unlock(tgui_connection c, tgui_activity a) {
		return exceptionToError<tgui_err>([&]() {
			proto0::Method m;
			proto0::RequestUnlockRequest r;
			r.set_aid(a);
			*m.mutable_requestunlock() = r;
			
			proto0::RequestUnlockResponse res;
			c->c.sendReadMessage(m, res);
			if (! res.success()) return TGUI_ERR_MESSAGE;
			return TGUI_ERR_OK;
		});
	}
	
	
	
	static tgui_err tgui_event_convert(const tgui::proto0::Event& ev, tgui_event* event_p) {
		using namespace tgui::proto0;
		tgui_event& event = *event_p;
		if (ev.event_case() == Event::kClick) {
			const ClickEvent& e = ev.click();
			event.type = TGUI_EVENT_CLICK;
			event.activity = e.v().aid();
			event.click.id = e.v().id();
			event.click.set = e.set();
		} else if (ev.event_case() == Event::kTouch) {
			const TouchEvent& e = ev.touch();
			event.type = TGUI_EVENT_TOUCH;
			event.activity = e.v().aid();
			event.touch.id = e.v().id();
			event.touch.action = TouchActionPBToPublic.at(e.action());
			
			event.touch.events = e.touches_size();
			event.touch.pointers = new tgui_touch_pointer*[event.touch.events];
			
			for (int i = 0; i < event.touch.events; i++) {
				const auto& pointers = e.touches(i);
				if (i == 0) {
					event.touch.num_pointers = pointers.pointers_size();
				}
				event.touch.pointers[i] = new tgui_touch_pointer[event.touch.num_pointers];
				for (int a = 0; a < event.touch.num_pointers; a++) {
					tgui_touch_pointer& p = event.touch.pointers[i][a];
					const auto& ep = pointers.pointers(a);
					p.id = ep.id();
					p.x = ep.x();
					p.y = ep.y();
				}
			}
			
			event.touch.index = e.index();
			event.touch.time = e.time();
			
		} else if (ev.event_case() == Event::kText) {
			const TextEvent& e = ev.text();
			event.type = TGUI_EVENT_TEXT;
			event.text.id = e.v().id();
			event.text.text = strdup(e.text().c_str());
			if (event.text.text == NULL) {
				throw std::system_error(std::error_code(errno, std::system_category()));
			}
		} else if (ev.event_case() == Event::kCreate) {
			const CreateEvent& e = ev.create();
			event.type = TGUI_EVENT_CREATE;
			event.activity = e.aid();
		} else if (ev.event_case() == Event::kStart) {
			const StartEvent& e = ev.start();
			event.type = TGUI_EVENT_START;
			event.activity = e.aid();
		} else if (ev.event_case() == Event::kResume) {
			const ResumeEvent& e = ev.resume();
			event.type = TGUI_EVENT_RESUME;
			event.activity = e.aid();
		} else if (ev.event_case() == Event::kPause) {
			const PauseEvent& e = ev.pause();
			event.type = TGUI_EVENT_PAUSE;
			event.activity = e.aid();
			event.finishing = e.finishing();
		} else if (ev.event_case() == Event::kStop) {
			const StopEvent& e = ev.stop();
			event.type = TGUI_EVENT_STOP;
			event.activity = e.aid();
			event.finishing = e.finishing();
		} else if (ev.event_case() == Event::kDestroy) {
			const DestroyEvent& e = ev.destroy();
			event.type = TGUI_EVENT_DESTROY;
			event.activity = e.aid();
			event.finishing = e.finishing();
		} else if (ev.event_case() == Event::kConfig) {
			const ConfigEvent& e = ev.config();
			event.type = TGUI_EVENT_CONFIG;
			event.activity = e.aid();
			event.configuration = tgui::ConfigurationPBToPublic(e.configuration());
		} else if (ev.event_case() == Event::kLongClick) {
			const LongClickEvent& e = ev.longclick();
			event.type = TGUI_EVENT_LONG_CLICK;
			event.activity = e.v().aid();
			event.click.id = e.v().id();
		} else if (ev.event_case() == Event::kFocusChange) {
			const FocusChangeEvent& e = ev.focuschange();
			event.type = TGUI_EVENT_FOCUS;
			event.activity = e.v().aid();
			event.focus.id = e.v().id();
			event.focus.focus = e.focus();
		} else if (ev.event_case() == Event::kRefresh) {
			const RefreshEvent& e = ev.refresh();
			event.type = TGUI_EVENT_REFRESH;
			event.activity = e.v().aid();
			event.refresh.id = e.v().id();
		} else if (ev.event_case() == Event::kSelected) {
			const SelectedEvent& e = ev.selected();
			event.type = TGUI_EVENT_SELECTED;
			event.activity = e.v().aid();
			event.selected.id = e.v().id();
			event.selected.selected = e.selected();
		} else if (ev.event_case() == Event::kItemSelected) {
			const ItemSelectedEvent& e = ev.itemselected();
			event.type = TGUI_EVENT_ITEM_SELECTED;
			event.activity = e.v().aid();
			event.itemSelected.id = e.v().id();
			event.itemSelected.selected = e.selected();
		} else if (ev.event_case() == Event::kBack) {
			const BackButtonEvent& e = ev.back();
			event.type = TGUI_EVENT_BACK;
			event.activity = e.aid();
		} else if (ev.event_case() == Event::kWebNavigation) {
			const WebViewNavigationEvent& e = ev.webnavigation();
			event.type = TGUI_EVENT_WEBVIEW_NAVIGATION;
			event.webNavigation.id = e.v().id();
			event.webNavigation.url = strdup(e.url().c_str());
			if (event.webNavigation.url == NULL) {
				throw std::system_error(std::error_code(errno, std::system_category()));
			}
		} else if (ev.event_case() == Event::kWebHTTPError) {
			const WebViewHTTPErrorEvent& e = ev.webhttperror();
			event.type = TGUI_EVENT_WEBVIEW_HTTP_ERROR;
			event.webHTTPError.id = e.v().id();
			event.webHTTPError.url = strdup(e.url().c_str());
			if (event.webHTTPError.url == NULL) {
				throw std::system_error(std::error_code(errno, std::system_category()));
			}
		} else if (ev.event_case() == Event::kWebError) {
			const WebViewErrorEvent& e = ev.weberror();
			event.type = TGUI_EVENT_WEBVIEW_ERROR;
			event.webError.id = e.v().id();
			event.webError.url = strdup(e.url().c_str());
			if (event.webError.url == NULL) {
				throw std::system_error(std::error_code(errno, std::system_category()));
			}
		} else if (ev.event_case() == Event::kWebDestroyed) {
			const WebViewDestroyedEvent& e = ev.webdestroyed();
			event.type = TGUI_EVENT_WEBVIEW_DESTROYED;
			event.webDestroyed.id = e.v().id();
		} else if (ev.event_case() == Event::kWebProgress) {
			const WebViewProgressEvent& e = ev.webprogress();
			event.type = TGUI_EVENT_WEBVIEW_PROGRESS;
			event.webProgress.id = e.v().id();
		} else if (ev.event_case() == Event::kWebConsoleMessage) {
			const WebViewConsoleMessageEvent& e = ev.webconsolemessage();
			event.type = TGUI_EVENT_WEBVIEW_CONSOLE;
			event.webConsole.id = e.v().id();
			event.webConsole.msg = strdup(e.message().c_str());
			if (event.webConsole.msg == NULL) {
				throw std::system_error(std::error_code(errno, std::system_category()));
			}
		} else if (ev.event_case() == Event::kAirplane) {
			const AirplaneEvent& e = ev.airplane();
			event.type = TGUI_EVENT_AIRPLANE;
			event.airplane = e.active();
		} else if (ev.event_case() == Event::kLocale) {
			const LocaleEvent& e = ev.locale();
			event.type = TGUI_EVENT_LOCALE;
			strncpy(event.locale, e.locale().c_str(), sizeof(event.locale));
			event.locale[sizeof(event.locale)-1] = '\0';
		} else if (ev.event_case() == Event::kTimezone) {
			const TimezoneEvent& e = ev.timezone();
			event.type = TGUI_EVENT_TIMEZONE;
			strncpy(event.timezone, e.tz().c_str(), sizeof(event.timezone));
			event.timezone[sizeof(event.timezone)-1] = '\0';
		} else if (ev.event_case() == Event::kScreenOff) {
			const ScreenOffEvent& e = ev.screenoff();
			event.type = TGUI_EVENT_SCREEN_OFF;
		} else if (ev.event_case() == Event::kScreenOn) {
			const ScreenOnEvent& e = ev.screenon();
			event.type = TGUI_EVENT_SCREEN_ON;
		} else if (ev.event_case() == Event::kUserLeaveHint) {
			const UserLeaveHintEvent& e = ev.userleavehint();
			event.type = TGUI_EVENT_USER_LEAVE_HINT;
			event.activity = e.aid();
		} else if (ev.event_case() == Event::kPip) {
			const PiPChangedEvent& e = ev.pip();
			event.type = TGUI_EVENT_PIP;
			event.activity = e.aid();
			event.pip.pip = e.pip();
		} else if (ev.event_case() == Event::kRemoteClick) {
			const RemoteClickEvent& e = ev.remoteclick();
			event.type = TGUI_EVENT_REMOTE_CLICK;
			event.remoteClick.rid = e.rid();
			event.remoteClick.id = e.id();
		} else if (ev.event_case() == Event::kNotification) {
			const NotificationEvent& e = ev.notification();
			event.type = TGUI_EVENT_NOTIFICATION;
		} else if (ev.event_case() == Event::kNotificationDismissed) {
			const NotificationDismissedEvent& e = ev.notificationdismissed();
			event.type = TGUI_EVENT_NOTIFICATION_DISMISSED;
		} else if (ev.event_case() == Event::kNotificationAction) {
			const NotificationActionEvent& e = ev.notificationaction();
			event.type = TGUI_EVENT_NOTIFICATION_ACTION;
			event.action.id = e.id();
			event.action.action = e.action();
		} else if (ev.event_case() == Event::kOverlayScale) {
			const OverlayScaleEvent& e = ev.overlayscale();
			event.overlayScale.span = e.span();
		} else if (ev.event_case() == Event::kKeyEvent) {
			const KeyEvent& e = ev.keyevent();
			event.type = TGUI_EVENT_KEY;
			event.key.code = e.code();
			event.key.codePoint = e.codepoint();
			event.key.mod = static_cast<tgui_key_modifier>(e.modifiers());
			event.key.flags = e.flags();
			event.key.down = e.action() == KeyAction::ACTION_DOWN;
		} else if (ev.event_case() == Event::kFrameComplete) {
			const SurfaceViewFrameCompleteEvent& e = ev.framecomplete();
			event.type = TGUI_EVENT_FRAME_COMPLETE;
			event.activity = e.v().aid();
			event.frame.id = e.v().id();
			event.frame.timestamp = e.timestamp();
		} else if (ev.event_case() == Event::kVolume) {
			const VolumeKeyEvent& e = ev.volume();
			event.type = TGUI_EVENT_VOLUME;
			event.activity = e.aid();
			event.volume.released = e.released();
			event.volume.volume_up = e.key() == VolumeKeyEvent::VOLUME_UP;
		} else if (ev.event_case() == Event::kInset) {
			const InsetEvent& e = ev.inset();
			event.type = TGUI_EVENT_INSET;
			event.activity = e.aid();
			event.inset.current_inset = BarsPBToPublic.at(e.visible());
		} else if (ev.event_case() == Event::kSurfaceChanged) {
			const SurfaceViewSurfaceChangedEvent& e = ev.surfacechanged();
			event.type = TGUI_EVENT_SURFACE_CHANGED;
			event.activity = e.v().aid();
			event.surfaceChanged.id = e.v().id();
			event.surfaceChanged.width = e.width();
			event.surfaceChanged.height = e.height();
		}  else {
			return TGUI_ERR_MESSAGE;
		}
		return TGUI_ERR_OK;
	}
	
	tgui_err tgui_wait_event(tgui_connection c, tgui_event* event) {
		return exceptionToError<tgui_err>([&]() {
			return tgui_event_convert(c->c.receiveEvent(), event);
		});
	}
	
	tgui_err tgui_poll_event(tgui_connection c, tgui_event* event, bool* available) {
		*available = false;
		return exceptionToError<tgui_err>([&]() {
			auto e = c->c.pollEvent();
			if (e == nullptr) {
				return TGUI_ERR_OK;
			}
			tgui_err err = tgui_event_convert(*e.get(), event);
			if (err != TGUI_ERR_OK) return err;
			*available = true;
			return TGUI_ERR_OK;
		});
	}
	
	
	void tgui_event_destroy(tgui_event* eventP) {
		tgui_event& event = *eventP;
		switch (event.type) {
			case TGUI_EVENT_TOUCH:
				if (event.touch.pointers != NULL) {
					for (uint32_t i = 0; i < event.touch.events; i++) {
						if (event.touch.pointers[i] != NULL) {
							delete[] event.touch.pointers[i];
							event.touch.pointers[i] = NULL;
						}
					}
					delete[] event.touch.pointers;
					event.touch.pointers = NULL;
				}
				break;
			case TGUI_EVENT_TEXT:
				if (event.text.text != NULL) {
					free(event.text.text);
					event.text.text = NULL;
				}
				break;
			case TGUI_EVENT_WEBVIEW_NAVIGATION:
				if (event.webNavigation.url != NULL) {
					free(event.webNavigation.url);
					event.webNavigation.url = NULL;
				}
				break;
			case TGUI_EVENT_WEBVIEW_HTTP_ERROR:
				if (event.webHTTPError.url != NULL) {
					free(event.webHTTPError.url);
					event.webHTTPError.url = NULL;
				}
				break;
			case TGUI_EVENT_WEBVIEW_ERROR:
				if (event.webError.url != NULL) {
					free(event.webError.url);
					event.webError.url = NULL;
				}
				break;
			case TGUI_EVENT_WEBVIEW_CONSOLE:
				if (event.webConsole.msg != NULL) {
					free(event.webConsole.msg);
					event.webConsole.msg = NULL;
				}
				break;
			default:
				break;
		} 
	}
	
}

