#ifndef YGL_CORE_CAMERA_H_
#define YGL_CORE_CAMERA_H_

#pragma once

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>

#include "math/math.h"
#include "math/color.h"
#include "math/point.h"
#include "math/rotate.h"
#include "math/size.h"

namespace ygl
{
	namespace core
	{
		class camera
		{
			public:

				camera();

				camera(const ygl::core::camera&) = delete;

				~camera();

				bool initialize(const std::string& name, const ygl::math::pointd& position, const ygl::math::sized& size);

				void destroy();

				void renderize();

				const std::string& name() const;

				const ygl::math::colord& color() const;

				double opacity() const;

				const ygl::math::pointd& position() const;

				const ygl::math::rotated& rotate() const;

				const ygl::math::sized& size() const;

				const ygl::math::sized& scale() const;

				void name(const std::string& name);

				void color(const ygl::math::colord& color);

				void opacity(double opacity);

				void position(const ygl::math::pointd& position);

				void rotate(const ygl::math::rotated& rotate);

				void size(const ygl::math::sized& size);

				void scale(const ygl::math::sized& scale);

			protected:

				std::string			_name		{ "Unamed" };
				ygl::math::colord	_color		{ ygl::math::colord().WHITE() };
				double				_opacity	{ 100.0 };
				ygl::math::pointd	_position	{ ygl::math::pointd() };
				ygl::math::rotated	_rotate		{ ygl::math::rotated() };
				ygl::math::sized	_size		{ ygl::math::sized() };
				ygl::math::sized	_scale		{ ygl::math::sized() };
		};
	}
}

#endif /* YGL_CORE_CAMERA_H_ */
