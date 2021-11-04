#include "gui/button.h"

ygl::gui::button::button() :
	_button(),
	_state(ygl::gui::state::STATE_ENABLED),
	_sensible(ygl::math::surfaced())
{
}

ygl::gui::button::~button()
{
	this->destroy();
}

bool ygl::gui::button::initialize(const std::string& filename, std::size_t colunm, std::size_t spot)
{
	if (!this->_button->initialize(filename, colunm, (spot == 0 ? colunm : spot)))
	{
		std::cerr << "Can not load file '" << filename << "', failed" << std::endl;

		return false;
	}

	this->_sensible.fill(0.0, 0.0, (float)this->_button->size().w(), (float)this->_button->size().h());

	return true;
}

void ygl::gui::button::destroy()
{
	this->_button->destroy();
}

void ygl::gui::button::draw(const ygl::math::pointd& position, const ygl::gui::state& state)
{
	if (this->_button->position() != position)
	{
		this->position(position);
	}

	if (this->_state != state && state != ygl::gui::state::STATE_NULL)
	{
		this->state(state);
	}

	this->_button->draw();
}

const ygl::math::pointd& ygl::gui::button::position() const
{
	return this->_button->position();
}

const ygl::gui::state& ygl::gui::button::state() const
{
	return this->_state;
}

void ygl::gui::button::sensible(const ygl::math::surfaced& sensible)
{
	this->_sensible = sensible;
}

const ygl::math::surfaced& ygl::gui::button::sensible() const
{
	return this->_sensible;
}

void ygl::gui::button::position(const ygl::math::pointd& position)
{
	this->_button->position(position);

	this->_sensible.x(position.x());
	this->_sensible.y(position.y());
}

void ygl::gui::button::state(const ygl::gui::state& state)
{
	this->_state = state;

	switch (this->_state)
	{
		case ygl::gui::state::STATE_ENABLED:  { this->_button->spot((std::size_t)ygl::gui::state::STATE_ENABLED);  break; }
		case ygl::gui::state::STATE_HOVER:    { this->_button->spot((std::size_t)ygl::gui::state::STATE_HOVER);    break; }
		case ygl::gui::state::STATE_PRESSED:  { this->_button->spot((std::size_t)ygl::gui::state::STATE_PRESSED);  break; }
		case ygl::gui::state::STATE_RELEASED: { this->_button->spot((std::size_t)ygl::gui::state::STATE_RELEASED); break; }
		case ygl::gui::state::STATE_DISABLED: { this->_button->spot((std::size_t)ygl::gui::state::STATE_DISABLED); break; }
		default: break;
	}
}

std::ostream& operator<<(std::ostream& stream, const ygl::gui::button& button)
{
	return stream << button.state();
}

std::istream& operator>>(std::istream& stream, ygl::gui::button& button)
{
	ygl::gui::state state;

	stream >> state;
	button.state(state);

	return stream;
}
