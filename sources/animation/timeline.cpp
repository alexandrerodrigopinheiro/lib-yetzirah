#include "animation/timeline.h"

ygl::animation::timeline::timeline() :
	_framer(NULL),
	_timeline({ 0, 0 }),
	_course(ygl::animation::course::COURSE_FORWARD),
	_control(ygl::animation::control::CONTROL_SINGLE),
	_frame_per_second(ygl::clock::FPS),
	_frame_rate(ygl::clock::SECOND)
{
}

ygl::animation::timeline::timeline(const ygl::animation::timeline& obj) :
	_framer(NULL),
	_timeline({ 0, 0 }),
	_course(ygl::animation::course::COURSE_FORWARD),
	_control(ygl::animation::control::CONTROL_SINGLE),
	_frame_per_second(ygl::clock::FPS),
	_frame_rate(ygl::clock::SECOND)
{
	*this = obj;
}

ygl::animation::timeline::~timeline()
{
	this->destroy();
}

bool ygl::animation::timeline::initialize(std::size_t length)
{
	this->_timeline         = ygl::math::rangeui( 0, length );
	this->_control          = ygl::animation::control::CONTROL_SINGLE;
	this->_frame_per_second = ygl::clock::FPS;;
	this->_frame_rate       = ygl::clock::SECOND;

	this->_framer = new ygl::animation::framer();
	this->_framer->initialize(this->_frame_rate / this->_frame_per_second);
	this->_framer->stop();

	return true;
}

bool ygl::animation::timeline::initialize(std::size_t begin, std::size_t end)
{
	this->_timeline         = ygl::math::rangeui( begin, end );
	this->_control          = ygl::animation::control::CONTROL_SINGLE;
	this->_frame_per_second = ygl::clock::FPS;
	this->_frame_rate       = ygl::clock::SECOND;

	this->_framer = new ygl::animation::framer();
	this->_framer->initialize(this->_frame_rate / this->_frame_per_second);
	this->_framer->stop();

	return true;
}

bool ygl::animation::timeline::initialize(std::size_t begin, std::size_t end, std::size_t fps)
{
	this->_timeline         = ygl::math::rangeui( begin, end );
	this->_control          = ygl::animation::control::CONTROL_SINGLE;
	this->_frame_per_second = fps;
	this->_frame_rate       = ygl::clock::SECOND;

	this->_framer = new ygl::animation::framer();

	if (!this->_framer->initialize(this->_frame_rate / this->_frame_per_second))
	{
		std::cerr << "Timeline: Cannot be initialized, failed" << std::endl;

		return false;
	}

	this->_framer->stop();

	return true;
}

void ygl::animation::timeline::destroy()
{
	delete this->_framer;
	this->_framer = NULL;
}

void ygl::animation::timeline::play()
{
	this->_framer->play();

	if (this->_framer->bound())
	{
		switch (this->_control)
		{
			case ygl::animation::control::CONTROL_SINGLE:
			{
				this->_framer->frame(ygl::math::clamp(this->_framer->frame(), this->_timeline.begin(), this->_timeline.end()));

				break;
			}
			case ygl::animation::control::CONTROL_CYCLE:
			{
				this->_framer->frame(ygl::math::wrap(this->_framer->frame(), this->_timeline.begin(), this->_timeline.end()));

				break;
			}
			case ygl::animation::control::CONTROL_PINGPONG:
			{
				this->_framer->frame(ygl::math::clamp(this->_framer->frame(), this->_timeline.begin(), this->_timeline.end()));

				if (this->_framer->frame() == this->_timeline.end())
				{
					this->_framer->course(ygl::animation::course::COURSE_BACKWARD);
				}
				else if (this->_framer->frame() == this->_timeline.begin())
				{
					this->_framer->course(ygl::animation::course::COURSE_FORWARD);
				}

				break;
			}
			case ygl::animation::control::CONTROL_ELASTIC:
			{
				/* ... -> <- ... */
				this->_framer->frame(ygl::math::clamp(this->_framer->frame(), this->_timeline.begin(), this->_timeline.end()));

				if (this->_framer->frame() == this->_timeline.end())
				{
					this->_framer->course(ygl::animation::course::COURSE_BACKWARD);
				}
				else if (this->_framer->frame() == this->_timeline.begin())
				{
					this->_framer->course(ygl::animation::course::COURSE_FORWARD);
				}

				break;
			}
		}
	}
}

void ygl::animation::timeline::start()
{
	this->_framer->start();
}

void ygl::animation::timeline::stop()
{
	this->_framer->stop();
}

void ygl::animation::timeline::reset()
{
	this->_framer->reset();
}

void ygl::animation::timeline::replay()
{
	this->_framer->replay();
}

bool ygl::animation::timeline::started() const
{
	return this->_framer->started();
}

void ygl::animation::timeline::begin()
{
	this->_framer->frame(0);
}

void ygl::animation::timeline::end()
{
	this->_framer->frame(this->_timeline.end());
}

bool ygl::animation::timeline::bounde() const
{
	return (this->_framer->frame() == this->_timeline.end());
}

bool ygl::animation::timeline::onset() const
{
	return (this->_framer->frame() == this->_timeline.begin());
}

void ygl::animation::timeline::course(const ygl::animation::course& course)
{
	this->_course = course;
	this->_framer->course(course);
}

void ygl::animation::timeline::control(const ygl::animation::control& control)
{
	this->_control = control;
}

void ygl::animation::timeline::fps(std::size_t frame_per_second)
{
	this->_frame_per_second = frame_per_second;

	this->_framer->expiry(this->_frame_rate / this->_frame_per_second);
}

void ygl::animation::timeline::frame_rate(std::size_t frame_rate)
{
	this->_frame_rate = frame_rate;

	this->_framer->expiry(this->_frame_rate / this->_frame_per_second);
}

void ygl::animation::timeline::frame(std::size_t frame)
{
	this->_framer->frame(frame);
}

std::size_t ygl::animation::timeline::length() const
{
	return this->_timeline.end();
}

const ygl::animation::course& ygl::animation::timeline::course() const
{
	return this->_course;
}

const ygl::animation::control& ygl::animation::timeline::control() const
{
	return this->_control;
}

std::size_t ygl::animation::timeline::fps() const
{
	return this->_frame_per_second;
}

std::size_t ygl::animation::timeline::frame_rate() const
{
	return this->_frame_rate;
}

std::size_t ygl::animation::timeline::frame() const
{
	return this->_framer->frame();
}

std::ostream& operator<<(std::ostream& stream, const ygl::animation::timeline& timeline)
{
	stream << "TIMELINE {";
	stream << " " << timeline.frame();
//	stream << " " << timeline._timeline;
	stream << " " << timeline.course();
	stream << " " << timeline.control();
	stream << " " << timeline.fps();
	stream << " " << timeline.frame_rate();
	stream << " " << timeline.started();
	stream << " }";

	return stream;
}

std::istream& operator>>(std::istream& stream, ygl::animation::timeline& timeline)
{
	std::string             garbage;
	std::size_t                    frame;
//	ygl::math::rangeui                 timeline;
	ygl::animation::course  course;
	ygl::animation::control control;
	std::size_t                    frame_per_second;
	std::size_t                    frame_rate;
	bool                    play;

	stream >> garbage >> garbage;
	stream >> frame;
//	stream >> timeline;
	stream >> course;
	stream >> control;
	stream >> frame_per_second;
	stream >> frame_rate;
	stream >> play;
	stream >> garbage;

	timeline.frame(frame);
//	timeline.timeline(timeline);
	timeline.course(course);
	timeline.control(control);
	timeline.fps(frame_per_second);
	timeline.frame_rate(frame_rate);
	(play ? timeline.start() : timeline.stop());

	return stream;
}
