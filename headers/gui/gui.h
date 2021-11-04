#ifndef YGL_GUI_GUI_H_
#define YGL_GUI_GUI_H_

#pragma once

#include <iostream>
#include <string>

namespace ygl
{
	namespace gui
	{
		typedef enum state
		{
			STATE_NULL = -1,
			STATE_ENABLED,
			STATE_HOVER,
			STATE_PRESSED,
			STATE_RELEASED,
			STATE_DISABLED,
		} state;

		std::ostream& operator<<(std::ostream& stream, const ygl::gui::state& state);

		std::istream& operator>>(std::istream& stream, ygl::gui::state& state);

		ygl::gui::state to_state(const std::string& state);
	}
}

#endif /* YGL_GUI_GUI_H_ */
