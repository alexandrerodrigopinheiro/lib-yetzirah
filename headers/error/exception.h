#ifndef YGL_ERROR_EXCEPTION_H_
#define YGL_ERROR_EXCEPTION_H_

#pragma once

#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>

namespace ygl
{
	namespace error
	{
		class exception : public std::runtime_error
		{
			public:

				exception(const std::string& e);
		};
	}
}

#endif /* YGL_ERROR_EXCEPTION_H_ */
