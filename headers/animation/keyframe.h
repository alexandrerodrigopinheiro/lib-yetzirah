#ifndef YGL_ANIMATION_KEYFRAME_H_
#define YGL_ANIMATION_KEYFRAME_H_

#pragma once

#include <iostream>
#include <string>

#include "math/color.h"
#include "math/size.h"
#include "math/point.h"
#include "math/rotate.h"
#include "graphic/graphic.h"

namespace ygl
{
	namespace animation
	{
		class keyframe
		{
			public:

				void frame(std::size_t frame);

				void visible(const ygl::graphic::visible& visible);

				void flip(const ygl::graphic::flip& flip);

				void color(const ygl::math::colord& color);

				void opacity(double opacity);

				void pivot(const ygl::math::pointd& pivot);

				void position(const ygl::math::pointd& position);

				void scale(const ygl::math::sized& scale);

				void rotate(const ygl::math::rotated& rotate);

				std::size_t frame() const;

				const ygl::graphic::visible& visible() const;

				const ygl::graphic::flip& flip() const;

				const ygl::math::colord& color() const;

				double opacity() const;

				const ygl::math::pointd& pivot() const;

				const ygl::math::pointd& position() const;

				const ygl::math::sized& scale() const;

				const ygl::math::rotated& rotate() const;

				friend std::ostream& operator<<(std::ostream& stream, const keyframe& keyframe)
				{
					stream << " KEYFRAME { ";
					stream << keyframe.frame()    << ", ";
					stream << keyframe.visible()  << ", ";
					stream << keyframe.flip()     << ", ";
					stream << keyframe.color()    << ", ";
					stream << keyframe.opacity()  << ", ";
					stream << keyframe.pivot()    << ", ";
					stream << keyframe.position() << ", ";
					stream << keyframe.scale()    << ", ";
					stream << keyframe.rotate() << " }";
					return stream;
				}

				friend std::istream& operator>>(std::istream& stream, keyframe& keyframe)
				{
					std::string garbage;
					std::size_t frame;
					ygl::graphic::visible visible;
					ygl::graphic::flip flip;
					ygl::math::colord color;
					std::size_t opacity;
					ygl::math::pointd pivot;
					ygl::math::pointd position;
					ygl::math::sized scale;
					std::size_t depth;
					ygl::math::rotated rotate;

					stream >> frame    >> garbage;
					stream >> visible  >> garbage;
					stream >> flip     >> garbage;
					stream >> color    >> garbage;
					stream >> opacity  >> garbage;
					stream >> pivot    >> garbage;
					stream >> position >> garbage;
					stream >> scale    >> garbage;
					stream >> depth    >> garbage;
					stream >> rotate >> garbage;

					keyframe.frame(frame);
					keyframe.visible(visible);
					keyframe.flip(flip);
					keyframe.color(color);
					keyframe.pivot(pivot);
					keyframe.position(position);
					keyframe.scale(scale);
					keyframe.rotate(rotate);

					return stream;
				}

			protected:

				std::size_t				_frame		{ 0 };
				ygl::graphic::visible	_visible	{ ygl::graphic::visible::VISIBLE_ON };
				ygl::graphic::flip		_flip		{ ygl::graphic::flip::FLIP_NONE };
				ygl::math::colord		_color		{ ygl::math::colord().WHITE() };
				double					_opacity	{ 100.0 };
				ygl::math::pointd		_pivot		{ ygl::math::pointd() };
				ygl::math::pointd		_position	{ ygl::math::pointd() };
				ygl::math::sized		_scale		{ ygl::math::sized() };
				ygl::math::rotated		_rotate		{ ygl::math::rotated() };
		};
	}
}

#endif /* YGL_ANIMATION_KEYFRAME_H_ */
