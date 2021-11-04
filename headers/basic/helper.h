#ifndef YGL_BASIC_HELPTER_H_
#define YGL_BASIC_HELPTER_H_

#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include <GL/glew.h>

#include "graphic/sprite.h"
#include "math/point.h"
#include "math/rotate.h"
#include "math/size.h"
#include "math/color.h"

namespace ygl
{
	namespace basic
	{
		/* XXX.XXX,XX */
		inline void horizontal(ygl::graphic::sprite* sprite, const ygl::math::pointd& position, int value, const std::string& format)
		{
			ygl::math::pointd pos = position;
			int num = ygl::math::numumber_digits(value);
			int lim = (format.length() - 1) - num;

			for (std::size_t i = 0; i < format.length(); i++)
			{
				pos.x(position.x() + (sprite->size().w() * i));

				if (format[i] == 'X')
				{
					int val = static_cast<int>(std::pow((float)10, (float)num - 1));

					if (value >= val && num >= 0 && i >= (std::size_t)lim)
					{
						sprite->draw(pos, static_cast<int>(value / val) % 10);
						num--;
					}
					else
					{
						sprite->draw(pos, 0);
					}
				}
				else if (format[i] == '.')
				{
					sprite->draw(pos, 10);
				}
				else if (format[i] == ',')
				{
					sprite->draw(pos,11);
				}
			}
		}

		inline void begin()
		{
			glPushMatrix();
		}

		inline void end()
		{
			glPopMatrix();
		}

		template<typename T>
		inline void position(const ygl::math::point<T>& position)
		{
			glTranslated(position.x(), position.y(), 0.f);
		}

		template<typename T>
		inline void position(const T& x, const T& y)
		{
			glTranslated(x, y, 0.f);
		}

		template<typename T>
		inline void rotating(const ygl::math::rotate<T>& rotate)
		{
			glRotated(rotate.h(), 1.0, 0.0, 0.0);
			glRotated(rotate.p(), 0.0, 1.0, 0.0);
			glRotated(rotate.b(), 0.0, 0.0, 1.0);
		}

		template<typename T>
		inline void rotating(const T& h, const T& p, const T& b)
		{
			glRotated(h, 1.0, 0.0, 0.0);
			glRotated(p, 0.0, 1.0, 0.0);
			glRotated(b, 0.0, 0.0, 1.0);
		}

		template<typename T>
		inline void scaling(const ygl::math::size<T>& scale)
		{
			glScaled(scale.w(), scale.h(), 1.0);
		}

		template<typename T>
		inline void scaling(const T& w, const T& h)
		{
			glScaled(w, h, 1.0);
		}

		inline void coloring(const ygl::math::colord& color)
		{
			glColor4d(
				ygl::math::normal_channel(color.r()),
				ygl::math::normal_channel(color.g()),
				ygl::math::normal_channel(color.b()),
				1.0
			);
		}

		inline void coloring(double& r, double g, double b)
		{
			glColor4d(
				ygl::math::normal_channel(r),
				ygl::math::normal_channel(g),
				ygl::math::normal_channel(b),
				1.f
			);
		}

		template<typename T>
		inline void opaciting(const T& opacity)
		{
			glColor4d(1.0, 1.0, 1.0, ygl::math::normal_opacity(opacity));
		}
	}
}

#endif /* YGL_BASIC_HELPTER_H_ */
