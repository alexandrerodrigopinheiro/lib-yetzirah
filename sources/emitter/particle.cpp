#include "emitter/particle.h"

ygl::emitter::particle::particle() :
	_running(false),
	_data(0),
	_life(0),
	_born(0),
	_timeline(0),
	_gravity(0.0),
	_wind(0.0),
	_friction(0.0),
	_random_color(false),
	_visible(true),
	_wireframe(false),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100.0),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_velocity(ygl::math::pointd()),
	_velocity_memory(ygl::math::pointd()),
	_position(ygl::math::pointd()),
	_displacement(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_map(ygl::math::uvmapd(1.0)),
	_tween(NULL)
{
}

ygl::emitter::particle::particle(const ygl::emitter::particle& obj) :
	_running(false),
	_data(0),
	_life(0),
	_born(0),
	_timeline(0),
	_gravity(0.0),
	_wind(0.0),
	_friction(0.0),
	_random_color(false),
	_visible(true),
	_wireframe(false),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100.0),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_velocity(ygl::math::pointd()),
	_velocity_memory(ygl::math::pointd()),
	_position(ygl::math::pointd()),
	_displacement(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_map(ygl::math::uvmapd(1.0)),
	_tween(NULL)
{
	*this = obj;
}

ygl::emitter::particle::particle(const ygl::math::sized& size, const ygl::math::colord& color) :
	_running(false),
	_data(0),
	_life(0),
	_born(0),
	_timeline(0),
	_gravity(0.0),
	_wind(0.0),
	_friction(0.0),
	_random_color(false),
	_visible(true),
	_wireframe(false),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100.0),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_velocity(ygl::math::pointd()),
	_velocity_memory(ygl::math::pointd()),
	_position(ygl::math::pointd()),
	_displacement(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_map(ygl::math::uvmapd(1.0)),
	_tween(NULL)
{
	this->initialize(size, color);
}

ygl::emitter::particle::~particle()
{
	this->destroy();
}

bool ygl::emitter::particle::initialize(std::size_t data, const ygl::math::sized& size, const ygl::math::colord& color)
{
	this->_data  = data;
	this->_size  = size;
	this->_color = color;
	this->_map   = ygl::math::uvmapd(1.0, 1.0);

	this->resolve();

	return true;
}

bool ygl::emitter::particle::initialize(const ygl::math::sized& size, const ygl::math::colord& color)
{
	this->_size  = size;
	this->_color = color;
	this->_map   = ygl::math::uvmapd(1.0, 1.0);

	this->resolve();

	return true;
}

void ygl::emitter::particle::destroy()
{
	glDeleteTextures(1, &this->_data);

	delete this->_tween;
	this->_tween = NULL;
}

void ygl::emitter::particle::draw()
{
	if (this->_visible && this->_opacity != 0)
	{
		this->resolve();

		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glBindTexture(GL_TEXTURE_2D, this->_data);

		glTranslated(this->_position.x() + this->_displacement.x(), this->_position.y() + this->_displacement.y(), this->_position.z() + ygl::math::invert(this->_displacement.z()));

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

		switch (this->_flip)
		{
			case ygl::graphic::flip::FLIP_NONE:
			{
				glBegin(GL_QUADS);

				glTexCoord2d(this->_offset.x(), this->_offset.y()); glVertex3d(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
				glTexCoord2d(this->_offset.w(), this->_offset.y()); glVertex3d(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
				glTexCoord2d(this->_offset.w(), this->_offset.h()); glVertex3d(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
				glTexCoord2d(this->_offset.x(), this->_offset.h()); glVertex3d(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());

				glEnd();

				break;
			}
			case ygl::graphic::flip::FLIP_HORIZONTAL:
			{
				glBegin(GL_QUADS);

				glTexCoord2d(this->_offset.x(), this->_offset.y()); glVertex3d(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
				glTexCoord2d(this->_offset.w(), this->_offset.y()); glVertex3d(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
				glTexCoord2d(this->_offset.w(), this->_offset.h()); glVertex3d(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
				glTexCoord2d(this->_offset.x(), this->_offset.h()); glVertex3d(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());

				glEnd();

				break;
			}
			case ygl::graphic::flip::FLIP_VERTICAL:
			{
				glBegin(GL_QUADS);

				glTexCoord2d(this->_offset.x(), this->_offset.y()); glVertex3d(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
				glTexCoord2d(this->_offset.w(), this->_offset.y()); glVertex3d(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
				glTexCoord2d(this->_offset.w(), this->_offset.h()); glVertex3d(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
				glTexCoord2d(this->_offset.x(), this->_offset.h()); glVertex3d(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());

				glEnd();

				break;
			}
			case ygl::graphic::flip::FLIP_ALL:
			{
				glBegin(GL_QUADS);

				glTexCoord2d(this->_offset.x(), this->_offset.y()); glVertex3d(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
				glTexCoord2d(this->_offset.w(), this->_offset.y()); glVertex3d(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
				glTexCoord2d(this->_offset.w(), this->_offset.h()); glVertex3d(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
				glTexCoord2d(this->_offset.x(), this->_offset.h()); glVertex3d(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());

				glEnd();

				break;
			}
		}

		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_COLOR_MATERIAL);

		if (this->_wireframe)
		{
			glEnable(GL_LINE_STIPPLE);

			glColor4d(0.0, 1.0, 0.0, 1.0);

			glLineWidth(2.0);
			glBegin(GL_LINE_LOOP);
			glVertex3d(this->_vertex.a().x(), this->_vertex.a().y(), 0.0);
			glVertex3d(this->_vertex.b().x(), this->_vertex.b().y(), 0.0);
			glVertex3d(this->_vertex.c().x(), this->_vertex.c().y(), 0.0);
			glVertex3d(this->_vertex.d().x(), this->_vertex.d().y(), 0.0);
			glEnd();

			glColor4d(0.0, 0.0, 1.0, 1.0);
			glLineWidth(2.0);
			glBegin(GL_LINES);
			glVertex3d(-10.0, 0.0, 0.0);
			glVertex3d( 10.0, 0.0, 0.0);
			glEnd();

			glColor4d(1.0, 0.0, 0.0, 1.0);
			glLineWidth(2.0);
			glBegin(GL_LINES);
			glVertex3d(0.0, -10.0, 0.0);
			glVertex3d(0.0,  10.0, 0.0);
			glEnd();

			glDisable(GL_LINE_STIPPLE);
		}

		glPopMatrix();
	}
}

void ygl::emitter::particle::draw(const ygl::math::pointd& position, const ygl::math::colord& color)
{
	if (this->_position != position && !position.is_null())
	{
		this->_position = position;
	}

	if (this->_color != color && !color.is_null() && !this->_random_color)
	{
		this->_color = color;
	}

	this->draw();
}

bool ygl::emitter::particle::animation(std::size_t born, std::size_t life)
{
	this->_born     = born;
	this->_life     = life < 3 ? life + 3 : life;
	this->_timeline = this->_born + this->_life;
	this->_tween = new ygl::animation::tween();

	if (!this->_tween->initialize(this->_timeline))
	{
		return false;
	}

	if (this->_born > 0)
	{
		this->_tween->attach_visible(              0, false);
		this->_tween->attach_visible(this->_born    , true);
		this->_tween->attach_visible(this->_timeline, true);
	}
	else
	{
		this->_tween->attach_visible(              0, true);
		this->_tween->attach_visible(this->_timeline, true);
	}

	this->_tween->start();
	this->_tween->control(ygl::animation::control::CONTROL_SINGLE);

	return true;
}

void ygl::emitter::particle::running()
{
	if (!this->_running)
	{
		return;
	}

	if (this->_tween == NULL)
	{
		return;
	}

	if (!this->_tween->has_tweening())
	{
		return;
	}

	if (this->_tween->has_visible())
	{
		this->visible(this->_tween->visible());
	}

	if (this->_tween->has_opacity())
	{
		this->opacity(this->_tween->opacity());
	}

	if (this->_tween->has_scale())
	{
		this->scale(this->_tween->scale());
	}

	if (this->_tween->has_rotate())
	{
		this->rotate(this->_tween->rotate());
	}

	if (this->_tween->moment() >= this->_born)
	{
		if (this->_velocity.x() > 0)
		{
			this->_velocity.x(this->_velocity.x() - this->_friction);
		}

		if (this->_velocity.x() < 0)
		{
			this->_velocity.x(this->_velocity.x() + this->_friction);
		}

		if (this->_velocity.y() > 0)
		{
			this->_velocity.y(this->_velocity.y() - this->_friction);
		}

		if (this->_velocity.y() < 0)
		{
			this->_velocity.y(this->_velocity.y() + this->_friction);
		}

		this->_velocity.x(this->_velocity.x() + this->_wind);
		this->_velocity.y(this->_velocity.y() + this->_gravity);

		this->_displacement.x(this->_displacement.x() + this->_velocity.x());
		this->_displacement.y(this->_displacement.y() + this->_velocity.y());
	}

	this->_tween->running();
}

void ygl::emitter::particle::start()
{
	this->_tween->start();
	this->_running = true;
}

void ygl::emitter::particle::pause()
{
	this->_tween->pause();
	this->_running = false;
}

void ygl::emitter::particle::restart(const ygl::math::pointd& position)
{
	this->_tween->restart();
	this->_running      = true;
	this->_position     = position;
	this->_velocity     = this->_velocity_memory;
	this->_displacement = ygl::math::pointd(0.0);
}

void ygl::emitter::particle::reset(const ygl::math::pointd& position)
{
	this->_tween->reset();
	this->_running      = false;
	this->_position     = position;
	this->_velocity     = this->_velocity_memory;
	this->_displacement = ygl::math::pointd(0.0);
}

bool ygl::emitter::particle::started()
{
	return this->_tween->started() && this->_running;
}

bool ygl::emitter::particle::is_born()
{
	return this->_visible;
}

bool ygl::emitter::particle::is_life()
{
	return !this->_tween->border();
}

bool ygl::emitter::particle::bound()
{
	return this->_tween->border();
}

bool ygl::emitter::particle::onset()
{
	return this->_tween->onset();
}

void ygl::emitter::particle::easy_opacity(const ygl::emitter::opacity& opacity)
{
	std::size_t m_vmin = 0;
	std::size_t m_born = this->_born;
	std::size_t m_half = this->_born + (this->_life / 2);
	std::size_t m_vmax = this->_timeline;

	this->_tween->clear_opacity();

	switch (opacity)
	{
		case ygl::emitter::opacity::OPACITY_NONE: break;
		case ygl::emitter::opacity::OPACITY_IN:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_opacity(m_vmin,   0.0);
				this->_tween->attach_opacity(m_born,   0.0);
				this->_tween->attach_opacity(m_vmax, 100.0);
			}
			else
			{
				this->_tween->attach_opacity(m_vmin,   0.0);
				this->_tween->attach_opacity(m_vmax, 100.0);
			}
			break;
		}
		case ygl::emitter::opacity::OPACITY_OUT:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_opacity(m_vmin, 100.0);
				this->_tween->attach_opacity(m_born, 100.0);
				this->_tween->attach_opacity(m_vmax,   0.0);
			}
			else
			{
				this->_tween->attach_opacity(m_vmin, 100.0);
				this->_tween->attach_opacity(m_vmax,   0.0);
			}
			break;
		}
		case ygl::emitter::opacity::OPACITY_IN_OUT:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_opacity(m_vmin,   0.0);
				this->_tween->attach_opacity(m_born,   0.0);
				this->_tween->attach_opacity(m_half, 100.0);
				this->_tween->attach_opacity(m_vmax,   0.0);
			}
			else
			{
				this->_tween->attach_opacity(m_vmin,   0.0);
				this->_tween->attach_opacity(m_half, 100.0);
				this->_tween->attach_opacity(m_vmax,   0.0);
			}
			break;
		}
		case ygl::emitter::opacity::OPACITY_OUT_IN:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_opacity(m_vmin, 100.0);
				this->_tween->attach_opacity(m_born, 100.0);
				this->_tween->attach_opacity(m_half,   0.0);
				this->_tween->attach_opacity(m_vmax, 100.0);
			}
			else
			{
				this->_tween->attach_opacity(m_vmin, 100.0);
				this->_tween->attach_opacity(m_half,   0.0);
				this->_tween->attach_opacity(m_vmax, 100.0);
			}
			break;
		}
	}
}

void ygl::emitter::particle::easy_scale(const ygl::emitter::scale& scale)
{
	std::size_t m_vmin = 0;
	std::size_t m_born = this->_born;
	std::size_t m_half = this->_born + (this->_life / 2);
	std::size_t m_vmax = this->_timeline;

	this->_tween->clear_scale();

	switch (scale)
	{
		case ygl::emitter::scale::SCALE_NONE: break;
		case ygl::emitter::scale::SCALE_IN:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_born, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(1.0));
			}
			else
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(1.0));
			}
			break;
		}
		case ygl::emitter::scale::SCALE_OUT:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_born, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(0.0));
			}
			else
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(0.0));
			}
			break;
		}
		case ygl::emitter::scale::SCALE_IN_OUT:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_born, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_half, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(0.0));
			}
			else
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_half, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(0.0));
			}
			break;
		}
		case ygl::emitter::scale::SCALE_OUT_IN:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_born, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_half, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(1.0));
			}
			else
			{
				this->_tween->attach_scale(m_vmin, ygl::math::sized(1.0));
				this->_tween->attach_scale(m_half, ygl::math::sized(0.0));
				this->_tween->attach_scale(m_vmax, ygl::math::sized(1.0));
			}
			break;
		}
	}
}

void ygl::emitter::particle::easy_rotate(const ygl::emitter::rotate& rotate)
{
	std::size_t m_vmin = 0;
	std::size_t m_born = this->_born;
	std::size_t m_half = this->_born + (this->_life / 2);
	std::size_t m_vmax = this->_timeline;

	this->_tween->clear_rotate();

	switch (rotate)
	{
		case ygl::emitter::rotate::ROTATE_NONE: break;
		case ygl::emitter::rotate::ROTATE_IN:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_born, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(360.0));
			}
			else
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(360.0));
			}
			break;
		}
		case ygl::emitter::rotate::ROTATE_OUT:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_born, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(  0.0));
			}
			else
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(  0.0));
			}
			break;
		}
		case ygl::emitter::rotate::ROTATE_IN_OUT:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_born, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_half, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(360.0));
			}
			else
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_half, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(360.0));
			}
			break;
		}
		case ygl::emitter::rotate::ROTATE_OUT_IN:
		{
			if (this->_born != 0)
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_born, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_half, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(  0.0));
			}
			else
			{
				this->_tween->attach_rotate(m_vmin, ygl::math::rotated(  0.0));
				this->_tween->attach_rotate(m_half, ygl::math::rotated(360.0));
				this->_tween->attach_rotate(m_vmax, ygl::math::rotated(  0.0));
			}
			break;
		}
	}
}

void ygl::emitter::particle::random_color(bool random)
{
	this->_random_color = random;
}

void ygl::emitter::particle::gravity(double gravity)
{
	this->_gravity = gravity;
}

void ygl::emitter::particle::wind(double wind)
{
	this->_wind = wind;
}

void ygl::emitter::particle::friction(double friction)
{
	this->_friction = friction;
}

void ygl::emitter::particle::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::emitter::particle::wireframe(bool wireframe)
{
	this->_wireframe = wireframe;
}

void ygl::emitter::particle::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::emitter::particle::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::emitter::particle::color(double r, double g, double b)
{
	this->_color.fill(r, g, b);
}

void ygl::emitter::particle::color_r(double r)
{
	this->_color.r(r);
}

void ygl::emitter::particle::color_g(double g)
{
	this->_color.g(g);
}

void ygl::emitter::particle::color_b(double b)
{
	this->_color.b(b);
}

void ygl::emitter::particle::opacity(double opacity)
{
	this->_opacity = ygl::math::clamp(opacity, 0.0, 100.0);
}

void ygl::emitter::particle::orientation(const ygl::graphic::orientation& orientation)
{
	this->_orientation = orientation;
}

void ygl::emitter::particle::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
}

void ygl::emitter::particle::pivot(double x, double y, double z)
{
	this->_pivot.fill(x, y, z);
}

void ygl::emitter::particle::pivot_x(double x)
{
	this->_pivot.x(x);
}

void ygl::emitter::particle::pivot_y(double y)
{
	this->_pivot.y(y);
}

void ygl::emitter::particle::pivot_z(double z)
{
	this->_pivot.z(z);
}

void ygl::emitter::particle::velocity(const ygl::math::pointd& velocity)
{
	this->_velocity         = velocity;
	this->_velocity_memory  = velocity;
}

void ygl::emitter::particle::velocity(double x, double y, double z)
{
	this->_velocity.fill(x, y, z);
}

void ygl::emitter::particle::velocity_x(double x)
{
	this->_velocity.x(x);
}

void ygl::emitter::particle::velocity_y(double y)
{
	this->_velocity.y(y);
}

void ygl::emitter::particle::velocity_z(double z)
{
	this->_velocity.z(z);
}

void ygl::emitter::particle::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::emitter::particle::position(double x, double y, double z)
{
	this->_position.fill(x, y, z);
}

void ygl::emitter::particle::position_x(double x)
{
	this->_position.x(x);
}

void ygl::emitter::particle::position_y(double y)
{
	this->_position.y(y);
}

void ygl::emitter::particle::position_z(double z)
{
	this->_position.z(z);
}

void ygl::emitter::particle::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::emitter::particle::scale(double w, double h, double l)
{
	this->_scale.fill(w, h, l);
}

void ygl::emitter::particle::scale_w(double w)
{
	this->_scale.w(w);
}

void ygl::emitter::particle::scale_h(double h)
{
	this->_scale.h(h);
}

void ygl::emitter::particle::scale_l(double l)
{
	this->_scale.l(l);
}

void ygl::emitter::particle::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::emitter::particle::rotate(double h, double p, double b)
{
	this->_rotate.fill(h, p, b);
}

void ygl::emitter::particle::rotate_h(double h)
{
	this->_rotate.h(h);
}

void ygl::emitter::particle::rotate_p(double p)
{
	this->_rotate.p(p);
}

void ygl::emitter::particle::rotate_b(double b)
{
	this->_rotate.b(b);
}

std::size_t ygl::emitter::particle::life() const
{
	return this->_life;
}

std::size_t ygl::emitter::particle::born() const
{
	return this->_born;
}

std::size_t ygl::emitter::particle::timeline() const
{
	return this->_timeline;
}

bool ygl::emitter::particle::random_color() const
{
	return this->_random_color;
}

double ygl::emitter::particle::gravity() const
{
	return this->_gravity;
}

double ygl::emitter::particle::wind() const
{
	return this->_wind;
}

double ygl::emitter::particle::friction() const
{
	return this->_friction;
}

bool ygl::emitter::particle::visible() const
{
	return this->_visible;
}

bool ygl::emitter::particle::wireframe() const
{
	return this->_wireframe;
}

const ygl::graphic::flip& ygl::emitter::particle::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::emitter::particle::color() const
{
	return this->_color;
}

double ygl::emitter::particle::opacity() const
{
	return this->_opacity;
}

const ygl::graphic::orientation& ygl::emitter::particle::orientation() const
{
	return this->_orientation;
}

const ygl::math::pointd& ygl::emitter::particle::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::emitter::particle::position() const
{
	return this->_position;
}

const ygl::math::pointd& ygl::emitter::particle::velocity() const
{
	return this->_velocity;
}

const ygl::math::sized& ygl::emitter::particle::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::emitter::particle::rotate() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::emitter::particle::size() const
{
	return this->_size;
}

void ygl::emitter::particle::resolve()
{
	double x = ygl::math::invert(this->_size.w() * this->_pivot.x());
	double y = ygl::math::invert(this->_size.h() * this->_pivot.y());
	double z = ygl::math::invert(this->_size.l() * this->_pivot.z());
	double w = x + this->_size.w();
	double h = y + this->_size.h();

	this->_offset.x(0.f);
	this->_offset.y(0.f);
	this->_offset.w(this->_map.u());
	this->_offset.h(this->_map.v());

	this->_vertex.a(x, y, z);
	this->_vertex.b(w, y, z);
	this->_vertex.c(w, h, z);
	this->_vertex.d(x, h, z);
}
