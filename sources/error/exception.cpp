#include "error/exception.h"

ygl::error::exception::exception(const std::string& e) :
	std::runtime_error(e)
{
}
