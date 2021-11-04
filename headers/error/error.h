#ifndef YGL_ERROR_ERROR_H_
#define YGL_ERROR_ERROR_H_

#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>

#define YGL_ERROR_GL_CHECK(x) \
	do { \
		x; \
		GLenum err = glGetError(); \
		while (err != GL_NO_ERROR) { \
			if (err != GL_NO_ERROR) \
				fprintf(stderr, "ERROR: %s:%d: glGetError() returned %s for call '%s'\n", \
					__FILE__, __LINE__, gluErrorString(err), #x ); \
			err = glGetError(); \
		} \
	} while (0)

namespace ygl
{
	namespace error
	{
		typedef enum type
		{
			ERROR_NONE = 0,
			ERROR_FAILED,
			ERROR_UNSIGNED,
			ERROR_INITIALIZED,
			ERROR_LOAD_IMAGE,
			ERROR_TCPIP_RESET,
			ERROR_TCPIP_TIMEOUT,
			ERROR_TCPIP_UNREAD,
			ERROR_AMOUNT
		} type;

		std::ostream& operator<<(std::ostream &stream, const ygl::error::type& arg);

		std::istream& operator>>(std::istream &stream, ygl::error::type& arg);
	}
}

#endif /* YGL_ERROR_ERROR_H_ */
