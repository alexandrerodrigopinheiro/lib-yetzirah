#ifndef YGL_CORE_RENDER_H_
#define YGL_CORE_RENDER_H_

#pragma once

#include "error/exception.h"
#include "math/color.h"
#include "math/math.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <GL/glew.h>

namespace ygl
{
	namespace core
	{
		class render
		{
			public:

				render();

				render(const render&) = delete;

				~render();

				bool initialize();

				void destroy();

				void renderize(const ygl::math::colord& color = ygl::math::colord().BLACK());

				void refresh();
		};
	}
}

#endif /* YGL_CORE_RENDER_H_ */
