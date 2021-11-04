#ifndef YGL_CORE_SYSTEM_H_
#define YGL_CORE_SYSTEM_H_

#pragma once

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>
#include <GL/glew.h>

#include "basic/basic.h"
#include "core/camera.h"
#include "core/core.h"
#include "scene/scene.h"
#include "core/handler.h"
#include "core/render.h"
#include "core/camera.h"
#include "clock/hertz.h"
#include "device/window.h"
#include "device/device.h"
#include "device/event.h"
#include "graphic/graphic.h"
#include "gui/hud.h"
#include "gui/ruler.h"

namespace ygl
{
	namespace core
	{
		class system
		{
			public:

				system();

				system(const ygl::core::system&) = delete;

				~system();

				bool initialize(const std::string& caption, const ygl::math::pointd& position, const ygl::math::sized& size, std::size_t fps, bool fullscreen = false, bool hud = false);

				bool double_window(const std::string& caption, const ygl::math::pointd& position, const ygl::math::sized& size, bool fullscreen = false);

				void destroy();

				bool scene(const std::string& name, ygl::scene::scene* scene);

				bool double_scene(ygl::scene::scene* scene);

				void running();

			private:

				void defines();

				void synchronize();

				void hud();

			protected:

				bool					_hud			{ false };
				ygl::device::window*	_window			{ nullptr };
				ygl::device::window*	_double_window	{ nullptr };
				ygl::core::render*		_render			{ nullptr };
				ygl::core::camera*		_camera			{ nullptr };
				ygl::scene::scene*		_double_scene	{ nullptr };
				ygl::device::event*		_event			{ nullptr };
				ygl::core::handler*		_handler		{ nullptr };
				ygl::clock::hertz*		_hertz			{ nullptr };
				ygl::gui::hud*			_info			{ nullptr };
		};
	}
}

#endif /* YGL_CORE_SYSTEM_H_ */
