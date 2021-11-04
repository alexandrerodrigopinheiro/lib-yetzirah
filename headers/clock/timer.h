#ifndef YGL_CLOCK_TIMER_H_
#define YGL_CLOCK_TIMER_H_

#pragma once

#include <chrono>
#include <ratio>
#include <thread>
#include <string>
#include <iostream>

namespace ygl
{
	namespace clock
	{
		class timer
		{
			public:

				timer();

				timer(const ygl::clock::timer& obj);

				~timer();

				void play();

				void start();

				void stop();

				void reset();

				void replay();

				bool started() const;

				std::size_t elapsed() const;

				std::size_t ticks() const;

			protected:

				bool		_play		{ false };
				std::size_t	_restore	{ 0 };
				std::size_t	_initial	{ 0 };
				std::size_t	_current	{ 0 };
		};
	}
}

#endif /* YGL_CLOCK_TIMER_H_ */
