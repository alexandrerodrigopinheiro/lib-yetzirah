#ifndef YGL_ANIMATION_ANIMATION_H_
#define YGL_ANIMATION_ANIMATION_H_

#pragma once

#include <string>
#include <iostream>

#include "error/error.h"

namespace ygl
{
	namespace animation
	{
		typedef enum play
		{
			PLAY_OFF = 0,
			PLAY_ON
		} play;

		std::ostream& operator<<(std::ostream& stream, const ygl::animation::play& play);

		std::istream& operator>>(std::istream& stream, ygl::animation::play& play);

		typedef enum control
		{
			CONTROL_SINGLE = 0,
			CONTROL_CYCLE,
			CONTROL_PINGPONG,
			CONTROL_ELASTIC
		} control;

		std::ostream& operator<<(std::ostream& stream, const ygl::animation::control& control);

		std::istream& operator>>(std::istream& stream, ygl::animation::control& control);

		typedef enum course
		{
			COURSE_BACKWARD = 0,
			COURSE_FORWARD
		} course;

		std::ostream& operator<<(std::ostream& stream, const ygl::animation::course& course);

		std::istream& operator>>(std::istream& stream, ygl::animation::course& course);

		typedef enum interpolation
		{
			INTERPOLATION_SOFT = 0,
			INTERPOLATION_HARD
		} interpolation;

		std::ostream& operator<<(std::ostream& stream, const ygl::animation::interpolation& interpolation);

		std::istream& operator>>(std::istream& stream, ygl::animation::interpolation& interpolation);

		ygl::animation::play to_play(const std::string& arg);

		ygl::animation::control to_control(const std::string& arg);

		ygl::animation::course to_course(const std::string& arg);

		ygl::animation::interpolation to_interpolation(const std::string& arg);

		template<typename T>
		inline T tweening(T v0, T v1, std::size_t k0, std::size_t k1, std::size_t frame)
		{
			if (k1 < k0)
			{
				std::cerr << "Tween keyframe lower of range, failed" << std::endl;
				exit(ygl::error::ERROR_FAILED);
			}

			if (frame < k0 || frame > k1)
			{
				std::cerr << "Tween frame out of keyframe range, failed" << std::endl;
				exit(ygl::error::ERROR_FAILED);
			}

			if (frame == k0)
			{
				return v0;
			}

			if (frame == k1)
			{
				return v1;
			}

			T f_frame        = static_cast<T>(frame);
			T f_size         = f_frame - k0;
			T f_sections     = (k1 - k0);
			T f_displacement = (v1 - v0) / f_sections;

			return v0 + (f_displacement * f_size);
		}

		inline double bounce_out(double t,double b , double c, double d)
		{
			if ((t /= d) < (1 / 2.75f))
			{
				return c * (7.5625f * t * t) + b;
			}
			else if (t < (2 / 2.75f))
			{
				double post = t -= (1.5f / 2.75f);

				return c * (7.5625f * (post) * t + .75f) + b;
			}
			else if (t < (2.5 / 2.75))
			{
				double post = t -= (2.25f / 2.75f);

				return c * (7.5625f * (post) * t + .9375f) + b;
			}

			double post = t -= (2.625f / 2.75f);

			return c * (7.5625f * (post) * t + .984375f) + b;
		}

		inline double bounce_in(double t,double b , double c, double d)
		{
			return c - bounce_out(d - t, 0, c, d) + b;
		}

		inline double bounce_in_out(double t, double b, double c, double d)
		{
			if (t < d / 2)
			{
				return bounce_in(t * 2, 0, c, d) * 0.5f + b;
			}
			else
			{
				return bounce_out(t * 2 - d, 0, c, d) * 0.5f + c * 0.5f + b;
			}
		}
	}
}

#endif /* YGL_ANIMATION_ANIMATION_H_ */
