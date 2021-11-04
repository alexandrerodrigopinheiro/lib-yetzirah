#include "animation/animator.h"

ygl::animation::animator::animator() :
	_timeline(NULL),
	_name(),
	_course(ygl::animation::course::COURSE_FORWARD),
	_control(ygl::animation::control::CONTROL_SINGLE)
{
}

ygl::animation::animator::animator(const animator& obj) :
	_timeline(NULL),
	_name(),
	_course(ygl::animation::course::COURSE_FORWARD),
	_control(ygl::animation::control::CONTROL_SINGLE)
{
	*this = obj;
}

ygl::animation::animator::~animator()
{
	this->destroy();
}

bool ygl::animation::animator::initialize(std::size_t length, const ygl::animation::course& course, const ygl::animation::control& control)
{
	this->_timeline = new ygl::animation::timeline();
	this->_timeline->initialize(length);
	this->_timeline->course(course);
	this->_timeline->control(control);

	return true;
}

void ygl::animation::animator::destroy()
{
	delete this->_timeline;
	this->_timeline = NULL;
}

void ygl::animation::animator::keyframe(const ygl::animation::keyframe& keyframe)
{
	ygl::animation::frame tmp;

	tmp.message(std::string());
	tmp.spot(keyframe.frame());
	tmp.visible(keyframe.visible());
	tmp.flip(keyframe.flip());
	tmp.color(keyframe.color());
	tmp.pivot(keyframe.pivot());
	tmp.position(keyframe.position());
	tmp.scale(keyframe.scale());
	tmp.rotate(keyframe.rotate());

	this->_frame.push_back(tmp);
}

void ygl::animation::animator::play()
{
	this->_timeline->play();
}

void ygl::animation::animator::start()
{
	this->_timeline->start();
}

void ygl::animation::animator::stop()
{
	this->_timeline->stop();
}

void ygl::animation::animator::reset()
{
	this->_timeline->reset();
}

void ygl::animation::animator::replay()
{
	this->_timeline->replay();
}

bool ygl::animation::animator::started() const
{
	return this->_timeline->started();
	return true;
}

const std::vector<ygl::animation::frame>& ygl::animation::animator::frame() const
{
	return this->_frame;
}

const ygl::animation::frame& ygl::animation::animator::frame(std::size_t index) const
{
	if (index >= this->_frame.size())
	{
		std::cerr << "Illegal index '" << index << "', failed" << std::endl;
		exit(0);
	}

	return this->_frame[index];
}

void ygl::animation::animator::interpolate()
{
//	Interpolation interpolation;
//	std::vector<ygl::animation::frame> frame;
//	if (this->_frame.size() != 0)
//	{
//		for (std::size_t i = 0; i < this->_frame.size() - 1; i++)
//		{
//			interpolation.resolve(this->_frame[i], this->_frame[i + 1]);
//			for (std::size_t l = 0; l < interpolation.get_size(); l++)
//			{
//				frame.push_back(interpolation.get_values(l));
//			}
//			if (i != this->_frame.size() - 2)
//			{
//				frame.pop_back();
//			}
//		}
//		this->_frame.clear();
//		for (std::size_t i = 0; i < frame.size(); i++)
//		{
//			this->_frame.push_back(interpolation.get_values(i));
//		}
//	}
}
