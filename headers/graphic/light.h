#ifndef YGL_GRAPHIC_LIGHT_H_
#define YGL_GRAPHIC_LIGHT_H_

#include <iostream>
#include <string>

#include <GL/glew.h>

#include "animation/animation.h"
#include "animation/animator.h"
#include "animation/tween.h"
#include "math/rotate.h"
#include "math/color.h"
#include "math/math.h"
#include "math/point.h"
#include "math/size.h"

namespace ygl
{
	namespace graphic
	{
		class light
		{
			public:

				light();

				light(const ygl::graphic::light& obj);

				light(const ygl::math::pointd& position, double radius = 1.0, const ygl::math::colord& color = ygl::math::colord().WHITE(), double intensity = 100.0, bool shadow = false, bool visible = true);

				~light();

				bool initialize(const ygl::math::pointd& position, double radius = 1.0, const ygl::math::colord& color = ygl::math::colord().WHITE(), double intensity = 100.0, bool shadow = false, bool visible = true);

				void destroy();

				ygl::animation::tween* tweening(const std::string& animation);

				bool animation(const std::string& animation, std::size_t timeline);

				bool animation(const std::string& animation, std::size_t timeline, std::size_t fps);

				void animation(const std::string& animation);

				bool sensible(const std::string& name, const ygl::math::surfaced& sensible);

				const ygl::math::surfaced& sensible(const std::string& name);

				void draw();

				void running();

				void start();

				void pause();

				void restart();

				void reset();

				bool started();

				bool border();

				bool onset();

				void visible(bool visible);

				void shadow(bool shadow);

				void intensity(double intensity);

				void radius(double radius);

				void depth(std::size_t depth);

				bool visible() const;

				bool shadow() const;

				double intensity() const;

				double radius() const;

				const ygl::math::colord& color();

				const ygl::math::pointd& position();

				const ygl::math::rotated& rotate();

				const ygl::math::sized& scale();

				std::size_t depth() const;

			protected:

				bool											_visible		{ true };
				bool											_shadow			{ false };
				ygl::math::colord								_color			{ ygl::math::colord().WHITE() };
				double											_intensity		{ 100 };
				double											_radius			{ 1 };
				ygl::math::pointd								_position		{ ygl::math::pointd() };
				ygl::math::rotated								_rotate			{ ygl::math::rotated() };
				ygl::math::sized								_scale			{ ygl::math::sized() };
				std::size_t										_depth			{ 0 };
				bool											_running		{ false };
				std::string										_animation		{ std::string() };
				std::map<std::string, ygl::math::surfaced>		_sensible		{ std::map<std::string, ygl::math::surfaced>() };
				std::map<std::string, ygl::animation::tween*>	_tweening		{ std::map<std::string, ygl::animation::tween*>() };
		};
	}
}

#endif /* YGL_GRAPHIC_LIGHT_H_ */
