#ifndef YGL_AUDIO_EFFECT_H_
#define YGL_AUDIO_EFFECT_H_

#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>

namespace ygl
{
	namespace audio
	{
		class effect
		{
			public:

				effect();

				effect(const ygl::audio::effect& obj);

				~effect();

				bool load(const std::string& filnema);

				void destroy();

				void play(int channel = -1);

			protected:

				Mix_Chunk* _effect  { NULL };
		};
	}
}

#endif /* YGL_AUDIO_EFFECT_H_ */
