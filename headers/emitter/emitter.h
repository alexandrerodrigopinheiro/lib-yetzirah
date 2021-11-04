#ifndef YGL_EMITTER_EMITTER_H_
#define YGL_EMITTER_EMITTER_H_

#pragma once

#include <iostream>
#include <string>

namespace ygl
{
	namespace emitter
	{
		typedef enum opacity
		{
			OPACITY_NONE,
			OPACITY_IN,
			OPACITY_OUT,
			OPACITY_IN_OUT,
			OPACITY_OUT_IN,
		} opacity;

		typedef enum scale
		{
			SCALE_NONE,
			SCALE_IN,
			SCALE_OUT,
			SCALE_IN_OUT,
			SCALE_OUT_IN,
		} scale;

		typedef enum rotate
		{
			ROTATE_NONE,
			ROTATE_IN,
			ROTATE_OUT,
			ROTATE_IN_OUT,
			ROTATE_OUT_IN,
		} rotate;

		typedef enum sprain
		{
			SPRAIN_NORMAL,
			SPRAIN_JET,
			SPRAIN_EXPLOSION,
			SPRAIN_SQUARE,
			SPRAIN_STAR,
			SPRAIN_CIRCLE,
			SPRAIN_SPIRAL,
			SPRAIN_TAN_COS,
			SPRAIN_TAN_SIN,
			SPRAIN_RANDOM_1,
			SPRAIN_RANDOM_2,
			SPRAIN_RANDOM_3,
			SPRAIN_RANDOM_4,
			SPRAIN_RANDOM_5,
			SPRAIN_RANDOM_6,
		} sprain;

		std::ostream& operator<<(std::ostream& stream, const ygl::emitter::sprain& sprain);

		std::istream& operator>>(std::istream& stream, ygl::emitter::sprain& sprain);

		ygl::emitter::sprain to_sprain(const std::string& sprain);
	}
}

#endif /* YGL_EMITTER_EMITTER_H_ */
