#ifndef YGL_DEVICE_TOUCH_H_
#define YGL_DEVICE_TOUCH_H_

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
		class touch
		{
			public:

				touch();

				~touch();

				void finger(const ygl::device::finger& finger);

				void position(const ygl::math::pointd& position);

				void position(double x, double y, double z);

				bool motioned() const;

				bool pressed() const;

				bool released() const;

				const ygl::math::pointd& position() const;

				const ygl::device::finger& finger() const;

				void clear();

			protected:

				ygl::device::finger	_finger		{ ygl::device::finger::FINGER_NONE };
				ygl::math::pointd	_position	{ ygl::math::pointd().null() };
		};
	}
}

#endif /* YGL_DEVICE_TOUCH_H_ */
