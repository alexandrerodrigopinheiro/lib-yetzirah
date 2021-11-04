#include "core/handler.h"

ygl::core::handler::handler() :
//	_background(NULL),
//	_field(NULL),
//	_bar(NULL),
//	_bump(0.0),
//	_progress(0.0),
//	_progress_size(0.0),
	_current(std::string())
{
}

ygl::core::handler::~handler()
{
	this->destroy();
}

void ygl::core::handler::destroy()
{
//	delete this->_background;
//	delete this->_field;
//	delete this->_bar;
//
//	this->_background = NULL;
//	this->_field      = NULL;
//	this->_bar        = NULL;

	if (!this->write())
	{
		//TODO
	}

	this->_scene[this->_current]->release();

	this->_scene.clear();
}

bool ygl::core::handler::attach(const std::string& name, ygl::scene::scene* scene)
{
	auto it = this->_scene.find(name);

	if (it != this->_scene.end())
	{
		return false;
	}

	if (this->_scene.size() == 0)
	{
		this->_current = name;
	}

	this->_scene.insert(std::pair<std::string, ygl::scene::scene*>(name, scene));

	return true;
}

void ygl::core::handler::loading()
{
//	this->process_size(200);
//
//	 while(this->load())
//	 {
//		this->processed();
//
//		this->_field->draw();
//		this->_bar->draw();
//		this->_background->draw();
//	}

	this->load();
}

bool ygl::core::handler::load()
{
	if (!this->read())
	{
		return false;
	}

	if (!this->_scene[this->_current]->loading())
	{
		return false;
	}

	return true;
}

void ygl::core::handler::unload()
{
	return this->_scene[this->_current]->release();
}


bool ygl::core::handler::scene(const std::string& name)
{
	auto it = this->_scene.find(name);

	if (it != this->_scene.end())
	{
		std::string m_next_scene    = name;
		std::string m_current_scene = this->_current;

		if (!this->_current.empty())
		{
			this->_scene[m_current_scene]->clear_next_scene();
			this->_scene[m_current_scene]->release();

			std::cout << "Handler: Destroyed scene current '" << this->_current << "', info" << std::endl;
		}

		this->_current = m_next_scene;

		if (!this->_scene[this->_current]->loading())
		{
			std::cerr << "Handler: Cannot initialize current scene '" << this->_current << "', failed" << std::endl;

			return false;
		}

		std::cerr << "Handler: Cannot initialize current scene '" << this->_current << "', failed" << std::endl;

		return true;
	}

	std::cout << "Handler: Current scene not found '" << name << "', failed" << std::endl;

	return false;
}

void ygl::core::handler::keyboard(const ygl::device::keyboard& keyboard)
{
	return this->_scene[this->_current]->keyboard(keyboard);
}

void ygl::core::handler::mouse(const ygl::device::mouse& mouse)
{
	return this->_scene[this->_current]->mouse(mouse);
}

void ygl::core::handler::touch(const ygl::device::touch& touch)
{
	return this->_scene[this->_current]->touch(touch);
}

void ygl::core::handler::update()
{
	return this->_scene[this->_current]->update();
}

void ygl::core::handler::render()
{
	return this->_scene[this->_current]->render();
}

void ygl::core::handler::clear()
{
	return this->_scene[this->_current]->clear();
}

bool ygl::core::handler::scene()
{
	if (this->_scene[this->_current]->next_scene().empty())
	{
		return true;
	}

	if (!this->scene(this->_scene[this->_current]->next_scene()))
	{
		return false;
	}

	return true;
}

bool ygl::core::handler::write()
{
//	std::ofstream stream("app/assets/data/system/handler.txt");
//
//	if (!stream.is_open())
//	{
//		std::cerr << "WARNING: Could not write to 'app/assets/data/system/handler.txt'." << std::endl;
//
//		return false;
//	}
//
//	stream << "SCENE { " << this->_current << " }\n";
//
//	stream.close();

	return true;
}

bool ygl::core::handler::read()
{
//	std::ifstream stream("app/assets/data/system/handler.txt");
//
//	if (!stream.is_open())
//	{
//		std::cerr << "WARNING: Could not read to 'app/assets/data/system/handler.txt', failed" << std::endl;
//
//		return false;
//	}
//
//	std::string garbage;
//
//	stream >> garbage >> garbage >> this->_current >> garbage;
//
//	stream.close();

	return true;
}

//void Handler::process_size(size_t size)
//{
//	this->_progress_size = size + 1.0;
//	this->_bump = ((float)this->_bar->size().w() / this->_progress_size);
//}
//
//bool Handler::loaded() const
//{
//	if (this->_progress <= YGL_MAXIMUM_PROCESS)
//	{
//		return true;
//	}
//
//	SDL_Delay(100);
//
//	return false;
//}
//
//void Handler::processed()
//{
//	this->_progress += (YGL_MAXIMUM_PROCESS / this->_progress_size);
//	this->_bar->position(this->_bar->position().x() + this->_bump);
//
//	if (this->_progress > YGL_MAXIMUM_PROCESS)
//	{
//		this->_bar->position_x((float)this->_bar->size().w());
//	}
//
//	SDL_Delay(100);
//}
//
//float Handler::progress() const
//{
//	return this->_progress;
//}
