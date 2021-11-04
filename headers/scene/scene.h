#ifndef YGL_SCENE_SCENE_H_
#define YGL_SCENE_SCENE_H_

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
		class scene
		{
			public:

				scene();

				virtual ~scene();

				virtual bool loading() = 0;

				virtual void release() = 0;

				virtual void keyboard(const ygl::device::keyboard& keyboard) = 0;

				virtual void mouse(const ygl::device::mouse& mouse) = 0;

				virtual void touch(const ygl::device::touch& touch) = 0;

				virtual void update() = 0;

				virtual void render() = 0;

				virtual void clear() = 0;

				virtual bool save() = 0;

				virtual bool load() = 0;

				void next_scene(const std::string& scene);

				const std::string& next_scene() const;

				void clear_next_scene();

			protected:

				std::string	_next_scene	{ std::string() };
		};
	}
}

#endif /* YGL_SCENE_SCENE_H_ */
