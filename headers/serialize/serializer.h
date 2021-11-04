#ifndef YGL_SERIALIZE_SERIALIZER_H_
#define YGL_SERIALIZE_SERIALIZER_H_

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <iosfwd>
#include <fstream>

namespace ygl
{
	namespace serialize
	{
		class serializer
		{
			public:

				serializer();

				serializer(const serializer&) = delete;

				~serializer();

				bool initialize(const std::string& filename);

				void destroy();

				bool attach(const std::string& key, const std::string& value);

				std::size_t get_rows() const;

				const std::string& get_filename() const;

				const std::string& get_value(const std::string& key);

				std::string get_stamp(std::size_t index);

			protected:

				std::size_t							_rows		{ 0 };
				std::string							_filename	{ std::string() };
				std::map<std::string, std::string>	_data		{ std::map<std::string, std::string>() };
		};
	}
}

#endif /* YGL_SERIALIZE_SERIALIZER_H_ */
