#ifndef YGL_GUI_HUD_H_
#define YGL_GUI_HUD_H_

#pragma once

#include <iostream>
#include <string>

#include "graphic/shape.h"
#include "graphic/text.h"
#include "graphic/text.h"
#include "math/color.h"
#include "math/point.h"
#include "math/rotate.h"
#include "math/size.h"
#include "math/math.h"

namespace ygl
{
	namespace gui
	{
		class hud
		{
			public:

				hud();

				hud(const std::string& filename, std::size_t measure, const ygl::math::sized& size);

				~hud();

				bool initialize(const std::string& filename, std::size_t measure, const ygl::math::sized& size);

				void destroy();

				void draw();

				void draw(const std::string& message, const ygl::math::pointd& position = ygl::math::pointd().null(), const ygl::math::rotated& rotate = ygl::math::rotated().null(), const ygl::math::colord& color = ygl::math::colord().null(), int opacity = -1, const ygl::graphic::align& align = ygl::graphic::align::ALIGN_NULL);

				void data(const std::string& message);

				void visible(bool visible);

				void color(const ygl::math::colord& color);

				void color(double r, double g, double b);

				void color_r(double r);

				void color_g(double g);

				void color_b(double b);

				void opacity(double opacity);

				void position(const ygl::math::pointd& position);

				void position(double x, double y, double z);

				void position_x(double x);

				void position_y(double y);

				void position_z(double z);

				void rotate(const ygl::math::rotated& rotate);

				void rotate(double h, double p, double b);

				void rotate_h(double h);

				void rotate_p(double p);

				void rotate_b(double b);

				void scale(const ygl::math::sized& scale);

				void scale(double w, double h, double l);

				void scale_w(double w);

				void scale_h(double h);

				void scale_l(double l);

				const std::string& data() const;

				bool visible() const;

				const ygl::math::colord& color() const;

				double opacity() const;

				const ygl::math::pointd& position() const;

				const ygl::math::rotated& rotate() const;

				const ygl::math::sized& scale() const;

				const ygl::math::sized& size() const;

				ygl::graphic::shape* access_box();

				ygl::graphic::text* access_data();

			protected:

				ygl::graphic::shape*	_box		{ nullptr };
				ygl::graphic::text*		_data		{ nullptr };
				bool					_visible	{ true };
				ygl::math::colord		_color		{ ygl::math::colord().WHITE() };
				double					_opacity	{ 100 };
				ygl::math::pointd		_position	{ ygl::math::pointd() };
				ygl::math::rotated		_rotate		{ ygl::math::rotated() };
				ygl::math::sized		_scale		{ ygl::math::sized(1) };
				ygl::math::sized		_size		{ ygl::math::sized() };
		};
	}
}

#endif /* YGL_GUI_HUD_H_ */
