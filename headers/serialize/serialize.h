#ifndef YGL_SERIALIZE_SERIALIZE_H_
#define YGL_SERIALIZE_SERIALIZE_H_

#pragma once

#include <iostream>
#include <string>

namespace ygl
{
	namespace serialize
	{
		typedef enum type
		{
			TYPE_IMAGE = 0,
			TYPE_FONT,
			TYPE_ANIMATION,
			TYPE_SOUND,
			TYPE_FX
		} type;

		std::ostream& operator<<(std::ostream& stream, const ygl::serialize::type& type);

		std::istream& operator>>(std::istream& stream, ygl::serialize::type& type);

		ygl::serialize::type to_type(const std::string& str);
	}
}

#endif /* YGL_SERIALIZE_SERIALIZE_H_ */
