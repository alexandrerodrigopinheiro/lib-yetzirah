#ifndef YGL_CONNECT_SQL_H_
#define YGL_CONNECT_SQL_H_

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace ygl
{
	namespace connect
	{
		extern const std::size_t BUFFER_SIZE;

		typedef std::vector<std::map<std::string, std::string>> row;

		typedef std::vector<std::string> field;
	}
}

#endif /* YGL_CONNECT_SQL_H_ */
