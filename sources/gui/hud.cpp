#include "gui/hud.h"

ygl::gui::hud::hud() :
	_box(nullptr),
	_data(nullptr),
	_visible(true),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_position(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_scale(ygl::math::sized(1.f)),
	_size(ygl::math::sized())
{
}

ygl::gui::hud::hud(const std::string& filename, std::size_t measure, const ygl::math::sized& size) :
	_box(nullptr),
	_data(nullptr),
	_visible(true),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_position(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_scale(ygl::math::sized(1.f)),
	_size(ygl::math::sized())
{
	this->initialize(filename, measure, size);
}

ygl::gui::hud::~hud()
{
	this->destroy();
}

bool ygl::gui::hud::initialize(const std::string& filename, std::size_t measure, const ygl::math::sized& size)
{
	this->_box  = new ygl::graphic::shape(size);

	this->_box->opacity(75);
	this->_box->color(ygl::math::colord().BLACK());

	this->_data = new ygl::graphic::text(filename, measure);

	this->_data->position(this->_data->size().w() / 2, (this->_data->size().h() / 2) + 2, 0.0);
	this->_data->color(ygl::math::colord().WHITE());

	this->_size = size;

	return true;
}

void ygl::gui::hud::destroy()
{
	delete this->_box;
	delete this->_data;

	this->_box  = nullptr;
	this->_data = nullptr;
}

void ygl::gui::hud::draw()
{
	if (this->_visible && this->_opacity > 0)
	{
		glPushMatrix();

		glEnable(GL_BLEND);

		glTranslated(this->_position.x(), this->_position.y(), this->_position.z());

		glRotated(this->_rotate.h(), 1.0, 0.0, 0.0);
		glRotated(this->_rotate.p(), 0.0, 1.0, 0.0);
		glRotated(this->_rotate.b(), 0.0, 0.0, 1.0);

		glScaled(this->_scale.w(), this->_scale.h(), this->_scale.l());

		glColor4d(
			ygl::math::normal_channel(this->_color.r()),
			ygl::math::normal_channel(this->_color.g()),
			ygl::math::normal_channel(this->_color.b()),
			ygl::math::normal_opacity(this->_opacity)
		);

		this->_box->draw();
		this->_data->draw();

		glDisable(GL_BLEND);

		glPopMatrix();
	}
}


void ygl::gui::hud::draw(const std::string& message, const ygl::math::pointd& position, const ygl::math::rotated& rotate, const ygl::math::colord& color, int opacity, const ygl::graphic::align& align)
{
	if (this->_data->message() != message)
	{
		this->_data->message(message);
	}

	if (this->_position != position && !position.is_null())
	{
		this->_position = position;
	}

	if (this->_rotate != rotate && !rotate.is_null())
	{
		this->_rotate = rotate;
	}

	if (this->_color != color && !color.is_null())
	{
		this->_color = color;
	}

	if ((int)this->_opacity != opacity && opacity > -1)
	{
		this->_opacity = (std::size_t)opacity;
	}

	if (this->_data->align() != align && align != ygl::graphic::align::ALIGN_NULL)
	{
		this->_data->align(align);
	}

	this->draw();
}

void ygl::gui::hud::data(const std::string& message)
{
	this->_data->message(message);
}

void ygl::gui::hud::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::gui::hud::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::gui::hud::color(double r, double g, double b)
{
	this->_color.fill(r, g, b);
}

void ygl::gui::hud::color_r(double r)
{
	this->_color.r(r);
}

void ygl::gui::hud::color_g(double g)
{
	this->_color.g(g);
}

void ygl::gui::hud::color_b(double b)
{
	this->_color.b(b);
}

void ygl::gui::hud::opacity(double opacity)
{
	this->_opacity = ygl::math::clamp(opacity, 0.0, 100.0);
}

void ygl::gui::hud::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::gui::hud::position(double x, double y, double z)
{
	this->_position.fill(x, y, z);
}

void ygl::gui::hud::position_x(double x)
{
	this->_position.x(x);
}

void ygl::gui::hud::position_y(double y)
{
	this->_position.y(y);
}

void ygl::gui::hud::position_z(double z)
{
	this->_position.z(z);
}

void ygl::gui::hud::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::gui::hud::rotate(double h, double p, double b)
{
	this->_rotate.fill(h, p, b);
}

void ygl::gui::hud::rotate_h(double h)
{
	this->_rotate.h(h);
}

void ygl::gui::hud::rotate_p(double p)
{
	this->_rotate.p(p);
}

void ygl::gui::hud::rotate_b(double b)
{
	this->_rotate.b(b);
}

void ygl::gui::hud::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::gui::hud::scale(double w, double h, double l)
{
	this->_scale.fill(w, h, l);
}

void ygl::gui::hud::scale_w(double w)
{
	this->_scale.w(w);
}

void ygl::gui::hud::scale_h(double h)
{
	this->_scale.h(h);
}

void ygl::gui::hud::scale_l(double l)
{
	this->_scale.l(l);
}

const std::string& ygl::gui::hud::data() const
{
	return this->_data->message();
}

bool ygl::gui::hud::visible() const
{
	return this->_visible;
}

const ygl::math::colord& ygl::gui::hud::color() const
{
	return this->_color;
}

double ygl::gui::hud::opacity() const
{
	return this->_opacity;
}

const ygl::math::pointd& ygl::gui::hud::position() const
{
	return this->_position;
}

const ygl::math::rotated& ygl::gui::hud::rotate() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::gui::hud::scale() const
{
	return this->_scale;
}

const ygl::math::sized& ygl::gui::hud::size() const
{
	return this->_size;
}

ygl::graphic::shape* ygl::gui::hud::access_box()
{
	return this->_box;
}

ygl::graphic::text* ygl::gui::hud::access_data()
{
	return this->_data;
}
