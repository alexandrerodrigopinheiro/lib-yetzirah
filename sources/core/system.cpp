#include "core/system.h"

ygl::core::system::system() :
	_hud(false),
	_window(nullptr),
	_double_window(nullptr),
	_render(nullptr),
	_camera(nullptr),
	_double_scene(nullptr),
	_event(nullptr),
	_handler(nullptr),
	_hertz(nullptr),
	_info(nullptr)
{
}

ygl::core::system::~system()
{
	this->destroy();
}

bool ygl::core::system::initialize(const std::string& caption, const ygl::math::pointd& position, const ygl::math::sized& size, std::size_t fps, bool fullscreen, bool hud)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	if (!SDL_WasInit(SDL_INIT_VIDEO))
	{
		throw ygl::error::exception("Could not initialize system system, failed");

		return false;
	}

	if (!TTF_WasInit())
	{
		throw ygl::error::exception("Could not initialize system system, failed");

		return false;
	}

	this->_window = new ygl::device::window();

	if (!this->_window->initialize(caption, position, size, fullscreen, hud))
	{
		throw ygl::error::exception("Could not initialize window, failed");

		return false;
	}

	this->_camera = new ygl::core::camera();

	if (!this->_camera->initialize("main", position, size))
	{
		throw ygl::error::exception("Could not initialize camera, failed");

		return false;
	}

	this->_render = new ygl::core::render();

	if (!this->_render->initialize())
	{
		throw ygl::error::exception("Could not initialize render, failed");

		return false;
	}

#if 0
	const int AUDIO_FREQUENCY  = 22050;
	const int AUDIO_CHANNELS   = 2;
	const int AUDIO_CHUNK_SIZE = 4096;
#endif
	const int AUDIO_FREQUENCY  = 44100;
	const int AUDIO_CHANNELS   = 2;
	const int AUDIO_CHUNK_SIZE = 2048;

	Mix_OpenAudio(AUDIO_FREQUENCY, MIX_DEFAULT_FORMAT, AUDIO_CHANNELS, AUDIO_CHUNK_SIZE);

	this->_event = new ygl::device::event();

	if (!this->_event->initialize())
	{
		throw ygl::error::exception("Could not initialize event, failed");

		return false;
	}

	this->_hud = hud;
	this->_handler = new ygl::core::handler();

	this->_hertz = new ygl::clock::hertz();
	this->_hertz->initialize(fps);
	this->_hertz->fps();

	this->_info = new ygl::gui::hud("assets/extra/system.ttf", 10, ygl::math::sized(65, 15, 0));
	this->_info->position(10.0, 10.0, 0.0);
	this->_info->access_data()->align(ygl::graphic::align::ALIGN_LEFT);
	this->_info->access_data()->position_x(this->_info->access_data()->position().x() + 3);

	return true;
}

bool ygl::core::system::double_window(const std::string& caption, const ygl::math::pointd& position, const ygl::math::sized& size, bool fullscreen)
{
	if (!SDL_WasInit(SDL_INIT_VIDEO))
	{
		throw ygl::error::exception("Could not initialize core system, failed");

		return false;
	}

	if (!TTF_WasInit())
	{
		throw ygl::error::exception("Could not initialize core system, failed");

		return false;
	}

	SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");

	this->_double_window = new ygl::device::window();

	if (!this->_double_window->initialize(caption, position, size, fullscreen))
	{
		throw ygl::error::exception("Could not initialize Double Screen, failed");

		return false;
	}
	return true;
}

void ygl::core::system::destroy()
{
	if (SDL_WasInit(SDL_INIT_EVERYTHING))
	{
		delete this->_window;
		delete this->_double_window;
		delete this->_double_scene;
		delete this->_render;
		delete this->_camera;
		delete this->_event;
		delete this->_handler;
		delete this->_hertz;
		delete this->_info;

		this->_window = nullptr;
		this->_double_window = nullptr;
		this->_render = nullptr;
		this->_camera = nullptr;
		this->_double_scene	= nullptr;
		this->_event = nullptr;
		this->_handler = nullptr;
		this->_hertz = nullptr;
		this->_info = nullptr;

		SDL_Quit();
		TTF_Quit();
		Mix_CloseAudio();
	}
}

bool ygl::core::system::scene(const std::string& name, ygl::scene::scene* scene)
{
	this->_handler->attach(name, scene);
	return true;
}

bool ygl::core::system::double_scene(ygl::scene::scene* scene)
{
	this->_double_scene = scene;
	return true;
}

void ygl::core::system::running()
{
	this->_handler->loading();

	this->_camera->renderize();
	this->_render->renderize();

	while(this->_event->opened())
	{
		this->defines();
		this->_event->listener();

		if (this->_double_window != nullptr)
		{
			this->_double_scene->keyboard(this->_event->keyoard());
			this->_double_scene->mouse(this->_event->mouse());
			this->_double_scene->touch(this->_event->touch());

			this->_double_scene->update();

			this->_camera->renderize();
			this->_render->renderize();
			this->_double_window->renderize();
			this->_double_scene->render();

			this->_render->refresh();
			this->_double_window->refresh();

			this->_double_scene->clear();
		}

		this->_handler->keyboard(this->_event->keyoard());
		this->_handler->mouse(this->_event->mouse());
		this->_handler->touch(this->_event->touch());

		this->_handler->update();

		this->_camera->renderize();
		this->_render->renderize();
		this->_window->renderize();

		this->_handler->render();
		this->_event->render();

		this->hud();

		this->_render->refresh();
		this->_window->refresh();

		this->synchronize();

		this->_handler->clear();
		this->_event->clear();

		if (this->_handler->scene() == false)
		{
			break;
		}
	}

	this->destroy();
}

void ygl::core::system::defines()
{
	switch (this->_event->keyoard().button())
	{
		case ygl::device::button::BUTTON_DEBUG_FULLSCREEN:
		{
			this->_window->fullscreen((this->_window->fullscreen() ? false : true));
			break;
		}
		case ygl::device::button::BUTTON_DEBUG_INFO:
		{
			this->_hud = this->_hud ? false : true;
			this->_event->verbose(this->_hud);
			break;
		}
		case ygl::device::button::BUTTON_DEBUG_RULER:
		{
			this->_window->hud((this->_window->hud() ? false : true));
			break;
		}
		default: break;
	}
}

void ygl::core::system::synchronize()
{
	this->_hertz->synchronize();
}

void ygl::core::system::hud()
{
	if (this->_hud)
	{
		this->_info->draw("FPS: " + ygl::basic::to_string(this->_hertz->frequency()));
	}
}

