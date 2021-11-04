#include "graphic/stack.h"

ygl::graphic::stack::stack() :
	_data(std::vector<uint>()),
	_filename(std::string()),
	_visible(true),
	_wireframe(false),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_position(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(std::vector<ygl::math::sized>()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_map(ygl::math::uvmapd(1.0)),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
}

ygl::graphic::stack::stack(const std::string& filename) :
	_data(std::vector<uint>()),
	_filename(std::string()),
	_visible(true),
	_wireframe(false),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_position(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0)),
	_rotate(ygl::math::rotated()),
	_size(std::vector<ygl::math::sized>()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_map(ygl::math::uvmapd(1.0)),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
	this->initialize(filename);
}

ygl::graphic::stack::~stack()
{
	this->destroy();
}

bool ygl::graphic::stack::initialize(const std::string& filename)
{
	SDL_Surface* image = IMG_Load(filename.c_str());

	if (image == NULL)
	{
		std::cerr << "ERROR: Filed initializing image " << filename << " -- " << IMG_GetError() << std::endl;
		exit(ygl::error::ERROR_FAILED);
	}

	this->_spot = 0;
	this->_filename = filename;
	this->_size.push_back(ygl::math::sized((double)image->w, (double)image->h, 0.0));
	this->_map = ygl::math::uvmapd(this->_size.back().w() / (double)image->w, this->_size.back().h() / (double)image->h);

	uint tmp_data;
	glGenTextures(1, &tmp_data);
	glBindTexture(GL_TEXTURE_2D, tmp_data);

	this->_data.push_back(tmp_data);

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
			std::cerr << "ERROR: Unknown image format" << std::endl;
			exit(ygl::error::type::ERROR_LOAD_IMAGE);
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, image->w % 4 == 0 ? 4 : 1);
	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);

	// Insert it in polygon !!!!
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP);

	SDL_FreeSurface(image);

	return true;
}

void ygl::graphic::stack::destroy()
{
	for (std::size_t i = 0; i < this->_data.size(); i++)
	{
		glDeleteTextures(1, &this->_data[i]);
	}
	this->_data.clear();
	this->_size.clear();
	this->_animation.clear();
	this->_sensible.clear();
	this->_tweening.clear();
}

ygl::animation::tween* ygl::graphic::stack::tweening(const std::string& animation)
{
	auto it = this->_tweening.find(animation);
	if (it == this->_tweening.end())
	{
		std::cerr << "Text animation '" << animation << "' not found, failed" << std::endl;
		exit(0);
	}
	return this->_tweening[animation];
}

bool ygl::graphic::stack::animation(const std::string& animation, std::size_t timeline)
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

bool ygl::graphic::stack::animation(const std::string& animation, std::size_t timeline, std::size_t fps)
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

void ygl::graphic::stack::animation(const std::string& animation)
{
	auto it = this->_tweening.find(animation);

	if (it == this->_tweening.end())
	{
		std::cerr << "Image animation '" << animation << "' not found, failed" << std::endl;

		exit(0);
	}

	this->_animation = animation;
}

bool ygl::graphic::stack::sensible(const std::string& name, const ygl::math::surfaced& sensible)
{
	auto it = this->_sensible.find(name);

	if (it != this->_sensible.end())
	{
		return false;
	}

	this->_sensible.insert(std::pair<std::string, ygl::math::surfaced>(name, sensible));

	return true;
}

const ygl::math::surfaced& ygl::graphic::stack::sensible(const std::string& name)
{
	auto it = this->_sensible.find(name);

	if (it == this->_sensible.end())
	{
		std::cerr << "Layer sensible not found" << std::endl;
		exit(ygl::error::ERROR_FAILED);
	}

	return this->_sensible[name];
}

void ygl::graphic::stack::draw()
{
	if (this->_visible && this->_opacity > 0)
	{
		this->resolve();

		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glBindTexture(GL_TEXTURE_2D, this->_data[this->_spot]);

		glTranslated(this->_position.x(), this->_position.y(), ygl::math::invert(this->_position.z()));

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

			glTranslated(this->_position.x(), this->_position.y(), this->_position.z());

			glRotated(this->_rotate.h(), 1.0, 0.0, 0.0);
			glRotated(this->_rotate.p(), 0.0, 1.0, 0.0);
			glRotated(this->_rotate.b(), 0.0, 0.0, 1.0);

			glScaled(this->_scale.w(), this->_scale.h(), 1.0);

			glColor4d(0.0, 1.0, 0.0, 1.0);

			glLineWidth(2.0);
			glBegin(GL_LINE_LOOP);
			glVertex3d(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
			glVertex3d(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
			glVertex3d(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
			glVertex3d(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
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

void ygl::graphic::stack::draw(const ygl::math::pointd& position, int spot, const ygl::math::rotated& rotate, const ygl::math::sized& scale, const ygl::math::colord& color)
{
	if (this->_position != position && position != ygl::math::pointd().is_null())
	{
		this->position(position);
	}
	if ((int)this->_spot != spot && spot > -1)
	{
		this->spot((std::size_t	)spot);
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

void ygl::graphic::stack::running()
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

	if (this->_tweening[this->_animation]->has_spot())
	{
		this->spot(this->_tweening[this->_animation]->spot());
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

void ygl::graphic::stack::start()
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

void ygl::graphic::stack::pause()
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

void ygl::graphic::stack::restart()
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

void ygl::graphic::stack::reset()
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

bool ygl::graphic::stack::started()
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

bool ygl::graphic::stack::border()
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

bool ygl::graphic::stack::onset()
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

void ygl::graphic::stack::spot(std::size_t spot)
{
	if (spot >= this->_data.size()) {
		std::cerr << "ERROR: Illegal index of stack as " << spot << " in [0," << this->_data.size() - 1 << "]" << std::endl;
		exit(ygl::error::ERROR_FAILED);
	}
	this->_spot = spot;
}

void ygl::graphic::stack::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::graphic::stack::wireframe(bool wireframe)
{
	this->_wireframe = wireframe;
}

void ygl::graphic::stack::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::graphic::stack::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::graphic::stack::color(double r, double g, double b)
{
	this->_color.fill(r, g, b);
}

void ygl::graphic::stack::color_r(double r)
{
	this->_color.r(r);
}

void ygl::graphic::stack::color_g(double g)
{
	this->_color.g(g);
}

void ygl::graphic::stack::color_b(double b)
{
	this->_color.b(b);
}

void ygl::graphic::stack::opacity(double  opacity)
{
	this->_opacity = ygl::math::clamp(opacity, 0.0, 100.0);
}

void ygl::graphic::stack::orientation(const ygl::graphic::orientation& orientation)
{
	this->_orientation = orientation;
}

void ygl::graphic::stack::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
}

void ygl::graphic::stack::pivot(double x, double y, double z)
{
	this->_pivot.fill(x, y, z);
}

void ygl::graphic::stack::pivot_x(double x)
{
	this->_pivot.x(x);
}

void ygl::graphic::stack::pivot_y(double y)
{
	this->_pivot.y(y);
}

void ygl::graphic::stack::pivot_z(double z)
{
	this->_pivot.z(z);
}

void ygl::graphic::stack::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::graphic::stack::position(double x, double y, double z)
{
	this->_position.fill(x, y, z);
}

void ygl::graphic::stack::position_x(double x)
{
	this->_position.x(x);
}

void ygl::graphic::stack::position_y(double y)
{
	this->_position.y(y);
}

void ygl::graphic::stack::position_z(double z)
{
	this->_position.z(z);
}

void ygl::graphic::stack::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::graphic::stack::scale(double w, double h, double l)
{
	this->_scale.fill(w, h, l);
}

void ygl::graphic::stack::scale_w(double w)
{
	this->_scale.w(w);
}

void ygl::graphic::stack::scale_h(double h)
{
	this->_scale.h(h);
}

void ygl::graphic::stack::scale_l(double l)
{
	this->_scale.l(l);
}

void ygl::graphic::stack::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::graphic::stack::rotate(double h, double p, double b)
{
	this->_rotate.fill(h, p, b);
}

void ygl::graphic::stack::rotate_h(double h)
{
	this->_rotate.h(h);
}

void ygl::graphic::stack::rotate_p(double p)
{
	this->_rotate.p(p);
}

void ygl::graphic::stack::rotate_b(double b)
{
	this->_rotate.b(b);
}

const std::string& ygl::graphic::stack::filename() const
{
	return this->_filename;
}

std::size_t ygl::graphic::stack::spot() const
{
	return this->_spot;
}

bool ygl::graphic::stack::visible() const
{
	return this->_visible;
}

bool ygl::graphic::stack::wireframe() const
{
	return this->_wireframe;
}

const ygl::graphic::flip& ygl::graphic::stack::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::graphic::stack::color() const
{
	return this->_color;
}

double ygl::graphic::stack::opacity() const
{
	return this->_opacity;
}

const ygl::graphic::orientation& ygl::graphic::stack::orientation() const
{
	return this->_orientation;
}

const ygl::math::pointd& ygl::graphic::stack::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::graphic::stack::position() const
{
	return this->_position;
}

const ygl::math::sized& ygl::graphic::stack::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::graphic::stack::rotate() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::graphic::stack::size() const
{
	return this->_size[this->_spot];
}

void ygl::graphic::stack::resolve()
{
	double x = ygl::math::invert(this->_size[this->_spot].w() * this->_pivot.x());
	double y = ygl::math::invert(this->_size[this->_spot].h() * this->_pivot.y());
	double z = ygl::math::invert(this->_size[this->_spot].l() * this->_pivot.z());
	double w = x + this->_size[this->_spot].w();
	double h = y + this->_size[this->_spot].h();

	this->_offset.x(0.f);
	this->_offset.y(0.f);
	this->_offset.w(this->_map.u());
	this->_offset.h(this->_map.v());

	this->_vertex.a(x, y, z);
	this->_vertex.b(w, y, z);
	this->_vertex.c(w, h, z);
	this->_vertex.d(x, h, z);
}
