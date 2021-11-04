#include "device/event.h"

ygl::device::event::event() :
	_pressed(false),
	_open(true),
	_verbose(false),
	_type(ygl::device::type::TYPE_NONE),
	_keyoard(),
	_mouse(),
	_touch(),
	_touch_pulse(NULL)
{
}

ygl::device::event::~event()
{
}

bool ygl::device::event::initialize()
{
	if (!SDL_WasInit(SDL_INIT_EVENTS))
	{
		SDL_Init(SDL_INIT_EVENTS);
	}

	if (!SDL_WasInit(SDL_INIT_EVENTS))
	{
		throw ygl::error::exception("Could not initializing keyboard, failed");

		return false;
	}

	this->_touch_pulse = new ygl::graphic::sprite();

	if (!this->_touch_pulse->initialize("assets/extra/pulse.png", 5, 5))
	{
		throw ygl::error::exception("Could not initializing touch pulse, failed");

		return false;
	}

	this->_touch_pulse->pivot(0.5, 0.5, 0.5);

	if (!this->_touch_pulse->animation("TOUCH_PULSE", 4))
	{
		throw ygl::error::exception("Could not initializing touch pulse animation, failed");

		return false;
	}

	this->_touch_pulse->visible(false);
	this->_touch_pulse->tweening("TOUCH_PULSE")->attach_spot(0, 0);
	this->_touch_pulse->tweening("TOUCH_PULSE")->attach_spot(5, 5);
	this->_touch_pulse->tweening("TOUCH_PULSE")->control(ygl::animation::control::CONTROL_CYCLE);
	this->_touch_pulse->animation("TOUCH_PULSE");
	this->_touch_pulse->pause();

	return true;
}

void ygl::device::event::destroy()
{
	delete this->_touch_pulse;
	this->_touch_pulse = NULL;
}

void ygl::device::event::listener()
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
			{
				this->_open = false;
				break;
			}
			case SDL_KEYUP:
			{
				this->_keyoard.key(ygl::device::key::KEY_RELEASED);
				break;
			}
			case SDL_KEYDOWN:
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					this->_open = false;
					return;
				}

				if (event.key.repeat != 0)
				{
					return;
				}

				this->_keyoard.key(ygl::device::key::KEY_PRESSED);
				this->_pressed = true;

				switch (event.key.keysym.sym)
				{
					case SDLK_p:      this->_keyoard.button(ygl::device::button::BUTTON_PLAY);             break;
					case SDLK_o:      this->_keyoard.button(ygl::device::button::BUTTON_AUTOPLAY);         break;
					case SDLK_i:      this->_keyoard.button(ygl::device::button::BUTTON_EXTRABALL);        break;
					case SDLK_q:      this->_keyoard.button(ygl::device::button::BUTTON_DECREASE_SPEED);   break;
					case SDLK_w:      this->_keyoard.button(ygl::device::button::BUTTON_INCREASE_SPEED);   break;
					case SDLK_e:      this->_keyoard.button(ygl::device::button::BUTTON_CHANGE_PATTERN);   break;
					case SDLK_a:      this->_keyoard.button(ygl::device::button::BUTTON_MAXIMUM_PATTERN);  break;
					case SDLK_s:      this->_keyoard.button(ygl::device::button::BUTTON_DECREASE_PATTERN); break;
					case SDLK_d:      this->_keyoard.button(ygl::device::button::BUTTON_INCREASE_PATTERN); break;
					case SDLK_z:      this->_keyoard.button(ygl::device::button::BUTTON_MAXIMUM_BET);      break;
					case SDLK_x:      this->_keyoard.button(ygl::device::button::BUTTON_DECREASE_BET);     break;
					case SDLK_c:      this->_keyoard.button(ygl::device::button::BUTTON_INCREASE_BET);     break;
					case SDLK_j:      this->_keyoard.button(ygl::device::button::BUTTON_CREDIT);           break;
					case SDLK_k:      this->_keyoard.button(ygl::device::button::BUTTON_SETTING);          break;
					case SDLK_l:      this->_keyoard.button(ygl::device::button::BUTTON_CASHOUT);          break;
					case SDLK_n:      this->_keyoard.button(ygl::device::button::BUTTON_LOG);              break;
					case SDLK_m:      this->_keyoard.button(ygl::device::button::BUTTON_HELP);             break;
					case SDLK_1:      this->_keyoard.button(ygl::device::button::BUTTON_DEBUG_FULLSCREEN); break;
					case SDLK_2:      this->_keyoard.button(ygl::device::button::BUTTON_DEBUG_INFO);       break;
					case SDLK_3:      this->_keyoard.button(ygl::device::button::BUTTON_DEBUG_RULER);      break;
					default:          this->_keyoard.button(ygl::device::button::BUTTON_INVALID);          break;
				}

				break;
			}
			case SDL_MOUSEMOTION:
			{
				this->_mouse.cursor(ygl::device::cursor::CURSOR_MOTION);
				this->_mouse.position(event.motion.x, event.motion.y, 0.0);

				break;
			}
			case SDL_MOUSEBUTTONUP:
			{
				this->_mouse.cursor(ygl::device::cursor::CURSOR_RELEASED);
				this->_mouse.position(event.motion.x, event.motion.y, 0.0);
				this->_touch_pulse->pause();
				this->_touch_pulse->visible(false);

				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				this->_pressed = true;
				this->_mouse.cursor(ygl::device::cursor::CURSOR_PRESSED);
				this->_mouse.position(event.motion.x, event.motion.y, 0.0);
				this->_touch_pulse->position(event.motion.x, event.motion.y, 0.0);
				this->_touch_pulse->restart();
				this->_touch_pulse->visible(true);

				break;
			}
			case SDL_FINGERMOTION:
			{
				this->_touch.finger(ygl::device::finger::FINGER_MOTION);
				this->_touch.position(event.tfinger.x, event.tfinger.y, 0.0);
				this->_touch_pulse->position(event.tfinger.x, event.tfinger.y, 0.0);

				break;
			}
			case SDL_FINGERUP:
			{
				this->_touch.finger(ygl::device::finger::FINGER_RELEASED);
				this->_touch.position(event.tfinger.x, event.tfinger.y, 0.0);
				this->_touch_pulse->pause();
				this->_touch_pulse->visible(false);

				break;
			}
			case SDL_FINGERDOWN:
			{
				this->_pressed = true;
				this->_touch.finger(ygl::device::finger::FINGER_PRESSED);
				this->_touch.position(event.tfinger.x, event.tfinger.y, 0.0);
				this->_touch_pulse->position(event.tfinger.x, event.tfinger.y, 0.0);
				this->_touch_pulse->restart();
				this->_touch_pulse->visible(true);

				break;
			}
			default: break;
		}
	}

	if (this->_pressed && this->_verbose)
	{
		switch (this->_keyoard.button())
		{
			case ygl::device::button::BUTTON_PLAY:             std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_AUTOPLAY:         std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_EXTRABALL:        std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_DECREASE_SPEED:   std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_INCREASE_SPEED:   std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_CHANGE_PATTERN:   std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_MAXIMUM_PATTERN:  std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_DECREASE_PATTERN: std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_INCREASE_PATTERN: std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_MAXIMUM_BET:      std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_DECREASE_BET:     std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_INCREASE_BET:     std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_CREDIT:           std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_SETTING:          std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_CASHOUT:          std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_LOG:              std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_HELP:             std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_DEBUG_FULLSCREEN: std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_DEBUG_INFO:       std::cout << this->_keyoard.button() << std::endl; break;
			case ygl::device::button::BUTTON_DEBUG_RULER:      std::cout << this->_keyoard.button() << std::endl; break;
			default:                                            std::cout << this->_keyoard.button() << std::endl; break;
		}

		switch (this->_mouse.cursor())
		{
			case ygl::device::cursor::CURSOR_MOTION:   std::cout << this->_mouse.cursor() << std::endl; break;
			case ygl::device::cursor::CURSOR_RELEASED: std::cout << this->_mouse.cursor() << std::endl; break;
			case ygl::device::cursor::CURSOR_PRESSED:  std::cout << this->_mouse.cursor() << std::endl; break;
			default: break;
		}

		switch (this->_touch.finger())
		{
			case ygl::device::finger::FINGER_MOTION:   std::cout << this->_touch.finger() << std::endl; break;
			case ygl::device::finger::FINGER_RELEASED: std::cout << this->_touch.finger() << std::endl; break;
			case ygl::device::finger::FINGER_PRESSED:  std::cout << this->_touch.finger() << std::endl; break;
			default: break;
		}
	}
}

void ygl::device::event::render()
{
	this->_touch_pulse->draw();
	this->_touch_pulse->running();
}

void ygl::device::event::clear()
{
	this->_type = ygl::device::type::TYPE_NONE;
	this->_keyoard.clear();
	this->_mouse.clear();
	this->_touch.clear();
	this->_pressed = false;
}

const ygl::device::keyboard& ygl::device::event::keyoard() const
{
	return this->_keyoard;
}

const ygl::device::mouse& ygl::device::event::mouse() const
{
	return this->_mouse;
}

const ygl::device::touch& ygl::device::event::touch() const
{
	return this->_touch;
}

void ygl::device::event::verbose(bool verbose)
{
	this->_verbose = verbose;
}

bool ygl::device::event::opened() const
{
	return this->_open;
}

bool ygl::device::event::verbosed() const
{
	return this->_verbose;
}
