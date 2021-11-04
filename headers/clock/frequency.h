#ifndef YGL_CLOCK_FREQUENCY_H_
#define YGL_CLOCK_FREQUENCY_H_

#pragma once

#include <string>
#include <iostream>

#include "clock/clock.h"
#include "clock/timer.h"

namespace ygl
{
	namespace clock
	{
		class frequency
		{
			public:

				frequency();

				frequency(const ygl::clock::frequency& obj);

				~frequency();

				bool initialize();

				void destroy();

				bool update();

				uint64_t get_frequency();

			protected:

				ygl::clock::timer*	_timer		{ NULL };
				uint64_t			_counter	{ 0 };
				uint64_t			_frequency	{ 0 };
		};
	}
}

#endif /* YGL_CLOCK_FREQUENCY_H_ */
