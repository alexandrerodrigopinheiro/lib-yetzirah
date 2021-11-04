#include "clock/timer.h"

ygl::clock::timer::timer() :
	_play(false),
	_restore(0),
	_initial(0),
	_current(0)
{
}

ygl::clock::timer::timer(const ygl::clock::timer& obj) :
	_play(false),
	_restore(0),
	_initial(0),
	_current(0)
{
	*this = obj;
}

ygl::clock::timer::~timer()
{
}

void ygl::clock::timer::play()
{
	if (this->_play)
	{
		this->_restore = this->ticks();
		return;
	}

	this->_current = this->ticks();
	this->_restore = 0;
}

void ygl::clock::timer::start()
{
	this->_play = true;

	if (this->_restore == 0)
	{
		this->_initial = this->ticks();
		return;
	}

	this->_initial += this->_restore;
	this->_restore = 0;
}

void ygl::clock::timer::stop()
{
	this->_play = false;
	this->_restore = this->ticks();
}

void ygl::clock::timer::reset()
{
	this->_restore = 0;
	this->_initial = this->ticks();
	this->_current = this->_initial;
	this->_play = false;
}

void ygl::clock::timer::replay()
{
	this->_restore = 0;
	this->_initial = this->ticks();
	this->_current = this->_initial;
	this->_play = true;
}

std::size_t ygl::clock::timer::elapsed() const
{
	return this->ticks() - this->_initial;
}

std::size_t ygl::clock::timer::ticks() const
{
	auto now = std::chrono::steady_clock::now();
	auto duration = now.time_since_epoch();
	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

bool ygl::clock::timer::started() const
{
	return this->_play;
}
