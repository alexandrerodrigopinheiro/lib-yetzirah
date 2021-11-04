#include "device/device.h"

std::ostream& ygl::device::operator<<(std::ostream& stream, const ygl::device::button& button)
{
	switch(button)
	{
		case ygl::device::BUTTON_INVALID:          stream << "BUTTON { INVALID }";          break;
		case ygl::device::BUTTON_EXIT:             stream << "BUTTON { EXIT }";             break;
		case ygl::device::BUTTON_PLAY:             stream << "BUTTON { PLAY }";             break;
		case ygl::device::BUTTON_AUTOPLAY:         stream << "BUTTON { AUTOPLAY }";         break;
		case ygl::device::BUTTON_EXTRABALL:        stream << "BUTTON { EXTRABALL }";        break;
		case ygl::device::BUTTON_DECREASE_SPEED:   stream << "BUTTON { DECREASE_SPEED }";   break;
		case ygl::device::BUTTON_INCREASE_SPEED:   stream << "BUTTON { INCREASE_SPEED }";   break;
		case ygl::device::BUTTON_MAXIMUM_PATTERN:  stream << "BUTTON { MAXIMUM_PATTERN }";  break;
		case ygl::device::BUTTON_DECREASE_PATTERN: stream << "BUTTON { DECREASE_PATTERN }"; break;
		case ygl::device::BUTTON_INCREASE_PATTERN: stream << "BUTTON { INCREASE_PATTERN }"; break;
		case ygl::device::BUTTON_MAXIMUM_BET:      stream << "BUTTON { MAXIMUM_BET }";      break;
		case ygl::device::BUTTON_DECREASE_BET:     stream << "BUTTON { DECREASE_BET }";     break;
		case ygl::device::BUTTON_INCREASE_BET:     stream << "BUTTON { INCREASE_BET }";     break;
		case ygl::device::BUTTON_CREDIT:           stream << "BUTTON { CREDIT }";           break;
		case ygl::device::BUTTON_CHANGE_PATTERN:   stream << "BUTTON { CHANGE_PATTERN }";   break;
		case ygl::device::BUTTON_SETTING:          stream << "BUTTON { SETTING }";          break;
		case ygl::device::BUTTON_CASHOUT:          stream << "BUTTON { CASHOUT }";          break;
		case ygl::device::BUTTON_LOG:              stream << "BUTTON { LOG }";              break;
		case ygl::device::BUTTON_HELP:             stream << "BUTTON { HELP }";             break;
		case ygl::device::BUTTON_DEBUG_FULLSCREEN: stream << "BUTTON { DEBUG_FULLSCREEN }"; break;
		case ygl::device::BUTTON_DEBUG_RULER:      stream << "BUTTON { DEBUG_RULER }";      break;
		case ygl::device::BUTTON_DEBUG_INFO:       stream << "BUTTON { DEBUG_INFO }";       break;
	}

	return stream;
}

std::istream& ygl::device::operator>>(std::istream& stream, ygl::device::button& button)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "INVALID")
	{
		button = ygl::device::BUTTON_INVALID;
	}
	else if (value == "EXIT")
	{
		button = ygl::device::BUTTON_EXIT;
	}
	else if (value == "PLAY")
	{
		button = ygl::device::BUTTON_PLAY;
	}
	else if (value == "AUTOPLAY")
	{
		button = ygl::device::BUTTON_AUTOPLAY;
	}
	else if (value == "EXTRABALL")
	{
		button = ygl::device::BUTTON_EXTRABALL;
	}
	else if (value == "DECREASE_SPEED")
	{
		button = ygl::device::BUTTON_DECREASE_SPEED;
	}
	else if (value == "INCREASE_SPEED")
	{
		button = ygl::device::BUTTON_INCREASE_SPEED;
	}
	else if (value == "MAXIMUM_PATTERN")
	{
		button = ygl::device::BUTTON_MAXIMUM_PATTERN;
	}
	else if (value == "DECREASE_PATTERN")
	{
		button = ygl::device::BUTTON_DECREASE_PATTERN;
	}
	else if (value == "INCREASE_PATTERN")
	{
		button = ygl::device::BUTTON_INCREASE_PATTERN;
	}
	else if (value == "MAXIMUM_BET")
	{
		button = ygl::device::BUTTON_MAXIMUM_BET;
	}
	else if (value == "DECREASE_BET")
	{
		button = ygl::device::BUTTON_DECREASE_BET;
	}
	else if (value == "INCREASE_BET")
	{
		button = ygl::device::BUTTON_INCREASE_BET;
	}
	else if (value == "CREDIT")
	{
		button = ygl::device::BUTTON_CREDIT;
	}
	else if (value == "CHANGE_PATTERN")
	{
		button = ygl::device::BUTTON_CHANGE_PATTERN;
	}
	else if (value == "SETTING")
	{
		button = ygl::device::BUTTON_SETTING;
	}
	else if (value == "CASHOUT")
	{
		button = ygl::device::BUTTON_CASHOUT;
	}
	else if (value == "LOG")
	{
		button = ygl::device::BUTTON_LOG;
	}
	else if (value == "HELP")
	{
		button = ygl::device::BUTTON_HELP;
	}
	else if (value == "DEBUG_FULLSCREEN")
	{
		button = ygl::device::BUTTON_DEBUG_FULLSCREEN;
	}
	else if (value == "DEBUG_INFO")
	{
		button = ygl::device::BUTTON_DEBUG_INFO;
	}
	else if (value == "DEBUG_RULER")
	{
		button = ygl::device::BUTTON_DEBUG_RULER;
	}

	return stream;
}

ygl::device::button ygl::device::to_button(const std::string& arg)
{
	ygl::device::button out;

	if (arg == "INVALID")
	{
		out = ygl::device::button::BUTTON_INVALID;
	}
	else if (arg == "EXIT")
	{
		out = ygl::device::button::BUTTON_EXIT;
	}
	else if (arg == "PLAY")
	{
		out = ygl::device::button::BUTTON_PLAY;
	}
	else if (arg == "AUTOPLAY")
	{
		out = ygl::device::button::BUTTON_AUTOPLAY;
	}
	else if (arg == "EXTRABALL")
	{
		out = ygl::device::button::BUTTON_EXTRABALL;
	}
	else if (arg == "DECREASE_SPEED")
	{
		out = ygl::device::button::BUTTON_DECREASE_SPEED;
	}
	else if (arg == "INCREASE_SPEED")
	{
		out = ygl::device::button::BUTTON_INCREASE_SPEED;
	}
	else if (arg == "MAXIMUM_PATTERN")
	{
		out = ygl::device::button::BUTTON_MAXIMUM_PATTERN;
	}
	else if (arg == "INCREASE_PATTERN")
	{
		out = ygl::device::button::BUTTON_INCREASE_PATTERN;
	}
	else if (arg == "DECREASE_PATTERN")
	{
		out = ygl::device::button::BUTTON_DECREASE_PATTERN;
	}
	else if (arg == "MAXIMUM_BET")
	{
		out = ygl::device::button::BUTTON_MAXIMUM_BET;
	}
	else if (arg == "DECREASE_BET")
	{
		out = ygl::device::button::BUTTON_DECREASE_BET;
	}
	else if (arg == "INCREASE_BET")
	{
		out = ygl::device::button::BUTTON_INCREASE_BET;
	}
	else if (arg == "CREDIT")
	{
		out = ygl::device::button::BUTTON_CREDIT;
	}
	else if (arg == "DECREASE_BET")
	{
		out = ygl::device::button::BUTTON_DECREASE_BET;
	}
	else if (arg == "CHANGE_PATTERN")
	{
		out = ygl::device::button::BUTTON_CHANGE_PATTERN;
	}
	else if (arg == "SETTING")
	{
		out = ygl::device::button::BUTTON_SETTING;
	}
	else if (arg == "CASHOUT")
	{
		out = ygl::device::button::BUTTON_CASHOUT;
	}
	else if (arg == "LOG")
	{
		out = ygl::device::button::BUTTON_LOG;
	}
	else if (arg == "HELP")
	{
		out = ygl::device::button::BUTTON_HELP;
	}
	else if (arg == "DEBUG_FULLSCREEN")
	{
		out = ygl::device::button::BUTTON_DEBUG_FULLSCREEN;
	}
	else if (arg == "DEBUG_INFO")
	{
		out = ygl::device::button::BUTTON_DEBUG_INFO;
	}
	else if (arg == "DEBUG_RULER")
	{
		out = ygl::device::button::BUTTON_DEBUG_RULER;
	}

	return out;
}
std::ostream& ygl::device::operator<<(std::ostream& stream, const ygl::device::type& type)
{
	switch(type)
	{
		case ygl::device::TYPE_NONE:     stream << "TYPE { NONE }";     break;
		case ygl::device::TYPE_BUTTON:   stream << "TYPE { BUTTON }";   break;
		case ygl::device::TYPE_KEYBOARD: stream << "TYPE { KEYBOARD }"; break;
		case ygl::device::TYPE_MOUSE:    stream << "TYPE { MOUSE }";    break;
		case ygl::device::TYPE_TOUCH:    stream << "TYPE { TOUCH }";    break;
	}

	return stream;
}

std::istream& ygl::device::operator>>(std::istream& stream, ygl::device::type& type)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "NONE")
	{
		type = ygl::device::TYPE_NONE;
	}
	else if (value == "BUTTON")
	{
		type = ygl::device::TYPE_BUTTON;
	}
	else if (value == "KEYBOARD")
	{
		type = ygl::device::TYPE_KEYBOARD;
	}
	else if (value == "MOUSE")
	{
		type = ygl::device::TYPE_MOUSE;
	}
	else if (value == "TOUCH")
	{
		type = ygl::device::TYPE_TOUCH;
	}

	return stream;
}

ygl::device::type ygl::device::to_type(const std::string& arg)
{
	ygl::device::type out;

	if (arg == "NONE")
	{
		out = ygl::device::type::TYPE_NONE;
	}
	else if (arg == "BUTTON")
	{
		out = ygl::device::type::TYPE_BUTTON;
	}
	else if (arg == "KEYBOARD")
	{
		out = ygl::device::type::TYPE_KEYBOARD;
	}
	else if (arg == "MOUSE")
	{
		out = ygl::device::type::TYPE_MOUSE;
	}
	else if (arg == "TOUCH")
	{
		out = ygl::device::type::TYPE_TOUCH;
	}

	return out;
}

std::ostream& ygl::device::operator<<(std::ostream& stream, const ygl::device::click& click)
{
	switch(click)
	{
		case ygl::device::CLICK_NONE:     stream << "CLICK { NONE }";    break;
		case ygl::device::CLICK_RELEASED: stream << "CLICK { RELEASE }"; break;
		case ygl::device::CLICK_PRESSED:  stream << "CLICK { PRESSED }"; break;
	}

	return stream;
}

std::istream& ygl::device::operator>>(std::istream& stream, ygl::device::click& click)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "NONE")
	{
		click = ygl::device::CLICK_NONE;
	}
	else if (value == "RELEASE")
	{
		click = ygl::device::CLICK_RELEASED;
	}
	else if (value == "PRESSED")
	{
		click = ygl::device::CLICK_PRESSED;
	}

	return stream;
}

ygl::device::click ygl::device::to_click(const std::string& arg)
{
	ygl::device::click out;

	if (arg == "NONE")
	{
		out = ygl::device::click::CLICK_NONE;
	}
	else if (arg == "RELEASED")
	{
		out = ygl::device::click::CLICK_RELEASED;
	}
	else if (arg == "PRESSED")
	{
		out = ygl::device::click::CLICK_PRESSED;
	}

	return out;
}

std::ostream& ygl::device::operator<<(std::ostream& stream, const ygl::device::key& key)
{
	switch(key)
	{
		case ygl::device::KEY_NONE:     stream << "KEY { NONE }";    break;
		case ygl::device::KEY_RELEASED: stream << "KEY { RELEASE }"; break;
		case ygl::device::KEY_PRESSED:  stream << "KEY { PRESSED }"; break;
	}

	return stream;
}

std::istream& ygl::device::operator>>(std::istream& stream, ygl::device::key& key)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "NONE")
	{
		key = ygl::device::KEY_NONE;
	}
	else if (value == "RELEASE")
	{
		key = ygl::device::KEY_RELEASED;
	}
	else if (value == "PRESSED")
	{
		key = ygl::device::KEY_PRESSED;
	}

	return stream;
}

ygl::device::key ygl::device::to_key(const std::string& arg)
{
	ygl::device::key out;

	if (arg == "NONE")
	{
		out = ygl::device::key::KEY_NONE;
	}
	else if (arg == "RELEASED")
	{
		out = ygl::device::key::KEY_RELEASED;
	}
	else if (arg == "PRESSED")
	{
		out = ygl::device::key::KEY_PRESSED;
	}

	return out;
}

std::ostream& ygl::device::operator<<(std::ostream& stream, const ygl::device::cursor& cursor)
{
	switch(cursor)
	{
		case ygl::device::CURSOR_NONE:     stream << "CURSOR { NONE }";    break;
		case ygl::device::CURSOR_MOTION:   stream << "CURSOR { MOTION }";  break;
		case ygl::device::CURSOR_RELEASED: stream << "CURSOR { RELEASE }"; break;
		case ygl::device::CURSOR_PRESSED:  stream << "CURSOR { PRESSED }"; break;
	}

	return stream;
}

std::istream& ygl::device::operator>>(std::istream& stream, ygl::device::cursor& cursor)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "NONE")
	{
		cursor = ygl::device::CURSOR_NONE;
	}
	else if (value == "MOTION")
	{
		cursor = ygl::device::CURSOR_MOTION;
	}
	else if (value == "RELEASE")
	{
		cursor = ygl::device::CURSOR_RELEASED;
	}
	else if (value == "PRESSED")
	{
		cursor = ygl::device::CURSOR_PRESSED;
	}

	return stream;
}

ygl::device::cursor ygl::device::to_cursor(const std::string& arg)
{
	ygl::device::cursor out;

	if (arg == "NONE")
	{
		out = ygl::device::cursor::CURSOR_NONE;
	}
	else if (arg == "MOTION")
	{
		out = ygl::device::cursor::CURSOR_MOTION;
	}
	else if (arg == "RELEASED")
	{
		out = ygl::device::cursor::CURSOR_RELEASED;
	}
	else if (arg == "PRESSED")
	{
		out = ygl::device::cursor::CURSOR_PRESSED;
	}

	return out;
}

std::ostream& ygl::device::operator<<(std::ostream& stream, const ygl::device::finger& finger)
{
	switch(finger)
	{
		case ygl::device::FINGER_NONE:     stream << "FINGER { NONE }";    break;
		case ygl::device::FINGER_MOTION:   stream << "FINGER { MOTION }";  break;
		case ygl::device::FINGER_RELEASED: stream << "FINGER { RELEASE }"; break;
		case ygl::device::FINGER_PRESSED:  stream << "FINGER { PRESSED }"; break;
	}

	return stream;
}

std::istream& ygl::device::operator>>(std::istream& stream, ygl::device::finger& finger)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	if (value == "NONE")
	{
		finger = ygl::device::FINGER_NONE;
	}
	else if (value == "MOTION")
	{
		finger = ygl::device::FINGER_MOTION;
	}
	else if (value == "RELEASE")
	{
		finger = ygl::device::FINGER_RELEASED;
	}
	else if (value == "PRESSED")
	{
		finger = ygl::device::FINGER_PRESSED;
	}

	return stream;
}

ygl::device::finger ygl::device::to_finger(const std::string& arg)
{
	ygl::device::finger out;

	if (arg == "NONE")
	{
		out = ygl::device::finger::FINGER_NONE;
	}
	else if (arg == "MOTION")
	{
		out = ygl::device::finger::FINGER_MOTION;
	}
	else if (arg == "RELEASED")
	{
		out = ygl::device::finger::FINGER_RELEASED;
	}
	else if (arg == "PRESSED")
	{
		out = ygl::device::finger::FINGER_PRESSED;
	}

	return out;
}
