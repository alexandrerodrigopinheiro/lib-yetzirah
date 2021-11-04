#ifndef YGL_CORE_HANDLER_H_
#define YGL_CORE_HANDLER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <map>

#include "device/device.h"
#include "device/event.h"
#include "device/keyboard.h"
#include "device/mouse.h"
#include "device/touch.h"
#include "basic/basic.h"
#include "scene/scene.h"
#include "graphic/layer.h"
#include "graphic/text.h"
#include "math/point.h"

#define YGL_MAXIMUM_PROCESS	100.0

namespace ygl
{
	namespace core
	{
		class handler
		{
			public:

				handler();

				handler(const ygl::core::handler&) = delete;

				~handler();

				void destroy();

				bool attach(const std::string& name, ygl::scene::scene* scene);

				void loading();

				bool load();

				void unload();

				bool scene(const std::string& name);

				void keyboard(const ygl::device::keyboard& keyboard);

				void mouse(const ygl::device::mouse& mouse);

				void touch(const ygl::device::touch& touch);

				void update();

				void render();

				void clear();

				bool scene();

			private:

				bool write();

				bool read();

			//	void process_size(std::size_t size);
			//
			//	bool loaded() const;
			//
			//	void processed();
			//
			//	float progress() const;

			protected:

//				Layer*										_background		{ NULL };
//				Layer*										_field			{ NULL };
//				Layer*										_bar			{ NULL };
//				TTF*										_font			{ NULL };
//				float										_bump			{ 0.0 };
//				float										_progress		{ 0.0 };
//				float										_progress_size	{ 0.0 };
				std::string									_current		{ std::string() };
				std::map<std::string, ygl::scene::scene*>	_scene			{ std::map<std::string, ygl::scene::scene*>() };
		};
	}
}

#endif /* YGL_CORE_HANDLER_H_ */
