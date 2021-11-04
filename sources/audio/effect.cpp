#include "audio/effect.h"

ygl::audio::effect::effect() :
	_effect(NULL)
{
}

ygl::audio::effect::effect(const ygl::audio::effect& obj) :
	_effect(NULL)
{
	*this = obj;
}

ygl::audio::effect::~effect()
{
	this->destroy();
}

bool ygl::audio::effect::load(const std::string& filnema)
{
	this->_effect = Mix_LoadWAV(filnema.c_str());

	if (this->_effect == NULL)
	{
		std::cerr << "Effect: Failed to load sound '" << filnema << "'" << std::endl;

		return false;
	}

	return true;
}

void ygl::audio::effect::destroy()
{
	Mix_FreeChunk(this->_effect);
}

void ygl::audio::effect::play(int channel)
{
	Mix_PlayChannel(channel, this->_effect, 0);
}
