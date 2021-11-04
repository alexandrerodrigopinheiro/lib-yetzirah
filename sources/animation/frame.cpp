#include "animation/frame.h"

void ygl::animation::frame::message(const std::string& message)
{
	this->_message = message;
}

void ygl::animation::frame::spot(std::size_t spot)
{
	this->_spot = spot;
}

void ygl::animation::frame::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::animation::frame::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::animation::frame::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::animation::frame::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
}

void ygl::animation::frame::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::animation::frame::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::animation::frame::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

const std::string& ygl::animation::frame::message() const
{
	return this->_message;
}

std::size_t ygl::animation::frame::spot() const
{
	return this->_spot;
}

bool ygl::animation::frame::visible() const
{
	return this->_visible;
}

const ygl::graphic::flip& ygl::animation::frame::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::animation::frame::color() const
{
	return this->_color;
}

const ygl::math::pointd& ygl::animation::frame::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::animation::frame::position() const
{
	return this->_position;
}

const ygl::math::sized& ygl::animation::frame::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::animation::frame::rotate() const
{
	return this->_rotate;
}
