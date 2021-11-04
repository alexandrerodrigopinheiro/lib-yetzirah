#include "graphic/atlas.h"

ygl::graphic::atlas::atlas() :
	_data(0),
	_spot(1),
	_frames(1),
	_filename(std::string()),
	_visible(true),
	_wireframe(false),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_position(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0f)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_matrix(ygl::math::matrixd(1)),
	_map(ygl::math::uvmapd(1.0)),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
}

ygl::graphic::atlas::atlas(const std::string& filename, std::size_t colunms, std::size_t frames) :
	_data(0),
	_spot(1),
	_frames(frames),
	_filename(std::string()),
	_visible(true),
	_wireframe(false),
	_flip(ygl::graphic::flip::FLIP_NONE),
	_color(ygl::math::colord().WHITE()),
	_opacity(100),
	_orientation(ygl::graphic::orientation::ORIENTATION_GLOBAL),
	_pivot(ygl::math::pointd(0.5)),
	_position(ygl::math::pointd()),
	_scale(ygl::math::sized(1.0f)),
	_rotate(ygl::math::rotated()),
	_size(ygl::math::sized()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_matrix(ygl::math::matrixd(1)),
	_map(ygl::math::uvmapd(1.0)),
	_running(false),
	_animation(std::string()),
	_sensible(std::map<std::string, ygl::math::surfaced>()),
	_tweening(std::map<std::string, ygl::animation::tween*>())
{
	this->initialize(filename, colunms, frames);
}

ygl::graphic::atlas::~atlas()
{
	this->destroy();
}

bool ygl::graphic::atlas::initialize(const std::string& filename, std::size_t colunms, std::size_t frames)
{
	this->_filename = filename;
	SDL_Surface* image = IMG_Load(filename.c_str());

	if (image == NULL)
	{
		std::cerr << IMG_GetError() << std::endl;
		return false;
	}

	std::size_t row = static_cast<std::size_t>(std::ceil(((double)frames == (double)0 ? (double)1 : (double)frames) / (double)colunms));

	this->_filename = filename;
	this->_spot = 0;
	this->_frames = frames;
	this->_matrix = ygl::math::matrixd(row, colunms);
	this->_size = ygl::math::sized((double)image->w / this->_matrix.colunms(), (double)image->h / this->_matrix.rows(), 0.0);
	this->_map = ygl::math::uvmapd(this->_size.w() / double(image->w), this->_size.h() / static_cast<double>(image->h));

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
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP);

	SDL_FreeSurface(image);

	this->resolve();

	return true;
}

void ygl::graphic::atlas::destroy()
{
	glDeleteTextures(1, &this->_data);
	this->_animation.clear();
}

ygl::animation::tween* ygl::graphic::atlas::tweening(const std::string& animation)
{
	auto it = this->_tweening.find(animation);
	if (it == this->_tweening.end())
	{
		std::cerr << "Text animation '" << animation << "' not found, failed" << std::endl;
		exit(0);
	}
	return this->_tweening[animation];
}

bool ygl::graphic::atlas::animation(const std::string& animation, std::size_t timeline)
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

bool ygl::graphic::atlas::animation(const std::string& animation, std::size_t timeline, std::size_t fps)
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

void ygl::graphic::atlas::animation(const std::string& animation)
{
	auto it = this->_tweening.find(animation);

	if (it == this->_tweening.end())
	{
		std::cerr << "Image animation '" << animation << "' not found, failed" << std::endl;

		exit(0);
	}

	this->_animation = animation;
}

bool ygl::graphic::atlas::sensible(const std::string& name, const ygl::math::surfaced& sensible)
{
	auto it = this->_sensible.find(name);

	if (it != this->_sensible.end())
	{
		return false;
	}

	this->_sensible.insert(std::pair<std::string, ygl::math::surfaced>(name, sensible));

	return true;
}

const ygl::math::surfaced& ygl::graphic::atlas::sensible(const std::string& name)
{
	auto it = this->_sensible.find(name);

	if (it == this->_sensible.end())
	{
		std::cerr << "Layer sensible not found" << std::endl;
		exit(1);
	}

	return this->_sensible[name];
}

void ygl::graphic::atlas::draw()
{
	if (this->_visible && this->_opacity > 0)
	{
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glBindTexture(GL_TEXTURE_2D, this->_data);

		glTranslated(this->_position.x(), this->_position.y(), ygl::math::invert(this->_position.z()));

		glRotated(this->_rotate.h(), 1.0f, 0.0f, 0.0f);
		glRotated(this->_rotate.p(), 0.0f, 1.0f, 0.0f);
		glRotated(this->_rotate.b(), 0.0f, 0.0f, 1.0f);

		glScaled(this->_scale.w(), this->_scale.h(), 1.0f);

		glColor4d(
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

			glRotated(this->_rotate.h(), 1.0f, 0.0f, 0.0f);
			glRotated(this->_rotate.p(), 0.0f, 1.0f, 0.0f);
			glRotated(this->_rotate.b(), 0.0f, 0.0f, 1.0f);

			glScaled(this->_scale.w(), this->_scale.h(), 1.0f);

			glColor4d(0.0f, 1.0f, 0.0f, 1.0f);

			glLineWidth(2.0f);
			glBegin(GL_LINE_LOOP);
			glVertex3d(this->_vertex.a().x(), this->_vertex.a().y(), this->_vertex.a().z());
			glVertex3d(this->_vertex.b().x(), this->_vertex.b().y(), this->_vertex.b().z());
			glVertex3d(this->_vertex.c().x(), this->_vertex.c().y(), this->_vertex.c().z());
			glVertex3d(this->_vertex.d().x(), this->_vertex.d().y(), this->_vertex.d().z());
			glEnd();

			glColor4d(0.0f, 0.0f, 1.0f, 1.0f);
			glLineWidth(2.0f);
			glBegin(GL_LINES);
			glVertex3d(-10.0f, 0.0f, 0.0f);
			glVertex3d( 10.0f, 0.0f, 0.0f);
			glEnd();

			glColor4d(1.0f, 0.0f, 0.0f, 1.0f);
			glLineWidth(2.0f);
			glBegin(GL_LINES);
			glVertex3d(0.0f, -10.0f, 0.0f);
			glVertex3d(0.0f,  10.0f, 0.0f);
			glEnd();

			glDisable(GL_LINE_STIPPLE);
		}

		glPopMatrix();
	}
}

void ygl::graphic::atlas::draw(const ygl::math::pointd& position, const ygl::math::rotated& rotation, const ygl::math::sized& scale, const ygl::math::colord& color, int spot)
{
	if (this->_position != position && !position.is_null())
	{
		this->position(position);
	}

	if (this->_rotate != rotation && !rotation.is_null())
	{
		this->rotate(rotation);
	}

	if (this->_scale != scale && !scale.is_null())
	{
		this->scale(scale);
	}

	if (this->_color != color && !color.is_null())
	{
		this->_color = color;
	}

	if (spot != -1 && this->_spot != (std::size_t)spot)
	{
		this->spot(spot);
	}

	this->draw();
}

void ygl::graphic::atlas::running()
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

void ygl::graphic::atlas::start()
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

void ygl::graphic::atlas::pause()
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

void ygl::graphic::atlas::restart()
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

void ygl::graphic::atlas::reset()
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

bool ygl::graphic::atlas::started()
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

bool ygl::graphic::atlas::border()
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

bool ygl::graphic::atlas::onset()
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

void ygl::graphic::atlas::spot(std::size_t spot)
{
	this->_spot = spot;
	this->resolve();
}

void ygl::graphic::atlas::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::graphic::atlas::wireframe(bool wireframe)
{
	this->_wireframe = wireframe;
}

void ygl::graphic::atlas::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::graphic::atlas::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::graphic::atlas::color(double r, double g, double b)
{
	this->_color.fill(r, g, b);
}

void ygl::graphic::atlas::color_r(double r)
{
	this->_color.r(r);
}

void ygl::graphic::atlas::color_g(double g)
{
	this->_color.g(g);
}

void ygl::graphic::atlas::color_b(double b)
{
	this->_color.b(b);
}

void ygl::graphic::atlas::opacity(double opacity)
{
	this->_opacity = ygl::math::clamp(opacity, 0.0, 100.0);
}

void ygl::graphic::atlas::orientation(const ygl::graphic::orientation& orientation)
{
	this->_orientation = orientation;
}

void ygl::graphic::atlas::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
	this->resolve();
}

void ygl::graphic::atlas::pivot(double x, double y, double z)
{
	this->_pivot.fill(x, y, z);
	this->resolve();
}

void ygl::graphic::atlas::pivot_x(double x)
{
	this->_pivot.x(x);
	this->resolve();
}

void ygl::graphic::atlas::pivot_y(double y)
{
	this->_pivot.y(y);
	this->resolve();
}

void ygl::graphic::atlas::pivot_z(double z)
{
	this->_pivot.z(z);
	this->resolve();
}

void ygl::graphic::atlas::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::graphic::atlas::position(double x, double y, double z)
{
	this->_position.fill(x, y, z);
}

void ygl::graphic::atlas::position_x(double x)
{
	this->_position.x(x);
}

void ygl::graphic::atlas::position_y(double y)
{
	this->_position.y(y);
}

void ygl::graphic::atlas::position_z(double z)
{
	this->_position.z(z);
}

void ygl::graphic::atlas::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::graphic::atlas::scale(double w, double h, double l)
{
	this->_scale.fill(w, h, l);
}

void ygl::graphic::atlas::scale_w(double w)
{
	this->_scale.w(w);
}

void ygl::graphic::atlas::scale_h(double h)
{
	this->_scale.h(h);
}

void ygl::graphic::atlas::scale_l(double l)
{
	this->_scale.l(l);
}

void ygl::graphic::atlas::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::graphic::atlas::rotation(double h, double p, double b)
{
	this->_rotate.fill(h, p, b);
}

void ygl::graphic::atlas::rotation_h(double h)
{
	this->_rotate.h(h);
}

void ygl::graphic::atlas::rotation_p(double p)
{
	this->_rotate.p(p);
}

void ygl::graphic::atlas::rotation_b(double b)
{
	this->_rotate.b(b);
}

std::size_t ygl::graphic::atlas::spot() const
{
	return this->_spot;
}

std::size_t ygl::graphic::atlas::frames() const
{
	return this->_frames;
}

const std::string& ygl::graphic::atlas::filename() const
{
	return this->_filename;
}

bool ygl::graphic::atlas::visible() const
{
	return this->_visible;
}

bool ygl::graphic::atlas::wireframe() const
{
	return this->_wireframe;
}

const ygl::graphic::flip& ygl::graphic::atlas::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::graphic::atlas::color() const
{
	return this->_color;
}

double ygl::graphic::atlas::opacity() const
{
	return this->_opacity;
}

const ygl::graphic::orientation& ygl::graphic::atlas::orientation() const
{
	return this->_orientation;
}

const ygl::math::pointd& ygl::graphic::atlas::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::graphic::atlas::position() const
{
	return this->_position;
}

const ygl::math::sized& ygl::graphic::atlas::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::graphic::atlas::rotation() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::graphic::atlas::size() const
{
	return this->_size;
}

const ygl::math::matrixd& ygl::graphic::atlas::matrix() const
{
	return this->_matrix;
}

void ygl::graphic::atlas::resolve()
{
	double x = ygl::math::invert(this->_size.w() * this->_pivot.x());
	double y = ygl::math::invert(this->_size.h() * this->_pivot.y());
	double w = x + this->_size.w();
	double h = y + this->_size.h();

	this->_offset.x(this->_map.u() * (double)(this->_spot % (std::size_t)this->_matrix.colunms()));
	this->_offset.y(this->_map.v() * (double)(this->_spot / (std::size_t)this->_matrix.colunms()));
	this->_offset.w(this->_map.u() + this->_offset.x());
	this->_offset.h(this->_map.v() + this->_offset.y());

	this->_vertex.a(x, y, 0.0f);
	this->_vertex.b(w, y, 0.0f);
	this->_vertex.c(w, h, 0.0f);
	this->_vertex.d(x, h, 0.0f);
}
