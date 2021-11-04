#ifndef YGL_GRAPHIC_STREAM_H_
#define YGL_GRAPHIC_STREAM_H_

#pragma once

#include <iostream>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "animation/animation.h"
#include "animation/animator.h"
#include "animation/tween.h"
#include "basic/basic.h"
#include "error/error.h"
#include "graphic/graphic.h"
#include "math/color.h"
#include "math/math.h"
#include "math/matrix.h"
#include "math/point.h"
#include "math/surface.h"
#include "math/rotate.h"
#include "math/size.h"
#include "math/uvmap.h"
#include "math/vertex.h"
#include "../serialize/animatic.h"

namespace ygl
{
	namespace graphic
	{
		class stream
		{
		public:

			stream();

			stream(const ygl::graphic::stream&) = delete;

			stream(const std::string& filename);

			~stream();

			bool initialize(const std::string& filename);

			void destroy();

			void draw();

			void draw(const ygl::math::pointd& position, const ygl::math::rotated& rotate = ygl::math::rotated().null(), const ygl::math::sized& scale = ygl::math::sized().null(), const ygl::math::colord& color = ygl::math::colord().null());

			void loop(bool loop);

			void play();

			void pause();

			void replay();

			void reset();

			bool loop() const;

			bool playing();

			bool border();

			bool onset();

			void visible(bool visible);

			void wireframe(bool wireframe);

			void flip(const ygl::graphic::flip& flip);

			void color(const ygl::math::colord& color);

			void color(double r, double g, double b);

			void color_r(double r);

			void color_g(double g);

			void color_b(double b);

			void opacity(double opacity);

			void orientation(const ygl::graphic::orientation& orientation);

			void pivot(const ygl::math::pointd& pivot);

			void pivot(double x, double y, double z);

			void pivot_x(double x);

			void pivot_y(double y);

			void pivot_z(double z);

			void position(const ygl::math::pointd& position);

			void position(double x, double y, double z);

			void position_x(double x);

			void position_y(double y);

			void position_z(double z);

			void volume(std::size_t volume);

			void scale(const ygl::math::sized& scale);

			void scale(double w, double h, double l);

			void scale_w(double w);

			void scale_h(double h);

			void scale_l(double l);

			void rotate(const ygl::math::rotated& rotate);

			void rotate(double h, double p, double b);

			void rotate_h(double h);

			void rotate_p(double p);

			void rotate_b(double b);

			const std::string& filename() const;

			bool visible() const;

			bool wireframe() const;

			const ygl::graphic::flip& flip() const;

			const ygl::math::colord& color() const;

			double opacity() const;

			const ygl::graphic::orientation& orientation() const;

			const ygl::math::pointd& pivot() const;

			const ygl::math::pointd& position() const;

			std::size_t volume() const;

			const ygl::math::sized& scale() const;

			const ygl::math::rotated& rotate() const;

			const ygl::math::sized& size() const;

		private:

			void resolve();

		protected:

			std::size_t										_volume			{ 100 };
			bool											_loop			{ false };
			uint											_data			{ 0 };
			std::string										_filename		{ std::string() };
			bool											_visible		{ true };
			bool											_wireframe		{ false };
			ygl::graphic::flip								_flip			{ ygl::graphic::flip::FLIP_NONE };
			ygl::math::colord								_color			{ ygl::math::colord().WHITE() };
			double											_opacity		{ 100 };
			ygl::graphic::orientation						_orientation	{ ygl::graphic::orientation::ORIENTATION_GLOBAL };
			ygl::math::pointd								_pivot			{ ygl::math::pointd(0.5) };
			ygl::math::pointd								_position		{ ygl::math::pointd() };
			ygl::math::sized								_scale			{ ygl::math::sized() };
			ygl::math::rotated								_rotate			{ ygl::math::rotated() };
			ygl::math::sized								_size			{ ygl::math::sized() };
			ygl::math::surfaced								_offset			{ ygl::math::surfaced() };
			ygl::math::vertexd								_vertex			{ ygl::math::vertexd() };
			ygl::math::uvmapd								_map			{ ygl::math::uvmapd() };
		};
	}
}

#endif /* YGL_GRAPHIC_STREAM_H_ */
