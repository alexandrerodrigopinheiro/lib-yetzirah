#ifndef YGL_ANIMATION_FRAMER_H_
#define YGL_ANIMATION_FRAMER_H_

#pragma once

#include <iostream>
#include <string>

#include "clock/timer.h"
#include "animation/animation.h"
#include "math/math.h"

namespace ygl
{
	namespace animation
	{
		class framer
		{
			public:

				framer();

				framer(const framer& obj);

				~framer();

				bool initialize(std::size_t expiry);

				void destroy();

				void play();

				void start();

				void stop();

				void reset();

				void replay();

				bool bound() const;

				bool started() const;

				void course(const ygl::animation::course& course);

				void frame(std::size_t frame);

				void expiry(std::size_t expiry);

				const ygl::animation::course& course() const;

				std::size_t frame() const;

				std::size_t expiry() const;

			protected:

				ygl::clock::timer*		_timer	{ NULL };
				ygl::animation::course	_course	{ ygl::animation::course::COURSE_FORWARD };
				int						_expiry	{ 0 };
				int						_frame	{ 0 };
				bool					_play	{ false };
				bool					_bound	{ false };
		};
	}
}

#endif /* YGL_ANIMATION_FRAMER_H_ */
