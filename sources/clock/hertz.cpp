#include "clock/hertz.h"

ygl::clock::hertz::hertz() :
	_timer(nullptr),
	_frequency(nullptr)
{
}

ygl::clock::hertz::hertz(const ygl::clock::hertz& obj) :
	_timer(nullptr),
	_frequency(nullptr)
{
	*this = obj;
}

ygl::clock::hertz::~hertz()
{
	this->destroy();
}

bool ygl::clock::hertz::initialize(std::size_t fps)
{
	this->_timer     = new ygl::clock::timer();
	this->_frequency = new ygl::clock::frequency();

	this->_frequency->initialize();

	this->_timer->start();

	this->_fps = fps == 0 ? this->get_hertz() : fps;
	this->_latency = ygl::clock::SECOND / this->_fps;

	return true;
}

void ygl::clock::hertz::destroy()
{
	delete _timer;
	delete _frequency;

	this->_timer = nullptr;
	this->_frequency = nullptr;
}

void ygl::clock::hertz::synchronize()
{
	do
	{
		this->_timer->play();
	}
	while (this->_timer->elapsed() < this->_latency);

	this->_frequency->update();
	this->_timer->replay();
}

void ygl::clock::hertz::fps(std::size_t fps)
{
	this->_fps = fps;
	this->_latency = ygl::clock::SECOND / this->_fps;
}

std::size_t ygl::clock::hertz::fps() const
{
	return this->_fps;
}

std::size_t ygl::clock::hertz::latency() const
{
	return this->_latency;
}

std::size_t ygl::clock::hertz::frequency() const
{
	return this->_frequency->get_frequency();
}

std::size_t ygl::clock::hertz::get_hertz()
{
//	int num_sizes;
//	Rotation current_rotation;
	Display* dpy = XOpenDisplay(nullptr);
	Window root = RootWindow(dpy, 0);
//	XRRScreenSize* xrrs = XRRSizes(dpy, 0, &num_sizes);
//	GET CURRENT RESOLUTION AND FREQUENCY
	XRRScreenConfiguration* conf = XRRGetScreenInfo(dpy, root);
//	short current_rate = XRRConfigCurrentRate(conf);
//	SizeID current_size_id = XRRConfigCurrentConfiguration(conf, &current_rotation);
//	int current_width = xrrs[current_size_id].width;
//	int current_height = xrrs[current_size_id].height;

	XCloseDisplay(dpy);

	return (std::size_t)XRRConfigCurrentRate(conf);
}

