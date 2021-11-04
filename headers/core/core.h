#ifndef YGL_CORE_CORE_H_
#define YGL_CORE_CORE_H_

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
#include "scene/scene.h"
#include "core/handler.h"
#include "clock/clock.h"
#include "clock/timer.h"
#include "clock/frequency.h"
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
		typedef enum state
		{
			STATE_INACTIVE,
			STATE_STANDBY,
			STATE_REFRESH,
			STATE_ROLLING,
			STATE_RESET,
			STATE_SPLASH,
			STATE_FREEZING,
		} state;

		std::ostream& operator<<(std::ostream& stream, const ygl::core::state& state);

		std::istream& operator>>(std::istream& stream, ygl::core::state& state);

		ygl::core::state to_state(const std::string& state);
	}
}

#endif /* YGL_CORE_CORE_H_ */
