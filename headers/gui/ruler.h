#ifndef YGL_GUI_RULER_H_
#define YGL_GUI_RULER_H_

#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>

#include "math/point.h"
#include "math/size.h"

namespace ygl
{
	namespace gui
	{
		class ruler
		{
			public:

				ruler();

				ruler(const ygl::math::sized& size);

				~ruler();

				bool initialize(const ygl::math::sized& size);

				void destroy();

				void draw();

				void visible(bool visible);

				void opacity(double opacity);

				bool visible() const;

				double opacity() const;

				const ygl::math::sized& size() const;

			protected:

				bool				_visible	{ true };
				double				_opacity	{ 100 };
				ygl::math::sized	_size		{ ygl::math::sized() };
		};
	}
}

#endif /* YGL_GUI_RULER_H_ */
