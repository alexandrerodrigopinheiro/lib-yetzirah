#ifndef YGL_MATH_ROTATE_H_
#define YGL_MATH_ROTATE_H_

#pragma once

#include <string>
#include <iostream>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<class T>
		class rotate
		{
			public:

				rotate() :
					_h((T)0),
					_p((T)0),
					_b((T)0),
					_null(false)
				{
				}

				rotate(const ygl::math::rotate<T>& obj) :
					_h(obj.h()),
					_p(obj.p()),
					_b(obj.b()),
					_null(false)
				{
				}

				rotate(T h, T p, T b) :
					_h(h),
					_p(p),
					_b(b),
					_null(false)
				{
				}

				rotate(T arg) :
					_h(arg),
					_p(arg),
					_b(arg),
					_null(false)
				{
				}

				void fill(const ygl::math::rotate<T>& obj)
				{
					this->_h = obj.h();
					this->_p = obj.p();
					this->_b = obj.b();
				}

				void fill(T h, T p, T b)
				{
					this->_h = h;
					this->_p = p;
					this->_b = b;
				}

				void fill(T arg)
				{
					this->_h = arg;
					this->_p = arg;
					this->_b = arg;
				}

				void h(T h)
				{
					this->_h = h;
				}

				void p(T p)
				{
					this->_p = p;
				}

				void b(T b)
				{
					this->_b = b;
				}

				T h() const
				{
					return this->_h;
				}

				T p() const
				{
					return this->_p;
				}

				T b() const
				{
					return this->_b;
				}

				ygl::math::rotate<T> null()
				{
					return ygl::math::rotate<T>(0, 0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::rotate<T> to_rotate(const std::string& h, const std::string& p, const std::string& b)
				{
					return ygl::math::rotate<T>(ygl::basic::string_to<T>(h), ygl::basic::string_to<T>(p), ygl::basic::string_to<T>(b));
				}

				const ygl::math::rotate<T>& operator++()
				{
					this->_h++;
					this->_p++;
					this->_b++;

					return *this;
				}

				const ygl::math::rotate<T>& operator++(int)
				{
					++this->_h;
					++this->_p;
					++this->_b;

					return *this;
				}

				const ygl::math::rotate<T>& operator--()
				{
					this->_h--;
					this->_p--;

					return *this;
				}

				const ygl::math::rotate<T>& operator--(int)
				{
					--this->_h;
					--this->_p;
					--this->_b;

					return *this;
				}

				const ygl::math::rotate<T>& operator+()
				{
					this->_h = +(this->_h);
					this->_p = +(this->_p);
					this->_b = +(this->_b);

					return *this;
				}

				const ygl::math::rotate<T>& operator-()
				{
					this->_h = -(this->_h);
					this->_p = -(this->_p);
					this->_b = -(this->_b);

					return *this;
				}

				ygl::math::rotate<T> operator+(const ygl::math::rotate<T>& rotate)
				{
					T h = this->_h + rotate.h();
					T p = this->_p + rotate.p();
					T b = this->_b + rotate.b();

					return ygl::math::rotate<T>(h, p, b);
				}

				ygl::math::rotate<T> operator-(const ygl::math::rotate<T>& rotate)
				{
					T h = this->_h - rotate.h();
					T p = this->_p - rotate.p();
					T b = this->_b - rotate.b();

					return ygl::math::rotate<T>(h, p, b);
				}

				ygl::math::rotate<T> operator*(const ygl::math::rotate<T>& rotate)
				{
					T h = this->_h * rotate.h();
					T p = this->_p * rotate.p();
					T b = this->_b * rotate.b();

					return ygl::math::rotate<T>(h, p, b);
				}

				ygl::math::rotate<T> operator/(const ygl::math::rotate<T>& rotate)
				{
					T h = this->_h / rotate.h();
					T p = this->_p / rotate.p();
					T b = this->_b / rotate.b();

					return ygl::math::rotate<T>(h, p, b);
				}

				const ygl::math::rotate<T>& operator+=(const ygl::math::rotate<T>& rotate)
				{
					this->_h = this->_h + rotate.h();
					this->_p = this->_p + rotate.p();
					this->_b = this->_b + rotate.b();

					return *this;
				}

				const ygl::math::rotate<T>& operator-=(const ygl::math::rotate<T>& rotate)
				{
					this->_h = this->_h - rotate.h();
					this->_p = this->_p - rotate.p();
					this->_b = this->_b - rotate.b();

					return *this;
				}

				const ygl::math::rotate<T>& operator*=(const ygl::math::rotate<T>& rotate)
				{
					this->_h = this->_h * rotate.h();
					this->_p = this->_p * rotate.p();
					this->_b = this->_b * rotate.b();

					return *this;
				}

				const ygl::math::rotate<T>& operator/=(const ygl::math::rotate<T>& rotate)
				{
					this->_h = this->_h / rotate.h();
					this->_p = this->_p / rotate.p();
					this->_b = this->_b / rotate.b();

					return *this;
				}

				bool operator>(const ygl::math::rotate<T>& rotate) const
				{
					return this->_h > rotate.h() && this->_p > rotate.p() && this->_b > rotate.b();
				}

				bool operator<(const ygl::math::rotate<T>& rotate) const
				{
					return this->_h < rotate.h() && this->_p < rotate.p() && this->_b < rotate.b();
				}

				bool operator>=(const ygl::math::rotate<T>& rotate) const
				{
					return this->_h >= rotate.h() && this->_p >= rotate.p() && this->_b >= rotate.b();
				}

				bool operator<=(const ygl::math::rotate<T>& rotate) const
				{
					return this->_h <= rotate.h() && this->_p <= rotate.p() && this->_b <= rotate.b();
				}

				bool operator==(const ygl::math::rotate<T>& rotate) const
				{
					return this->_h == rotate.h() && this->_p == rotate.p() && this->_b == rotate.b();
				}

				bool operator!=(const ygl::math::rotate<T>& rotate) const
				{
					return this->_h != rotate.h() || this->_p != rotate.p() || this->_b != rotate.b();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::rotate<T>& rotate)
				{
					return stream << "ROTATE { H " << rotate.h() << " P " << rotate.p() << " B " << rotate.b() << " }";
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::rotate<T>& rotate)
				{
					std::string garbage;
					T h;
					T p;
					T b;

					stream >> garbage >> garbage >> garbage >> h >> garbage >> p >> garbage >> b >> garbage;

					rotate.fill(h, p, b);

					return stream;
				}

			private:

				rotate(T h, T p, T b, bool null) :
					_h(h),
					_p(p),
					_b(b),
					_null(null)
				{
				}

			protected:

				T		_h		{ (T)0 };
				T		_p		{ (T)0 };
				T		_b		{ (T)0 };
				bool	_null	{ false };
		};

		typedef ygl::math::rotate<float>  rotatef;
		typedef ygl::math::rotate<double> rotated;
		typedef ygl::math::rotate<int>    rotatei;
		typedef ygl::math::rotate<std::size_t>   rotateui;
	}
}

#endif /* YGL_MATH_ROTATE_H_ */
