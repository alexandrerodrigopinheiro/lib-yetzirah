#include "scene/scene.h"

ygl::scene::scene::scene() :
	_next_scene(std::string())
{
}

ygl::scene::scene::~scene()
{
}

void ygl::scene::scene::next_scene(const std::string& scene)
{
	this->_next_scene = scene;
}

const std::string& ygl::scene::scene::next_scene() const
{
	return this->_next_scene;
}

void ygl::scene::scene::clear_next_scene()
{
	this->_next_scene.clear();
}
