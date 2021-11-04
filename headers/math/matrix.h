#ifndef YGL_MATH_MATRIX_H_
#define YGL_MATH_MATRIX_H_

#pragma once

#include <iostream>
#include <string>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<typename T>
		class matrix
		{
			public:

				matrix() :
					_rows(static_cast<T>(0)),
					_colunms(static_cast<T>(0)),
					_null(false)
				{
				}

				matrix(const ygl::math::matrix<T>& obj) :
					_rows(obj.rows()),
					_colunms(obj.colunms()),
					_null(false)
				{
				}

				matrix(T rows, T colunms) :
					_rows(rows),
					_colunms(colunms),
					_null(false)
				{
				}

				matrix(T arg) :
					_rows(arg),
					_colunms(arg),
					_null(false)
				{
				}

				void fill(T value)
				{
					this->_rows = value;
					this->_colunms = value;
				}

				void fill(T rows, T colunms)
				{
					this->_rows = rows;
					this->_colunms = colunms;
				}

				void rows(const T& rows)
				{
					this->_rows = rows;
				}

				void colunms(const T& colunms)
				{
					this->_colunms = colunms;
				}

				T rows() const
				{
					return this->_rows;
				}

				T colunms() const
				{
					return this->_colunms;
				}

				void clear()
				{
					this->_rows = static_cast<T>(0);
					this->_colunms = static_cast<T>(0);
				}

				bool empty()
				{
					return this->_rows == static_cast<T>(0) && this->_colunms == static_cast<T>(0);
				}

				ygl::math::matrix<T>null()
				{
					return ygl::math::matrix<T>(0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::matrix<T> to_matrix(const std::string& rows, const std::string& colunms)
				{
					return ygl::math::matrix<T>(ygl::basic::string_to<T>(rows), ygl::basic::string_to<T>(colunms));
				}

				const ygl::math::matrix<T>& operator++()
				{
					++this->_rows;
					++this->_colunms;
					return *this;
				}

				const ygl::math::matrix<T>& operator++(int)
				{
					this->_rows++;
					this->_colunms++;
					return *this;
				}

				const ygl::math::matrix<T>& operator--()
				{
					--this->_rows;
					--this->_colunms;
					return *this;
				}

				const ygl::math::matrix<T>& operator--(int)
				{
					this->_rows--;
					this->_colunms--;
					return *this;
				}

				const ygl::math::matrix<T>& operator+()
				{
					this->_rows = +(this->_rows);
					this->_colunms = +(this->_colunms);
					return *this;
				}

				const ygl::math::matrix<T>& operator+(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows + arg.rows();
					this->_colunms = this->_colunms + arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator+=(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows + arg.rows();
					this->_colunms = this->_colunms + arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator-()
				{
					this->_rows = -(this->_rows);
					this->_colunms = -(this->_colunms);
					return *this;
				}

				const ygl::math::matrix<T>& operator-(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows - arg.rows();
					this->_colunms = this->_colunms - arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator-=(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows - arg.rows();
					this->_colunms = this->_colunms - arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator*(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows * arg.rows();
					this->_colunms = this->_colunms * arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator*=(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows * arg.rows();
					this->_colunms = this->_colunms * arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator/(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows / arg.rows();
					this->_colunms = this->_colunms / arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator/=(const ygl::math::matrix<T>& arg)
				{
					this->_rows = this->_rows / arg.rows();
					this->_colunms = this->_colunms / arg.colunms();
					return *this;
				}

				const ygl::math::matrix<T>& operator=(const ygl::math::matrix<T>& arg)
				{
					this->_rows = arg.rows();
					this->_colunms = arg.colunms();
					return *this;
				}

				bool operator==(const ygl::math::matrix<T>& arg) const
				{
					return this->_rows == arg.rows() && this->_colunms == arg.colunms();
				}

				bool operator!=(const ygl::math::matrix<T>& arg) const
				{
					return this->_rows != arg.rows() || this->_colunms != arg.colunms();
				}

				bool operator>(const ygl::math::matrix<T>& arg) const
				{
					return this->_rows > arg.rows() || this->_colunms > arg.colunms();
				}

				bool operator>=(const ygl::math::matrix<T>& arg) const
				{
					return this->_rows >= arg.rows() || this->_colunms >= arg.colunms();
				}

				bool operator<(const ygl::math::matrix<T>& arg) const
				{
					return this->_rows < arg.rows() || this->_colunms < arg.colunms();
				}

				bool operator<=(const ygl::math::matrix<T>& arg) const
				{
					return this->_rows <= arg.rows() || this->_colunms <= arg.colunms();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::matrix<T>& arg)
				{
					stream << "MATRIX { R: " << arg.rows() << " C: " << arg.colunms() << " }";
					return stream;
				}

				friend std::istream& operator>>(std::istream& stream, ygl::math::matrix<T>& arg)
				{
					T rows;
					T colunms;
					std::string garbage;

					stream >> garbage >> garbage >> garbage >> rows >> garbage >> colunms >> garbage;

					arg.rows(rows);
					arg.colunms(colunms);

					return stream;
				}

			private:

				matrix(T rows, T colunms, bool null) :
					_rows(rows),
					_colunms(colunms),
					_null(null)
				{
				}

			protected:

				T		_rows		{ (T)0 };
				T		_colunms	{ (T)0 };
				bool	_null		{ false };
		};

		typedef ygl::math::matrix<int>    matrixi;
		typedef ygl::math::matrix<std::size_t>   matrixui;
		typedef ygl::math::matrix<float>  matrixf;
		typedef ygl::math::matrix<double> matrixd;
	}
}

#endif /* YGL_MATH_MATRIX_H_ */
