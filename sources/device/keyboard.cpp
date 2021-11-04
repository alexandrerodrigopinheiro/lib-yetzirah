#include "device/keyboard.h"

ygl::device::keyboard::keyboard() :
	_button(ygl::device::button::BUTTON_INVALID),
	_key(ygl::device::key::KEY_NONE)
{
}

ygl::device::keyboard::~keyboard()
{
}

void ygl::device::keyboard::button(const ygl::device::button& button)
{
	this->_button = button;
}

void ygl::device::keyboard::key(const ygl::device::key& key)
{
	this->_key = key;
}

const ygl::device::button& ygl::device::keyboard::button() const
{
	return this->_button;
}

bool ygl::device::keyboard::pressed() const
{
	return this->_key == ygl::device::key::KEY_PRESSED;
}

bool ygl::device::keyboard::released() const
{
	return this->_key == ygl::device::key::KEY_RELEASED;
}

void ygl::device::keyboard::clear()
{
	this->_button = ygl::device::button::BUTTON_INVALID;
	this->_key = ygl::device::key::KEY_NONE;
}
