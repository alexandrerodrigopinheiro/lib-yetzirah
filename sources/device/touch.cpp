#include "device/touch.h"

ygl::device::touch::touch() :
	_finger(ygl::device::finger::FINGER_NONE),
	_position(ygl::math::pointd().null())
{
}

ygl::device::touch::~touch()
{
}

void ygl::device::touch::finger(const ygl::device::finger& finger)
{
	this->_finger = finger;
}

void ygl::device::touch::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::device::touch::position(double x, double y, double z)
{
	this->_position.fill(x, y, z);
}

bool ygl::device::touch::motioned() const
{
	return this->_finger == ygl::device::finger::FINGER_MOTION;
}

bool ygl::device::touch::pressed() const
{
	return this->_finger == ygl::device::finger::FINGER_PRESSED;
}

bool ygl::device::touch::released() const
{
	return this->_finger == ygl::device::finger::FINGER_RELEASED;
}

const ygl::math::pointd& ygl::device::touch::position() const
{
	return this->_position;
}

const ygl::device::finger& ygl::device::touch::finger() const
{
	return this->_finger;
}

void ygl::device::touch::clear()
{
	this->_finger = ygl::device::finger::FINGER_NONE;
	this->_position = ygl::math::pointd().null();
}
