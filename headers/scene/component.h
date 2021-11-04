#ifndef YGL_SCENE_COMPONENT_H_
#define YGL_SCENE_COMPONENT_H_

#pragma once

#include <string>
#include <iostream>

#include "device/device.h"
#include "device/keyboard.h"
#include "device/mouse.h"
#include "device/touch.h"
#include "math/point.h"

namespace ygl
{
	namespace scene
	{
		class component
		{
			public:

				component();

				virtual ~component();

				virtual bool initialize(const ygl::math::pointd& position) = 0;

				virtual void destroy() = 0;

				virtual void keyboard(const ygl::device::keyboard& keyboard) = 0;

				virtual void mouse(const ygl::device::mouse& mouse) = 0;

				virtual void touch(const ygl::device::touch& touch) = 0;

				virtual void update() = 0;

				virtual void render() = 0;

				virtual void clear() = 0;

				virtual bool save() = 0;

				virtual bool load() = 0;

				ygl::math::pointd	_position	{ ygl::math::pointd() };
		};
	}
}

#endif /* YGL_SCENE_COMPONENT_H_ */
