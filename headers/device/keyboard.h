#ifndef YGL_DEVICE_KEYBOARD_H_
#define YGL_DEVICE_KEYBOARD_H_

#pragma once

#pragma once

#include <string>
#include <iostream>

#include "error/exception.h"
#include "device/device.h"

namespace ygl
{
	namespace device
	{
		class keyboard
		{
			public:

				keyboard();

				~keyboard();

				void button(const ygl::device::button& button);

				void key(const ygl::device::key& key);

				const ygl::device::button& button() const;

				bool pressed() const;

				bool released() const;

				void clear();

			protected:

				ygl::device::button	_button { ygl::device::button::BUTTON_INVALID };
				ygl::device::key	_key	{ ygl::device::key::KEY_NONE };
		};
	}
}

#endif /* YGL_DEVICE_KEYBOARD_H_ */
