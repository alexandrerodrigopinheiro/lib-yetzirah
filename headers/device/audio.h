#ifndef YGL_DEVICE_AUDIO_H_
#define YGL_DEVICE_AUDIO_H_

#pragma once

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

namespace ygl
{
	namespace device
	{
		class audio
		{
			public:

				audio();

				audio(const audio&) = delete;

				~audio();

				bool initialize();

				void destroy();
		};
	}
}

#endif /* YGL_DEVICE_AUDIO_H_ */
