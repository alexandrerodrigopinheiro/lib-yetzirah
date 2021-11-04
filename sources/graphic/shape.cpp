#include "graphic/shape.h"

ygl::graphic::shape::shape() :
	_visible(true),
	_wireframe(false),
	_filename(std::string()),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_position(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_vertex(ygl::math::vertexd()),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
}

ygl::graphic::shape::shape(const shape& obj) :
	_visible(true),
	_wireframe(false),
	_filename(std::string()),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_position(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_vertex(ygl::math::vertexd()),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
	*this = obj;
}

ygl::graphic::shape::shape(const ygl::math::sized& size) :
	_visible(true),
	_wireframe(false),
	_filename(std::string()),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_position(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_vertex(ygl::math::vertexd()),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
	this->initialize(size);
}

ygl::graphic::shape::~shape()
{
	this->destroy();
}

bool ygl::graphic::shape::initialize(const ygl::math::sized& size)
{
	this->_size = size;

	this->resolve();

	return true;
}

void ygl::graphic::shape::destroy()
{
	this->_animation.clear();
}

ygl::animation::tween* ygl::graphic::shape::tweening(const std::string& animation)
{
	auto it = this->_tweening.find(animation);
	if (it == this->_tweening.end())
	{
		std::cerr << "Text animation '" << animation << "' not found, failed" << std::endl;
		exit(0);
	}
	return this->_tweening[animation];
}

bool ygl::graphic::shape::animation(const std::string& animation, std::size_t timeline)
{
	auto it = this->_tweening.find(animation);

	if (it != this->_tweening.end())
	{
		return false;
	}

	if (this->_tweening.size() == 0)
	{
		this->_animation = animation;
	}

	this->_tweening.insert(std::pair<std::string, ygl::animation::tween*>(animation, new ygl::animation::tween(animation, timeline)));

	return true;
}

bool ygl::graphic::shape::animation(const std::string& animation, std::size_t timeline, std::size_t fps)
{
	auto it = this->_tweening.find(animation);

	if (it != this->_tweening.end())
	{
		return false;
	}

	if (this->_tweening.size() == 0)
	{
		this->_animation = animation;
	}

	this->_tweening.insert(std::pair<std::string, ygl::animation::tween*>(animation, new ygl::animation::tween(animation, timeline, fps)));

	return true;
}

void ygl::graphic::shape::animation(const std::string& animation)
{
	auto it = this->_tweening.find(animation);

	if (it == this->_tweening.end())
	{
		std::cerr << "Image animation '" << animation << "' not found, failed" << std::endl;

		exit(0);
	}

	this->_animation = animation;
}

bool ygl::graphic::shape::sensible(const std::string& name, const ygl::math::surfaced& sensible)
{
	auto it = this->_sensible.find(name);

	if (it != this->_sensible.end())
	{
		return false;
	}

	this->_sensible.insert(std::pair<std::string, ygl::math::surfaced>(name, sensible));

	return true;
}

const ygl::math::surfaced& ygl::graphic::shape::sensible(const std::string& name)
{
	auto it = this->_sensible.find(name);

	if (it == this->_sensible.end())
	{
		std::cerr << "Layer sensible not found" << std::endl;
		exit(1);
	}

	return this->_sensible[name];
}

void ygl::graphic::shape::draw()
{
	if (this->_visible && this->_opacity > 0)
	{
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
//		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glTranslated(this->_position.x(), this->_position.y(), ygl::math::invert(this->_position.z()));

		glRotatef(this->_rotate.h(), 1.0, 0.0, 0.0);
		glRotatef(this->_rotate.p(), 0.0, 1.0, 0.0);
		glRotatef(this->_rotate.b(), 0.0, 0.0, 1.0);

		glScalef(this->_scale.w(), this->_scale.h(), this->_scale.l());

		glColor4f(
			ygl::math::normal_channel(this->_color.r()),
			ygl::math::normal_channel(this->_color.g()),
			ygl::math::normal_channel(this->_color.b()),
			ygl::math::normal_opacity(this->_opacity)
		);

		switch (this->_flip)
		{
			case ygl::graphic::flip::FLIP_NONE:
			{
				glBegin(GL_QUADS);

				glVertex3f(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
				glVertex3f(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
				glVertex3f(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
				glVertex3f(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());

				glEnd();

				break;
			}
			case ygl::graphic::flip::FLIP_HORIZONTAL:
			{
				glBegin(GL_QUADS);

				glVertex3f(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
				glVertex3f(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
				glVertex3f(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
				glVertex3f(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());

				glEnd();

				break;
			}
			case ygl::graphic::flip::FLIP_VERTICAL:
			{
				glBegin(GL_QUADS);

				glVertex3f(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
				glVertex3f(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
				glVertex3f(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
				glVertex3f(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());

				glEnd();

				break;
			}
			case ygl::graphic::flip::FLIP_ALL:
			{
				glBegin(GL_QUADS);

				glVertex3f(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
				glVertex3f(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
				glVertex3f(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
				glVertex3f(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());

				glEnd();

				break;
			}
		}

		glDisable(GL_BLEND);
//		glDisable(GL_TEXTURE_2D);

		if (this->_wireframe)
		{
			glEnable(GL_LINE_STIPPLE);

			glTranslatef(this->_position.x(), this->_position.y(), this->_position.z());

			glRotatef(this->_rotate.h(), 1.0, 0.0, 0.0);
			glRotatef(this->_rotate.p(), 0.0, 1.0, 0.0);
			glRotatef(this->_rotate.b(), 0.0, 0.0, 1.0);

			glScalef(this->_scale.w(), this->_scale.h(), this->_scale.l());

			glColor4f(0.0, 1.0, 0.0, 1.0);

			glLineWidth(2.0);
			glBegin(GL_LINE_LOOP);
			glVertex3f(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
			glVertex3f(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
			glVertex3f(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
			glVertex3f(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
			glEnd();

			glColor4f(0.0, 0.0, 1.0, 1.0);
			glLineWidth(2.0);
			glBegin(GL_LINES);
			glVertex3f(-10.0, 0.0, 0.0);
			glVertex3f( 10.0, 0.0, 0.0);
			glEnd();

			glColor4f(1.0, 0.0, 0.0, 1.0);
			glLineWidth(2.0);
			glBegin(GL_LINES);
			glVertex3f(0.0, -10.0, 0.0);
			glVertex3f(0.0,  10.0, 0.0);
			glEnd();

			glDisable(GL_LINE_STIPPLE);
		}

		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();
	}
}

void ygl::graphic::shape::draw(const ygl::math::pointd& position, const ygl::math::rotated& rotate, const ygl::math::sized& scale, const ygl::math::colord& color)
{
	if (this->_position != position && position != ygl::math::pointd().is_null())
	{
		this->position(position);
	}

	if (this->_rotate != rotate && rotate != ygl::math::rotated().is_null())
	{
		this->rotate(rotate);
	}

	if (this->_scale != scale && scale != ygl::math::sized().is_null())
	{
		this->scale(scale);
	}

	if (this->_color != color && color != ygl::math::colord().is_null())
	{
		this->color(color);
	}

	this->draw();
}

void ygl::graphic::shape::running()
{
	if (!this->_running)
	{
		return;
	}

	if (this->_tweening.empty())
	{
		return;
	}

	if (!this->_tweening[this->_animation]->has_tweening())
	{
		return;
	}

	if (this->_tweening[this->_animation]->has_visible())
	{
		this->visible(this->_tweening[this->_animation]->visible());
	}

	if (this->_tweening[this->_animation]->has_wireframe())
	{
		this->wireframe(this->_tweening[this->_animation]->wireframe());
	}

	if (this->_tweening[this->_animation]->has_flip())
	{
		this->flip(this->_tweening[this->_animation]->flip());
	}

	if (this->_tweening[this->_animation]->has_color())
	{
		this->color(this->_tweening[this->_animation]->color());
	}

	if (this->_tweening[this->_animation]->has_opacity())
	{
		this->opacity(this->_tweening[this->_animation]->opacity());
	}

	if (this->_tweening[this->_animation]->has_orientation())
	{
		this->orientation(this->_tweening[this->_animation]->orientation());
	}

	if (this->_tweening[this->_animation]->has_pivot())
	{
		this->pivot(this->_tweening[this->_animation]->pivot());
	}

	if (this->_tweening[this->_animation]->has_position())
	{
		this->position(this->_tweening[this->_animation]->position());
	}

	if (this->_tweening[this->_animation]->has_scale())
	{
		this->scale(this->_tweening[this->_animation]->scale());
	}

	if (this->_tweening[this->_animation]->has_rotate())
	{
		this->rotate(this->_tweening[this->_animation]->rotate());
	}

	this->_tweening[this->_animation]->running();
}

void ygl::graphic::shape::start()
{
	if (!this->_animation.empty())
	{
		if (this->_tweening[this->_animation]->has_tweening())
		{
			this->_tweening[this->_animation]->start();
			this->_running = true;
		}
	}
}

void ygl::graphic::shape::pause()
{
	if (!this->_animation.empty())
	{
		if (this->_tweening[this->_animation]->has_tweening())
		{
			this->_tweening[this->_animation]->pause();
			this->_running = false;
		}
	}
}

void ygl::graphic::shape::restart()
{
	if (!this->_animation.empty())
	{
		if (this->_tweening[this->_animation]->has_tweening())
		{
			this->_tweening[this->_animation]->restart();
			this->_running = true;
		}
	}
}

void ygl::graphic::shape::reset()
{
	if (!this->_animation.empty())
	{
		if (this->_tweening[this->_animation]->has_tweening())
		{
			this->_tweening[this->_animation]->reset();
			this->_running = false;
		}
	}
}

bool ygl::graphic::shape::started()
{
	if (!this->_animation.empty())
	{
		if (this->_tweening[this->_animation]->has_tweening())
		{
			return this->_tweening[this->_animation]->started() && this->_running;
		}
	}
	return false;
}

bool ygl::graphic::shape::border()
{
	if (!this->_animation.empty())
	{
		if (this->_tweening[this->_animation]->has_tweening())
		{
			return this->_tweening[this->_animation]->border();
		}
	}
	return false;
}

bool ygl::graphic::shape::onset()
{
	if (!this->_animation.empty())
	{
		if (this->_tweening[this->_animation]->has_tweening())
		{
			return this->_tweening[this->_animation]->onset();
		}
	}
	return false;
}

void ygl::graphic::shape::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::graphic::shape::wireframe(bool wireframe)
{
	this->_wireframe = wireframe;
}

void ygl::graphic::shape::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::graphic::shape::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::graphic::shape::color(double r, double g, double b)
{
	this->_color.fill(r, g, b);
}

void ygl::graphic::shape::color_r(double r)
{
	this->_color.r(r);
}

void ygl::graphic::shape::color_g(double g)
{
	this->_color.g(g);
}

void ygl::graphic::shape::color_b(double b)
{
	this->_color.b(b);
}

void ygl::graphic::shape::opacity(double opacity)
{
	this->_opacity = ygl::math::clamp(opacity, 0.0, 100.0);
}

void ygl::graphic::shape::orientation(const ygl::graphic::orientation& orientation)
{
	this->_orientation = orientation;
}

void ygl::graphic::shape::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
}

void ygl::graphic::shape::pivot(double x, double y, double l)
{
	this->_pivot.fill(x, y, l);
}

void ygl::graphic::shape::pivot_x(double x)
{
	this->_pivot.x(x);
}

void ygl::graphic::shape::pivot_y(double y)
{
	this->_pivot.y(y);
}

void ygl::graphic::shape::pivot_z(double z)
{
	this->_pivot.z(z);
}

void ygl::graphic::shape::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::graphic::shape::position(double x, double y, double l)
{
	this->_position.fill(x, y, l);
}

void ygl::graphic::shape::position_x(double x)
{
	this->_position.x(x);
}

void ygl::graphic::shape::position_y(double y)
{
	this->_position.y(y);
}

void ygl::graphic::shape::position_z(double z)
{
	this->_position.z(z);
}

void ygl::graphic::shape::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::graphic::shape::scale(double w, double h, double l)
{
	this->_scale.fill(w, h, l);
}

void ygl::graphic::shape::scale_w(double w)
{
	this->_scale.w(w);
}

void ygl::graphic::shape::scale_h(double h)
{
	this->_scale.h(h);
}

void ygl::graphic::shape::scale_l(double l)
{
	this->_scale.l(l);
}

void ygl::graphic::shape::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::graphic::shape::rotate(double h, double p, double b)
{
	this->_rotate.fill(h, p, b);
}

void ygl::graphic::shape::rotate_h(double h)
{
	this->_rotate.h(h);
}

void ygl::graphic::shape::rotate_p(double p)
{
	this->_rotate.p(p);
}

void ygl::graphic::shape::rotate_b(double b)
{
	this->_rotate.b(b);
}

bool ygl::graphic::shape::visible() const
{
	return this->_visible;
}

bool ygl::graphic::shape::wireframe() const
{
	return this->_wireframe;
}

const ygl::graphic::flip& ygl::graphic::shape::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::graphic::shape::color() const
{
	return this->_color;
}

double ygl::graphic::shape::opacity() const
{
	return this->_opacity;
}

const ygl::graphic::orientation& ygl::graphic::shape::orientation() const
{
	return this->_orientation;
}

const ygl::math::pointd& ygl::graphic::shape::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::graphic::shape::position() const
{
	return this->_position;
}

const ygl::math::sized& ygl::graphic::shape::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::graphic::shape::rotate() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::graphic::shape::size() const
{
	return this->_size;
}

void ygl::graphic::shape::resolve()
{
	double x = ygl::math::invert(this->_size.w() * this->_pivot.x());
	double y = ygl::math::invert(this->_size.h() * this->_pivot.y());
	double w = x + this->_size.w();
	double h = y + this->_size.h();

	this->_vertex.a(x, y, 0.0);
	this->_vertex.b(w, y, 0.0);
	this->_vertex.c(w, h, 0.0);
	this->_vertex.d(x, h, 0.0);
}
