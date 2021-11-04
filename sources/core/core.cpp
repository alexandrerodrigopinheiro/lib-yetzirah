#include "core/core.h"

std::ostream& ygl::core::operator<<(std::ostream& stream, const ygl::core::state& state)
{
	switch (state)
	{
		case ygl::core::state::STATE_INACTIVE: { stream << "STATE { INACTIVE }"; break; }
		case ygl::core::state::STATE_STANDBY:  { stream << "STATE { STANDBY }" ; break; }
		case ygl::core::state::STATE_REFRESH:  { stream << "STATE { REFRESH }" ; break; }
		case ygl::core::state::STATE_ROLLING:  { stream << "STATE { ROLLING }" ; break; }
		case ygl::core::state::STATE_RESET:    { stream << "STATE { RESET }"   ; break; }
		case ygl::core::state::STATE_SPLASH:   { stream << "STATE { SPLASH }"  ; break; }
		case ygl::core::state::STATE_FREEZING: { stream << "STATE { FREEZING }"; break; }
	}

	return stream;
}

std::istream& ygl::core::operator>>(std::istream& stream, ygl::core::state& state)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "INACTIVE")
	{
		state = ygl::core::state::STATE_INACTIVE;
	}
	else if (value == "STANDBY")
	{
		state = ygl::core::state::STATE_STANDBY;
	}
	else if (value == "REFRESH")
	{
		state = ygl::core::state::STATE_REFRESH;
	}
	else if (value == "ROLLING")
	{
		state = ygl::core::state::STATE_ROLLING;
	}
	else if (value == "RESET")
	{
		state = ygl::core::state::STATE_RESET;
	}
	else if (value == "SPLASH")
	{
		state = ygl::core::state::STATE_SPLASH;
	}
	else if (value == "FREEZING")
	{
		state = ygl::core::state::STATE_FREEZING;
	}

	return stream;
}

ygl::core::state ygl::core::to_state(const std::string& state)
{
	ygl::core::state out;

	if (state == "INACTIVE")
	{
		out = ygl::core::state::STATE_INACTIVE;
	}
	else if (state == "STANDBY")
	{
		out = ygl::core::state::STATE_STANDBY;
	}
	else if (state == "REFRESH")
	{
		out = ygl::core::state::STATE_REFRESH;
	}
	else if (state == "ROLLING")
	{
		out = ygl::core::state::STATE_ROLLING;
	}
	else if (state == "RESET")
	{
		out = ygl::core::state::STATE_RESET;
	}
	else if (state == "SPLASH")
	{
		out = ygl::core::state::STATE_SPLASH;
	}
	else if (state == "FREEZING")
	{
		out = ygl::core::state::STATE_FREEZING;
	}

	return out;
}
