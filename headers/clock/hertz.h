#ifndef YGL_CLOCK_HERTZ_H_
#define YGL_CLOCK_HERTZ_H_

#pragma once

#include <string>
#include <iostream>

#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

#include "clock/frequency.h"
#include "clock/timer.h"

namespace ygl
{
	namespace clock
	{
		class hertz
		{
			public:

				hertz();

				hertz(const ygl::clock::hertz& obj);

				~hertz();

				bool initialize(std::size_t fps);

				void destroy();

				void synchronize();

				void fps(std::size_t fps);

				std::size_t fps() const;

				std::size_t latency() const;

				std::size_t frequency() const;

				std::size_t get_hertz();

			protected:

				ygl::clock::timer*		_timer		{ nullptr };
				ygl::clock::frequency*	_frequency	{ nullptr };
				std::size_t				_fps		{ ygl::clock::FPS };
				std::size_t				_latency	{ ygl::clock::LATENCY };
		};
	}
}

#endif /* YGL_CLOCK_HERTZ_H_ */
