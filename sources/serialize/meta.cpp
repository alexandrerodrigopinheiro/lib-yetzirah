#include "serialize/meta.h"

void ygl::serialize::meta::scene(const std::string& scene)
{
	this->_scene = scene;
}

void ygl::serialize::meta::type(const ygl::graphic::type& type)
{
	this->_type = type;
}

void ygl::serialize::meta::filename(const std::string& filename)
{
	this->_filename = filename;
}

void ygl::serialize::meta::name(const std::string& name)
{
	this->_name = name;
}

void ygl::serialize::meta::matrix(const ygl::math::matrixd& matrix)
{
	this->_matrix = matrix;
}

void ygl::serialize::meta::spot(std::size_t spot)
{
	this->_spot = spot;
}

void ygl::serialize::meta::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::serialize::meta::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::serialize::meta::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::serialize::meta::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
}

void ygl::serialize::meta::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::serialize::meta::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::serialize::meta::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::serialize::meta::animatic(const std::vector<ygl::serialize::animatic>& animated)
{
	for (std::size_t i = 0; i < animated.size(); i++)
	{
		this->_animatic.push_back(animated[i]);
	}
}

void ygl::serialize::meta::animatic(const ygl::serialize::animatic& animated)
{
	this->_animatic.push_back(animated);
}

const std::string& ygl::serialize::meta::scene() const
{
	return this->_scene;
}

const ygl::graphic::type& ygl::serialize::meta::type() const
{
	return this->_type;
}

const std::string& ygl::serialize::meta::filename() const
{
	return this->_filename;
}

const std::string& ygl::serialize::meta::name() const
{
	return this->_name;
}

const ygl::math::matrixd& ygl::serialize::meta::matrix() const
{
	return this->_matrix;
}

std::size_t ygl::serialize::meta::spot() const
{
	return this->_spot;
}

bool ygl::serialize::meta::visible() const
{
	return this->_visible;
}

const ygl::graphic::flip& ygl::serialize::meta::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::serialize::meta::color() const
{
	return this->_color;
}

const ygl::math::pointd& ygl::serialize::meta::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::serialize::meta::position() const
{
	return this->_position;
}

const ygl::math::sized& ygl::serialize::meta::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::serialize::meta::rotate() const
{
	return this->_rotate;
}

std::vector<ygl::serialize::animatic>& ygl::serialize::meta::animatic()
{
	return this->_animatic;
}

ygl::serialize::animatic& ygl::serialize::meta::animatic(std::size_t index)
{
	if (index >= this->_animatic.size())
	{
		std::cerr << "Illegal index '" << index << "', failed" << std::endl;
		exit(0);
	}

	return this->_animatic[index];
}
