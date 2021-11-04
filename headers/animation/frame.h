#ifndef YGL_ANIMATION_FRAME_H_
#define YGL_ANIMATION_FRAME_H_

#pragma once

#include <iostream>
#include <string>

#include "math/point.h"
#include "math/color.h"
#include "math/point.h"
#include "math/size.h"
#include "math/rotate.h"
#include "graphic/graphic.h"

namespace ygl
{
	namespace animation
	{
		class frame
		{
			public:

				void message(const std::string& message);

				void spot(std::size_t spot);

				void visible(bool visible);

				void flip(const ygl::graphic::flip& flip);

				void color(const ygl::math::colord& color);

				void pivot(const ygl::math::pointd& pivot);

				void position(const ygl::math::pointd& position);

				void scale(const ygl::math::sized& scale);

				void rotate(const ygl::math::rotated& rotate);

				const std::string& message() const;

				std::size_t spot() const;

				bool visible() const;

				const ygl::graphic::flip& flip() const;

				const ygl::math::colord& color() const;

				const ygl::math::pointd& pivot() const;

				const ygl::math::pointd& position() const;

				const ygl::math::sized& scale() const;

				const ygl::math::rotated& rotate() const;

				friend std::ostream& operator<<(std::ostream& stream, const ygl::animation::frame& frame)
				{
					stream << "FRAME { ";
					stream << " MESSAGE { " << frame.message() << " }, ";
					stream << " FRAME { " << frame.spot() << " }, ";
					stream << frame.visible() << ", ";
					stream << frame.flip() << ", ";
					stream << frame.color() << ", ";
					stream << frame.pivot() << ", ";
					stream << frame.position() << ", ";
					stream << frame.scale() << ", ";
					stream << frame.rotate() << " }";

					return stream;
				}

				friend std::istream& operator>>(std::istream& stream, ygl::animation::frame& frame)
				{
					std::string garbage;
					std::string message;
					std::size_t spot;
					bool visible;
					ygl::graphic::flip flip;
					ygl::math::colord color;
					ygl::math::pointd pivot;
					ygl::math::pointd position;
					ygl::math::sized scale;
					ygl::math::rotated rotate;

					stream >> garbage  >> garbage;
					stream >> garbage  >> garbage >> message >> garbage;
					stream >> garbage  >> garbage >> spot >> garbage;
					stream >> visible  >> garbage;
					stream >> color    >> garbage;
					stream >> pivot    >> garbage;
					stream >> position >> garbage;
					stream >> scale    >> garbage;
					stream >> rotate >> garbage;

					frame.message(message);
					frame.spot(spot);
					frame.visible(visible);
					frame.flip(flip);
					frame.color(color);
					frame.pivot(pivot);
					frame.position(position);
					frame.scale(scale);
					frame.rotate(rotate);

					return stream;
				}

			protected:

				std::string			_message;
				std::size_t			_spot;
				bool				_visible;
				ygl::graphic::flip	_flip;
				ygl::math::colord	_color;
				ygl::math::pointd	_pivot;
				ygl::math::pointd	_position;
				ygl::math::sized	_scale;
				ygl::math::rotated	_rotate;
		};
	}
}

#endif /* YGL_ANIMATION_FRAME_H_ */
