#include "animation/framer.h"

ygl::animation::framer::framer() :
	_timer(NULL),
	_course(ygl::animation::course::COURSE_FORWARD),
	_expiry(0),
	_frame(0),
	_play(false),
	_bound(false)
{
}

ygl::animation::framer::framer(const framer& obj) :
	_timer(NULL),
	_course(ygl::animation::course::COURSE_FORWARD),
	_expiry(0),
	_frame(0),
	_play(false),
	_bound(false)
{
	*this = obj;
}

ygl::animation::framer::~framer()
{
	this->destroy();
}

bool ygl::animation::framer::initialize(std::size_t expired)
{
	this->_timer  = new ygl::clock::timer();
	this->_course = ygl::animation::course::COURSE_FORWARD;
	this->_expiry = expired;
	this->_frame  = 0;

	this->reset();

	return true;
}

void ygl::animation::framer::destroy()
{
	delete this->_timer;
	this->_timer = NULL;
}

void ygl::animation::framer::play()
{
	this->_timer->play();

	if (this->_play)
	{
		std::size_t expiry = this->_expiry;
		if (this->_timer->elapsed() >= expiry)
		{
			int max = this->_frame + 1;
			switch (this->_course)
			{
				case ygl::animation::course::COURSE_FORWARD:
				{
					this->_frame = ygl::math::clamp(++this->_frame, 0, max);
					break;
				}
				case ygl::animation::course::COURSE_BACKWARD:
				{
					this->_frame = ygl::math::clamp(--this->_frame, 0, max);
					break;
				}
			}

			this->_timer->replay();

			this->_bound = true;
		}
		else
		{
			this->_bound = false;
		}
	}
}

void ygl::animation::framer::start()
{
	this->_timer->start();

	this->_play = true;
}

void ygl::animation::framer::stop()
{
	this->_timer->stop();

	this->_play = false;
}

void ygl::animation::framer::reset()
{
	this->_timer->reset();
}

void ygl::animation::framer::replay()
{
	this->_timer->replay();

	this->_frame = 0;
	this->_play = true;
	this->_bound = false;
}

bool ygl::animation::framer::bound() const
{
	return this->_bound;
}

bool ygl::animation::framer::started() const
{
	return this->_play;
}

void ygl::animation::framer::course(const ygl::animation::course& course)
{
	this->_course = course;
}

void ygl::animation::framer::frame(std::size_t frame)
{
	this->_frame = frame;
}

void ygl::animation::framer::expiry(std::size_t expired)
{
	this->_expiry = expired;
}

const ygl::animation::course& ygl::animation::framer::course() const
{
	return this->_course;
}

std::size_t ygl::animation::framer::frame() const
{
	return this->_frame;
}

std::size_t ygl::animation::framer::expiry() const
{
	return this->_expiry;
}
