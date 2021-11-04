#ifndef YGL_SERIALIZE_MEMORIZE_H_
#define YGL_SERIALIZE_MEMORIZE_H_

#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <iosfwd>
#include <fstream>

#include "basic/basic.h"

namespace ygl
{
	namespace serialize
	{
		class memorize
		{
			public:

				memorize();

				memorize(const memorize& obj);

				memorize(const std::string& filename);

				~memorize();

				bool initialize(const std::string& filename);

				void destroy();

				bool copy(ygl::serialize::memorize& obj);

				bool attach(const std::string& key, const std::string& value);

				std::size_t rows() const;

				const std::string& filename() const;

				const std::string& value(const std::string& key);

				std::string stamp(std::size_t index);

			protected:

				std::size_t							_rows		{ 0 };
				std::string							_filename	{ std::string() };
				std::map<std::string, std::string>	_data		{ std::map<std::string, std::string>() };
		};
	}
}

#endif /* YGL_SERIALIZE_MEMORIZE_H_ */
