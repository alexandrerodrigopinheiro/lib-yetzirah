#include "emitter/launcher.h"

ygl::emitter::launcher::launcher() :
	_data(0),
	_regeneration(-1),
	_murdered(0),
	_filename(std::string()),
	_running(true),
	_visible(true),
	_life(0),
	_amount(0),
	_color(ygl::math::colord().WHITE()),
	_position(ygl::math::pointd()),
	_area(ygl::math::sized()),
	_size(ygl::math::sized()),
	_velocity(0.0),
	_gravity(0.0),
	_wind(0.0),
	_friction(0.0),
	_easy_opacity(ygl::emitter::opacity::OPACITY_NONE),
	_easy_scale(ygl::emitter::scale::SCALE_NONE),
	_easy_rotate(ygl::emitter::rotate::ROTATE_NONE),
	_particle(),
	_generator()
{
}

ygl::emitter::launcher::launcher(const launcher& obj) :
	_data(0),
	_regeneration(-1),
	_murdered(0),
	_filename(std::string()),
	_running(true),
	_visible(true),
	_life(0),
	_amount(0),
	_color(ygl::math::colord().WHITE()),
	_position(ygl::math::pointd()),
	_area(ygl::math::sized()),
	_size(ygl::math::sized()),
	_velocity(0.0),
	_gravity(0.0),
	_wind(0.0),
	_friction(0.0),
	_easy_opacity(ygl::emitter::opacity::OPACITY_NONE),
	_easy_scale(ygl::emitter::scale::SCALE_NONE),
	_easy_rotate(ygl::emitter::rotate::ROTATE_NONE),
	_particle(),
	_generator()
{
	*this = obj;
}

ygl::emitter::launcher::~launcher()
{
	this->destroy();
}

bool ygl::emitter::launcher::initialize(const ygl::math::sized& area)
{
	this->_area = area;

	return true;
}

bool ygl::emitter::launcher::initialize(const std::string& filename, const ygl::math::sized& area)
{
	this->_filename = filename;
	this->_area     = area;

	if (!this->load(filename))
	{
		return false;
	}

	return true;
}

void ygl::emitter::launcher::destroy()
{
	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		delete this->_particle[i];
		this->_particle[i] = NULL;
	}
}

bool ygl::emitter::launcher::generator(const ygl::math::sized& size, double velocity, std::size_t life, std::size_t amount)
{
	this->_velocity = velocity;
	this->_size     = size;
	this->_life     = life;
	this->_amount   = amount;

	this->_particle.clear();

	this->_generator.seed();

	for (std::size_t i = 0; i < this->_amount; i++)
	{
		this->_generator.spown(this->_size, this->_velocity, this->_life);

		this->_particle.push_back(new particle());

		if (!this->_particle[i]->initialize(this->_data, this->_generator.size(), this->_color))
		{
			return false;
		}

		this->_particle[i]->position(this->_position);
		this->_particle[i]->rotate(this->_generator.rotate());
		this->_particle[i]->velocity(this->_generator.velocity());

		if (!this->_particle[i]->animation(this->_generator.born(), this->_life))
		{
			return false;
		}

		this->_particle[i]->start();
	}

	return true;
}

bool ygl::emitter::launcher::generator(const ygl::math::pointd& position, const ygl::math::sized& size, double velocity, std::size_t life, std::size_t amount)
{
	this->_position = position;
	this->_velocity = velocity;
	this->_size     = size;
	this->_life     = life;
	this->_amount   = amount;

	this->_particle.clear();

	this->_generator.seed();

	for (std::size_t i = 0; i < this->_amount; i++)
	{
		this->_generator.spown(this->_size, this->_velocity, this->_life);

		this->_particle.push_back(new particle());

		if (!this->_particle[i]->initialize(this->_data, this->_generator.size(), this->_color))
		{
			return false;
		}

		this->_particle[i]->position(this->_position);
		this->_particle[i]->rotate(this->_generator.rotate());
		this->_particle[i]->velocity(this->_generator.velocity());

		if (!this->_particle[i]->animation(this->_generator.born(), this->_life))
		{
			return false;
		}

		this->_particle[i]->start();
	}

	return true;
}

void ygl::emitter::launcher::draw()
{
	if (!this->_visible)
	{
		return;
	}

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		if (!this->_particle[i]->bound())
		{
			this->_particle[i]->draw();
		}
		else if (this->_regeneration <= -1)
		{
			this->_particle[i]->restart(this->_position);
		}
		else if (this->_regeneration >= 1)
		{
			if (this->_murdered == 0)
			{
				return;
			}

			this->_particle[i]->restart(this->_position);

			this->_murdered--;
		}
	}
}

void ygl::emitter::launcher::draw(const ygl::math::pointd& position, const ygl::math::colord& color)
{
	if (this->_position != position)
	{
		this->_position = position;
	}

	if (this->_color != color && !color.is_null())
	{
		this->_color = color;
	}

	if (!this->_visible)
	{
		return;
	}

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		if (!this->_particle[i]->bound())
		{
			this->_particle[i]->draw(this->_position, this->_color);
		}
		else if (this->_regeneration <= -1)
		{
			this->_particle[i]->restart(this->_position);
		}
		else if (this->_regeneration >= 1)
		{
			if (this->_murdered == 0)
			{
				return;
			}

			this->_particle[i]->restart(this->_position);

			this->_murdered--;
		}
	}
}

void ygl::emitter::launcher::running()
{
	if (!this->_running)
	{
		return;
	}

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		if (!this->_particle[i]->bound())
		{
			this->_particle[i]->running();
		}
	}
}

void ygl::emitter::launcher::start()
{
	this->_running = true;
}

void ygl::emitter::launcher::pause()
{
	this->_running = false;
}

void ygl::emitter::launcher::restart()
{
	this->_running  = true;
	this->_murdered = this->_regeneration > 0 ? this->_regeneration : 0;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->restart(this->_position);
	}
}

void ygl::emitter::launcher::reset()
{
	this->_running  = false;
	this->_murdered = this->_regeneration > 0 ? this->_regeneration : 0;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->reset(this->_position);
	}
}

bool ygl::emitter::launcher::bound()
{
	bool m_bound = false;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		m_bound = this->_particle[i]->bound() ? true : m_bound;
	}

	return m_bound;
}

bool ygl::emitter::launcher::onset()
{
	bool m_onset = false;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		m_onset = this->_particle[i]->onset() ? true : m_onset;
	}

	return m_onset;
}

void ygl::emitter::launcher::easy_opacity(const ygl::emitter::opacity& opacity)
{
	if (this->_easy_opacity == opacity)
	{
		return;
	}

	this->_easy_opacity = opacity;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->easy_opacity(this->_easy_opacity);
	}
}

void ygl::emitter::launcher::easy_scale(const ygl::emitter::scale& scale)
{
	if (this->_easy_scale == scale)
	{
		return;
	}

	this->_easy_scale = scale;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->easy_scale(this->_easy_scale);
	}
}

void ygl::emitter::launcher::easy_rotate(const ygl::emitter::rotate& rotate)
{
	if (this->_easy_rotate == rotate)
	{
		return;
	}

	this->_easy_rotate = rotate;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->easy_rotate(this->_easy_rotate);
	}
}

void ygl::emitter::launcher::random_color()
{
	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->random_color(true);
		this->_particle[i]->color(this->_generator.random_color());
	}
}

void ygl::emitter::launcher::regeneration(int regeneration)
{
	this->_regeneration = regeneration <= -1 ? -1 : regeneration;
	this->_murdered     = this->_regeneration > 0 ? this->_regeneration : 0;
}

void ygl::emitter::launcher::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::emitter::launcher::gravity(double gravity)
{
	if (this->_gravity == gravity)
	{
		return;
	}

	this->_gravity = gravity;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->gravity(this->_gravity);
	}
}

void ygl::emitter::launcher::wind(double wind)
{
	if (this->_wind == wind)
	{
		return;
	}

	this->_wind = wind;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->wind(this->_wind);
	}
}

void ygl::emitter::launcher::friction(double friction)
{
	if (this->_friction == friction)
	{
		return;
	}

	this->_friction = friction;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->friction(this->_friction);
	}
}

void ygl::emitter::launcher::color(const ygl::math::colord& color)
{
	if (this->_color == color)
	{
		return;
	}
	this->_color = color;

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->color(this->_color);
	}
}

void ygl::emitter::launcher::color(double r, double g, double b)
{
	if (this->_color == ygl::math::colord(r, g, b))
	{
		return;
	}

	this->_color.fill(r, g, b);

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->color(this->_color);
	}
}

void ygl::emitter::launcher::color_r(double r)
{
	if (this->_color.r() == r)
	{
		return;
	}

	this->_color.r(r);

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->color(this->_color);
	}
}

void ygl::emitter::launcher::color_g(double g)
{
	if (this->_color.g() == g)
	{
		return;
	}

	this->_color.g(g);

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->color(this->_color);
	}
}

void ygl::emitter::launcher::color_b(double b)
{
	if (this->_color.b() == b)
	{
		return;
	}

	this->_color.b(b);

	for (std::size_t i = 0; i < this->_particle.size(); i++)
	{
		this->_particle[i]->color(this->_color);
	}
}

void ygl::emitter::launcher::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::emitter::launcher::position(double x, double y, double z)
{
	this->_position = ygl::math::pointd(x, y, z);
}

void ygl::emitter::launcher::position_x(double x)
{
	this->_position.x(x);
}

void ygl::emitter::launcher::position_y(double y)
{
	this->_position.y(y);
}

void ygl::emitter::launcher::position_z(double z)
{
	this->_position.z(z);
}

std::size_t ygl::emitter::launcher::life() const
{
	return this->_life;
}

std::size_t ygl::emitter::launcher::amount() const
{
	return this->_amount;
}

const ygl::math::colord& ygl::emitter::launcher::color()
{
	return this->_color;
}

const ygl::math::pointd& ygl::emitter::launcher::position() const
{
	return this->_position;
}

double ygl::emitter::launcher::velocity() const
{
	return this->_velocity;
}

const ygl::math::sized& ygl::emitter::launcher::area() const
{
	return this->_area;
}

bool ygl::emitter::launcher::visible() const
{
	return this->_visible;
}

double ygl::emitter::launcher::gravity() const
{
	return this->_gravity;
}

double ygl::emitter::launcher::wind() const
{
	return this->_wind;
}

double ygl::emitter::launcher::friction() const
{
	return this->_friction;
}

bool ygl::emitter::launcher::load(const std::string& filename)
{
	SDL_Surface* image = IMG_Load(filename.c_str());

	if (image == NULL)
	{
		std::cerr << "ERROR: Filed initializing image '" << filename << "' -- " << IMG_GetError() << std::endl;
		exit(0);
	}

	this->_filename = filename;

	glGenTextures(1, &this->_data);
	glBindTexture(GL_TEXTURE_2D, this->_data);

	GLint internal_format = 0;
	GLint format = 0;

	switch (image->format->BytesPerPixel)
	{
		case 1:
			internal_format = GL_LUMINANCE;
			format = GL_RED;
			break;
		case 2:
			internal_format = GL_LUMINANCE_ALPHA;
			format = GL_RG;
			break;
		case 3:
		internal_format = GL_RGB;
#ifdef __APPLE__
			format = GL_BGR;
#else
			format = GL_RGB;
#endif
			break;
		case 4:
			internal_format = GL_RGBA;
#ifdef __APPLE__
			format = GL_BGRA;
#else
			format = GL_RGBA;
#endif
			break;
		default:
			std::cerr << "ERROR: Unknown image format at '" << filename << "', failed" << std::endl;
			exit(ygl::error::type::ERROR_LOAD_IMAGE);
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, image->w % 4 == 0 ? 4 : 1);
	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);

	// Insert it in polygon !!!!
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP);

	SDL_FreeSurface(image);

	return true;
}
