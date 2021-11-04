#ifndef YGL_GRAPHIC_TEXT_H_
#define YGL_GRAPHIC_TEXT_H_

#pragma once

#include <iostream>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <GL/glew.h>

#include "animation/animation.h"
#include "animation/animator.h"
#include "animation/tween.h"
#include "basic/basic.h"
#include "math/math.h"
#include "math/color.h"
#include "math/point.h"
#include "math/rotate.h"
#include "math/surface.h"
#include "math/size.h"
#include "math/uvmap.h"
#include "math/vertex.h"
#include "graphic/graphic.h"
#include "../serialize/animatic.h"

namespace ygl
{
	namespace graphic
	{
		class text
		{
		public:

			text();

			text(const ygl::graphic::text&) = delete;

			text(const std::string& filename, std::size_t measure);

			~text();

			bool initialize(const std::string& filename, std::size_t measure);

			void destroy();

			ygl::animation::tween* tweening(const std::string& animation);

			bool animation(const std::string& animation, std::size_t timeline);

			bool animation(const std::string& animation, std::size_t timeline, std::size_t fps);

			void animation(const std::string& animation);

			bool sensible(const std::string& name, const ygl::math::surfaced& sensible);

			const ygl::math::surfaced& sensible(const std::string& name);

			void draw();

			void draw(const std::string& message, const ygl::math::pointd& position = ygl::math::pointd().null(), const ygl::math::rotated& rotate = ygl::math::rotated().null(), const ygl::math::sized& scale = ygl::math::sized().null(), const ygl::math::colord& color = ygl::math::colord().null(), const ygl::graphic::align& align = ygl::graphic::align::ALIGN_NULL);

			void running();

			void start();

			void pause();

			void restart();

			void reset();

			bool started();

			bool border();

			bool onset();

			void message(const std::string& message);

			void align(const ygl::graphic::align& align);

			void weight(const ygl::graphic::weight& weight);

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

			std::size_t measure() const;

			const std::string& message() const;

			const ygl::graphic::align& align() const;

			const ygl::graphic::weight& weight() const;

			bool visible() const;

			bool wireframe() const;

			const ygl::graphic::flip& flip() const;

			const ygl::math::colord& color() const;

			double opacity() const;

			const ygl::graphic::orientation& orientation() const;

			const ygl::math::pointd& pivot() const;

			const ygl::math::pointd& position() const;

			const ygl::math::sized& scale() const;

			const ygl::math::rotated& rotate() const;

			const ygl::math::sized& size() const;

		private:

			void resolve();

		protected:

			uint											_data			{ 0 };
			TTF_Font*										_font			{ nullptr };
			std::string										_filename		{ std::string() };
			std::size_t										_measure		{ 0 };
			std::string										_buffer			{ std::string() };
			std::string										_message		{ std::string() };
			ygl::graphic::align								_align			{ ygl::graphic::align::ALIGN_LEFT };
			ygl::graphic::weight							_weight			{ ygl::graphic::weight::WEIGHT_NORMAL };
			bool											_visible		{ true };
			bool											_wireframe		{ false };
			ygl::graphic::flip								_flip			{ ygl::graphic::flip::FLIP_NONE };
			ygl::math::colord								_color			{ ygl::math::colord().WHITE() };
			double											_opacity		{ 100.0 };
			ygl::graphic::orientation						_orientation	{ ygl::graphic::orientation::ORIENTATION_GLOBAL };
			ygl::math::pointd								_pivot			{ ygl::math::pointd() };
			ygl::math::pointd								_position		{ ygl::math::pointd() };
			ygl::math::sized								_scale			{ ygl::math::sized() };
			ygl::math::rotated								_rotate			{ ygl::math::rotated() };
			ygl::math::sized								_size			{ ygl::math::sized() };
			ygl::math::surfaced								_offset			{ ygl::math::surfaced() };
			ygl::math::vertexd								_vertex			{ ygl::math::vertexd() };
			ygl::math::uvmapd								_map			{ ygl::math::uvmapd() };
			bool											_running		{ false };
			std::string										_animation		{ std::string() };
			std::map<std::string, ygl::math::surfaced>		_sensible		{ std::map<std::string, ygl::math::surfaced>() };
			std::map<std::string, ygl::animation::tween*>	_tweening		{ std::map<std::string, ygl::animation::tween*>() };
		};
	}
}

#endif /* YGL_GRAPHIC_TEXT_H_ */
