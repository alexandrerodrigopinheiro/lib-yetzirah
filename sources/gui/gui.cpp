#include "gui/gui.h"

std::ostream& ygl::gui::operator<<(std::ostream& stream, const ygl::gui::state& state)
{
	switch (state)
	{
		case ygl::gui::state::STATE_NULL:     { stream << "STATE { NULL }"    ; break; }
		case ygl::gui::state::STATE_ENABLED:  { stream << "STATE { NORMAL }"  ; break; }
		case ygl::gui::state::STATE_HOVER:    { stream << "STATE { HOVER }"   ; break; }
		case ygl::gui::state::STATE_PRESSED:  { stream << "STATE { PRESSED }" ; break; }
		case ygl::gui::state::STATE_RELEASED: { stream << "STATE { RELEASED }"; break; }
		case ygl::gui::state::STATE_DISABLED: { stream << "STATE { DISABLED }"; break; }
	}

	return stream;
}

std::istream& ygl::gui::operator>>(std::istream& stream, ygl::gui::state& state)
{
	std::string garbage;
	std::string value;

	stream >> garbage >> garbage >> value >> garbage;

	     if (value == "NULL")     { state = ygl::gui::state::STATE_NULL    ; }
	else if (value == "NORMAL")   { state = ygl::gui::state::STATE_ENABLED ; }
	else if (value == "HOVER")    { state = ygl::gui::state::STATE_HOVER   ; }
	else if (value == "PRESSED")  { state = ygl::gui::state::STATE_PRESSED ; }
	else if (value == "RELEASED") { state = ygl::gui::state::STATE_RELEASED; }
	else if (value == "DISABLED") { state = ygl::gui::state::STATE_DISABLED; }

	return stream;
}

ygl::gui::state ygl::gui::to_state(const std::string& state)
{
	ygl::gui::state out;

	     if (state == "NULL")     { out = ygl::gui::state::STATE_NULL    ; }
	else if (state == "NORMAL")   { out = ygl::gui::state::STATE_ENABLED ; }
	else if (state == "HOVER")    { out = ygl::gui::state::STATE_HOVER   ; }
	else if (state == "PRESSED")  { out = ygl::gui::state::STATE_PRESSED ; }
	else if (state == "RELEASED") { out = ygl::gui::state::STATE_RELEASED; }
	else if (state == "DISABLED") { out = ygl::gui::state::STATE_DISABLED; }

	return out;
}
