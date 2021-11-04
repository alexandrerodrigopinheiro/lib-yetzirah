#ifndef YGL_ANIMATION_TIMELINE_H_
#define YGL_ANIMATION_TIMELINE_H_

#pragma once

#include <iostream>
#include <string>

#include "clock/clock.h"
#include "clock/timer.h"
#include "math/range.h"

#include "animation/animation.h"
#include "animation/framer.h"

namespace ygl
{
	namespace animation
	{
		class timeline
		{
			public:

				timeline();

				timeline(const ygl::animation::timeline& obj);

				~timeline();

				bool initialize(std::size_t length);

				bool initialize(std::size_t begin, std::size_t end);

				bool initialize(std::size_t begin, std::size_t end, std::size_t fps);

				void destroy();

				void play();

				void start();

				void stop();

				void reset();

				void replay();

				bool started() const;

				void begin();

				void end();

				bool bounde() const;

				bool onset() const;

				void length(std::size_t length);

				void course(const ygl::animation::course& course);

				void control(const ygl::animation::control& control);

				void fps(std::size_t frame_per_second);

				void frame_rate(std::size_t frame_rate);

				void frame(std::size_t frame);

				std::size_t length() const;

				const ygl::animation::course& course() const;

				const ygl::animation::control& control() const;

				std::size_t fps() const;

				std::size_t frame_rate() const;

				std::size_t frame() const;

				friend std::ostream& operator<<(std::ostream& stream, const ygl::animation::timeline& timeline);

				friend std::istream& operator>>(std::istream& stream, ygl::animation::timeline& timeline);

			protected:

				ygl::animation::framer*	_framer				{ NULL };
				ygl::math::rangeui		_timeline			{ 1, 1 };
				ygl::animation::course	_course				{ ygl::animation::course::COURSE_FORWARD };
				ygl::animation::control	_control			{ ygl::animation::control::CONTROL_SINGLE };
				std::size_t				_frame_per_second	{ ygl::clock::FPS };
				std::size_t				_frame_rate			{ ygl::clock::SECOND };
		};
	}
}

#endif /* YGL_ANIMATION_TIMELINE_H_ */
