#ifndef YGL_MATH_VERTEX_H_
#define YGL_MATH_VERTEX_H_

#pragma once

#include <string>
#include <iostream>

#include "basic/basic.h"
#include "math/point.h"

namespace ygl
{
	namespace math
	{
		template<class T>
		class vertex
		{
			public:

				vertex() :
					_a((T)0),
					_b((T)0),
					_c((T)0),
					_d((T)0),
					_null(false)
				{
				}

				vertex(const ygl::math::vertex<T>& obj) :
					_a(obj.a()),
					_b(obj.b()),
					_c(obj.c()),
					_d(obj.d()),
					_null(false)
				{
				}

				vertex(T a, T b, T c, T d) :
					_a(a),
					_b(b),
					_c(c),
					_d(d),
					_null(false)
				{
				}

				vertex(T arg) :
					_a(arg),
					_b(arg),
					_c(arg),
					_d(arg),
					_null(false)
				{
				}

				vertex(const ygl::math::point<T>& a, const ygl::math::point<T>& b, const ygl::math::point<T>& c, const ygl::math::point<T>& d) :
					_a(a),
					_b(b),
					_c(c),
					_d(d),
					_null(false)
				{
				}

				vertex(const ygl::math::point<T>& arg) :
					_a(arg),
					_b(arg),
					_c(arg),
					_d(arg),
					_null(false)
				{
				}

				void fill(const ygl::math::vertex<T>& obj)
				{
					this->_a = obj.a();
					this->_b = obj.b();
					this->_c = obj.c();
					this->_d = obj.d();
				}

				void fill(T a, T b, T c, T d)
				{
					this->_a = a;
					this->_b = b;
					this->_c = c;
					this->_d = d;
				}

				void fill(T arg)
				{
					this->_a = arg;
					this->_b = arg;
					this->_c = arg;
					this->_d = arg;
				}

				void fill(const ygl::math::point<T>& a, const ygl::math::point<T>& b, const ygl::math::point<T>& c, const ygl::math::point<T>& d)
				{
					this->_a = a;
					this->_b = b;
					this->_c = c;
					this->_d = d;
				}

				void fill(const ygl::math::point<T>& arg)
				{
					this->_a = arg;
					this->_b = arg;
					this->_c = arg;
					this->_d = arg;
				}

				void a(T x, T y, T z)
				{
					this->_a = ygl::math::point<T>(x, y, z);
				}

				void b(T x, T y, T z)
				{
					this->_b = ygl::math::point<T>(x, y, z);
				}

				void c(T x, T y, T z)
				{
					this->_c = ygl::math::point<T>(x, y, z);
				}

				void d(T x, T y, T z)
				{
					this->_d = ygl::math::point<T>(x, y, z);
				}

				void a(T a)
				{
					this->_a = a;
				}

				void b(T b)
				{
					this->_b = b;
				}

				void c(T c)
				{
					this->_c = c;
				}

				void d(T d)
				{
					this->_d = d;
				}

				void a(const ygl::math::point<T>& a)
				{
					this->_a = a;
				}

				void b(const ygl::math::point<T>& b)
				{
					this->_b = b;
				}

				void c(const ygl::math::point<T>& c)
				{
					this->_c = c;
				}

				void d(const ygl::math::point<T>& d)
				{
					this->_d = d;
				}

				const ygl::math::point<T>& a() const
				{
					return this->_a;
				}

				const ygl::math::point<T>& b() const
				{
					return this->_b;
				}

				const ygl::math::point<T>& c() const
				{
					return this->_c;
				}

				const ygl::math::point<T>& d() const
				{
					return this->_d;
				}

				ygl::math::vertex<T> null()
				{
					return ygl::math::vertex<T>(0, 0, 0, 0, true);
				}

				bool is_null()
				{
					return this->_null;
				}

				ygl::math::vertex<T> to_arg(const std::string& a, const std::string& b, const std::string& c, const std::string& d)
				{
					return ygl::math::vertex<T>(ygl::basic::string_to<T>(a), ygl::basic::string_to<T>(b), ygl::basic::string_to<T>(c), ygl::basic::string_to<T>(d));
				}

				const ygl::math::vertex<T>& operator++()
				{
					this->_a++;
					this->_b++;
					this->_c++;
					this->_d++;

					return *this;
				}

				const ygl::math::vertex<T>& operator++(int)
				{
					++this->_a;
					++this->_b;
					++this->_c;
					++this->_d;

					return *this;
				}

				const ygl::math::vertex<T>& operator--()
				{
					this->_a--;
					this->_b--;
					this->_c--;
					this->_d--;

					return *this;
				}

				const ygl::math::vertex<T>& operator--(int)
				{
					--this->_a;
					--this->_b;
					--this->_c;
					--this->_d;

					return *this;
				}

				const ygl::math::vertex<T>& operator+()
				{
					this->_a = +(this->_a);
					this->_b = +(this->_b);
					this->_c = +(this->_c);
					this->_d = +(this->_d);

					return *this;
				}

				const ygl::math::vertex<T>& operator-()
				{
					this->_a = -(this->_a);
					this->_b = -(this->_b);
					this->_c = -(this->_c);
					this->_d = -(this->_d);

					return *this;
				}

				ygl::math::vertex<T> operator+(const ygl::math::vertex<T>& arg)
				{
					return ygl::math::vertex<T>(this->_a + arg.a(), this->_b + arg.b(), this->_c + arg.c(), this->_d + arg.d());
				}

				ygl::math::vertex<T> operator-(const ygl::math::vertex<T>& arg)
				{
					return ygl::math::vertex<T>(this->_a - arg.a(), this->_b - arg.b(), this->_c - arg.c(), this->_d - arg.d());
				}

				ygl::math::vertex<T>operator*(const ygl::math::vertex<T>& arg)
				{
					return ygl::math::vertex<T>(this->_a * arg.a(), this->_b * arg.b(), this->_c * arg.c(), this->_d * arg.d());
				}

				ygl::math::vertex<T> operator/(const ygl::math::vertex<T>& arg)
				{
					return ygl::math::vertex<T>(this->_a / arg.a(), this->_b / arg.b(), this->_c / arg.c(), this->_d / arg.d());
				}

				const ygl::math::vertex<T>& operator+=(const ygl::math::vertex<T>& arg)
				{
					this->_a = this->_a + arg.a();
					this->_b = this->_b + arg.b();
					this->_c = this->_c + arg.c();
					this->_d = this->_d + arg.d();

					return *this;
				}

				const ygl::math::vertex<T>& operator-=(const ygl::math::vertex<T>& arg)
				{
					this->_a = this->_a - arg.a();
					this->_b = this->_b - arg.b();
					this->_c = this->_c - arg.c();
					this->_d = this->_d - arg.d();

					return *this;
				}

				const ygl::math::vertex<T>& operator*=(const ygl::math::vertex<T>& arg)
				{
					this->_a = this->_a * arg.a();
					this->_b = this->_b * arg.b();
					this->_c = this->_c * arg.c();
					this->_d = this->_d * arg.d();

					return *this;
				}

				const ygl::math::vertex<T>& operator/=(const ygl::math::vertex<T>& arg)
				{
					this->_a = this->_a / arg.a();
					this->_b = this->_b / arg.b();
					this->_c = this->_c / arg.c();
					this->_d = this->_d / arg.d();

					return *this;
				}

				bool operator>(const ygl::math::vertex<T>& arg) const
				{
					return this->_a > arg.a() && this->_b > arg.b() && this->_c > arg.c() && this->_d > arg.d();
				}

				bool operator<(const ygl::math::vertex<T>& arg) const
				{
					return this->_a < arg.a() && this->_b < arg.b() && this->_c < arg.c() && this->_d < arg.d();
				}

				bool operator>=(const ygl::math::vertex<T>& arg) const
				{
					return this->_a >= arg.a() && this->_b >= arg.b() && this->_c >= arg.c() && this->_d >= arg.d();
				}

				bool operator<=(const ygl::math::vertex<T>& arg) const
				{
					return this->_a <= arg.a() && this->_b <= arg.b() && this->_c <= arg.c() && this->_d <= arg.d();
				}

				bool operator==(const ygl::math::vertex<T>& arg) const
				{
					return this->_a == arg.a() && this->_b == arg.b() && this->_c == arg.c() && this->_d == arg.d();
				}

				bool operator!=(const ygl::math::vertex<T>& arg) const
				{
					return this->_a != arg.a() || this->_b != arg.b() || this->_c != arg.c() || this->_d != arg.d();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::vertex<T>& arg)
				{
					return stream << "VERTEX { A: " << arg.a() << " B: " << arg.b() << " C: " << arg.c() << " D: " << arg.d() << " }";
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::vertex<T>& arg)
				{
					std::string garbage;
					ygl::math::point<T> a;
					ygl::math::point<T> b;
					ygl::math::point<T> c;
					ygl::math::point<T> d;

					stream >> garbage >> garbage >> garbage >> a >> garbage >> b >> garbage >> c >> garbage >> d >> garbage;

					arg.fill(a, b, c, d);

					return stream;
				}

			private:

				vertex(T a, T b, T c, T d, bool null) :
					_a(a),
					_b(b),
					_c(c),
					_d(d),
					_null(null)
				{
				}

			protected:

				ygl::math::point<T>	_a		{ ygl::math::point<T>() };
				ygl::math::point<T>	_b		{ ygl::math::point<T>() };
				ygl::math::point<T>	_c		{ ygl::math::point<T>() };
				ygl::math::point<T>	_d		{ ygl::math::point<T>()};
				bool				_null	{ false };
		};

		typedef ygl::math::vertex<float>  		vertexf;
		typedef ygl::math::vertex<double> 		vertexd;
		typedef ygl::math::vertex<int>    		vertexi;
		typedef ygl::math::vertex<std::size_t>	vertexui;
	}
}

#endif /* YGL_MATH_VERTEX_H_ */
