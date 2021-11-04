#ifndef YGL_GUI_BUTTON_H_
#define YGL_GUI_BUTTON_H_

#pragma once

#include <iostream>
#include <string>

#include "gui/gui.h"
#include "graphic/sprite.h"
#include "math/color.h"
#include "math/point.h"
#include "math/surface.h"
#include "math/size.h"

namespace ygl
{
	namespace gui
	{
		class button
		{
			public:

				button();

				~button();

				bool initialize(const std::string& filename, std::size_t colunm, std::size_t spot = 0);

				void destroy();

				void draw(const ygl::math::pointd& position, const ygl::gui::state& state = ygl::gui::state::STATE_NULL);

				const ygl::math::pointd& position() const;

				const ygl::gui::state& state() const;

				void sensible(const ygl::math::surfaced& sensible);

				const ygl::math::surfaced& sensible() const;

				void position(const ygl::math::pointd& position);

				void state(const ygl::gui::state& state);

				friend std::ostream& operator<<(std::ostream& stream, const button& button);

				friend std::istream& operator>>(std::istream& stream, button& button);

			protected:

				ygl::graphic::sprite*	_button		{ NULL };
				ygl::gui::state			_state		{ ygl::gui::state::STATE_ENABLED };
				ygl::math::surfaced		_sensible	{ ygl::math::surfaced() };
		};
	}
}

#endif /* YGL_GUI_BUTTON_H_ */
