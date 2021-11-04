#ifndef YGL_SERIALIZE_ANIMATIC_H_
#define YGL_SERIALIZE_ANIMATIC_H_

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "animation/keyframe.h"
#include "animation/animation.h"

namespace ygl
{
	namespace serialize
	{
		class animatic
		{
			public:

				animatic();

				~animatic();

				void name(const std::string& name);

				void size(std::size_t size);

				void play(const ygl::animation::play& play);

				void control(const ygl::animation::control& control);

				void course(const ygl::animation::course& course);

				void interpolation(const ygl::animation::interpolation& interpolation);

				void keyframe(const std::vector<ygl::animation::keyframe>& keyframe);

				void keyframe(const ygl::animation::keyframe& keyframe);

				const std::string& name() const;

				std::size_t size() const;

				const ygl::animation::play& play() const;

				const ygl::animation::control& control() const;

				const ygl::animation::course& course() const;

				const ygl::animation::interpolation& interpolation() const;

				std::vector<ygl::animation::keyframe>& keyframe();

				ygl::animation::keyframe& keyframe(std::size_t index);

				const ygl::animation::keyframe& keyframe_at(std::size_t index) const;

				friend std::ostream& operator<<(std::ostream& stream, const ygl::serialize::animatic& animation)
				{
						stream << "ANIMATED { ";
						stream << " NAME { " << animation.name() << "}, ";
						stream << animation.play() << ", ";
						stream << animation.control() << ", ";
						stream << animation.course() << ", ";
						stream << animation.interpolation() << ", ";

						for (std::size_t i = 0; i < animation.size(); i++)
						{
							if (i < animation.size() - 2)
							{
								stream << animation.keyframe_at(i) << ", ";
							}
							else
							{
								stream << animation.keyframe_at(i) << " }";
							}
						}

					return stream;
				}

				friend std::istream& operator>>(std::istream& stream, ygl::serialize::animatic& animation)
				{
						std::string garbage;
						std::string name;
						std::size_t size;
						ygl::animation::play play;
						ygl::animation::control control;
						ygl::animation::course course;
						ygl::animation::interpolation interpolation;
						ygl::animation::keyframe keyframes;

						stream >> garbage >> garbage;
						stream >> garbage >> garbage >> name >> garbage;
						stream >> play >> garbage;
						stream >> control >> garbage;
						stream >> course >> garbage;
						stream >> interpolation >> garbage;
						stream >> garbage >> garbage;

						for (std::size_t i = 0; i < animation.keyframe().size(); i++)
						{
							stream >> keyframes >> garbage;
							animation.keyframe(keyframes);
						}

						animation.name(name);
						animation.size(size);
						animation.play(play);
						animation.control(control);
						animation.course(course);
						animation.interpolation(interpolation);

					return stream;
				}

			protected:

				std::string								_name			{ "Untitle" };
				std::size_t								_size			{ 0 };
				ygl::animation::play					_play			{ ygl::animation::play::PLAY_ON };
				ygl::animation::control					_control		{ ygl::animation::control::CONTROL_SINGLE };
				ygl::animation::course					_course			{ ygl::animation::course::COURSE_FORWARD };
				ygl::animation::interpolation			_interpolation	{ ygl::animation::interpolation::INTERPOLATION_HARD };
				std::vector<ygl::animation::keyframe>	_keyframe;
		};
	}
}

#endif /* YGL_SERIALIZE_ANIMATIC_H_ */
