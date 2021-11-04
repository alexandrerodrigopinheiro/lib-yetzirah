#ifndef YGL_GUI_SENSIBLE_H_
#define YGL_GUI_SENSIBLE_H_

#pragma once

#include <iostream>
#include <string>

#include "gui/gui.h"
#include "math/surface.h"

namespace ygl
{
	namespace gui
	{
		class sensible
		{
			public:

				sensible();

				sensible(const ygl::gui::state& state, const ygl::math::surfaced& area);

				sensible(const sensible& obj);

				~sensible();

				bool initialize(const ygl::gui::state& state, const ygl::math::surfaced& area);

				bool destroy();

				void state(const ygl::gui::state& state);

				void area(const ygl::math::surfaced& area);

				void area_x(double x);

				void area_y(double y);

				void area_w(double w);

				void area_h(double h);

				const ygl::gui::state& state() const;

				const ygl::math::surfaced& area() const;

			protected:

				ygl::gui::state		_state	{ ygl::gui::state::STATE_NULL };
				ygl::math::surfaced	_area	{ ygl::math::surfaced() };
		};
	}
}

#endif /* YGL_GUI_SENSIBLE_H_ */
