	#include "clock/frequency.h"

ygl::clock::frequency::frequency() :
	_timer(NULL),
	_counter(0),
	_frequency(0)
{
}

ygl::clock::frequency::frequency(const ygl::clock::frequency& obj) :
	_timer(NULL),
	_counter(0),
	_frequency(0)
{
	*this = obj;
}

ygl::clock::frequency::~frequency()
{
	this->destroy();
}


bool ygl::clock::frequency::initialize()
{
	this->_timer = new ygl::clock::timer();
	this->_timer->replay();

	return true;
}

void ygl::clock::frequency::destroy()
{
	delete this->_timer;
	this->_timer = NULL;
}

bool ygl::clock::frequency::update()
{
	this->_timer->play();

	if (this->_timer->elapsed() >= ygl::clock::SECOND)
	{
		this->_frequency = this->_counter;
		this->_counter   = 0;

		this->_timer->replay();
	}

	return true;
}

uint64_t ygl::clock::frequency::get_frequency()
{
	this->_counter++;

	return this->_frequency;
}
