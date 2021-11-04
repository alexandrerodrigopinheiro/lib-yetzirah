#include "error/error.h"

std::ostream& ygl::error::operator<<(std::ostream &stream, const ygl::error::type& arg)
{
	switch (arg)
	{
		case ygl::error::ERROR_NONE:          stream << "ERROR { NONE }";          break;
		case ygl::error::ERROR_FAILED:        stream << "ERROR { FAILED }";        break;
		case ygl::error::ERROR_UNSIGNED:      stream << "ERROR { UNSIGNED }";      break;
		case ygl::error::ERROR_INITIALIZED:   stream << "ERROR { INITIALIZED }";   break;
		case ygl::error::ERROR_LOAD_IMAGE:    stream << "ERROR { LOAD_IMAGE }";    break;
		case ygl::error::ERROR_TCPIP_RESET:   stream << "ERROR { TCPIP_RESET }";   break;
		case ygl::error::ERROR_TCPIP_TIMEOUT: stream << "ERROR { TCPIP_TIMEOUT }"; break;
		case ygl::error::ERROR_TCPIP_UNREAD:  stream << "ERROR { TCPIP_UNREAD }";  break;
		case ygl::error::ERROR_AMOUNT:        stream << "ERROR { AMOUNT }";        break;
	}
	return stream;
}

std::istream& ygl::error::operator>>(std::istream &stream, ygl::error::type& arg)
{
	std::string garbage;
	std::string value;
	stream >> garbage >> garbage >> value >> garbage;
	if (value == "NONE")
	{
		arg = ygl::error::ERROR_NONE;
	}
	else if (value == "FAILED")
	{
		arg = ygl::error::ERROR_FAILED;
	}
	else if (value == "UNSIGNED")
	{
		arg = ygl::error::ERROR_UNSIGNED;
	}
	else if (value == "INITIALIZED")
	{
		arg = ygl::error::ERROR_INITIALIZED;
	}
	else if (value == "LOAD_IMAGE")
	{
		arg = ygl::error::ERROR_LOAD_IMAGE;
	}
	else if (value == "TCPIP_RESET")
	{
		arg = ygl::error::ERROR_TCPIP_RESET;
	}
	else if (value == "TCPIP_TIMEOUT")
	{
		arg = ygl::error::ERROR_TCPIP_TIMEOUT;
	}
	else if (value == "TCPIP_UNREAD")
	{
		arg = ygl::error::ERROR_TCPIP_UNREAD;
	}
	else if (value == "AMOUNT")
	{
		arg = ygl::error::ERROR_AMOUNT;
	}
	return stream;
}
