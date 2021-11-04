#include "animation/keyframe.h"

void ygl::animation::keyframe::frame(std::size_t frame)
{
	this->_frame = frame;
}

void ygl::animation::keyframe::visible(const ygl::graphic::visible& visible)
{
	this->_visible = visible;
}

void ygl::animation::keyframe::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::animation::keyframe::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::animation::keyframe::opacity(double opacity)
{
	this->_opacity = opacity;
}

void ygl::animation::keyframe::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
}

void ygl::animation::keyframe::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::animation::keyframe::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::animation::keyframe::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

std::size_t ygl::animation::keyframe::frame() const
{
	return this->_frame;
}

const ygl::graphic::visible& ygl::animation::keyframe::visible() const
{
	return this->_visible;
}

const ygl::graphic::flip& ygl::animation::keyframe::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::animation::keyframe::color() const
{
	return this->_color;
}

double ygl::animation::keyframe::opacity() const
{
	return this->_opacity;
}

const ygl::math::pointd& ygl::animation::keyframe::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::animation::keyframe::position() const
{
	return this->_position;
}

const ygl::math::sized& ygl::animation::keyframe::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::animation::keyframe::rotate() const
{
	return this->_rotate;
}

