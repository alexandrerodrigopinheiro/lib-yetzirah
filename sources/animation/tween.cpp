#include "animation/tween.h"

ygl::animation::tween::tween() :
	_timeline(),
	_title(),
	_measure(),
	_message(),
	_weight(),
	_visible(),
	_wireframe(),
	_flip(),
	_color(),
	_opacity(),
	_orientation(),
	_pivot(),
	_position(),
	_scale(),
	_rotate(),
	_size()
{
}

ygl::animation::tween::tween(const ygl::animation::tween& obj) :
	_timeline(),
	_title(),
	_measure(),
	_message(),
	_weight(),
	_visible(),
	_wireframe(),
	_flip(),
	_color(),
	_opacity(),
	_orientation(),
	_pivot(),
	_position(),
	_scale(),
	_rotate(),
	_size()
{
	*this = obj;
}

ygl::animation::tween::tween(std::size_t timeline) :
	_timeline(),
	_title(),
	_measure(),
	_message(),
	_weight(),
	_visible(),
	_wireframe(),
	_flip(),
	_color(),
	_opacity(),
	_orientation(),
	_pivot(),
	_position(),
	_scale(),
	_rotate(),
	_size()
{
	this->initialize(timeline);
}

ygl::animation::tween::tween(const std::string& title, std::size_t timeline) :
	_timeline(),
	_title(),
	_measure(),
	_message(),
	_weight(),
	_visible(),
	_wireframe(),
	_flip(),
	_color(),
	_opacity(),
	_orientation(),
	_pivot(),
	_position(),
	_scale(),
	_rotate(),
	_size()
{
	this->initialize(title, timeline);
}

ygl::animation::tween::tween(const std::string& title, std::size_t timeline, std::size_t fps) :
	_timeline(),
	_title(),
	_measure(),
	_message(),
	_weight(),
	_visible(),
	_wireframe(),
	_flip(),
	_color(),
	_opacity(),
	_orientation(),
	_pivot(),
	_position(),
	_scale(),
	_rotate(),
	_size()
{
	this->initialize(title, timeline, fps);
}

ygl::animation::tween::~tween()
{
	this->destroy();
}

bool ygl::animation::tween::initialize(std::size_t timeline)
{
	if (!this->_timeline.initialize(0, timeline))
	{
		return false;
	}

	this->_timeline.stop();

	return true;
}

bool ygl::animation::tween::initialize(const std::string& title, std::size_t timeline)
{
	if (!this->_timeline.initialize(0, timeline))
	{
		return false;
	}

	this->_timeline.stop();

	this->_title = title;

	return true;
}

bool ygl::animation::tween::initialize(const std::string& title, std::size_t timeline, std::size_t fps)
{
	if (!this->_timeline.initialize(0, timeline, fps))
	{
		return false;
	}

	this->_timeline.stop();

	this->_title = title;

	return true;
}

void ygl::animation::tween::destroy()
{
	this->_title.clear();
	this->_timeline.destroy();
	this->_visible.clear();
	this->_wireframe.clear();
	this->_flip.clear();
	this->_color.clear();
	this->_opacity.clear();
	this->_orientation.clear();
	this->_pivot.clear();
	this->_position.clear();
	this->_scale.clear();
	this->_rotate.clear();
	this->_size.clear();
}

void ygl::animation::tween::running()
{
	this->_timeline.play();
}

void ygl::animation::tween::start()
{
	this->_timeline.start();
}

void ygl::animation::tween::pause()
{
	this->_timeline.stop();
}

void ygl::animation::tween::restart()
{
	this->_timeline.replay();
}

void ygl::animation::tween::reset()
{
	this->_timeline.reset();
}

bool ygl::animation::tween::started() const
{
	return this->_timeline.started();
}

bool ygl::animation::tween::border() const
{
	return this->_timeline.bounde();
}

bool ygl::animation::tween::onset() const
{
	return this->_timeline.onset();
}

std::size_t ygl::animation::tween::length() const
{
	return this->_timeline.length();
}

std::size_t ygl::animation::tween::moment() const
{
	return this->_timeline.frame();
}

void ygl::animation::tween::course(const ygl::animation::course& course)
{
	this->_timeline.course(course);
}

void ygl::animation::tween::control(const ygl::animation::control& control)
{
	this->_timeline.control(control);
}

const ygl::animation::course& ygl::animation::tween::course() const
{
	return this->_timeline.course();
}

const ygl::animation::control& ygl::animation::tween::control() const
{
	return this->_timeline.control();
}

void ygl::animation::tween::attach_measure(std::size_t keyframe, std::size_t measure)
{
	this->_measure.push_back(key<std::size_t>(keyframe, measure));
}

void ygl::animation::tween::attach_message(std::size_t keyframe, std::string& message)
{
	this->_message.push_back(key<std::string>(keyframe, message));
}

void ygl::animation::tween::attach_weight(std::size_t keyframe, const ygl::graphic::weight& weight)
{
	this->_weight.push_back(key<ygl::graphic::weight>(keyframe, weight));
}

void ygl::animation::tween::attach_spot(std::size_t keyframe, std::size_t spot)
{
	this->_spot.push_back(key<std::size_t>(keyframe, spot));
}

void ygl::animation::tween::attach_visible(std::size_t keyframe, bool visible)
{
	this->_visible.push_back(key<bool>(keyframe, visible));
}

void ygl::animation::tween::attach_wireframe(std::size_t keyframe, bool wireframe)
{
	this->_wireframe.push_back(key<bool>(keyframe, wireframe));
}

void ygl::animation::tween::attach_flip(std::size_t keyframe, const ygl::graphic::flip& flip)
{
	this->_flip.push_back(key<ygl::graphic::flip>(keyframe, flip));
}

void ygl::animation::tween::attach_color(std::size_t keyframe, const ygl::math::colord& color)
{
	this->_color.push_back(key<ygl::math::colord>(keyframe, color));
}

void ygl::animation::tween::attach_opacity(std::size_t keyframe, double opacity)
{
	this->_opacity.push_back(key<double>(keyframe, opacity));
}

void ygl::animation::tween::attach_orientation(std::size_t keyframe, const ygl::graphic::orientation& orientation)
{
	this->_orientation.push_back(key<ygl::graphic::orientation>(keyframe, orientation));
}

void ygl::animation::tween::attach_pivot(std::size_t keyframe, const ygl::math::pointd& pivot)
{
	this->_pivot.push_back(key<ygl::math::pointd>(keyframe, pivot));
}

void ygl::animation::tween::attach_position(std::size_t keyframe, const ygl::math::pointd& position)
{
	this->_position.push_back(key<ygl::math::pointd>(keyframe, position));
}

void ygl::animation::tween::attach_scale(std::size_t keyframe, const ygl::math::sized& scale)
{
	this->_scale.push_back(key<ygl::math::sized>(keyframe, scale));
}

void ygl::animation::tween::attach_rotate(std::size_t keyframe, const ygl::math::rotated& rotate)
{
	this->_rotate.push_back(key<ygl::math::rotated>(keyframe, rotate));
}

void ygl::animation::tween::attach_size(std::size_t keyframe, const ygl::math::sized& size)
{
	this->_size.push_back(key<ygl::math::sized>(keyframe, size));
}

void ygl::animation::tween::clear_tweening()
{
	this->_measure.clear();
	this->_message.clear();
	this->_weight.clear();
	this->_spot.clear();
	this->_visible.clear();
	this->_wireframe.clear();
	this->_color.clear();
	this->_opacity.clear();
	this->_orientation.clear();
	this->_pivot.clear();
	this->_position.clear();
	this->_scale.clear();
	this->_rotate.clear();
	this->_size.clear();
}

void ygl::animation::tween::clear_measure()
{
	this->_measure.clear();
}

void ygl::animation::tween::clear_message()
{
	this->_message.clear();
}

void ygl::animation::tween::clear_weight()
{
	this->_weight.clear();
}

void ygl::animation::tween::clear_spot()
{
	this->_spot.clear();
}

void ygl::animation::tween::clear_visible()
{
	this->_visible.clear();
}

void ygl::animation::tween::clear_wireframe()
{
	this->_wireframe.clear();
}

void ygl::animation::tween::clear_flip()
{
	this->_flip.clear();
}

void ygl::animation::tween::clear_color()
{
	this->_color.clear();
}

void ygl::animation::tween::clear_opacity()
{
	this->_opacity.clear();
}

void ygl::animation::tween::clear_orientation()
{
	this->_orientation.clear();
}

void ygl::animation::tween::clear_pivot()
{
	this->_pivot.clear();
}

void ygl::animation::tween::clear_position()
{
	this->_position.clear();
}

void ygl::animation::tween::clear_scale()
{
	this->_scale.clear();
}

void ygl::animation::tween::clear_rotate()
{
	this->_rotate.clear();
}

void ygl::animation::tween::clear_size()
{
	this->_size.clear();
}

std::size_t ygl::animation::tween::size_tweening() const
{
	return this->_timeline.length();
}

std::size_t ygl::animation::tween::size_measure() const
{
	return this->_measure.size();
}

std::size_t ygl::animation::tween::size_message() const
{
	return this->_message.size();
}

std::size_t ygl::animation::tween::size_weight() const
{
	return this->_weight.size();
}

std::size_t ygl::animation::tween::size_spot() const
{
	return this->_spot.size();
}

std::size_t ygl::animation::tween::size_visible() const
{
	return this->_visible.size();
}

std::size_t ygl::animation::tween::size_wireframe() const
{
	return this->_wireframe.size();
}

std::size_t ygl::animation::tween::size_flip() const
{
	return this->_flip.size();
}

std::size_t ygl::animation::tween::size_color() const
{
	return this->_color.size();
}

std::size_t ygl::animation::tween::size_opacity() const
{
	return this->_opacity.size();
}

std::size_t ygl::animation::tween::size_orientation() const
{
	return this->_orientation.size();
}

std::size_t ygl::animation::tween::size_pivot() const
{
	return this->_pivot.size();
}

std::size_t ygl::animation::tween::size_position() const
{
	return this->_position.size();
}

std::size_t ygl::animation::tween::size_scale() const
{
	return this->_scale.size();
}

std::size_t ygl::animation::tween::size_rotate() const
{
	return this->_rotate.size();
}

std::size_t ygl::animation::tween::size_size() const
{
	return this->_size.size();
}

const ygl::animation::key<std::size_t>& ygl::animation::tween::keyframe_measure(std::size_t index) const
{
	if (index >= this->_measure.size())
	{
		std::cerr << "Tweening: Illegal index at measure as '" << index << "' in size '" << this->_measure.size() << "', failed" << std::endl;
	}

	return this->_measure[index];
}

const ygl::animation::key<std::string>& ygl::animation::tween::keyframe_message(std::size_t index) const
{
	if (index >= this->_message.size())
	{
		std::cerr << "Tweening: Illegal index at message as '" << index << "' in size '" << this->_message.size() << "', failed" << std::endl;
	}

	return this->_message[index];
}

const ygl::animation::key<ygl::graphic::weight>& ygl::animation::tween::keyframe_weight(std::size_t index) const
{
	if (index >= this->_weight.size())
	{
		std::cerr << "Tweening: Illegal index at weight as '" << index << "' in size '" << this->_weight.size() << "', failed" << std::endl;
	}

	return this->_weight[index];
}

const ygl::animation::key<std::size_t>& ygl::animation::tween::keyframe_spot(std::size_t index) const
{
	if (index >= this->_spot.size())
	{
		std::cerr << "Tweening: Illegal index at spot as '" << index << "' in size '" << this->_spot.size() << "', failed" << std::endl;
	}

	return this->_spot[index];
}

const ygl::animation::key<bool>& ygl::animation::tween::keyframe_visible(std::size_t index) const
{
	if (index >= this->_visible.size())
	{
		std::cerr << "Tweening: Illegal index at visible as '" << index << "' in size '" << this->_visible.size() << "', failed" << std::endl;
	}

	return this->_visible[index];
}

const ygl::animation::key<bool>& ygl::animation::tween::keyframe_wireframe(std::size_t index) const
{
	if (index >= this->_wireframe.size())
	{
		std::cerr << "Tweening: Illegal index at wireframe as '" << index << "' in size '" << this->_wireframe.size() << "', failed" << std::endl;
	}

	return this->_wireframe[index];
}

const ygl::animation::key<ygl::graphic::flip>& ygl::animation::tween::keyframe_flip(std::size_t index) const
{
	if (index >= this->_flip.size())
	{
		std::cerr << "Tweening: Illegal index at flip as '" << index << "' in size '" << this->_flip.size() << "', failed" << std::endl;
	}

	return this->_flip[index];
}

const ygl::animation::key<ygl::math::colord>& ygl::animation::tween::keyframe_color(std::size_t index) const
{
	if (index >= this->_color.size())
	{
		std::cerr << "Tweening: Illegal index at color as '" << index << "' in size '" << this->_color.size() << "', failed" << std::endl;
	}

	return this->_color[index];
}

const ygl::animation::key<double>& ygl::animation::tween::keyframe_opacity(std::size_t index) const
{
	if (index >= this->_opacity.size())
	{
		std::cerr << "Tweening: Illegal index at opacity as '" << index << "' in size '" << this->_opacity.size() << "', failed" << std::endl;
	}

	return this->_opacity[index];
}

const ygl::animation::key<ygl::graphic::orientation>& ygl::animation::tween::keyframe_orientation(std::size_t index) const
{
	if (index >= this->_orientation.size())
	{
		std::cerr << "Tweening: Illegal index at orientation as '" << index << "' in size '" << this->_orientation.size() << "', failed" << std::endl;
	}

	return this->_orientation[index];
}

const ygl::animation::key<ygl::math::pointd>& ygl::animation::tween::keyframe_pivot(std::size_t index) const
{
	if (index >= this->_pivot.size())
	{
		std::cerr << "Tweening: Illegal index at pivot as '" << index << "' in size '" << this->_pivot.size() << "', failed" << std::endl;
	}

	return this->_pivot[index];
}

const ygl::animation::key<ygl::math::pointd>& ygl::animation::tween::keyframe_position(std::size_t index) const
{
	if (index >= this->_position.size())
	{
		std::cerr << "Tweening: Illegal index at position as '" << index << "' in size '" << this->_position.size() << "', failed" << std::endl;
	}

	return this->_position[index];
}

const ygl::animation::key<ygl::math::sized>& ygl::animation::tween::keyframe_scale(std::size_t index) const
{
	if (index >= this->_scale.size())
	{
		std::cerr << "Tweening: Illegal index at scale as '" << index << "' in size '" << this->_scale.size() << "', failed" << std::endl;
	}

	return this->_scale[index];
}

const ygl::animation::key<ygl::math::rotated>& ygl::animation::tween::keyframe_rotate(std::size_t index) const
{
	if (index >= this->_rotate.size())
	{
		std::cerr << "Tweening: Illegal index at rotate as '" << index << "' in size '" << this->_rotate.size() << "', failed" << std::endl;
	}

	return this->_rotate[index];
}

const ygl::animation::key<ygl::math::sized>& ygl::animation::tween::keyframe_size(std::size_t index) const
{
	if (index >= this->_size.size())
	{
		std::cerr << "Tweening: Illegal index at size as '" << index << "' in size '" << this->_size.size() << "', failed" << std::endl;
	}

	return this->_size[index];
}

bool ygl::animation::tween::has_tweening()
{
	bool m_has_tweeing = false;

	m_has_tweeing = this->has_measure()     ? true : m_has_tweeing;
	m_has_tweeing = this->has_message()     ? true : m_has_tweeing;
	m_has_tweeing = this->has_weight()      ? true : m_has_tweeing;
	m_has_tweeing = this->has_spot()       ? true : m_has_tweeing;
	m_has_tweeing = this->has_visible()     ? true : m_has_tweeing;
	m_has_tweeing = this->has_wireframe()   ? true : m_has_tweeing;
	m_has_tweeing = this->has_color()       ? true : m_has_tweeing;
	m_has_tweeing = this->has_opacity()     ? true : m_has_tweeing;
	m_has_tweeing = this->has_orientation() ? true : m_has_tweeing;
	m_has_tweeing = this->has_pivot()       ? true : m_has_tweeing;
	m_has_tweeing = this->has_position()    ? true : m_has_tweeing;
	m_has_tweeing = this->has_scale()       ? true : m_has_tweeing;
	m_has_tweeing = this->has_rotate()    ? true : m_has_tweeing;
	m_has_tweeing = this->has_size()        ? true : m_has_tweeing;

	return m_has_tweeing;
}

bool ygl::animation::tween::has_measure() const
{
	return this->_measure.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_message() const
{
	return this->_message.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_weight() const
{
	return this->_weight.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_spot() const
{
	return this->_spot.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_visible() const
{
	return this->_visible.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_wireframe() const
{
	return this->_wireframe.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_flip() const
{
	return this->_flip.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_color() const
{
	return this->_color.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_opacity() const
{
	return this->_opacity.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_orientation() const
{
	return this->_orientation.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_pivot() const
{
	return this->_pivot.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_position() const
{
	return this->_position.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_scale() const
{
	return this->_scale.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_rotate() const
{
	return this->_rotate.size() == 0 ? false : true;
}

bool ygl::animation::tween::has_size() const
{
	return this->_size.size() == 0 ? false : true;
}

std::size_t ygl::animation::tween::measure()
{
	if (this->_measure.size() < 2)
	{
		std::cerr << "Tweening keyframe measure error size at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value;
	double m_max_value;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_measure.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_measure[i].frame() && m_frame <= this->_measure[n].frame())
		{
			m_min_frame = this->_measure[i].frame();
			m_max_frame = this->_measure[n].frame();
			m_min_value = this->_measure[i].value();
			m_max_value = this->_measure[n].value();
			m_tween  = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening measure values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::size_t m_measure = ygl::animation::tweening(m_min_value, m_max_value, m_min_frame, m_max_frame, m_frame);

	return m_measure;
}

std::string ygl::animation::tween::message()
{
	if (this->_message.size() < 2)
	{
		std::cerr << "Tweening keyframe message error size at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::string m_message;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_message.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_message[i].frame() && m_frame <= this->_message[n].frame())
		{
			m_message  = this->_message[i].value();
			m_tween = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening message values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	return m_message;
}

ygl::graphic::weight ygl::animation::tween::weight()
{
	if (this->_weight.size() < 2)
	{
		std::cerr << "Tweening keyframe weight error size at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	ygl::graphic::weight m_weight;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_weight.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_weight[i].frame() && m_frame <= this->_weight[n].frame())
		{
			m_weight   = this->_weight[i].value();
			m_tween = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening weight values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	return m_weight;
}

std::size_t ygl::animation::tween::spot()
{
	if (this->_spot.size() < 2)
	{
		std::cerr << "Tweening keyframe frame error size at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value;
	double m_max_value;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_spot.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_spot[i].frame() && m_frame <= this->_spot[n].frame())
		{
			m_min_frame = this->_spot[i].frame();
			m_max_frame = this->_spot[n].frame();
			m_min_value = this->_spot[i].value();
			m_max_value = this->_spot[n].value();
			m_tween  = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening frame values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::size_t m_framer = ygl::animation::tweening(m_min_value, m_max_value, m_min_frame, m_max_frame, m_frame);

	return m_framer;
}

bool ygl::animation::tween::visible()
{
	if (this->_visible.size() < 2)
	{
		std::cerr << "Tweening keyframe visible error size at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	bool m_visible;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_visible.size() - 1;
	bool m_tween     = false;
	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame == this->_visible[i].frame())
		{
			return m_visible = this->_visible[i].value();
		}
		else if (m_frame == this->_visible[n].frame())
		{
			return m_visible = this->_visible[n].value();
		}
		else if (m_frame > this->_visible[i].frame() && m_frame < this->_visible[n].frame())
		{
			m_min_frame = this->_visible[i].frame();
			m_max_frame = this->_visible[n].frame();
			m_visible   = this->_visible[i].value();
			m_tween  = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening visible values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	if (m_frame < m_min_frame || m_frame > m_max_frame)
	{
		std::cerr << "Tweening frame out of range visible at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	return m_visible;
}

bool ygl::animation::tween::wireframe()
{
	if (this->_wireframe.size() < 2)
	{
		std::cerr << "Tweening keyframe wireframe error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;
;
	bool m_wireframe;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_wireframe.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_wireframe[i].frame() && m_frame <= this->_wireframe[n].frame())
		{
			m_min_frame = this->_wireframe[i].frame();
			m_max_frame = this->_wireframe[n].frame();
			m_wireframe = this->_wireframe[i].value();
			m_tween  = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening wireframe values acquisition error at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	if (m_frame < m_min_frame || m_frame > m_max_frame)
	{
		std::cerr << "Tweening frame out of range wireframe at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	return m_wireframe;
}

ygl::graphic::flip ygl::animation::tween::flip()
{
	if (this->_flip.size() < 2)
	{
		std::cerr << "Tweening keyframe flip error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	ygl::graphic::flip m_flip;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_flip.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_flip[i].frame() && m_frame <= this->_flip[n].frame())
		{
			m_flip     = this->_flip[i].value();
			m_tween = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening flip values acquisition error at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	return m_flip;
}

ygl::math::colord ygl::animation::tween::color()
{
	if (this->_color.size() < 2)
	{
		std::cerr << "Tweening keyframe color error size at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value_r;
	double m_max_value_r;
	double m_min_value_g;
	double m_max_value_g;
	double m_min_value_b;
	double m_max_value_b;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_color.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_color[i].frame() && m_frame <= this->_color[n].frame())
		{
			m_min_frame   = this->_color[i].frame();
			m_max_frame   = this->_color[n].frame();
			m_min_value_r = this->_color[i].value().r();
			m_max_value_r = this->_color[n].value().r();
			m_min_value_g = this->_color[i].value().g();
			m_max_value_g = this->_color[n].value().g();
			m_min_value_b = this->_color[i].value().b();
			m_max_value_b = this->_color[n].value().b();
			m_tween    = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening color values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	double m_r = ygl::animation::tweening(m_min_value_r, m_max_value_r, m_min_frame, m_max_frame, m_frame);
	double m_g = ygl::animation::tweening(m_min_value_g, m_max_value_g, m_min_frame, m_max_frame, m_frame);
	double m_b = ygl::animation::tweening(m_min_value_b, m_max_value_b, m_min_frame, m_max_frame, m_frame);

	return ygl::math::colord(m_r, m_g, m_b);
}

double ygl::animation::tween::opacity()
{
	if (this->_opacity.size() < 2)
	{
		std::cerr << "Tweening keyframe opacity error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value;
	double m_max_value;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_opacity.size() - 1;

	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_opacity[i].frame() && m_frame <= this->_opacity[n].frame())
		{
			m_min_frame = this->_opacity[i].frame();
			m_max_frame = this->_opacity[n].frame();
			m_min_value = this->_opacity[i].value();
			m_max_value = this->_opacity[n].value();
			m_tween  = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening opacity values acquisition error at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	double m_opacity = ygl::animation::tweening(m_min_value, m_max_value, m_min_frame, m_max_frame, m_frame);

	return m_opacity;
}

ygl::graphic::orientation ygl::animation::tween::orientation()
{
	if (this->_orientation.size() < 2)
	{
		std::cerr << "Tweening keyframe orientation error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	ygl::graphic::orientation m_orientation;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_orientation.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_orientation[i].frame() && m_frame <= this->_orientation[n].frame())
		{
			m_orientation = this->_orientation[i].value();
			m_tween    = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening orientation values acquisition error at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	return m_orientation;
}

ygl::math::pointd ygl::animation::tween::pivot()
{
	if (this->_pivot.size() < 2)
	{
		std::cerr << "Tweening keyframe pivot error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value_x;
	double m_max_value_x;
	double m_min_value_y;
	double m_max_value_y;
	double m_min_value_z;
	double m_max_value_z;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_pivot.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_pivot[i].frame() && m_frame <= this->_pivot[n].frame())
		{
			m_min_frame   = this->_pivot[i].frame();
			m_max_frame   = this->_pivot[n].frame();
			m_min_value_x = this->_pivot[i].value().x();
			m_max_value_x = this->_pivot[n].value().x();
			m_min_value_y = this->_pivot[i].value().y();
			m_max_value_y = this->_pivot[n].value().y();
			m_min_value_z = this->_pivot[i].value().z();
			m_max_value_z = this->_pivot[n].value().z();
			m_tween    = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening pivot values acquisition error at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	double m_x = ygl::animation::tweening(m_min_value_x, m_max_value_x, m_min_frame, m_max_frame, m_frame);
	double m_y = ygl::animation::tweening(m_min_value_y, m_max_value_y, m_min_frame, m_max_frame, m_frame);
	double m_z = ygl::animation::tweening(m_min_value_z, m_max_value_z, m_min_frame, m_max_frame, m_frame);

	return ygl::math::pointd(m_x, m_y, m_z);
}

ygl::math::pointd ygl::animation::tween::position()
{
	if (this->_position.size() < 2)
	{
		std::cerr << "Tweening keyframe position error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value_x;
	double m_max_value_x;
	double m_min_value_y;
	double m_max_value_y;
	double m_min_value_z;
	double m_max_value_z;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_position.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_position[i].frame() && m_frame <= this->_position[n].frame())
		{
			m_min_frame   = this->_position[i].frame();
			m_max_frame   = this->_position[n].frame();
			m_min_value_x = this->_position[i].value().x();
			m_max_value_x = this->_position[n].value().x();
			m_min_value_y = this->_position[i].value().y();
			m_max_value_y = this->_position[n].value().y();
			m_min_value_z = this->_position[i].value().z();
			m_max_value_z = this->_position[n].value().z();
			m_tween    = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening position values acquisition error at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	double m_x = ygl::animation::tweening(m_min_value_x, m_max_value_x, m_min_frame, m_max_frame, m_frame);
	double m_y = ygl::animation::tweening(m_min_value_y, m_max_value_y, m_min_frame, m_max_frame, m_frame);
	double m_z = ygl::animation::tweening(m_min_value_z, m_max_value_z, m_min_frame, m_max_frame, m_frame);

	return ygl::math::pointd(m_x, m_y, m_z);
}

ygl::math::sized ygl::animation::tween::scale()
{
	if (this->_scale.size() < 2)
	{
		std::cerr << "Tweening keyframe scale error size at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value_w;
	double m_max_value_w;
	double m_min_value_h;
	double m_max_value_h;
	double m_min_value_l;
	double m_max_value_l;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_scale.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_scale[i].frame() && m_frame <= this->_scale[n].frame())
		{
			m_min_frame   = this->_scale[i].frame();
			m_max_frame   = this->_scale[n].frame();
			m_min_value_w = this->_scale[i].value().w();
			m_max_value_w = this->_scale[n].value().w();
			m_min_value_h = this->_scale[i].value().h();
			m_max_value_h = this->_scale[n].value().h();
			m_min_value_l = this->_scale[i].value().l();
			m_max_value_l = this->_scale[n].value().l();
			m_tween    = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening scale values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	double m_w = ygl::animation::tweening(m_min_value_w, m_max_value_w, m_min_frame, m_max_frame, m_frame);
	double m_h = ygl::animation::tweening(m_min_value_h, m_max_value_h, m_min_frame, m_max_frame, m_frame);
	double m_l = ygl::animation::tweening(m_min_value_l, m_max_value_l, m_min_frame, m_max_frame, m_frame);

	return ygl::math::sized(m_w, m_h, m_l);
}

ygl::math::rotated ygl::animation::tween::rotate()
{
	if (this->_rotate.size() < 2)
	{
		std::cerr << "Tweening keyframe rotate error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value_h;
	double m_max_value_h;
	double m_min_value_p;
	double m_max_value_p;
	double m_min_value_b;
	double m_max_value_b;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_rotate.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_rotate[i].frame() && m_frame <= this->_rotate[n].frame())
		{
			m_min_frame   = this->_rotate[i].frame();
			m_max_frame   = this->_rotate[n].frame();
			m_min_value_h = this->_rotate[i].value().h();
			m_max_value_h = this->_rotate[n].value().h();
			m_min_value_p = this->_rotate[i].value().p();
			m_max_value_p = this->_rotate[n].value().p();
			m_min_value_b = this->_rotate[i].value().b();
			m_max_value_b = this->_rotate[n].value().b();
			m_tween    = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening rotate values acquisition error at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	double m_h = ygl::animation::tweening(m_min_value_h, m_max_value_h, m_min_frame, m_max_frame, m_frame);
	double m_p = ygl::animation::tweening(m_min_value_p, m_max_value_p, m_min_frame, m_max_frame, m_frame);
	double m_b = ygl::animation::tweening(m_min_value_b, m_max_value_b, m_min_frame, m_max_frame, m_frame);

	return ygl::math::rotated(m_h, m_p, m_b);
}

ygl::math::sized ygl::animation::tween::size()
{
	if (this->_size.size() < 2)
	{
		std::cerr << "Tweening keyframe size error size at '" << this->_title << "', failed" << std::endl;

		exit(0);
	}

	std::size_t m_min_frame;
	std::size_t m_max_frame;

	double m_min_value_w;
	double m_max_value_w;
	double m_min_value_h;
	double m_max_value_h;
	double m_min_value_l;
	double m_max_value_l;

	std::size_t m_frame = this->_timeline.frame();
	std::size_t m_size  = this->_size.size() - 1;
	bool m_tween     = false;

	for (std::size_t i = 0, n = 1; i < m_size; i++, n++)
	{
		if (m_frame >= this->_size[i].frame() && m_frame <= this->_size[n].frame())
		{
			m_min_frame   = this->_size[i].frame();
			m_max_frame   = this->_size[n].frame();
			m_min_value_w = this->_size[i].value().w();
			m_max_value_w = this->_size[n].value().w();
			m_min_value_h = this->_size[i].value().h();
			m_max_value_h = this->_size[n].value().h();
			m_min_value_l = this->_size[i].value().l();
			m_max_value_l = this->_size[n].value().l();
			m_tween    = true;
		}
	}

	if (!m_tween)
	{
		std::cerr << "Tweening size values acquisition error at '" << this->_title << "', failed" << std::endl;
		exit(0);
	}

	double m_w = ygl::animation::tweening(m_min_value_w, m_max_value_w, m_min_frame, m_max_frame, m_frame);
	double m_h = ygl::animation::tweening(m_min_value_h, m_max_value_h, m_min_frame, m_max_frame, m_frame);
	double m_l = ygl::animation::tweening(m_min_value_l, m_max_value_l, m_min_frame, m_max_frame, m_frame);

	return ygl::math::sized(m_w, m_h, m_l);
}

