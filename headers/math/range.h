#ifndef YGL_MATH_RANGE_H_
#define YGL_MATH_RANGE_H_

#pragma once

#include <iostream>
#include <string>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<typename T>
		class range
		{
			public:

				range() :
					_begin(static_cast<T>(0)),
					_end(static_cast<T>(0)),
					_null(false)
				{
				}

				range(const ygl::math::range<T>& obj) :
					_begin(obj.begin()),
					_end(obj.end()),
					_null(false)
				{
				}

				range(T begin, T end) :
					_begin(begin),
					_end(end),
					_null(false)
				{
				}

				range(T value) :
					_begin(value),
					_end(value),
					_null(false)
				{
				}

				void fill(T value)
				{
					this->_begin = value;
					this->_end = value;
				}

				void fill(T begin, T end)
				{
					this->_begin = begin;
					this->_end = end;
				}

				void begin(T begin)
				{
					this->_begin = begin;
				}

				void end(T end)
				{
					this->_end = end;
				}

				T begin() const
				{
					return this->_begin;
				}

				T end() const
				{
					return this->_end;
				}

				void clear()
				{
					this->_begin = static_cast<T>(0);
					this->_end = static_cast<T>(0);
				}

				bool empty()
				{
					return this->_begin == static_cast<T>(0) && this->_end == static_cast<T>(0);
				}

				T delta()
				{
					return std::max(this->_begin, this->_end) - std::min(this->_begin, this->_end);
				}

				bool in_range(T value)
				{
					return value >= std::min(this->_begin, this->_end) && value <= std::max(this->_begin, this->_end);
				}

				T min()
				{
					return std::min(this->_begin, this->_end);
				}

				T max()
				{
					return std::max(this->_begin, this->_end);
				}

				std::size_t length() const
				{
					std::size_t n = 0;

					if (this->_begin < this->_end - 1)
					{
						for (int i = this->_begin; i < this->_end; i++)
						{
							n++;
						}
					}
					else if (this->_end < this->_begin - 1)
					{
						for (int i = this->_end; i < this->_begin; i++)
						{
							n++;
						}
					}
					else if (this->_begin != this->_end)
					{
						return 1;
					}

					return n;
				}

				ygl::math::range<T> null()
				{
					return ygl::math::range<T>(0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::range<T> to_range(const std::string& begin, const std::string& end)
				{
					return ygl::math::range<T>(ygl::basic::string_to<T>(begin), ygl::basic::string_to<T>(end));
				}

				const ygl::math::range<T>& operator++()
				{
					this->_begin++;
					this->_end++;

					return *this;
				}

				const ygl::math::range<T>& operator++(int)
				{
					++this->_begin;
					++this->_end;

					return *this;
				}

				const ygl::math::range<T>& operator--()
				{
					this->_begin--;
					this->_end--;

					return *this;
				}

				const ygl::math::range<T>& operator--(int)
				{
					--this->_begin;
					--this->_end;

					return *this;
				}

				const ygl::math::range<T>& operator+()
				{
					this->_begin = +(this->_begin);
					this->_end   = +(this->_end);

					return *this;
				}

				const ygl::math::range<T>& operator-()
				{
					this->_begin = -(this->_begin);
					this->_end   = -(this->_end);

					return *this;
				}

				const ygl::math::range<T>& operator+(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin + range.begin();
					this->_end   = this->_end + range.end();

					return *this;
				}

				const ygl::math::range<T>& operator-(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin - range.begin();
					this->_end   = this->_end - range.end();

					return *this;
				}

				const ygl::math::range<T>& operator*(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin * range.begin();
					this->_end   = this->_end * range.end();

					return *this;
				}

				const ygl::math::range<T>& operator/(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin / range.begin();
					this->_end   = this->_end / range.end();

					return *this;
				}

				const ygl::math::range<T>& operator+=(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin + range.begin();
					this->_end   = this->_end + range.end();

					return *this;
				}

				const ygl::math::range<T>& operator-=(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin - range.begin();
					this->_end   = this->_end - range.end();

					return *this;
				}

				const ygl::math::range<T>& operator*=(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin * range.begin();
					this->_end   = this->_end * range.end();

					return *this;
				}

				const ygl::math::range<T>& operator/=(const ygl::math::range<T>& range)
				{
					this->_begin = this->_begin / range.begin();
					this->_end   = this->_end / range.end();

					return *this;
				}

				bool operator>(const ygl::math::range<T>& range) const
				{
					return this->_begin > range.begin() && this->_end > range.end();
				}

				bool operator<(const ygl::math::range<T>& range) const
				{
					return this->_begin < range.begin() && this->_end < range.end();
				}

				bool operator>=(const ygl::math::range<T>& range) const
				{
					return this->_begin >= range.begin() && this->_end >= range.end();
				}

				bool operator<=(const ygl::math::range<T>& range) const
				{
					return this->_begin <= range.begin() && this->_end <= range.end();
				}

				bool operator==(const ygl::math::range<T>& range) const
				{
					return this->_begin == range.begin() && this->_end == range.end();
				}

				bool operator!=(const ygl::math::range<T>& range) const
				{
					return this->_begin != range.begin() || this->_end != range.end();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::range<T>& range)
				{
					return stream << "RANGE { B: " << range.begin() << " E: " << range.end() << " }";
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::range<T>& range)
				{
					std::string garbage;
					T begin;
					T end;

					stream >> garbage >> garbage >> garbage >> begin >> garbage >> end >> garbage;

					range.fill(begin, end);

					return stream;
				}

			private:

				range(T begin, T end, bool null) :
					_begin(begin),
					_end(end),
					_null(null)
				{
				}

			protected:

				T		_begin	{ (T)0 };
				T		_end	{ (T)0 };
				bool	_null	{ false };
		};

		typedef ygl::math::range<int>    rangei;
		typedef ygl::math::range<std::size_t>   rangeui;
		typedef ygl::math::range<float>  rangef;
		typedef ygl::math::range<double> ranged;
	}
}

#endif /* YGL_MATH_RANGE_H_ */
