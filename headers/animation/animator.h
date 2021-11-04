#ifndef YGL_ANIMATION_ANIMATOR_H_
#define YGL_ANIMATION_ANIMATOR_H_

#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "basic/basic.h"
#include "animation/animation.h"
#include "animation/timeline.h"
#include "animation/frame.h"
#include "animation/keyframe.h"
#include "serialize/serialize.h"

namespace ygl
{
	namespace animation
	{
		class animator
		{
			public:

				animator();

				animator(const animator& obj);

				~animator();

				bool initialize(std::size_t size, const ygl::animation::course& course, const ygl::animation::control& control);

				void destroy();

				void keyframe(const ygl::animation::keyframe& keyframe);

				void play();

				void start();

				void stop();

				void reset();

				void replay();

				bool started() const;

				const std::vector<ygl::animation::frame>& frame() const;

				const ygl::animation::frame& frame(std::size_t index) const;

				void interpolate();

			protected:

				ygl::animation::timeline*			_timeline	{ NULL };
				std::string							_name		{ std::string() };
				ygl::animation::course				_course		{ ygl::animation::course::COURSE_FORWARD };
				ygl::animation::control				_control	{ ygl::animation::control::CONTROL_SINGLE };
				std::vector<ygl::animation::frame>	_frame;
		};
	}
}

#endif /* YGL_ANIMATION_ANIMATION_H_ */
