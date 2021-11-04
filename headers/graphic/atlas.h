#ifndef YGL_GRAPHIC_ATLAS_H_
#define YGL_GRAPHIC_ATLAS_H_

#pragma once

#include <iostream>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>

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
		class atlas
		{
			public:

				atlas();

				atlas(const ygl::graphic::atlas&) = delete;

				atlas(const std::string& filename, std::size_t colunms, std::size_t frames);

//				atlas(const std::string& filename, ygl::math::surface& surface);

				~atlas();

				bool initialize(const std::string& filename, std::size_t colunms, std::size_t frames);

//				bool initialize(const std::string& filename, ygl::math::surface& surface);

				void destroy();

				ygl::animation::tween* tweening(const std::string& animation);

				bool animation(const std::string& animation, std::size_t timeline);

				bool animation(const std::string& animation, std::size_t timeline, std::size_t fps);

				void animation(const std::string& animation);

				bool sensible(const std::string& name, const ygl::math::surfaced& sensible);

				const ygl::math::surfaced& sensible(const std::string& name);

				void draw();

				void draw(const ygl::math::pointd& position, const ygl::math::rotated& rotation = ygl::math::rotated().null(), const ygl::math::sized& scale = ygl::math::sized().null(), const ygl::math::colord& color = ygl::math::colord().null(), int spot = -1);

				void running();

				void start();

				void pause();

				void restart();

				void reset();

				bool started();

				bool border();

				bool onset();

				void spot(std::size_t spot);

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

				void rotation(double h, double p, double b);

				void rotation_h(double h);

				void rotation_p(double p);

				void rotation_b(double b);

				std::size_t spot() const;

				std::size_t frames() const;

				const std::string& filename() const;

				bool visible() const;

				bool wireframe() const;

				const ygl::graphic::flip& flip() const;

				const ygl::math::colord& color() const;

				double opacity() const;

				const ygl::graphic::orientation& orientation() const;

				const ygl::math::pointd& pivot() const;

				const ygl::math::pointd& position() const;

				const ygl::math::sized& scale() const;

				const ygl::math::rotated& rotation() const;

				const ygl::math::sized& size() const;

				const ygl::math::matrixd& matrix() const;

			private:

				void resolve();

			protected:

				uint											_data			{ 0 };
				std::size_t										_spot			{ 0 };
				std::size_t										_frames			{ 0 };
				std::string										_filename		{ std::string() };
				bool											_visible		{ true };
				bool											_wireframe		{ false };
				ygl::graphic::flip								_flip			{ ygl::graphic::flip::FLIP_NONE };
				ygl::math::colord								_color			{ ygl::math::colord() };
				double											_opacity		{ 100 };
				ygl::graphic::orientation						_orientation	{ ygl::graphic::orientation::ORIENTATION_GLOBAL };
				ygl::math::pointd								_pivot			{ ygl::math::pointd(0.5) };
				ygl::math::pointd								_position		{ ygl::math::pointd() };
				ygl::math::sized								_scale			{ ygl::math::sized() };
				ygl::math::rotated								_rotate			{ ygl::math::rotated() };
				ygl::math::sized								_size			{ ygl::math::sized() };
				ygl::math::surfaced								_offset			{ ygl::math::surfaced() };
				ygl::math::vertexd								_vertex			{ ygl::math::vertexd() };
				ygl::math::matrixd								_matrix			{ ygl::math::matrixd() };
				ygl::math::uvmapd								_map			{ ygl::math::uvmapd() };
				bool											_running		{ false };
				std::string										_animation		{ std::string() };
				std::map<std::string, ygl::math::surfaced>		_sensible		{ std::map<std::string, ygl::math::surfaced>() };
				std::map<std::string, ygl::animation::tween*>	_tweening		{ std::map<std::string, ygl::animation::tween*>() };
		};
	}
}

#endif /* YGL_GRAPHIC_ATLAS_H_ */
