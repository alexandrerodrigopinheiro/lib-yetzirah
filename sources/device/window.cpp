#include "device/window.h"

ygl::device::window::window() :
	_window(nullptr),
	_context(nullptr),
	_caption("Unamed"),
	_position(ygl::math::pointd()),
	_size(ygl::math::sized()),
	_fullscreen(false),
	_hud(false),
	_ruler(nullptr),
	_info(nullptr)
{
}

ygl::device::window::~window()
{
	this->destroy();
}

bool ygl::device::window::initialize(const std::string& caption, const ygl::math::pointd& position, const ygl::math::sized& size, bool fullscreen, bool hud)
{
	this->_caption = caption;
	this->_position = position;
	this->_size = size;
	this->_fullscreen = fullscreen;
	this->_hud = hud;
	this->_ruler = new ygl::gui::ruler(size);
	this->_info = new ygl::gui::hud("assets/extra/system.ttf", 10, ygl::math::sized(100, 15, 0));

	this->_info->access_box()->position(-100, -15, 0);
	this->_info->access_data()->align(ygl::graphic::align::ALIGN_CENTER);
	this->_info->access_data()->position(this->_info->access_data()->position().x() - 100 / 2, this->_info->access_data()->position().y() - 15, 0.0);

	Uint32 flag = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

	if (this->_fullscreen)
	{
		flag |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	this->_window = SDL_CreateWindow(this->_caption.c_str(), this->_position.x(), this->_position.y(), this->_size.w(), this->_size.h(), flag);

	if (this->_window == nullptr)
	{
		throw ygl::error::exception("Could not create the window '" + this->_caption + "', failed");

		return false;
	}

	SDL_ShowCursor(-1);

	this->_context = SDL_GL_CreateContext(this->_window);

	if (this->_context == nullptr)
	{
		throw ygl::error::exception("Could not create context at the '" + this->_caption + "', failed");

		return false;
	}

	return true;
}

void ygl::device::window::destroy()
{
	SDL_GL_DeleteContext(this->_context);
	SDL_DestroyWindow(this->_window);
	this->_window = nullptr;
	this->_context = nullptr;
}

void ygl::device::window::renderize()
{
	SDL_GL_MakeCurrent(this->_window, this->_context);
}

void ygl::device::window::refresh()
{
	this->ruler();
	SDL_GL_SwapWindow(this->_window);
}

const std::string& ygl::device::window::caption() const
{
	return this->_caption;
}

const ygl::math::pointd& ygl::device::window::position() const
{
	return this->_position;
}

const ygl::math::sized& ygl::device::window::size() const
{
	return this->_size;
}

bool ygl::device::window::fullscreen() const
{
	return this->_fullscreen;
}

bool ygl::device::window::hud() const
{
	return this->_hud;
}

void ygl::device::window::caption(const std::string& caption)
{
	this->_caption = caption;

	SDL_SetWindowTitle(this->_window, this->_caption.c_str());
}

void ygl::device::window::position(const ygl::math::pointd& position)
{
	this->_position = position;

	SDL_SetWindowPosition(this->_window, this->_position.x(), this->_position.y());
}

void ygl::device::window::size(const ygl::math::sized& size)
{
	this->_size = size;

	SDL_SetWindowSize(this->_window, this->_size.w(), this->_size.h());
}

void ygl::device::window::fullscreen(bool fullscreen)
{
	this->_fullscreen = fullscreen;

	Uint32 flag = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

	if (this->_fullscreen)
	{
		flag |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	SDL_SetWindowFullscreen(this->_window, flag);
}

void ygl::device::window::hud(bool hud)
{
	this->_hud = hud;
	SDL_ShowCursor((this->_hud ? 1 : -1));
}

void ygl::device::window::ruler()
{
	if (this->_hud)
	{
		int x;
		int y;
		SDL_GetMouseState(&x, &y);
		this->_ruler->draw();
		this->_info->draw("X: " + ygl::basic::to_string(x) + " Y: " + ygl::basic::to_string(y), ygl::math::pointd((double)x, (double)y, 0.0));
	}
}
