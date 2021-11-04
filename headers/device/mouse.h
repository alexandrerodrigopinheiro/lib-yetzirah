#ifndef YGL_DEVICE_MOUSE_H_
#define YGL_DEVICE_MOUSE_H_

#pragma once

#pragma once

#include <string>
#include <iostream>

#include "error/exception.h"
#include "device/device.h"
#include "math/point.h"

namespace ygl
{
	namespace device
	{
		class mouse
		{
			public:

				mouse();

				~mouse();

				void cursor(const ygl::device::cursor& cursor);

				void position(const ygl::math::pointd& position);

				void position(double x, double y, double z);

				bool motioned() const;

				bool pressed() const;

				bool released() const;

				const ygl::math::pointd& position() const;

				const ygl::device::cursor& cursor() const;

				void clear();

			protected:

				ygl::device::cursor	_cursor		{ ygl::device::cursor::CURSOR_NONE };
				ygl::math::pointd	_position	{ ygl::math::pointd().null() };
		};
	}
}

#endif /* YGL_DEVICE_MOUSE_H_ */
