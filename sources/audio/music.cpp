#include "audio/music.h"

ygl::audio::music::music() :
	_music(NULL)
{
}

ygl::audio::music::music(const ygl::audio::music& obj) :
	_music(NULL)
{
	*this = obj;
}

ygl::audio::music::~music()
{
	this->destroy();
}

bool ygl::audio::music::load(const std::string& filnema)
{
	this->_music = Mix_LoadMUS(filnema.c_str());

	if (this->_music == NULL)
	{
		std::cerr << "Music: Failed to load sound '" << filnema << "'" << std::endl;

		return false;
	}

	return true;
}

void ygl::audio::music::destroy()
{
	Mix_FreeMusic(this->_music);
}

void ygl::audio::music::play()
{
	Mix_PlayMusic(this->_music, -1);
}
