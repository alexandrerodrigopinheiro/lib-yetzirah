#ifndef YGL_AUDIO_MUSIC_H_
#define YGL_AUDIO_MUSIC_H_

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
		class music
		{
			public:

				music();

				music(const ygl::audio::music& obj);

				~music();

				bool load(const std::string& filnema);

				void destroy();

				void play();

			protected:

				Mix_Music* _music  { NULL };
		};
	}
}

#endif /* YGL_AUDIO_MUSIC_H_ */
