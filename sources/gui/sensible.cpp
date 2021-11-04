#include "gui/sensible.h"

ygl::gui::sensible::sensible() :
	_state(ygl::gui::state::STATE_NULL),
	_area(ygl::math::surfaced())
{
}

ygl::gui::sensible::sensible(const sensible& obj) :
	_state(ygl::gui::state::STATE_NULL),
	_area(ygl::math::surfaced())
{
	*this = obj;
}

ygl::gui::sensible::sensible(const ygl::gui::state& state, const ygl::math::surfaced& area) :
	_state(ygl::gui::state::STATE_NULL),
	_area(ygl::math::surfaced())
{
	this->initialize(state, area);
}

ygl::gui::sensible::~sensible()
{
	this->destroy();
}

bool ygl::gui::sensible::initialize(const ygl::gui::state& state, const ygl::math::surfaced& area)
{
	this->_state = state;
	this->_area  = area;

	return true;
}

bool ygl::gui::sensible::destroy()
{
	return true;
}

void ygl::gui::sensible::state(const ygl::gui::state& state)
{
	this->_state = state;
}

void ygl::gui::sensible::area(const ygl::math::surfaced& area)
{
	this->_area = area;
}

void ygl::gui::sensible::area_x(double x)
{
	this->_area.x(x);
}

void ygl::gui::sensible::area_y(double y)
{
	this->_area.y(y);
}

void ygl::gui::sensible::area_w(double w)
{
	this->_area.w(w);
}

void ygl::gui::sensible::area_h(double h)
{
	this->_area.h(h);
}

const ygl::gui::state& ygl::gui::sensible::state() const
{
	return this->_state;
}

const ygl::math::surfaced& ygl::gui::sensible::area() const
{
	return this->_area;
}
