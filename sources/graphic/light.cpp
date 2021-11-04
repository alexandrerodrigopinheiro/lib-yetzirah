#include "graphic/light.h"

ygl::graphic::light::light() :
	_visible(true),
	_shadow(false),
	_color(ygl::math::colord().WHITE()),
	_intensity(100.0),
	_radius(1.0),
	_position(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_scale(ygl::math::sized(1.0)),
	_depth(0),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
}

ygl::graphic::light::light(const light& obj) :
	_visible(true),
	_shadow(false),
	_color(ygl::math::colord().WHITE()),
	_intensity(100.0),
	_radius(1.0),
	_position(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_scale(ygl::math::sized(1.0)),
	_depth(0),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
	*this = obj;
}

ygl::graphic::light::light(const ygl::math::pointd& position, double radius, const ygl::math::colord& color, double intensity, bool shadow, bool visible) :
	_visible(true),
	_shadow(false),
	_color(ygl::math::colord().WHITE()),
	_intensity(100.0),
	_radius(1.0),
	_position(ygl::math::pointd()),
	_rotate(ygl::math::rotated()),
	_scale(ygl::math::sized(1.0)),
	_depth(0),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
	this->initialize(position, radius, color, intensity, shadow, visible);
}

ygl::graphic::light::~light()
{
	this->destroy();
}

bool ygl::graphic::light::initialize(const ygl::math::pointd& position, double radius, const ygl::math::colord& color, double intensity, bool shadow, bool visible)
{
	this->_position = position;
	this->_radius = radius;
	this->_color = color;
	this->_intensity = intensity;
	this->_shadow = shadow;
	this->_visible = visible;

	/* Enable Lighting */
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glEnable(GL_LIGHT2);
//	glEnable(GL_LIGHT3);
//	glEnable(GL_LIGHT4);
//	glEnable(GL_LIGHT5);
//	glEnable(GL_LIGHT6);
//	glEnable(GL_LIGHT7);

	return true;
}

void ygl::graphic::light::destroy()
{
}

ygl::animation::tween* ygl::graphic::light::tweening(const std::string& animation)
{
	auto it = this->_tweening.find(animation);
	if (it == this->_tweening.end())
	{
		std::cerr << "Text animation '" << animation << "' not found, failed" << std::endl;
		exit(0);
	}
	return this->_tweening[animation];
}

bool ygl::graphic::light::animation(const std::string& animation, std::size_t timeline)
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

bool ygl::graphic::light::animation(const std::string& animation, std::size_t timeline, std::size_t fps)
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

void ygl::graphic::light::animation(const std::string& animation)
{
	auto it = this->_tweening.find(animation);

	if (it == this->_tweening.end())
	{
		std::cerr << "Image animation '" << animation << "' not found, failed" << std::endl;

		exit(0);
	}

	this->_animation = animation;
}

bool ygl::graphic::light::sensible(const std::string& name, const ygl::math::surfaced& sensible)
{
	auto it = this->_sensible.find(name);

	if (it != this->_sensible.end())
	{
		return false;
	}

	this->_sensible.insert(std::pair<std::string, ygl::math::surfaced>(name, sensible));

	return true;
}

const ygl::math::surfaced& ygl::graphic::light::sensible(const std::string& name)
{
	auto it = this->_sensible.find(name);

	if (it == this->_sensible.end())
	{
		std::cerr << "Layer sensible not found" << std::endl;
		exit(1);
	}

	return this->_sensible[name];
}

void ygl::graphic::light::draw()
{
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glBegin(GL_TRIANGLE_FAN);

	glColor4f(this->_color.r(), this->_color.g(), this->_color.b(), this->_intensity);

	glVertex2f(this->_position.x(), this->_position.y());

	glColor4f(this->_color.r(), this->_color.g(), this->_color.b(), 0.0f);

	for (std::size_t i = 0; i <= 10; i++)
	{
		double angle = i * 2 * ygl::math::PI / 10;
		glVertex2f(this->_position.x() + (std::cos(angle) * this->_radius), this->_position.y() + (std::sin(angle) * this->_radius));
	}

	glEnd();

	if (this->_shadow)
	{
//			for(std::size_t i = 0; i < scene->polygons.size(); i++)
//			{
//				std::vector<m_Edge*> away = scene->polygons[i]->getNotFacingEdges(pos);
//
//				glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
//
//				glBegin(GL_QUADS);
//
//				for(std::size_t j =0; j < away.size(); j++)
//				{
//					vector2f towards = away[j]->p1 - pos;
//					towards.normalize();
//					towards *= 1000;
//					glVertex2f(away[j]->p1.x + towards.x, away[j]->p1.y + towards.y);
//					glVertex2f(away[j]->p1.x, away[j]->p1.y);
//
//					towards = away[j]->p2 - pos;
//					towards.normalize();
//					towards *= 1000;
//					glVertex2f(away[j]->p2.x, away[j]->p2.y);
//					glVertex2f(away[j]->p2.x + towards.x, away[j]->p2.y + towards.y);
//				}
//
//				glEnd();
//			}
	}

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
}

void ygl::graphic::light::running()
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

//	if (this->_tweening[this->_animation]->has_wireframe())
//	{
//		this->wireframe(this->_tweening[this->_animation]->wireframe());
//	}
//
//	if (this->_tweening[this->_animation]->has_flip())
//	{
//		this->flip(this->_tweening[this->_animation]->flip());
//	}
//
//	if (this->_tweening[this->_animation]->has_color())
//	{
//		this->color(this->_tweening[this->_animation]->color());
//	}
//
//	if (this->_tweening[this->_animation]->has_opacity())
//	{
//		this->opacity(this->_tweening[this->_animation]->opacity());
//	}
//
//	if (this->_tweening[this->_animation]->has_orientation())
//	{
//		this->orientation(this->_tweening[this->_animation]->orientation());
//	}
//
//	if (this->_tweening[this->_animation]->has_pivot())
//	{
//		this->pivot(this->_tweening[this->_animation]->pivot());
//	}
//
//	if (this->_tweening[this->_animation]->has_position())
//	{
//		this->position(this->_tweening[this->_animation]->position());
//	}
//
//	if (this->_tweening[this->_animation]->has_scale())
//	{
//		this->scale(this->_tweening[this->_animation]->scale());
//	}
//
//	if (this->_tweening[this->_animation]->has_rotate())
//	{
//		this->rotate(this->_tweening[this->_animation]->rotate());
//	}

	this->_tweening[this->_animation]->running();
}

void ygl::graphic::light::start()
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

void ygl::graphic::light::pause()
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

void ygl::graphic::light::restart()
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

void ygl::graphic::light::reset()
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

bool ygl::graphic::light::started()
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

bool ygl::graphic::light::border()
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

bool ygl::graphic::light::onset()
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

void ygl::graphic::light::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::graphic::light::shadow(bool shadow)
{
	this->_shadow = shadow;
}

void ygl::graphic::light::intensity(double intensity)
{
	this->_intensity = ygl::math::clamp(intensity, 0.0, 100.0);
}

void ygl::graphic::light::radius(double radius)
{
	this->_radius = radius;
}

void ygl::graphic::light::depth(std::size_t depth)
{
	this->_depth = depth;
}

bool ygl::graphic::light::visible() const
{
	return this->_visible;
}

bool ygl::graphic::light::shadow() const
{
	return this->_shadow;
}

double ygl::graphic::light::intensity() const
{
	return this->_intensity;
}

double ygl::graphic::light::radius() const
{
	return this->_radius;
}

const ygl::math::colord& ygl::graphic::light::color()
{
	return this->_color;
}

const ygl::math::pointd& ygl::graphic::light::position()
{
	return this->_position;
}

const ygl::math::rotated& ygl::graphic::light::rotate()
{
	return this->_rotate;
}

const ygl::math::sized& ygl::graphic::light::scale()
{
	return this->_scale;
}

std::size_t ygl::graphic::light::depth() const
{
	return this->_depth;
}
