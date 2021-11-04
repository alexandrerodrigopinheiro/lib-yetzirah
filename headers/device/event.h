#ifndef YGL_DEVICE_EVENT_H_
#define YGL_DEVICE_EVENT_H_

#pragma once

#pragma once

#include <string>
#include <iostream>

#include <SDL2/SDL_events.h>

#include "error/exception.h"
#include "device/device.h"
#include "device/keyboard.h"
#include "device/mouse.h"
#include "device/touch.h"
#include "graphic/sprite.h"
#include "animation/timeline.h"

namespace ygl
{
	namespace device
	{
		class event
		{
			public:

				event();

				event(const event&) = delete;

				~event();

				bool initialize();

				void destroy();

				void listener();

				void render();

				void clear();

				const ygl::device::keyboard& keyoard() const;

				const ygl::device::mouse& mouse() const;

				const ygl::device::touch& touch() const;

				void verbose(bool verbose);

				bool opened() const;

				bool verbosed() const;

			protected:

				bool					_pressed		{ false };
				bool					_open			{ true };
				bool					_verbose		{ false };
				ygl::device::type		_type			{ ygl::device::type::TYPE_NONE };
				ygl::device::keyboard	_keyoard		{ ygl::device::keyboard() };
				ygl::device::mouse		_mouse			{ ygl::device::mouse() };
				ygl::device::touch		_touch			{ ygl::device::touch() };
				ygl::graphic::sprite*	_touch_pulse	{ NULL };
		};
	}
}

#endif /* YGL_DEVICE_EVENT_H_ */
