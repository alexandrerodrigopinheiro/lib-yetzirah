#ifndef YGL_MATH_POINT_H_
#define YGL_MATH_POINT_H_

#pragma once

#include <string>
#include <iostream>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<class T>
		class point
		{
			public:

				point() :
					_x((T)0),
					_y((T)0),
					_z((T)0),
					_null(false)
				{
				}

				point(const ygl::math::point<T>& obj) :
					_x(obj.x()),
					_y(obj.y()),
					_z(obj.z()),
					_null(false)
				{
				}

				point(T x, T y, T z) :
					_x(x),
					_y(y),
					_z(z),
					_null(false)
				{
				}

				point(T arg) :
					_x(arg),
					_y(arg),
					_z(arg),
					_null(false)
				{
				}

				void copy(const ygl::math::point<T>& obj)
				{
					this->_x = obj.x();
					this->_y = obj.y();
					this->_z = obj.z();
				}

				void fill(T x, T y, T z)
				{
					this->_x = x;
					this->_y = y;
					this->_z = z;
				}

				void fill(T arg)
				{
					this->_x = arg;
					this->_y = arg;
					this->_z = arg;
				}

				void x(T x)
				{
					this->_x = x;
				}

				void y(T y)
				{
					this->_y = y;
				}

				void z(T z)
				{
					this->_z = z;
				}

				T x() const
				{
					return this->_x;
				}

				T y() const
				{
					return this->_y;
				}

				T z() const
				{
					return this->_z;
				}

				ygl::math::point<T> null()
				{
					return ygl::math::point<T>(0, 0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::point<T> to_point(const std::string& x, const std::string& y, const std::string& z)
				{
					return ygl::math::point<T>(ygl::basic::string_to<T>(x), ygl::basic::string_to<T>(y), ygl::basic::string_to<T>(z));
				}

				const ygl::math::point<T>& operator++()
				{
					this->_x++;
					this->_y++;
					this->_z++;
					return *this;
				}

				const ygl::math::point<T>& operator++(int)
				{
					++this->_x;
					++this->_y;
					++this->_z;
					return *this;
				}

				const ygl::math::point<T>& operator--()
				{
					this->_x--;
					this->_y--;
					this->_z--;
					return *this;
				}

				const ygl::math::point<T>& operator--(int)
				{
					--this->_x;
					--this->_y;
					--this->_z;
					return *this;
				}

				const ygl::math::point<T>& operator+()
				{
					this->_x = +(this->_x);
					this->_y = +(this->_y);
					this->_z = +(this->_z);
					return *this;
				}

				const ygl::math::point<T>& operator-()
				{
					this->_x = -(this->_x);
					this->_y = -(this->_y);
					this->_z = -(this->_z);
					return *this;
				}

				ygl::math::point<T> operator+(const ygl::math::point<T>& point)
				{
					T x = this->_x + point.x();
					T y = this->_y + point.y();
					T z = this->_z + point.z();
					return ygl::math::point<T>(x, y, z);
				}

				ygl::math::point<T> operator-(const ygl::math::point<T>& point)
				{
					T x = this->_x - point.x();
					T y = this->_y - point.y();
					T z = this->_z - point.z();
					return ygl::math::point<T>(x, y, z);
				}

				ygl::math::point<T> operator*(const ygl::math::point<T>& point)
				{
					T x = this->_x * point.x();
					T y = this->_y * point.y();
					T z = this->_z * point.z();

					return ygl::math::point<T>(x, y, z);
				}

				ygl::math::point<T> operator/(const ygl::math::point<T>& point)
				{
					T x = this->_x / point.x();
					T y = this->_y / point.y();
					T z = this->_z / point.z();
					return ygl::math::point<T>(x, y, z);
				}

				const ygl::math::point<T>& operator+=(const ygl::math::point<T>& point)
				{
					this->_x = this->_x + point.x();
					this->_y = this->_y + point.y();
					this->_z = this->_z + point.z();
					return *this;
				}

				const ygl::math::point<T>& operator-=(const ygl::math::point<T>& point)
				{
					this->_x = this->_x - point.x();
					this->_y = this->_y - point.y();
					this->_z = this->_z - point.z();
					return *this;
				}

				const ygl::math::point<T>& operator*=(const ygl::math::point<T>& point)
				{
					this->_x = this->_x * point.x();
					this->_y = this->_y * point.y();
					this->_z = this->_z * point.z();
					return *this;
				}

				const ygl::math::point<T>& operator/=(const ygl::math::point<T>& point)
				{
					this->_x = this->_x / point.x();
					this->_y = this->_y / point.y();
					this->_z = this->_z / point.z();
					return *this;
				}

				bool operator>(const ygl::math::point<T>& point) const
				{
					return this->_x > point.x() && this->_y > point.y() && this->_z > point.z();
				}

				bool operator<(const ygl::math::point<T>& point) const
				{
					return this->_x < point.x() && this->_y < point.y() && this->_z < point.z();
				}

				bool operator>=(const ygl::math::point<T>& point) const
				{
					return this->_x >= point.x() && this->_y >= point.y() && this->_z >= point.z();
				}

				bool operator<=(const ygl::math::point<T>& point) const
				{
					return this->_x <= point.x() && this->_y <= point.y() && this->_z <= point.z();
				}

				bool operator==(const ygl::math::point<T>& point) const
				{
					return this->_x == point.x() && this->_y == point.y() && this->_z == point.z();
				}

				bool operator!=(const ygl::math::point<T>& point) const
				{
					return this->_x != point.x() || this->_y != point.y() || this->_z != point.z();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::point<T>& point)
				{
					return stream << "POINT { X " << point.x() << " Y " << point.y() << " Z " << point.z() << " }";
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::point<T>& point)
				{
					std::string garbage;
					T x;
					T y;
					T z;
					stream >> garbage >> garbage >> garbage >> x >> garbage >> y >> garbage >> z >> garbage;
					point.fill(x, y, z);
					return stream;
				}

			private:

				point(T x, T y, T z, bool null) :
					_x(x),
					_y(y),
					_z(z),
					_null(null)
				{
				}

			protected:

				T		_x		{ (T)0 };
				T		_y		{ (T)0 };
				T		_z		{ (T)0 };
				bool	_null	{ false };
		};

		typedef ygl::math::point<float>			pointf;
		typedef ygl::math::point<double>		pointd;
		typedef ygl::math::point<int>			pointi;
		typedef ygl::math::point<std::size_t>	pointui;
	}
}

#endif /* YGL_MATH_POINT_H_ */
