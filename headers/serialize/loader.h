#ifndef YGL_SERIALIZE_LOADER_H_
#define YGL_SERIALIZE_LOADER_H_

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <streambuf>
#include <fstream>
#include <iosfwd>
#include <cstring>

#include "basic/basic.h"
#include "serialize/serialize.h"
#include "serialize/meta.h"

namespace ygl
{
	namespace serialize
	{
		class loader
		{
			public:

				loader();

				~loader();

				bool load(const std::string& filename);

				void resume();

				void fill();

				const std::vector<ygl::serialize::meta>& meta() const;

				const ygl::serialize::meta& meta(std::size_t index) const;

				std::size_t size() const;

			protected:

				std::vector<std::string>			_lines;
				std::vector<ygl::serialize::meta>	_meta;
		};
	}
}

#endif /* YGL_SERIALIZE_LOADER_H_ */
