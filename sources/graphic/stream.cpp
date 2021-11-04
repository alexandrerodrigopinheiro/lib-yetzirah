#include "graphic/stream.h"

ygl::graphic::stream::stream() :
	_volume(100),
	_data(0),
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
	_size(ygl::math::sized()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_map(ygl::math::uvmapd(1.0))
{
}

ygl::graphic::stream::stream(const std::string& filename) :
	_volume(100),
	_data(0),
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
	_size(ygl::math::sized()),
	_offset(ygl::math::surfaced(0.0, 0.0, 1.0, 1.0)),
	_vertex(ygl::math::vertexd()),
	_map(ygl::math::uvmapd(1.0))
{
	this->initialize(filename);
}

ygl::graphic::stream::~stream()
{
	this->destroy();
}

bool ygl::graphic::stream::initialize(const std::string& filename)
{
	this->_filename = filename;

	SDL_Surface* image = nullptr;

    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
       on the endianness (byte order) of the machine */
//#if SDL_BYTEORDER == SDL_BIG_ENDIAN
//	image = SDL_CreateRGBSurface(SDL_SWSURFACE, this->_info.width, this->_info.height, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
//#else
//	image = SDL_CreateRGBSurface(SDL_SWSURFACE, this->_info.width, this->_info.height, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
//#endif

	if (image == nullptr)
	{
		std::cerr << "ERROR: Filed initializing image " << filename << " -- " << IMG_GetError() << std::endl;
		exit(1);
	}

	this->_filename = filename;
	this->_size = ygl::math::sized((double)image->w, (double)image->h, 0.0);
	this->_map = ygl::math::uvmapd(this->_size.w() / (double)image->w, this->_size.h() / (double)image->h);

	SDL_FreeSurface(image);

	this->resolve();

	return true;
}

void ygl::graphic::stream::destroy()
{
	glDeleteTextures(1, &this->_data);
}

void ygl::graphic::stream::draw()
{
	if (this->_visible && this->_opacity > 0)
	{
		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glBindTexture(GL_TEXTURE_2D, this->_data);

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

void ygl::graphic::stream::draw(const ygl::math::pointd& position, const ygl::math::rotated& rotate, const ygl::math::sized& scale, const ygl::math::colord& color)
{
	if (this->_position != position && !position.is_null())
	{
		this->position(position);
	}

	if (this->_rotate != rotate && !rotate.is_null())
	{
		this->rotate(rotate);
	}

	if (this->_scale != scale && !scale.is_null())
	{
		this->scale(scale);
	}

	if (this->_color != color && !color.is_null())
	{
		this->_color = color;
	}

	this->draw();
}

void ygl::graphic::stream::loop(bool loop)
{
	this->_loop = loop;
}

void ygl::graphic::stream::play()
{
}

void ygl::graphic::stream::pause()
{
}

void ygl::graphic::stream::replay()
{
}

void ygl::graphic::stream::reset()
{
}

bool ygl::graphic::stream::loop() const
{
	return this->_loop;
}

bool ygl::graphic::stream::playing()
{
	return true;
}

bool ygl::graphic::stream::border()
{
	return false;
}

bool ygl::graphic::stream::onset()
{
	return false;
}

void ygl::graphic::stream::visible(bool visible)
{
	this->_visible = visible;
}

void ygl::graphic::stream::wireframe(bool wireframe)
{
	this->_wireframe = wireframe;
}

void ygl::graphic::stream::flip(const ygl::graphic::flip& flip)
{
	this->_flip = flip;
}

void ygl::graphic::stream::color(const ygl::math::colord& color)
{
	this->_color = color;
}

void ygl::graphic::stream::color(double r, double g, double b)
{
	this->_color.fill(r, g, b);
}

void ygl::graphic::stream::color_r(double r)
{
	this->_color.r(r);
}

void ygl::graphic::stream::color_g(double g)
{
	this->_color.g(g);
}

void ygl::graphic::stream::color_b(double b)
{
	this->_color.b(b);
}

void ygl::graphic::stream::opacity(double opacity)
{
	this->_opacity = ygl::math::clamp(opacity, 0.0, 100.0);
}

void ygl::graphic::stream::orientation(const ygl::graphic::orientation& orientation)
{
	this->_orientation = orientation;
}

void ygl::graphic::stream::pivot(const ygl::math::pointd& pivot)
{
	this->_pivot = pivot;
	this->resolve();
}

void ygl::graphic::stream::pivot(double x, double y, double z)
{
	this->_pivot.fill(x, y, z);
	this->resolve();
}

void ygl::graphic::stream::pivot_x(double x)
{
	this->_pivot.x(x);
	this->resolve();
}

void ygl::graphic::stream::pivot_y(double y)
{
	this->_pivot.y(y);
	this->resolve();
}

void ygl::graphic::stream::pivot_z(double z)
{
	this->_pivot.z(z);
	this->resolve();
}

void ygl::graphic::stream::position(const ygl::math::pointd& position)
{
	this->_position = position;
}

void ygl::graphic::stream::position(double x, double y, double z)
{
	this->_position.fill(x, y, z);
}

void ygl::graphic::stream::position_x(double x)
{
	this->_position.x(x);
}

void ygl::graphic::stream::position_y(double y)
{
	this->_position.y(y);
}

void ygl::graphic::stream::position_z(double z)
{
	this->_position.z(z);
}

void ygl::graphic::stream::volume(std::size_t volume)
{
	this->_volume = volume;
}

void ygl::graphic::stream::scale(const ygl::math::sized& scale)
{
	this->_scale = scale;
}

void ygl::graphic::stream::scale(double w, double h, double l)
{
	this->_scale.fill(w, h, l);
}

void ygl::graphic::stream::scale_w(double w)
{
	this->_scale.w(w);
}

void ygl::graphic::stream::scale_h(double h)
{
	this->_scale.h(h);
}

void ygl::graphic::stream::scale_l(double l)
{
	this->_scale.l(l);
}

void ygl::graphic::stream::rotate(const ygl::math::rotated& rotate)
{
	this->_rotate = rotate;
}

void ygl::graphic::stream::rotate(double h, double p, double b)
{
	this->_rotate.fill(h, p, b);
}

void ygl::graphic::stream::rotate_h(double h)
{
	this->_rotate.h(h);
}

void ygl::graphic::stream::rotate_p(double p)
{
	this->_rotate.p(p);
}

void ygl::graphic::stream::rotate_b(double b)
{
	this->_rotate.b(b);
}

const std::string& ygl::graphic::stream::filename() const
{
	return this->_filename;
}

bool ygl::graphic::stream::visible() const
{
	return this->_visible;
}

bool ygl::graphic::stream::wireframe() const
{
	return this->_wireframe;
}

const ygl::graphic::flip& ygl::graphic::stream::flip() const
{
	return this->_flip;
}

const ygl::math::colord& ygl::graphic::stream::color() const
{
	return this->_color;
}

double ygl::graphic::stream::opacity() const
{
	return this->_opacity;
}

const ygl::graphic::orientation& ygl::graphic::stream::orientation() const
{
	return this->_orientation;
}

const ygl::math::pointd& ygl::graphic::stream::pivot() const
{
	return this->_pivot;
}

const ygl::math::pointd& ygl::graphic::stream::position() const
{
	return this->_position;
}

std::size_t ygl::graphic::stream::volume() const
{
	return this->_volume;
}

const ygl::math::sized& ygl::graphic::stream::scale() const
{
	return this->_scale;
}

const ygl::math::rotated& ygl::graphic::stream::rotate() const
{
	return this->_rotate;
}

const ygl::math::sized& ygl::graphic::stream::size() const
{
	return this->_size;
}

void ygl::graphic::stream::resolve()
{
	SDL_Surface* image = nullptr;

    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
       on the endianness (byte order) of the machine */
//#if SDL_BYTEORDER == SDL_BIG_ENDIAN
//	image = SDL_CreateRGBSurface(SDL_SWSURFACE, this->_info.width, this->_info.height, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
//#else
//	image = SDL_CreateRGBSurface(SDL_SWSURFACE, this->_info.width, this->_info.height, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
//#endif

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
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP);

	SDL_FreeSurface(image);

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
