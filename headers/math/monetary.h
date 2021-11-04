#ifndef YGL_MATH_MONETARY_H_
#define YGL_MATH_MONETARY_H_

#pragma once

#include <iostream>
#include <string>

#include "basic/basic.h"
#include "error/error.h"

namespace ygl
{
	namespace math
	{
		class monetary
		{
			public:

				monetary();

				monetary(uint64_t credits);

				~monetary();

				bool empty() const;

				void clear();

				std::string stamp() const;

				void add(uint64_t credit);

				void sum(uint64_t credit);

				void sub(uint64_t credit);

				float money() const;

				uint64_t credit() const;

				void operator=(const monetary& monetary);

				monetary operator++();

				monetary operator++(int);

				monetary operator--();

				monetary operator--(int);

				monetary operator+(const monetary& monetary);

				monetary operator-(const monetary& monetary);

				monetary operator*(const monetary& monetary);

				monetary operator/(const monetary& monetary);

				bool operator<(const monetary& monetary);

				bool operator<=(const monetary& monetary);

				bool operator>(const monetary& monetary);

				bool operator>=(const monetary& monetary);

				bool operator==(const monetary& monetary);

				bool operator!=(const monetary& monetary);

				friend std::ostream& operator<<(std::ostream &stream, const monetary& monetary)
				{
					stream << "MONETARY { " << monetary.credit() << " }";

					return stream;
				}

				friend std::istream& operator>>(std::istream &stream, monetary& monetary)
				{
					std::string garage;
					uint64_t tmp;

					stream >> garage >> garage >> tmp >> garage;

					monetary.add(tmp);

					return stream;
				}

			protected:

				uint64_t _credit { 0 };
		};
	}
}

#endif /* YGL_MATH_MONETARY_H_ */
