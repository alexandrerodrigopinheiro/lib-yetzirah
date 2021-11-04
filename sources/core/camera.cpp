#include "core/camera.h"

ygl::core::camera::camera() :
	_name("Unamed"),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_position(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_scale(ygl::math::sized())
{
}

ygl::core::camera::~camera()
{
	this->destroy();
}

bool ygl::core::camera::initialize(const std::string& name, const ygl::math::pointd& position, const ygl::math::sized& size)
{
	this->_name = name;
	this->_position = position;
	this->_size = size;

	return true;
}

void ygl::core::camera::destroy()
{
}

void ygl::core::camera::renderize()
{
	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glTranslated(this->_position.x(), this->_position.y(), 0.0);

	glRotated(this->_rotate.h(), 1.0, 0.0, 0.0);
	glRotated(this->_rotate.p(), 0.0, 1.0, 0.0);
	glRotated(this->_rotate.b(), 0.0, 0.0, 1.0);
	glScaled(this->_scale.w(), this->_scale.h(), this->_scale.l());

	glColor4d(
		(double)ygl::math::normal_channel(this->_color.r()),
		(double)ygl::math::normal_channel(this->_color.g()),
		(double)ygl::math::normal_channel(this->_color.b()),
		(double)ygl::math::normal_opacity(this->_opacity)
	);

	glViewport(this->_position.x(), this->_position.y(), this->_size.w(), this->_size.h());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(this->_position.x(), this->_size.w(), this->_size.h(),  this->_position.y(), ygl::math::invert(this->_size.w()), this->_size.w());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);

	glPopMatrix();
}

const std::string& ygl::core::camera::name() const
{
	return this->_name;
}

const ygl::math::colord& ygl::core::camera::color() const
{
	return this->_color;
}

double ygl::core::camera::opacity() const
{
	return this->_opacity;
}

const ygl::math::pointd& ygl::core::camera::position() const
{
	return this->_position;
}

const ygl::math::rotated& ygl::core::camera::rotate() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::core::camera::size() const
{
	return this->_size;
}

const ygl::math::sized& ygl::core::camera::scale() const
{
	return this->_scale;
}

void ygl::core::camera::name(const std::string& name)
{
	this->_name = name;
}

void ygl::core::camera::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::core::camera::opacity(double opacity)
{
	this->_opacity = opacity;
}

void ygl::core::camera::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::core::camera::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::core::camera::size(const ygl::math::sized& size)
{
	this->_size = size;
}

void ygl::core::camera::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}
