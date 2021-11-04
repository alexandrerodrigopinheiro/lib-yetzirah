#include "math/monetary.h"

ygl::math::monetary::monetary() :
	_credit(0)
{
}

ygl::math::monetary::monetary(uint64_t credits) :
	_credit(credits)
{
}

ygl::math::monetary::~monetary()
{
}

bool ygl::math::monetary::empty() const
{
	return this->_credit == 0;
}

void ygl::math::monetary::clear()
{
	this->_credit = 0;
}

std::string ygl::math::monetary::stamp() const
{
	std::string str = ygl::basic::to_string(this->_credit);
	std::string tmp;

	for (uint64_t i = 0; i < str.length(); i++)
	{
		if (i == str.length() - 2)
		{
			tmp += ",";
		}

		tmp += str[i];
	}

	return tmp;
}

float ygl::math::monetary::money() const
{
	return static_cast<float>(this->_credit * 1.00);
}

uint64_t ygl::math::monetary::credit() const
{
	return this->_credit;
}

void ygl::math::monetary::add(uint64_t value)
{
	this->_credit = value;
}

void ygl::math::monetary::sum(uint64_t value)
{
	this->_credit += value;
}

void ygl::math::monetary::sub(uint64_t value)
{
	this->_credit -= value;
}

void ygl::math::monetary::operator=(const ygl::math::monetary& monetary)
{
	this->_credit = monetary.credit();
}

ygl::math::monetary ygl::math::monetary::operator++()
{
	return ygl::math::monetary(this->_credit + 1);
}

ygl::math::monetary ygl::math::monetary::operator--()
{
	this->_credit = this->_credit > 0 ? this->_credit - 1 : this->_credit;

	return ygl::math::monetary(this->_credit);
}

ygl::math::monetary ygl::math::monetary::operator++(int)
{
	uint64_t val = this->_credit;

	this->_credit += 1;

	return ygl::math::monetary(val);
}

ygl::math::monetary ygl::math::monetary::operator--(int)
{
	uint64_t val = this->_credit;

	this->_credit = this->_credit > 0 ? this->_credit - 1 : this->_credit;

	return ygl::math::monetary(val);
}

ygl::math::monetary ygl::math::monetary::operator+(const ygl::math::monetary& monetary)
{
	return ygl::math::monetary(this->_credit + monetary.credit());
}

ygl::math::monetary ygl::math::monetary::operator-(const ygl::math::monetary& monetary)
{
	if (monetary.credit() > this->_credit)
	{
		std::cerr << "ERROR: in operator-() current value is high that value to subtraction: " << this->_credit << " < " << monetary.credit() << std::endl;
		exit(ygl::error::type::ERROR_UNSIGNED);
	}

	return ygl::math::monetary(this->_credit - monetary.credit());
}

ygl::math::monetary ygl::math::monetary::operator*(const ygl::math::monetary& monetary)
{
	return ygl::math::monetary(this->_credit * monetary.credit());
}

ygl::math::monetary ygl::math::monetary::operator/(const ygl::math::monetary& monetary)
{
	return ygl::math::monetary(this->_credit / monetary.credit());
}

bool ygl::math::monetary::operator<(const ygl::math::monetary& monetary)
{
	return this->_credit < monetary.credit();
}

bool ygl::math::monetary::operator<=(const ygl::math::monetary& monetary)
{
	return this->_credit <= monetary.credit();
}

bool ygl::math::monetary::operator>(const ygl::math::monetary& monetary)
{
	return this->_credit > monetary.credit();
}

bool ygl::math::monetary::operator>=(const ygl::math::monetary& monetary)
{
	return this->_credit >= monetary.credit();
}

bool ygl::math::monetary::operator==(const ygl::math::monetary& monetary)
{
	return this->_credit == monetary.credit();
}

bool ygl::math::monetary::operator!=(const ygl::math::monetary& monetary)
{
	return this->_credit != monetary.credit();
}
