#include "device/mouse.h"

ygl::device::mouse::mouse() :
	_cursor(ygl::device::cursor::CURSOR_NONE),
	_position(ygl::math::pointd().null())
{
}

ygl::device::mouse::~mouse()
{
}

void ygl::device::mouse::cursor(const ygl::device::cursor& cursor)
{
	this->_cursor = cursor;
}

void ygl::device::mouse::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::device::mouse::position(double x, double y, double z)
{
	this->_position.fill(x, y, z);
}

bool ygl::device::mouse::motioned() const
{
	return this->_cursor == ygl::device::cursor::CURSOR_MOTION;
}

bool ygl::device::mouse::pressed() const
{
	return this->_cursor == ygl::device::cursor::CURSOR_PRESSED;
}

bool ygl::device::mouse::released() const
{
	return this->_cursor == ygl::device::cursor::CURSOR_RELEASED;
}

const ygl::math::pointd& ygl::device::mouse::position() const
{
	return this->_position;
}

const ygl::device::cursor& ygl::device::mouse::cursor() const
{
	return this->_cursor;
}

void ygl::device::mouse::clear()
{
	this->_cursor   = ygl::device::cursor::CURSOR_NONE;
	this->_position = ygl::math::pointd().null();
}
