#ifndef YGL_ANIMATION_KEY_H_
#define YGL_ANIMATION_KEY_H_

#pragma once

#include <iostream>
#include <string>

namespace ygl
{
	namespace animation
	{
		template<typename T>
		class key
		{
			public:

				key() :
					_frame(0),
					_value(T())
				{
				}

				key(const key& obj) :
					_frame(),
					_value()
				{
					*this = obj;
				}

				key(std::size_t frame, T value) :
					_frame(frame),
					_value(value)
				{
				}

				void frame(std::size_t frame)
				{
					this->_frame = frame;
				}

				void value(T value)
				{
					this->_value = value;
				}

				std::size_t frame() const
				{
					return this->_frame;
				}

				T value() const
				{
					return this->_value;
				}

			protected:

				std::size_t _frame;
				T           _value;
		};
	}
}

#endif /* YGL_ANIMATION_KEY_H_ */
