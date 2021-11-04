#include "graphic/graphic.h"

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::type& type)
{
	switch (type)
	{
		case ygl::graphic::type::TYPE_LAYER:
		{
			stream << "TYPE { LAYER }";
			break;
		}
		case ygl::graphic::type::TYPE_SHAPE:
		{
			stream << "TYPE { SHAPE }";
			break;
		}
		case ygl::graphic::type::TYPE_SPRITE:
		{
			stream << "TYPE { SPRITE }";
			break;
		}
		case ygl::graphic::type::TYPE_FONT:
		{
			stream << "TYPE { FONT }";
			break;
		}
		case ygl::graphic::type::TYPE_EMITTER:
		{
			stream << "TYPE { EMITTER }";
			break;
		}
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::type& type)
{
	std::string garbage;
	std::string value;

	stream >> garbage;
	stream >> garbage;
	stream >> value;
	stream >> garbage;

	if (value == "LAYER")
	{
		type = ygl::graphic::type::TYPE_LAYER;
	}
	else if (value == "SHAPE")
	{
		type = ygl::graphic::type::TYPE_SHAPE;
	}
	else if (value == "SPRITE")
	{
		type = ygl::graphic::type::TYPE_SPRITE;
	}
	else if (value == "FONT")
	{
		type = ygl::graphic::type::TYPE_FONT;
	}
	else if (value == "EMITTER")
	{
		type = ygl::graphic::type::TYPE_EMITTER;
	}

	return stream;
}

ygl::graphic::type ygl::graphic::to_type(const std::string& type)
{
	ygl::graphic::type out;

	if (type == "LAYER")
	{
		out = ygl::graphic::type::TYPE_LAYER;
	}
	else if (type == "SHAPE")
	{
		out = ygl::graphic::type::TYPE_SHAPE;
	}
	else if (type == "SPRITE")
	{
		out = ygl::graphic::type::TYPE_SPRITE;
	}
	else if (type == "FONT")
	{
		out = ygl::graphic::type::TYPE_FONT;
	}
	else if (type == "EMITTER")
	{
		out = ygl::graphic::type::TYPE_EMITTER;
	}

	return out;
}

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::flip& flip)
{
	switch (flip)
	{
		case ygl::graphic::flip::FLIP_NONE:       { stream << " FLIP { NONE }";       break; }
		case ygl::graphic::flip::FLIP_HORIZONTAL: { stream << " FLIP { HORIZONTAL }"; break; }
		case ygl::graphic::flip::FLIP_VERTICAL:   { stream << " FLIP { VERTICAL }";   break; }
		case ygl::graphic::flip::FLIP_ALL:        { stream << " FLIP { ALL }";        break; }
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::flip& flip)
{
	std::string garbage;
	std::string value;

	stream >> garbage;
	stream >> garbage;
	stream >> value;
	stream >> garbage;

	     if (value == "NONE") 		{ flip = ygl::graphic::flip::FLIP_NONE; }
	else if (value == "HORIZONTAL") { flip = ygl::graphic::flip::FLIP_HORIZONTAL; }
	else if (value == "VERTICAL")   { flip = ygl::graphic::flip::FLIP_VERTICAL; }
	else if (value == "ALL")        { flip = ygl::graphic::flip::FLIP_ALL; }

	return stream;
}

ygl::graphic::flip ygl::graphic::to_flip(const std::string& flip)
{
	ygl::graphic::flip out;

	     if (flip == "NONE") { out = ygl::graphic::flip::FLIP_NONE; }
	else if (flip == "HORIZONTAL") { out = ygl::graphic::flip::FLIP_HORIZONTAL; }
	else if (flip == "VERTICAL")   { out = ygl::graphic::flip::FLIP_VERTICAL; }
	else if (flip == "ALL")        { out = ygl::graphic::flip::FLIP_ALL; }

	return out;
}

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::align& align)
{
	switch (align)
	{
		case ygl::graphic::align::ALIGN_NULL:
		{
			stream << "{ ALIGN_NULL }";
			break;
		}
		case ygl::graphic::align::ALIGN_CENTER:
		{
			stream << "{ ALIGN_CENTER }";
			break;
		}
		case ygl::graphic::align::ALIGN_RIGHT:
		{
			stream << "{ ALIGN_RIGHT }";
			break;
		}
		case ygl::graphic::align::ALIGN_LEFT:
		{
			stream << "{ ALIGN_LEFT }";
			break;
		}
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::align& align)
{
	std::string garbage;
	std::string value;

	stream >> garbage;
	stream >> value;
	stream >> garbage;

	if (value == "ALIGN_NULL")
	{
		align = ygl::graphic::align::ALIGN_NULL;
	}
	else if (value == "ALIGN_CENTER")
	{
		align = ygl::graphic::align::ALIGN_CENTER;
	}
	else if (value == "ALIGN_RIGHT")
	{
		align = ygl::graphic::align::ALIGN_RIGHT;
	}
	else if (value == "ALIGN_LEFT")
	{
		align = ygl::graphic::align::ALIGN_LEFT;
	}

	return stream;
}

ygl::graphic::align ygl::graphic::to_align(const std::string& align)
{
	ygl::graphic::align out;

	if (align == "ALIGN_NULL")
	{
		out = ygl::graphic::align::ALIGN_NULL;
	}
	else if (align == "ALIGN_CENTER")
	{
		out = ygl::graphic::align::ALIGN_CENTER;
	}
	else if (align == "ALIGN_RIGHT")
	{
		out = ygl::graphic::align::ALIGN_RIGHT;
	}
	else if (align == "ALIGN_LEFT")
	{
		out = ygl::graphic::align::ALIGN_LEFT;
	}

	return out;
}

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::weight& weight)
{
	switch (weight)
	{
		case ygl::graphic::weight::WEIGHT_NORMAL:        { stream << "WEIGHT { NORMAL }"; break; }
		case ygl::graphic::weight::WEIGHT_BOLD:          { stream << "WEIGHT { BOLD }"; break; }
		case ygl::graphic::weight::WEIGHT_ITALIC:        { stream << "WEIGHT { ITALIC }"; break; }
		case ygl::graphic::weight::WEIGHT_UNDERLINE:     { stream << "WEIGHT { UNDERLINE }"; break; }
		case ygl::graphic::weight::WEIGHT_STRIKETHROUGH: { stream << "WEIGHT { STRIKETHROUGH }"; break; }
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::weight& weight)
{
	std::string garbage;
	std::string value;

	stream >> garbage;
	stream >> garbage;
	stream >> value;
	stream >> garbage;

	     if (value == "NORMAL")        { weight = ygl::graphic::weight::WEIGHT_NORMAL; }
	else if (value == "BOLD")          { weight = ygl::graphic::weight::WEIGHT_BOLD; }
	else if (value == "ITALIC")        { weight = ygl::graphic::weight::WEIGHT_ITALIC; }
	else if (value == "UNDERLINE")     { weight = ygl::graphic::weight::WEIGHT_UNDERLINE; }
	else if (value == "STRIKETHROUGH") { weight = ygl::graphic::weight::WEIGHT_STRIKETHROUGH; }

	return stream;
}

ygl::graphic::weight ygl::graphic::to_weight(const std::string& weight)
{
	ygl::graphic::weight out;

	     if (weight == "NORMAL")        { out = ygl::graphic::weight::WEIGHT_NORMAL; }
	else if (weight == "BOLD")          { out = ygl::graphic::weight::WEIGHT_BOLD; }
	else if (weight == "ITALIC")        { out = ygl::graphic::weight::WEIGHT_ITALIC; }
	else if (weight == "UNDERLINE")     { out = ygl::graphic::weight::WEIGHT_UNDERLINE; }
	else if (weight == "STRIKETHROUGH") { out = ygl::graphic::weight::WEIGHT_STRIKETHROUGH; }

	return out;
}

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::hinting& hinting)
{
	switch (hinting)
	{
		case ygl::graphic::hinting::HINTING_DEFAULT: { stream << "HINTING { DEFAULT }"; break; }
		case ygl::graphic::hinting::HINTING_LIGHT:   { stream << "HINTING { LIGHT }"; break; }
		case ygl::graphic::hinting::HINTING_MONO:    { stream << "HINTING { MONO }"; break; }
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::hinting& hinting)
{
	std::string garbage;
	std::string value;

	stream >> garbage;
	stream >> garbage;
	stream >> value;
	stream >> garbage;

	     if (value == "DEFAULT") { hinting = ygl::graphic::hinting::HINTING_DEFAULT; }
	else if (value == "LIGHT")   { hinting = ygl::graphic::hinting::HINTING_LIGHT; }
	else if (value == "MONO")    { hinting = ygl::graphic::hinting::HINTING_MONO; }

	return stream;
}

ygl::graphic::hinting ygl::graphic::to_hinting(const std::string& hinting)
{
	ygl::graphic::hinting out;

	if (hinting == "NORMAL")      { out = ygl::graphic::hinting::HINTING_LIGHT; }
	else if (hinting == "BOLD")   { out = ygl::graphic::hinting::HINTING_LIGHT; }
	else if (hinting == "ITALIC") { out = ygl::graphic::hinting::HINTING_MONO; }

	return out;
}

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::orientation& orientation)
{
	switch (orientation)
	{
		case ygl::graphic::orientation::ORIENTATION_GLOBAL: { stream << "ORIENTATION { GLOBAL }"; break; }
		case ygl::graphic::orientation::ORIENTATION_LOCAL:  { stream << "ORIENTATION { LOCAL }"; break; }
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::orientation& orientation)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	     if (value == "GLOBAL") { orientation = ygl::graphic::orientation::ORIENTATION_GLOBAL; }
	else if (value == "LOCAL")  { orientation = ygl::graphic::orientation::ORIENTATION_LOCAL; }

	return stream;
}

ygl::graphic::orientation ygl::graphic::to_orientation(const std::string& orientation)
{
	ygl::graphic::orientation out;

	     if (orientation == "GLOBAL") { out = ygl::graphic::orientation::ORIENTATION_GLOBAL; }
	else if (orientation == "LOCAL")  { out = ygl::graphic::orientation::ORIENTATION_LOCAL; }

	return out;
}

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::visible& visible)
{
	switch (visible)
	{
		case ygl::graphic::visible::VISIBLE_ON: { stream << "VISIBLE { ON }"; break; }
		case ygl::graphic::visible::VISIBLE_OFF: { stream << "VISIBLE { OFF }"; break; }
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::visible& visible)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	     if (value == "ON") { visible = ygl::graphic::visible::VISIBLE_ON; }
	else if (value == "OFF") { visible = ygl::graphic::visible::VISIBLE_OFF; }

	return stream;
}

ygl::graphic::visible ygl::graphic::to_visible(const std::string& visible)
{
	ygl::graphic::visible out;

	     if (visible == "ON") { out = ygl::graphic::visible::VISIBLE_ON; }
	else if (visible == "OFF")  { out = ygl::graphic::visible::VISIBLE_OFF; }

	return out;
}

std::ostream& ygl::graphic::operator<<(std::ostream& stream, const ygl::graphic::status& status)
{
	switch (status)
	{
		case ygl::graphic::status::STATUS_NULL:     { stream << "STATUS { NULL }"    ; break; }
		case ygl::graphic::status::STATUS_ENABLED:  { stream << "STATUS { ENABLED }"  ; break; }
		case ygl::graphic::status::STATUS_HOVER:    { stream << "STATUS { HOVER }"   ; break; }
		case ygl::graphic::status::STATUS_PRESSED:  { stream << "STATUS { PRESSED }" ; break; }
		case ygl::graphic::status::STATUS_RELEASED: { stream << "STATUS { RELEASED }"; break; }
		case ygl::graphic::status::STATUS_DISABLED: { stream << "STATUS { DISABLED }"; break; }
	}

	return stream;
}

std::istream& ygl::graphic::operator>>(std::istream& stream, ygl::graphic::status& status)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	     if (value == "NULL")     { status = ygl::graphic::status::STATUS_NULL    ; }
	else if (value == "ENABLED")   { status = ygl::graphic::status::STATUS_ENABLED ; }
	else if (value == "HOVER")    { status = ygl::graphic::status::STATUS_HOVER   ; }
	else if (value == "PRESSED")  { status = ygl::graphic::status::STATUS_PRESSED ; }
	else if (value == "RELEASED") { status = ygl::graphic::status::STATUS_RELEASED; }
	else if (value == "DISABLED") { status = ygl::graphic::status::STATUS_DISABLED; }

	return stream;
}

ygl::graphic::status ygl::graphic::to_status(const std::string& status)
{
	ygl::graphic::status out;

	     if (status == "NULL")     { out = ygl::graphic::status::STATUS_NULL    ; }
	else if (status == "ENABLED")  { out = ygl::graphic::status::STATUS_ENABLED ; }
	else if (status == "HOVER")    { out = ygl::graphic::status::STATUS_HOVER   ; }
	else if (status == "PRESSED")  { out = ygl::graphic::status::STATUS_PRESSED ; }
	else if (status == "RELEASED") { out = ygl::graphic::status::STATUS_RELEASED; }
	else if (status == "DISABLED") { out = ygl::graphic::status::STATUS_DISABLED; }

	return out;
}
