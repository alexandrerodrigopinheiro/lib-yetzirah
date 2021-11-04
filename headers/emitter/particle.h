#ifndef YGL_EMITTER_PARTICLE_H_
#define YGL_EMITTER_PARTICLE_H_

#pragma once

#include <iostream>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>

#include "animation/animation.h"
#include "animation/key.h"
#include "animation/tween.h"
#include "basic/basic.h"
#include "emitter.h"
#include "error/error.h"
#include "graphic/graphic.h"
#include "gui/sensible.h"
#include "math/color.h"
#include "math/math.h"
#include "math/matrix.h"
#include "math/point.h"
#include "math/surface.h"
#include "math/rotate.h"
#include "math/size.h"
#include "math/uvmap.h"
#include "math/vertex.h"

namespace ygl
{
	namespace emitter
	{
		class particle
		{
			public:

				particle();

				particle(const ygl::emitter::particle& obj);

				particle(const ygl::math::sized& size, const ygl::math::colord& color);

				~particle();

				bool initialize(std::size_t data, const ygl::math::sized& size, const ygl::math::colord& color);

				bool initialize(const ygl::math::sized& size, const ygl::math::colord& color);

				void destroy();

				void draw();

				void draw(const ygl::math::pointd& position, const ygl::math::colord& color = ygl::math::colord().null());

				bool animation(std::size_t born, std::size_t life);

				void running();

				void start();

				void pause();

				void restart(const ygl::math::pointd& position);

				void reset(const ygl::math::pointd& position);

				bool started();

				bool is_born();

				bool is_life();

				bool bound();

				bool onset();

				void easy_opacity(const ygl::emitter::opacity& opacity);

				void easy_scale(const ygl::emitter::scale& scale);

				void easy_rotate(const ygl::emitter::rotate& rotate);

				void random_color(bool random);

				void gravity(double gravity);

				void wind(double wind);

				void friction(double friction);

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

				void velocity(const ygl::math::pointd& velocity);

				void velocity(double x, double y, double z);

				void velocity_x(double x);

				void velocity_y(double y);

				void velocity_z(double z);

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

				void depth(std::size_t depth);

				std::size_t life() const;

				std::size_t born() const;

				std::size_t timeline() const;

				bool random_color() const;

				double gravity() const;

				double wind() const;

				double friction() const;

				bool visible() const;

				bool wireframe() const;

				const ygl::graphic::flip& flip() const;

				const ygl::math::colord& color() const;

				double opacity() const;

				const ygl::graphic::orientation& orientation() const;

				const ygl::math::pointd& pivot() const;

				const ygl::math::pointd& position() const;

				const ygl::math::pointd& velocity() const;

				const ygl::math::sized& scale() const;

				const ygl::math::rotated& rotate() const;

				const ygl::math::sized& size() const;

			private:

				void resolve();

			protected:

				bool						_running			{ false };
				GLuint						_data				{ 0 };
				std::size_t					_life				{ 0 };
				std::size_t					_born				{ 0 };
				std::size_t					_timeline			{ 0 };
				double						_gravity			{ 0.0 };
				double						_wind				{ 0.0 };
				double						_friction			{ 0.0 };
				bool						_random_color		{ false };
				bool						_visible			{ true };
				bool						_wireframe			{ false };
				ygl::graphic::flip			_flip				{ ygl::graphic::flip::FLIP_NONE };
				ygl::math::colord			_color				{ ygl::math::colord().WHITE() };
				double						_opacity			{ 100.0 };
				ygl::graphic::orientation	_orientation		{ ygl::graphic::orientation::ORIENTATION_GLOBAL };
				ygl::math::pointd			_pivot				{ ygl::math::pointd(0.5) };
				ygl::math::pointd			_velocity			{ ygl::math::pointd() };
				ygl::math::pointd			_velocity_memory	{ ygl::math::pointd() };
				ygl::math::pointd			_position			{ ygl::math::pointd() };
				ygl::math::pointd			_displacement		{ ygl::math::pointd() };
				ygl::math::sized			_scale				{ ygl::math::sized(1.0) };
				ygl::math::rotated			_rotate				{ ygl::math::rotated() };
				ygl::math::sized			_size				{ ygl::math::sized() };
				ygl::math::surfaced			_offset				{ ygl::math::surfaced() };
				ygl::math::vertexd			_vertex				{ ygl::math::vertexd() };
				ygl::math::uvmapd			_map				{ ygl::math::uvmapd(1.0) };
				ygl::animation::tween*		_tween				{ NULL };
		};
	}
}

#endif /* YGL_EMITTER_PARTICLE_H_ */
