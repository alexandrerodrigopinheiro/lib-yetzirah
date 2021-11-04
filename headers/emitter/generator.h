#ifndef YGL_EMITTER_GENERATOR_H_
#define YGL_EMITTER_GENERATOR_H_

#pragma once

#include <iostream>
#include <string>

#include "math/color.h"
#include "math/math.h"
#include "math/point.h"
#include "math/size.h"
#include "math/rotate.h"
#include "random/random.h"

namespace ygl
{
	namespace emitter
	{
		class generator
		{
			public:

				generator();

				generator(const generator& obj);

				~generator();

				void seed();

				bool spown(const ygl::math::sized& size, double velocity, std::size_t life);

				std::size_t spown_born(std::size_t life);

				ygl::math::pointd spown_velocity(double velocity);

				ygl::math::rotated spown_rotate();

				ygl::math::sized spown_size(const ygl::math::sized& size);

				ygl::math::colord random_color();

				std::size_t born() const;

				const ygl::math::pointd& velocity() const;

				const ygl::math::rotated& rotate() const;

				const ygl::math::sized& size() const;

			protected:

				std::size_t			_born		{ 0 };
				ygl::math::pointd	_velocity	{ ygl::math::pointd() };
				ygl::math::rotated	_rotate		{ ygl::math::rotated() };
				ygl::math::sized	_size		{ ygl::math::sized() };
		};
	}
}

#endif /* YGL_EMITTER_GENERATOR_H_ */
