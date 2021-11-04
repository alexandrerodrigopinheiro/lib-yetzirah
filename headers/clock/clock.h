#ifndef YGL_CLOCK_CLOCK_H_
#define YGL_CLOCK_CLOCK_H_

#pragma once

#include <ctime>
#include <string>
#include <iostream>

namespace ygl
{
	namespace clock
	{
		extern const std::size_t SECOND;
		extern const std::size_t HERTZ;
		extern const std::size_t FPS;
		extern const std::size_t LATENCY;

		inline const std::string datetime_stamp()
		{
			time_t now = std::time(0);
			struct tm tstruct;
			char buf[80];

			tstruct = *std::localtime(&now);

			/** Visit http://en.cppreference.com/w/cpp/chrono/c/strftime */
			/** for more information about date/time format. */
			std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);

			return std::string(buf);
		}

		inline std::string date_stamp()
		{
			time_t now = std::time(0);
			struct tm tstruct;
			char buf[80];

			tstruct = *std::localtime(&now);

			/** Visit http://en.cppreference.com/w/cpp/chrono/c/strftime */
			/** for more information about date/time format. */
			std::strftime(buf, sizeof(buf), "%Y%m%d", &tstruct);

			return std::string(buf);
		}

		inline std::string time_stamp()
		{
			time_t now = std::time(0);
			struct tm tstruct;
			char buf[80];

			tstruct = *std::localtime(&now);

			/** Visit http://en.cppreference.com/w/cpp/chrono/c/strftime */
			/** for more information about date/time format. */
			std::strftime(buf, sizeof(buf), "%H%M%S", &tstruct);

			return std::string(buf);
		}
	}
}

#endif /* YGL_CLOCK_CLOCK_H_ */
