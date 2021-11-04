#ifndef YGL_EMITTER_LAUNCHER_H_
#define YGL_EMITTER_LAUNCHER_H_

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "animation/animation.h"
#include "emitter/generator.h"
#include "emitter/particle.h"
#include "emitter/emitter.h"
#include "math/math.h"
#include "math/color.h"
#include "math/point.h"
#include "math/rotate.h"
#include "math/size.h"

namespace ygl
{
	namespace emitter
	{
		class launcher
		{
			public:

				launcher();

				launcher(const launcher& obj);

				~launcher();

				bool initialize(const ygl::math::sized& area);

				bool initialize(const std::string& filename, const ygl::math::sized& area);

				void destroy();

				bool generator(const ygl::math::sized& size, double velocity, std::size_t life, std::size_t amount);

				bool generator(const ygl::math::pointd& position, const ygl::math::sized& size, double velocity, std::size_t life, std::size_t amount);

				void draw();

				void draw(const ygl::math::pointd& position, const ygl::math::colord& color = ygl::math::colord().null());

				void running();

				void start();

				void pause();

				void restart();

				void reset();

				bool bound();

				bool onset();

				void easy_opacity(const ygl::emitter::opacity& opacity);

				void easy_scale(const ygl::emitter::scale& scale);

				void easy_rotate(const ygl::emitter::rotate& rotate);

				void random_color();

				void regeneration(int regeneration = -1);

				void visible(bool visible);

				void gravity(double gravity);

				void wind(double wind);

				void friction(double friction);

				void color(const ygl::math::colord& color);

				void color(double r, double g, double b);

				void color_r(double r);

				void color_g(double g);

				void color_b(double b);

				void position(const ygl::math::pointd& position);

				void position(double x, double y, double z);

				void position_x(double x);

				void position_y(double y);

				void position_z(double z);

				std::size_t life() const;

				std::size_t amount() const;

				const ygl::math::colord& color();

				const ygl::math::pointd& position() const;

				double velocity() const;

				const ygl::math::sized& area() const;

				bool visible() const;

				double gravity() const;

				double wind() const;

				double friction() const;

			private:

				bool load(const std::string& filename);

			protected:

				GLuint									_data			{ 0 };
				int										_regeneration	{ -1 };
				std::size_t								_murdered		{ 0 };
				std::string								_filename		{ std::string() };
				bool									_running		{ true };
				bool									_visible		{ true };
				std::size_t								_life			{ 0 };
				std::size_t								_amount			{ 0 };
				ygl::math::colord						_color			{ ygl::math::colord().WHITE() };
				ygl::math::pointd						_position		{ ygl::math::pointd() };
				ygl::math::sized						_area			{ ygl::math::sized() };
				ygl::math::sized						_size			{ ygl::math::sized() };
				double									_velocity		{ 0.0 };
				double									_gravity		{ 0.0 };
				double									_wind			{ 0.0 };
				double									_friction		{ 0.0 };
				ygl::emitter::opacity					_easy_opacity	{ ygl::emitter::opacity::OPACITY_NONE };
				ygl::emitter::scale						_easy_scale		{ ygl::emitter::scale::SCALE_NONE };
				ygl::emitter::rotate					_easy_rotate	{ ygl::emitter::rotate::ROTATE_NONE };
				std::vector<ygl::emitter::particle*>	_particle		{ std::vector<ygl::emitter::particle*>() };
				ygl::emitter::generator					_generator		{ ygl::emitter::generator() };
		};
	}
}

#endif /* YGL_EMITTER_LAUNCHER_H_ */
