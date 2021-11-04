#ifndef YGL_MATH_CIRCLE_H_
#define YGL_MATH_CIRCLE_H_

#pragma once

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<typename T>
		class circle
		{
			public:

				circle() :
					_x(static_cast<T>(0)),
					_y(static_cast<T>(0)),
					_radius(static_cast<T>(0)),
					_null(false)
				{
				}

				circle(const ygl::math::circle<T>& obj) :
					_x(obj.x()),
					_y(obj.y()),
					_radius(obj.radius()),
					_null(false)
				{
				}

				circle(T x, T y, T radius) :
					_x(x),
					_y(y),
					_radius(radius),
					_null(false)
				{
				}

				T x() const
				{
					return this->_x;
				}

				T y() const
				{
					return this->_y;
				}

				T radius() const
				{
					return this->_radius;
				}

				T angle()
				{
					return (T)atan2(this->_y, this->_x);
				}

				T length()
				{
					return sqrt(this->_x * this->_x + this->_y * this->_y);
				}

				void x(const T& x)
				{
					this->_x = x;
				}

				void y(const T& y)
				{
					this->_y = y;
				}

				void radius(const T& radius)
				{
					this->_radius = radius;
				}

				void fill(T value)
				{
					this->_x = value;
					this->_y = value;
					this->_radius = value;
				}

				void fill(T x, T y, T radius)
				{
					this->_x = x;
					this->_y = y;
					this->_radius = radius;
				}

				void angle(T angle)
				{
					T length = this->length();

					this->_x = cos(angle) * length;
					this->_y = sin(angle) * length;
				}

				void length(T length)
				{
					T angle = this->angle();

					this->_x = cos(angle) * length;
					this->_y = sin(angle) * length;
				}

				T area()
				{
					return 3.1415926535897932384626433832795028841971693993751058209749445923078164062 * (this->_radius * this->_radius);
				}

				void clear()
				{
					this->_x = static_cast<T>(0);
					this->_y = static_cast<T>(0);
					this->_radius = static_cast<T>(0);
				}

				bool empty()
				{
					return this->_x == static_cast<T>(0) && this->_y == static_cast<T>(0) && this->_radius == static_cast<T>(0);
				}

				ygl::math::circle<T> null()
				{
					return ygl::math::circle<T>(0, 0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::circle<T> to_circle(const std::string& x, const std::string& y, const std::string& radius)
				{
					return ygl::math::circle<T>(ygl::basic::string_to<T>(x), ygl::basic::string_to<T>(y), ygl::basic::string_to<T>(radius));
				}

				const ygl::math::circle<T>& operator++()
				{
					++this->_x;
					++this->_y;
					++this->_radius;
					return *this;
				}

				const ygl::math::circle<T>& operator++(int)
				{
					this->_x++;
					this->_y++;
					this->_radius++;
					return *this;
				}

				const ygl::math::circle<T>& operator--()
				{
					--this->_x;
					--this->_y;
					--this->_radius;
					return *this;
				}

				const ygl::math::circle<T>& operator--(int)
				{
					this->_x--;
					this->_y--;
					this->_radius--;
					return *this;
				}

				const ygl::math::circle<T>& operator+()
				{
					this->_x = +(this->_x);
					this->_y = +(this->_y);
					this->_radius = +(this->_radius);
					return *this;
				}

				const ygl::math::circle<T>& operator+(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x + circle.x();
					this->_y = this->_y + circle.y();
					this->_radius = this->_radius + circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator+=(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x + circle.x();
					this->_y = this->_y + circle.y();
					this->_radius = this->_radius + circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator-()
				{
					this->_x = -(this->_x);
					this->_y = -(this->_y);
					this->_radius = -(this->_radius);
					return *this;
				}

				const ygl::math::circle<T>& operator-(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x - circle.x();
					this->_y = this->_y - circle.y();
					this->_radius = this->_radius - circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator-=(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x - circle.x();
					this->_y = this->_y - circle.y();
					this->_radius = this->_radius - circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator*(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x * circle.x();
					this->_y = this->_y * circle.y();
					this->_radius = this->_radius * circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator*=(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x * circle.x();
					this->_y = this->_y * circle.y();
					this->_radius = this->_radius * circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator/(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x / circle.x();
					this->_y = this->_y / circle.y();
					this->_radius = this->_radius / circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator/=(const ygl::math::circle<T>& circle)
				{
					this->_x = this->_x / circle.x();
					this->_y = this->_y / circle.y();
					this->_radius = this->_radius / circle.radius();
					return *this;
				}

				const ygl::math::circle<T>& operator=(const ygl::math::circle<T>& circle)
				{
					this->_x = circle.x();
					this->_y = circle.y();
					this->_radius = circle.radius();
					return *this;
				}

				bool operator==(const ygl::math::circle<T>& circle) const
				{
					return this->_x == circle.x() && this->_y == circle.y() && this->_radius == circle.radius();
				}

				bool operator!=(const ygl::math::circle<T>& circle) const
				{
					return this->_x != circle.x() || this->_y != circle.y() || this->_radius != circle.radius();
				}

				bool operator>(const ygl::math::circle<T>& circle) const
				{
					return this->_x > circle.x() || this->_y > circle.y() || this->_radius > circle.radius();
				}

				bool operator>=(const ygl::math::circle<T>& circle) const
				{
					return this->_x >= circle.x() || this->_y >= circle.y() || this->_radius >= circle.radius();
				}

				bool operator<(const ygl::math::circle<T>& circle) const
				{
					return this->_x < circle.x() || this->_y < circle.y() || this->_radius < circle.radius();
				}

				bool operator<=(const ygl::math::circle<T>& circle) const
				{
					return this->_x <= circle.x() || this->_y <= circle.y() || this->_radius <= circle.radius();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::circle<T>& circle)
				{
					stream << "CIRCLE { X: " << circle.x() << " Y: " << circle.y() << " R: " << circle.radius() << " }";
					return stream;
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::circle<T>& circle)
				{
					T x;
					T y;
					T radius;
					std::string garbage;

					stream >> garbage  >> garbage  >> garbage >> x >> garbage >> y >> radius >> garbage;

					circle.fill(x, y, radius);

					return stream;
				}

			private:

				circle(T x, T y, T radius, bool null) :
					_x(x),
					_y(y),
					_radius(radius),
					_null(null)
				{
				}

			protected:

				T		_x		{ (T)0 };
				T		_y		{ (T)0 };
				T		_radius	{ (T)0 };
				bool	_null	{ false };
		};

		typedef ygl::math::circle<int>    circlei;
		typedef ygl::math::circle<std::size_t>   circleui;
		typedef ygl::math::circle<float>  circlef;
		typedef ygl::math::circle<double> circled;
	}
}

#endif /* YGL_MATH_CIRCLE_H_ */
