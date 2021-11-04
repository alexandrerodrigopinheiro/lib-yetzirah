#ifndef YGL_DEVICE_WINDOW_H_
#define YGL_DEVICE_WINDOW_H_

#pragma once

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "error/exception.h"
#include "graphic/shape.h"
#include "graphic/text.h"
#include "math/color.h"
#include "math/point.h"
#include "math/surface.h"
#include "math/size.h"
#include "gui/hud.h"
#include "gui/ruler.h"

namespace ygl
{
	namespace device
	{
		class window
		{
			public:

				window();

				window(const window&) = delete;

				~window();

				bool initialize(const std::string& caption, const ygl::math::pointd& position, const ygl::math::sized& size, bool fullscreen = false, bool hud = false);

				void destroy();

				void renderize();

				void refresh();

				const std::string& caption() const;

				const ygl::math::pointd& position() const;

				const ygl::math::sized& size() const;

				bool fullscreen() const;

				bool hud() const;

				void caption(const std::string& caption);

				void position(const ygl::math::pointd& position);

				void size(const ygl::math::sized& size);

				void fullscreen(bool fullscreen);

				void hud(bool hud);

			private:

				void ruler();

			protected:

				SDL_Window*			_window		{ nullptr };
				SDL_GLContext		_context	{ nullptr };
				std::string			_caption	{ "Unamed" };
				ygl::math::pointd	_position	{ ygl::math::pointd() };
				ygl::math::sized	_size		{ ygl::math::sized() };
				bool				_fullscreen	{ false };
				bool				_hud		{ false };
				ygl::gui::ruler*	_ruler		{ nullptr };
				ygl::gui::hud*		_info		{ nullptr };
		};
	}
}
#endif /* YGL_DEVICE_WINDOW_H_ */
