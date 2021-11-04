#include "serialize/serialize.h"

std::ostream& ygl::serialize::operator<<(std::ostream& stream, const ygl::serialize::type& type)
{
	switch (type)
	{
		case ygl::serialize::type::TYPE_IMAGE:
		{
			stream << "TYPE { IMAGE }";
			break;
		}
		case ygl::serialize::type::TYPE_FONT:
		{
			stream << "TYPE { FONT }";
			break;
		}
		case ygl::serialize::type::TYPE_ANIMATION:
		{
			stream << "TYPE { ANIMATION }";
			break;
		}
		case ygl::serialize::type::TYPE_SOUND:
		{
			stream << "TYPE { SOUND }";
			break;
		}
		case ygl::serialize::type::TYPE_FX:
		{
			stream << "TYPE { FX }";
			break;
		}
	}
	return stream;
}

std::istream& ygl::serialize::operator>>(std::istream& stream, ygl::serialize::type& type)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "IMAGE")
	{
		type = ygl::serialize::type::TYPE_IMAGE;
	}
	else if (value == "FONT")
	{
		type = ygl::serialize::type::TYPE_FONT;
	}
	else if (value == "ANIMATION")
	{
		type = ygl::serialize::type::TYPE_ANIMATION;
	}
	else if (value == "SOUND")
	{
		type = ygl::serialize::type::TYPE_SOUND;
	}
	else if (value == "FX")
	{
		type = ygl::serialize::type::TYPE_FX;
	}

	return stream;
}

ygl::serialize::type ygl::serialize::to_type(const std::string& str)
{
	ygl::serialize::type out;

	if (str == "IMAGE")
	{
		out = ygl::serialize::type::TYPE_IMAGE;
	}
	else if (str == "FONT")
	{
		out = ygl::serialize::type::TYPE_FONT;
	}
	else if (str == "ANIMATION")
	{
		out = ygl::serialize::type::TYPE_ANIMATION;
	}
	else if (str == "SOUND")
	{
		out = ygl::serialize::type::TYPE_SOUND;
	}
	else if (str == "FX")
	{
		out = ygl::serialize::type::TYPE_FX;
	}

	return out;
}
