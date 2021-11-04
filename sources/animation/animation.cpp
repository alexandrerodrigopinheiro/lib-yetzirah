#include "animation/animation.h"

std::ostream& ygl::animation::operator<<(std::ostream& stream, const ygl::animation::play& play)
{
	switch (play)
	{
		case ygl::animation::play::PLAY_OFF:
		{
			stream << "PLAY { OFF }";
			break;
		}
		case ygl::animation::play::PLAY_ON:
		{
			stream << "PLAY { ON }";
			break;
		}
	}
	return stream;
}

std::istream& ygl::animation::operator>>(std::istream& stream, ygl::animation::play& play)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "OFF")
	{
		play = ygl::animation::play::PLAY_OFF;
	}
	else if (value == "ON")
	{
		play = ygl::animation::play::PLAY_ON;
	}

	return stream;
}

std::ostream& ygl::animation::operator<<(std::ostream& stream, const ygl::animation::control& control)
{
	switch (control)
	{
		case ygl::animation::control::CONTROL_SINGLE:
		{
			stream << "CONTROL { SINGLE }";
			break;
		}
		case ygl::animation::control::CONTROL_CYCLE:
		{
			stream << "CONTROL { CYCLE }";
			break;
		}
		case ygl::animation::control::CONTROL_PINGPONG:
		{
			stream << "CONTROL { PINGPONG }";
			break;
		}
		case ygl::animation::control::CONTROL_ELASTIC:
		{
			stream << "CONTROL { ELASTIC }";
			break;
		}
	}
	return stream;
}

std::istream& ygl::animation::operator>>(std::istream& stream, ygl::animation::control& control)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "SINGLE")
	{
		control = ygl::animation::control::CONTROL_SINGLE;
	}
	else if (value == "CYCLE")
	{
		control = ygl::animation::control::CONTROL_CYCLE;
	}
	else if (garbage == "PINGPONG")
	{
		control = ygl::animation::control::CONTROL_PINGPONG;
	}
	else if (value == "ELASTIC")
	{
		control = ygl::animation::control::CONTROL_ELASTIC;
	}
	return stream;
}

std::ostream& ygl::animation::operator<<(std::ostream& stream, const ygl::animation::course& course)
{
	switch (course)
	{
		case ygl::animation::course::COURSE_BACKWARD:
		{
			stream << "COURSE { BACKWARDCOURSE }";
			break;
		}
		case ygl::animation::course::COURSE_FORWARD:
		{
			stream << "COURSE { FORWARD }";
			break;
		}
	}
	return stream;
}

std::istream& ygl::animation::operator>>(std::istream& stream, ygl::animation::course& course)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "BACKWARD")
	{
		course = ygl::animation::course::COURSE_BACKWARD;
	}
	else if (value == "FORWARD")
	{
		course = ygl::animation::course::COURSE_FORWARD;
	}

	return stream;
}

std::ostream& ygl::animation::operator<<(std::ostream& stream, const ygl::animation::interpolation& interpolation)
{
	switch (interpolation)
	{
		case ygl::animation::interpolation::INTERPOLATION_SOFT:
		{
			stream << "INTERPOLATION { SOFT }";
			break;
		}
		case ygl::animation::interpolation::INTERPOLATION_HARD:
		{
			stream << "INTERPOLATION { HARD }";
			break;
		}
	}

	return stream;
}

std::istream& ygl::animation::operator>>(std::istream& stream, ygl::animation::interpolation& interpolation)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "SOFT")
	{
		interpolation = ygl::animation::interpolation::INTERPOLATION_SOFT;
	}
	else if (value == "HARD")
	{
		interpolation = ygl::animation::interpolation::INTERPOLATION_HARD;
	}

	return stream;
}

ygl::animation::play ygl::animation::to_play(const std::string& arg)
{
	ygl::animation::play out;

	if (arg == "OFF")
	{
		out = ygl::animation::play::PLAY_OFF;
	}
	else if (arg == "ON")
	{
		out = ygl::animation::play::PLAY_ON;
	}

	return out;
}

ygl::animation::control ygl::animation::to_control(const std::string& arg)
{
	ygl::animation::control out;

	if (arg == "SINGLE")
	{
		out = ygl::animation::control::CONTROL_SINGLE;
	}
	else if (arg == "CYCLE")
	{
		out = ygl::animation::control::CONTROL_CYCLE;
	}
	else if (arg == "PINGPONG")
	{
		out = ygl::animation::control::CONTROL_PINGPONG;
	}
	else if (arg == "PINGPONG")
	{
		out = ygl::animation::control::CONTROL_ELASTIC;
	}

	return out;
}

ygl::animation::course ygl::animation::to_course(const std::string& arg)
{
	ygl::animation::course out;

	if (arg == "BACKWARD")
	{
		out = ygl::animation::course::COURSE_BACKWARD;
	}
	else if (arg == "FORWARD")
	{
		out = ygl::animation::course::COURSE_FORWARD;
	}

	return out;
}

ygl::animation::interpolation ygl::animation::to_interpolation(const std::string& arg)
{
	ygl::animation::interpolation out;

	if (arg == "SOFT")
	{
		out = ygl::animation::interpolation::INTERPOLATION_SOFT;
	}
	else if (arg == "HARD")
	{
		out = ygl::animation::interpolation::INTERPOLATION_HARD;
	}

	return out;
}
