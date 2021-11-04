#ifndef YGL_MATH_SURFACE_H_
#define YGL_MATH_SURFACE_H_

#pragma once

#include <string>
#include <iostream>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<class T>
		class surface
		{
		public:

			surface() :
				_x((T)0),
				_y((T)0),
				_w((T)0),
				_h((T)0),
				_null(false)
			{
			}

			surface(const ygl::math::surface<T>& obj) :
				_x(obj.x()),
				_y(obj.y()),
				_w(obj.w()),
				_h(obj.h()),
				_null(false)
			{
			}

			surface(T x, T y, T w, T h) :
				_x(x),
				_y(y),
				_w(w),
				_h(h),
				_null(false)
			{
			}

			surface(T arg) :
				_x(arg),
				_y(arg),
				_w(arg),
				_h(arg),
				_null(false)
			{
			}

			void fill(const ygl::math::surface<T>& obj)
			{
				this->_x = obj.x();
				this->_y = obj.y();
				this->_w = obj.w();
				this->_h = obj.h();
			}

			void fill(T x, T y, T w, T h)
			{
				this->_x = x;
				this->_y = y;
				this->_w = w;
				this->_h = h;
			}

			void fill(T arg)
			{
				this->_x = arg;
				this->_y = arg;
				this->_w = arg;
				this->_h = arg;
			}

			void x(T x)
			{
				this->_x = x;
			}

			void y(T y)
			{
				this->_y = y;
			}

			void w(T w)
			{
				this->_w = w;
			}

			void h(T h)
			{
				this->_h = h;
			}

			T x() const
			{
				return this->_x;
			}

			T y() const
			{
				return this->_y;
			}

			T w() const
			{
				return this->_w;
			}

			T h() const
			{
				return this->_h;
			}

			ygl::math::surface<T> null()
			{
				return ygl::math::surface<T>(0, 0, 0, 0, true);
			}

			bool is_null()
			{
				return this->_null;
			}

			ygl::math::surface<T> to_arg(const std::string& x, const std::string& y, const std::string& w, const std::string& h)
			{
				return ygl::math::surface<T>(ygl::basic::string_to<T>(x), ygl::basic::string_to<T>(y), ygl::basic::string_to<T>(w), ygl::basic::string_to<T>(h));
			}

			const ygl::math::surface<T>& operator++()
			{
				this->_x++;
				this->_y++;
				this->_w++;
				this->_h++;

				return *this;
			}

			const ygl::math::surface<T>& operator++(int)
			{
				++this->_x;
				++this->_y;
				++this->_w;
				++this->_h;

				return *this;
			}

			const ygl::math::surface<T>& operator--()
			{
				this->_x--;
				this->_y--;
				this->_w--;
				this->_h--;

				return *this;
			}

			const ygl::math::surface<T>& operator--(int)
			{
				--this->_x;
				--this->_y;
				--this->_w;
				--this->_h;

				return *this;
			}

			const ygl::math::surface<T>& operator+()
			{
				this->_x = +(this->_x);
				this->_y = +(this->_y);
				this->_w = +(this->_w);
				this->_h = +(this->_h);

				return *this;
			}

			const ygl::math::surface<T>& operator-()
			{
				this->_x = -(this->_x);
				this->_y = -(this->_y);
				this->_w = -(this->_w);
				this->_h = -(this->_h);

				return *this;
			}

			ygl::math::surface<T> operator+(const ygl::math::surface<T>& arg)
			{
				return ygl::math::surface<T>(this->_x + arg.x(), this->_y + arg.y(), this->_w + arg.w(), this->_h + arg.h());
			}

			ygl::math::surface<T> operator-(const ygl::math::surface<T>& arg)
			{
				return ygl::math::surface<T>(this->_x - arg.x(), this->_y - arg.y(), this->_w - arg.w(), this->_h - arg.h());
			}

			ygl::math::surface<T> operator*(const ygl::math::surface<T>& arg)
			{
				return ygl::math::surface<T>(this->_x * arg.x(), this->_y * arg.y(), this->_w * arg.w(), this->_h * arg.h());
			}

			ygl::math::surface<T> operator/(const ygl::math::surface<T>& arg)
			{
				return ygl::math::surface<T>(this->_x / arg.x(), this->_y / arg.y(), this->_w / arg.w(), this->_h / arg.h());
			}

			const ygl::math::surface<T>& operator+=(const ygl::math::surface<T>& arg)
			{
				this->_x = this->_x + arg.x();
				this->_y = this->_y + arg.y();
				this->_w = this->_w + arg.w();
				this->_h = this->_h + arg.h();

				return *this;
			}

			const ygl::math::surface<T>& operator-=(const ygl::math::surface<T>& arg)
			{
				this->_x = this->_x - arg.x();
				this->_y = this->_y - arg.y();
				this->_w = this->_w - arg.w();
				this->_h = this->_h - arg.h();

				return *this;
			}

			const ygl::math::surface<T>& operator*=(const ygl::math::surface<T>& arg)
			{
				this->_x = this->_x * arg.x();
				this->_y = this->_y * arg.y();
				this->_w = this->_w * arg.w();
				this->_h = this->_h * arg.h();

				return *this;
			}

			const ygl::math::surface<T>& operator/=(const ygl::math::surface<T>& arg)
			{
				this->_x = this->_x / arg.x();
				this->_y = this->_y / arg.y();
				this->_w = this->_w / arg.w();
				this->_h = this->_h / arg.h();

				return *this;
			}

			bool operator>(const ygl::math::surface<T>& arg) const
			{
				return this->_x > arg.x() && this->_y > arg.y() && this->_w > arg.w() && this->_h > arg.h();
			}

			bool operator<(const ygl::math::surface<T>& arg) const
			{
				return this->_x < arg.x() && this->_y < arg.y() && this->_w < arg.w() && this->_h < arg.h();
			}

			bool operator>=(const ygl::math::surface<T>& arg) const
			{
				return this->_x >= arg.x() && this->_y >= arg.y() && this->_w >= arg.w() && this->_h >= arg.h();
			}

			bool operator<=(const ygl::math::surface<T>& arg) const
			{
				return this->_x <= arg.x() && this->_y <= arg.y() && this->_w <= arg.w() && this->_h <= arg.h();
			}

			bool operator==(const ygl::math::surface<T>& arg) const
			{
				return this->_x == arg.x() && this->_y == arg.y() && this->_w == arg.w() && this->_h == arg.h();
			}

			bool operator!=(const ygl::math::surface<T>& arg) const
			{
				return this->_x != arg.x() || this->_y != arg.y() || this->_w != arg.w() || this->_h != arg.h();
			}

			friend std::ostream& operator<<(std::ostream& stream, const ygl::math::surface<T>& arg)
			{
				return stream << "SURFACE { X: " << arg.x() << " Y: " << arg.y() << " W: " << arg.w() << " H: " << arg.h() << " }";
			}

			friend std::istream& operator>>(std::istream& stream, ygl::math::surface<T>& arg)
			{
				std::string garbage;
				T x;
				T y;
				T w;
				T h;

				stream >> garbage >> garbage >> garbage >> x >> garbage >> y >> garbage >> w >> garbage >> h >> garbage;

				arg.fill(x, y, w, h);

				return stream;
			}

		private:

			surface(T x, T y, T w, T h, bool null) :
				_x(x),
				_y(y),
				_w(w),
				_h(h),
				_null(null)
			{
			}

		protected:

			T		_x		{ (T)0 };
			T		_y		{ (T)0 };
			T		_w		{ (T)0 };
			T		_h		{ (T)0 };
			bool	_null	{ false };
		};

		typedef ygl::math::surface<float>  surfacef;
		typedef ygl::math::surface<double> surfaced;
		typedef ygl::math::surface<int>    surfacei;
		typedef ygl::math::surface<std::size_t>   surfaceui;
	}
}

#endif /* YGL_MATH_SURFACE_H_ */
