#include "serialize/animatic.h"

ygl::serialize::animatic::animatic() : _name(std::string())
	, _size(0)
	, _play(ygl::animation::play::PLAY_ON)
	, _control(ygl::animation::control::CONTROL_SINGLE)
	, _course(ygl::animation::course::COURSE_FORWARD)
	, _interpolation(ygl::animation::interpolation::INTERPOLATION_HARD)
	, _keyframe(std::vector<ygl::animation::keyframe>())
{
}

ygl::serialize::animatic::~animatic()
{
	this->_keyframe.clear();
}

void ygl::serialize::animatic::name(const std::string& name)
{
	this->_name = name;
}

void ygl::serialize::animatic::size(std::size_t size)
{
	this->_size = size;
}

void ygl::serialize::animatic::play(const ygl::animation::play& play)
{
	this->_play = play;
}

void ygl::serialize::animatic::control(const ygl::animation::control& control)
{
	this->_control = control;
}

void ygl::serialize::animatic::course(const ygl::animation::course& course)
{
	this->_course = course;
}

void ygl::serialize::animatic::interpolation(const ygl::animation::interpolation& interpolation)
{
	this->_interpolation = interpolation;
}

void ygl::serialize::animatic::keyframe(const std::vector<ygl::animation::keyframe>& keyframe)
{
	for (std::size_t i = 0; i < keyframe.size(); i++)
	{
		this->_keyframe.push_back(keyframe[i]);
	}
}

void ygl::serialize::animatic::keyframe(const ygl::animation::keyframe& keyframe)
{
	this->_keyframe.push_back(keyframe);
}

const std::string& ygl::serialize::animatic::name() const
{
	return this->_name;
}

std::size_t ygl::serialize::animatic::size() const
{
	return this->_size;
}

const ygl::animation::play& ygl::serialize::animatic::play() const
{
	return this->_play;
}

const ygl::animation::control& ygl::serialize::animatic::control() const
{
	return this->_control;
}

const ygl::animation::course& ygl::serialize::animatic::course() const
{
	return this->_course;
}

const ygl::animation::interpolation& ygl::serialize::animatic::interpolation() const
{
	return this->_interpolation;
}

std::vector<ygl::animation::keyframe>& ygl::serialize::animatic::keyframe()
{
	return this->_keyframe;
}

ygl::animation::keyframe& ygl::serialize::animatic::keyframe(std::size_t index)
{
	if (index >= this->_keyframe.size())
	{
		std::cerr << "Illegal index '" << index << "', failed" << std::endl;
		exit(0);
	}

	return this->_keyframe[index];
}

const ygl::animation::keyframe& ygl::serialize::animatic::keyframe_at(std::size_t index) const
{
	if (index >= this->_keyframe.size())
	{
		std::cerr << "Illegal index '" << index << "', failed" << std::endl;
		exit(0);
	}

	return this->_keyframe[index];
}
