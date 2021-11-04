#ifndef YGL_ANIMATION_TWEEN_H_
#define YGL_ANIMATION_TWEEN_H_

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "animation/animation.h"
#include "animation/key.h"
#include "animation/timeline.h"
#include "graphic/graphic.h"
#include "math/color.h"
#include "math/math.h"
#include "math/point.h"
#include "math/rotate.h"
#include "math/size.h"

namespace ygl
{
	namespace animation
	{
		class tween
		{
			public:

				tween();

				tween(const ygl::animation::tween& obj);

				tween(std::size_t timeline);

				tween(const std::string& title, std::size_t timeline);

				tween(const std::string& title, std::size_t timeline, std::size_t fps);

				~tween();

				bool initialize(std::size_t timeline);

				bool initialize(const std::string& title, std::size_t timeline);

				bool initialize(const std::string& title, std::size_t timeline, std::size_t fps);

				void destroy();

				void running();

				void start();

				void pause();

				void restart();

				void reset();

				bool started() const;

				bool border() const;

				bool onset() const;

				std::size_t length() const;

				std::size_t moment() const;

				void course(const ygl::animation::course& course);

				void control(const ygl::animation::control& control);

				const ygl::animation::course& course() const;

				const ygl::animation::control& control() const;

				void attach_measure(std::size_t keyframe, std::size_t measure);

				void attach_message(std::size_t keyframe, std::string& message);

				void attach_weight(std::size_t keyframe, const ygl::graphic::weight& weight);

				void attach_spot(std::size_t keyframe, std::size_t spot);

				void attach_visible(std::size_t keyframe, bool visible);

				void attach_wireframe(std::size_t keyframe, bool wireframe);

				void attach_flip(std::size_t keyframe, const ygl::graphic::flip& flip);

				void attach_color(std::size_t keyframe, const ygl::math::colord& color);

				void attach_opacity(std::size_t keyframe, double opacity);

				void attach_orientation(std::size_t keyframe, const ygl::graphic::orientation& orientation);

				void attach_pivot(std::size_t keyframe, const ygl::math::pointd& pivot);

				void attach_position(std::size_t keyframe, const ygl::math::pointd& position);

				void attach_scale(std::size_t keyframe, const ygl::math::sized& scale);

				void attach_rotate(std::size_t keyframe, const ygl::math::rotated& rotate);

				void attach_size(std::size_t keyframe, const ygl::math::sized& size);

				void clear_tweening();

				void clear_measure();

				void clear_message();

				void clear_weight();

				void clear_spot();

				void clear_visible();

				void clear_wireframe();

				void clear_flip();

				void clear_color();

				void clear_opacity();

				void clear_orientation();

				void clear_pivot();

				void clear_position();

				void clear_scale();

				void clear_rotate();

				void clear_size();

				std::size_t size_tweening() const;

				std::size_t size_measure() const;

				std::size_t size_message() const;

				std::size_t size_weight() const;

				std::size_t size_spot() const;

				std::size_t size_visible() const;

				std::size_t size_wireframe() const;

				std::size_t size_flip() const;

				std::size_t size_color() const;

				std::size_t size_opacity() const;

				std::size_t size_orientation() const;

				std::size_t size_pivot() const;

				std::size_t size_position() const;

				std::size_t size_scale() const;

				std::size_t size_rotate() const;

				std::size_t size_size() const;

				const ygl::animation::key<std::size_t>& keyframe_measure(std::size_t index) const;

				const ygl::animation::key<std::string>& keyframe_message(std::size_t index) const;

				const ygl::animation::key<ygl::graphic::weight>& keyframe_weight(std::size_t index) const;

				const ygl::animation::key<std::size_t>& keyframe_spot(std::size_t index) const;

				const ygl::animation::key<bool>& keyframe_visible(std::size_t index) const;

				const ygl::animation::key<bool>& keyframe_wireframe(std::size_t index) const;

				const ygl::animation::key<ygl::graphic::flip>& keyframe_flip(std::size_t index) const;

				const ygl::animation::key<ygl::math::colord>& keyframe_color(std::size_t index) const;

				const ygl::animation::key<double>& keyframe_opacity(std::size_t index) const;

				const ygl::animation::key<ygl::graphic::orientation>& keyframe_orientation(std::size_t index) const;

				const ygl::animation::key<ygl::math::pointd>& keyframe_pivot(std::size_t index) const;

				const ygl::animation::key<ygl::math::pointd>& keyframe_position(std::size_t index) const;

				const ygl::animation::key<ygl::math::sized>& keyframe_scale(std::size_t index) const;

				const ygl::animation::key<ygl::math::rotated>& keyframe_rotate(std::size_t index) const;

				const ygl::animation::key<ygl::math::sized>& keyframe_size(std::size_t index) const;

				bool has_tweening();

				bool has_measure() const;

				bool has_message() const;

				bool has_weight() const;

				bool has_spot() const;

				bool has_visible() const;

				bool has_wireframe() const;

				bool has_flip() const;

				bool has_color() const;

				bool has_opacity() const;

				bool has_orientation() const;

				bool has_pivot() const;

				bool has_position() const;

				bool has_scale() const;

				bool has_rotate() const;

				bool has_size() const;

				std::size_t measure();

				std::string message();

				ygl::graphic::weight weight();

				std::size_t spot();

				bool visible();

				bool wireframe();

				ygl::graphic::flip flip();

				ygl::math::colord color();

				double opacity();

				ygl::graphic::orientation orientation();

				ygl::math::pointd pivot();

				ygl::math::pointd position();

				ygl::math::sized scale();

				ygl::math::rotated rotate();

				ygl::math::sized size();

			protected:

				ygl::animation::timeline									_timeline;
				std::string													_title;
				std::vector<ygl::animation::key<std::size_t>>				_measure;
				std::vector<ygl::animation::key<std::string>>				_message;
				std::vector<ygl::animation::key<ygl::graphic::weight>>		_weight;
				std::vector<ygl::animation::key<std::size_t>>				_spot;
				std::vector<ygl::animation::key<bool>>						_visible;
				std::vector<ygl::animation::key<bool>>						_wireframe;
				std::vector<ygl::animation::key<ygl::graphic::flip>>		_flip;
				std::vector<ygl::animation::key<ygl::math::colord>>			_color;
				std::vector<ygl::animation::key<double>>					_opacity;
				std::vector<ygl::animation::key<ygl::graphic::orientation>>	_orientation;
				std::vector<ygl::animation::key<ygl::math::pointd>>			_pivot;
				std::vector<ygl::animation::key<ygl::math::pointd>>			_position;
				std::vector<ygl::animation::key<ygl::math::sized>>			_scale;
				std::vector<ygl::animation::key<ygl::math::rotated>>		_rotate;
				std::vector<ygl::animation::key<ygl::math::sized>>			_size;
		};
	}
}

#endif /* YGL_ANIMATION_TWEEN_H_ */
