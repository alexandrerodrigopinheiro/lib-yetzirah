#ifndef YGL_MATH_SIZE_H_
#define YGL_MATH_SIZE_H_

#pragma once

#include <string>
#include <iostream>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<class T>
		class size
		{
			public:

				size() :
					_w((T)0),
					_h((T)0),
					_l((T)0),
					_null(false)
				{
				}

				size(const ygl::math::size<T>& obj) :
					_w(obj.w()),
					_h(obj.h()),
					_l(obj.l()),
					_null(false)
				{
				}

				size(T w, T h, T l) :
					_w(w),
					_h(h),
					_l(l),
					_null(false)
				{
				}

				size(T arg) :
					_w(arg),
					_h(arg),
					_l(arg),
					_null(false)
				{
				}

				void copy(const ygl::math::size<T>& obj)
				{
					this->_w = obj.w();
					this->_h = obj.h();
					this->_l = obj.l();
				}

				void fill(T w, T h, T l)
				{
					this->_w = w;
					this->_h = h;
					this->_l = l;
				}

				void fill(T arg)
				{
					this->_w = arg;
					this->_h = arg;
					this->_l = arg;
				}

				void w(T w)
				{
					this->_w = w;
				}

				void h(T h)
				{
					this->_h = h;
				}

				void l(T l)
				{
					this->_l = l;
				}

				T w() const
				{
					return this->_w;
				}

				T h() const
				{
					return this->_h;
				}

				T l() const
				{
					return this->_l;
				}

				ygl::math::size<T> null()
				{
					return ygl::math::size<T>(0, 0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::size<T> to_size(const std::string& w, const std::string& h, const std::string& l)
				{
					return ygl::math::size<T>(ygl::basic::string_to<T>(w), ygl::basic::string_to<T>(h), ygl::basic::string_to<T>(l));
				}

				const ygl::math::size<T>& operator++()
				{
					this->_w++;
					this->_h++;
					this->_l++;
					return *this;
				}

				const ygl::math::size<T>& operator++(int)
				{
					++this->_w;
					++this->_h;
					++this->_l;
					return *this;
				}

				const ygl::math::size<T>& operator--()
				{
					this->_w--;
					this->_h--;
					this->_l--;
					return *this;
				}

				const ygl::math::size<T>& operator--(int)
				{
					--this->_w;
					--this->_h;
					--this->_l;
					return *this;
				}

				const ygl::math::size<T>& operator+()
				{
					this->_w = +(this->_w);
					this->_h = +(this->_h);
					this->_l = +(this->_l);
					return *this;
				}

				const ygl::math::size<T>& operator-()
				{
					this->_w = -(this->_w);
					this->_h = -(this->_h);
					this->_l = -(this->_l);
					return *this;
				}

				ygl::math::size<T> operator+(const ygl::math::size<T>& arg)
				{
					T w = this->_w + arg.w();
					T h = this->_h + arg.h();
					T l = this->_l + arg.l();
					return ygl::math::size<T>(w, h, l);
				}

				ygl::math::size<T> operator-(const ygl::math::size<T>& arg)
				{
					T w = this->_w - arg.w();
					T h = this->_h - arg.h();
					T l = this->_l - arg.l();

					return ygl::math::size<T>(w, h, l);
				}

				ygl::math::size<T> operator*(const ygl::math::size<T>& arg)
				{
					T w = this->_w * arg.w();
					T h = this->_h * arg.h();
					T l = this->_l * arg.l();
					return ygl::math::size<T>(w, h, l);
				}

				ygl::math::size<T> operator/(const ygl::math::size<T>& arg)
				{
					T w = this->_w / arg.w();
					T h = this->_h / arg.h();
					T l = this->_l / arg.l();
					return ygl::math::size<T>(w, h, l);
				}

				const ygl::math::size<T>& operator+=(const ygl::math::size<T>& arg)
				{
					this->_w = this->_w + arg.w();
					this->_h = this->_h + arg.h();
					this->_l = this->_l + arg.l();
					return *this;
				}

				const ygl::math::size<T>& operator-=(const ygl::math::size<T>& arg)
				{
					this->_w = this->_w - arg.w();
					this->_h = this->_h - arg.h();
					this->_l = this->_l - arg.l();
					return *this;
				}

				const ygl::math::size<T>& operator*=(const ygl::math::size<T>& arg)
				{
					this->_w = this->_w * arg.w();
					this->_h = this->_h * arg.h();
					this->_l = this->_l * arg.l();
					return *this;
				}

				const ygl::math::size<T>& operator/=(const ygl::math::size<T>& arg)
				{
					this->_w = this->_w / arg.w();
					this->_h = this->_h / arg.h();
					this->_l = this->_l / arg.l();
					return *this;
				}

				bool operator>(const ygl::math::size<T>& arg) const
				{
					return this->_w > arg.w() && this->_h > arg.h() && this->_l > arg.l();
				}

				bool operator<(const ygl::math::size<T>& arg) const
				{
					return this->_w < arg.w() && this->_h < arg.h() && this->_l < arg.l();
				}

				bool operator>=(const ygl::math::size<T>& arg) const
				{
					return this->_w >= arg.w() && this->_h >= arg.h() && this->_l >= arg.l();
				}

				bool operator<=(const ygl::math::size<T>& arg) const
				{
					return this->_w <= arg.w() && this->_h <= arg.h() && this->_l <= arg.l();
				}

				bool operator==(const ygl::math::size<T>& arg) const
				{
					return this->_w == arg.w() && this->_h == arg.h() && this->_l == arg.l();
				}

				bool operator!=(const ygl::math::size<T>& arg) const
				{
					return this->_w != arg.w() || this->_h != arg.h() || this->_l != arg.l();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::size<T>& arg)
				{
					return stream << "SIZE { W " << arg.w() << " H " << arg.h() << " L " << arg.l() << " }";
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::size<T>& arg)
				{
					std::string garbage;
					T w;
					T h;
					T l;

					stream >> garbage >> garbage >> garbage >> w >> garbage >> h >> garbage >> l >> garbage;

					arg.fill(w, h, l);

					return stream;
				}

			private:

				size(T w, T h, T l, bool null) :
					_w(w),
					_h(h),
					_l(l),
					_null(null)
				{
				}

			protected:

				T		_w		{ (T)0 };
				T		_h		{ (T)0 };
				T		_l		{ (T)0 };
				bool	_null	{ false };
		};

		typedef ygl::math::size<float>		 sizef;
		typedef ygl::math::size<double>		 sized;
		typedef ygl::math::size<int>		 sizei;
		typedef ygl::math::size<std::size_t> sizeui;
	}
}

#endif /* YGL_MATH_SIZE_H_ */
