#include "emitter/generator.h"

ygl::emitter::generator::generator() :
	_born(0),
	_velocity(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized())
{
	ygl::random::seed();
}

ygl::emitter::generator::generator(const generator& obj) :
	_born(0),
	_velocity(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized())
{
	*this = obj;
}

ygl::emitter::generator::~generator()
{
}

void ygl::emitter::generator::seed()
{
	ygl::random::seed();
}

bool ygl::emitter::generator::spown(const ygl::math::sized& size, double velocity, std::size_t life)
{
	this->spown_born(life);
	this->spown_velocity(velocity);
	this->spown_rotate();
	this->spown_size(size);

	return true;
}

std::size_t ygl::emitter::generator::spown_born(std::size_t life)
{
	double m_max = static_cast<double>(life);
	double m_out = static_cast<double>(m_max) * (static_cast<double>(ygl::random::number() % 101) / 100.0);
	this->_born  = static_cast<std::size_t>(std::ceil(m_out));

	return this->_born;
}

ygl::math::pointd ygl::emitter::generator::spown_velocity(double velocity)
{
	double m_val_x  = velocity * (static_cast<double>(ygl::random::number() % 100 + 1) / 100.0);
	double m_val_y  = velocity * (static_cast<double>(ygl::random::number() % 100 + 1) / 100.0);
	double m_val_z  = velocity * (static_cast<double>(ygl::random::number() % 100 + 1) / 100.0);
	double m_out_x  = ygl::random::number() % 2 == 0 ? ygl::math::invert(m_val_x) : m_val_x;
	double m_out_y  = ygl::random::number() % 2 == 0 ? ygl::math::invert(m_val_y) : m_val_y;
	double m_out_z  = ygl::random::number() % 2 == 0 ? ygl::math::invert(m_val_z) : m_val_z;
	this->_velocity = ygl::math::pointd(m_out_x, m_out_y, m_out_z);

	return this->_velocity;
}

ygl::math::rotated ygl::emitter::generator::spown_rotate()
{
	double m_rot_h  = 0.0;
	double m_rot_p  = 0.0;
	double m_rot_b  = ygl::random::number() % 360;
	this->_rotate = ygl::math::rotated(m_rot_h, m_rot_p, m_rot_b);

	return this->_rotate;
}

ygl::math::sized ygl::emitter::generator::spown_size(const ygl::math::sized& size)
{
	double m_max = std::max(size.w(), size.h());
	double m_val = static_cast<double>(m_max * (static_cast<double>(ygl::random::number() % 51 + 50) / 100.0));

	double m_out = ygl::random::number() % 2 == 0 ? ygl::math::invert(m_val) : m_val;
	this->_size  = ygl::math::sized(m_out);

	return this->_size;
}

ygl::math::colord ygl::emitter::generator::random_color()
{
	double m_r = ygl::random::number() % 256;
	double m_g = ygl::random::number() % 256;
	double m_b = ygl::random::number() % 256;

	return ygl::math::colord(m_r, m_g, m_b);
}

std::size_t ygl::emitter::generator::born() const
{
	return this->_born;
}

const ygl::math::pointd& ygl::emitter::generator::velocity() const
{
	return this->_velocity;
}

const ygl::math::rotated& ygl::emitter::generator::rotate() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::emitter::generator::size() const
{
	return this->_size;
}
