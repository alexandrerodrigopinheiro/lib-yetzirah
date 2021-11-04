#ifndef YGL_MATH_UVMAP_H_
#define YGL_MATH_UVMAP_H_

#pragma once

#include <string>
#include <iostream>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<typename T>
		class uvmap
		{
			public:

				uvmap() :
					_u(static_cast<T>(0)),
					_v(static_cast<T>(0)),
					_null(false)
				{
				}

				uvmap(const ygl::math::uvmap<T>& obj) :
					_u(obj.u()),
					_v(obj.v()),
					_null(false)
				{
				}

				uvmap(T u, T v) :
					_u(u),
					_v(v),
					_null(false)
				{
				}

				uvmap(T arg) :
					_u(arg),
					_v(arg),
					_null(false)
				{
				}

				void fill(T value)
				{
					this->_u = value;
					this->_v = value;
				}

				void fill(T u, T v)
				{
					this->_u = u;
					this->_v = v;
				}

				void u(T u)
				{
					this->_u = u;
				}

				void v(T v)
				{
					this->_v = v;
				}

				T u() const
				{
					return this->_u;
				}

				T v() const
				{
					return this->_v;
				}

				void clear()
				{
					this->_u = static_cast<T>(0);
					this->_v = static_cast<T>(0);
				}

				bool empth()
				{
					return this->_u == static_cast<T>(0) && this->_v == static_cast<T>(0);
				}

				ygl::math::uvmap<T> null()
				{
					return ygl::math::uvmap<T>(0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::uvmap<T> to_uvmap(const std::string& u, const std::string& v)
				{
					return ygl::math::uvmap<T>(ygl::basic::string_to<T>(u), ygl::basic::string_to<T>(v));
				}

				const ygl::math::uvmap<T>& operator++()
				{
					++this->_u;
					++this->_v;
					return *this;
				}

				const ygl::math::uvmap<T>& operator++(int)
				{
					this->_u++;
					this->_v++;
					return *this;
				}

				const ygl::math::uvmap<T>& operator--()
				{
					--this->_u;
					--this->_v;
					return *this;
				}

				const ygl::math::uvmap<T>& operator--(int)
				{
					this->_u--;
					this->_v--;
					return *this;
				}

				const ygl::math::uvmap<T>& operator+()
				{
					this->_u = +(this->_u);
					this->_v = +(this->_v);
					return *this;
				}

				const ygl::math::uvmap<T>& operator+(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u + uvmap.u();
					this->_v = this->_v + uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator+=(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u + uvmap.u();
					this->_v = this->_v + uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator-()
				{
					this->_u = -(this->_u);
					this->_v = -(this->_v);
					return *this;
				}

				const ygl::math::uvmap<T>& operator-(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u - uvmap.u();
					this->_v = this->_v - uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator-=(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u - uvmap.u();
					this->_v = this->_v - uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator*(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u * uvmap.u();
					this->_v = this->_v * uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator*=(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u * uvmap.u();
					this->_v = this->_v * uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator/(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u / uvmap.u();
					this->_v = this->_v / uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator/=(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = this->_u / uvmap.u();
					this->_v = this->_v / uvmap.v();
					return *this;
				}

				const ygl::math::uvmap<T>& operator=(const ygl::math::uvmap<T>& uvmap)
				{
					this->_u = uvmap.u();
					this->_v = uvmap.v();
					return *this;
				}

				bool operator==(const ygl::math::uvmap<T>& uvmap) const
				{
					return this->_u == uvmap.u() && this->_v == uvmap.v();
				}

				bool operator!=(const ygl::math::uvmap<T>& uvmap) const
				{
					return this->_u != uvmap.u() || this->_v != uvmap.v();
				}

				bool operator!=(void* arg) const
				{
					return this != arg;
				}

				bool operator>(const ygl::math::uvmap<T>& uvmap) const
				{
					return this->_u > uvmap.u() || this->_v > uvmap.v();
				}

				bool operator>=(const ygl::math::uvmap<T>& uvmap) const
				{
					return this->_u >= uvmap.u() || this->_v >= uvmap.v();
				}

				bool operator<(const ygl::math::uvmap<T>& uvmap) const
				{
					return this->_u < uvmap.u() || this->_v < uvmap.v();
				}

				bool operator<=(const ygl::math::uvmap<T>& uvmap) const
				{
					return this->_u <= uvmap.u() || this->_v <= uvmap.v();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::uvmap<T>& uvmap)
				{
					stream << "UVMAP { U: " << uvmap.u() << " V: " << uvmap.v() << " }";
					return stream;
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::uvmap<T>& uvmap)
				{
					T u;
					T v;
					std::string garbage;

					stream >> garbage >> garbage >> garbage >> u >> garbage >> v >> garbage;

					uvmap.uvmap(u, v);

					return stream;
				}

			private:

				uvmap(T u, T v, bool null) :
					_u(u),
					_v(v),
					_null(null)
				{
				}

			protected:

				T		_u		{ (T)0 };
				T		_v		{ (T)0 };
				bool	_null	{ false };
		};

		typedef ygl::math::uvmap<int>    uvmapi;
		typedef ygl::math::uvmap<std::size_t>   uvmapui;
		typedef ygl::math::uvmap<float>  uvmapf;
		typedef ygl::math::uvmap<double> uvmapd;
	}
}

#endif /* YGL_MATH_UVMAP_H_ */
