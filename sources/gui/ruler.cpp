#include "gui/ruler.h"

ygl::gui::ruler::ruler() :
	_visible(true),
	_opacity(100),
	_size(ygl::math::sized())
{
}

ygl::gui::ruler::ruler(const ygl::math::sized& size) :
	_visible(true),
	_opacity(100),
	_size(ygl::math::sized())
{
	this->initialize(size);
}

ygl::gui::ruler::~ruler()
{
	this->destroy();
}

bool ygl::gui::ruler::initialize(const ygl::math::sized& size)
{
	this->_size.fill((double)size.w(), (double)size.h(), 0.0);

	return true;
}

void ygl::gui::ruler::destroy()
{
}

void ygl::gui::ruler::draw()
{
	if (this->_visible && this->_opacity > 0)
	{
		glPushMatrix();

		glEnable(GL_LINE_STIPPLE);

		glColor4d(0.0, 0.0, 0.0, 0.1);
		glLineWidth(0.5);
		glBegin(GL_LINES);
		for (std::size_t i = 5; i < this->_size.h(); i += 5)
		{
			glVertex2d(0, i);
			glVertex2d(this->_size.w(), i);
		}
		for (std::size_t i = 5; i < this->_size.w(); i += 5)
		{
			glVertex2d(i, 0);
			glVertex2d(i, this->_size.h());
		}
		glEnd();

		glColor4d(0.0, 0.0, 0.0, 0.3);
		glLineWidth(1.0);
		glBegin(GL_LINES);
		for (std::size_t i = 10; i < this->_size.h(); i += 10)
		{
			if (i % 50 != 0 && i % 100 != 0)
			{
				glVertex2d(0, i);
				glVertex2d(this->_size.w(), i);
			}
		}
		for (std::size_t i = 10; i < this->_size.w(); i += 10)
		{
			if (i % 50 != 0 && i % 100 != 0)
			{
				glVertex2d(i, 0);
				glVertex2d(i, this->_size.h());
			}
		}
		glEnd();

		glColor4d(0.0, 0.0, 0.0, 0.6);
		glLineWidth(1.5);
		glBegin(GL_LINES);
		for (std::size_t i = 50; i < this->_size.h(); i += 50)
		{
			glVertex2d(0.0, i);
			glVertex2d(this->_size.w(), i);
		}
		for (std::size_t i = 50; i < this->_size.w(); i += 50)
		{
			glVertex2d(i, 0.0);
			glVertex2d(i, this->_size.h());
		}
		glEnd();

		glColor4d(0.0, 0.0, 0.0, 0.9);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		for (std::size_t i = 100; i < this->_size.h(); i += 100)
		{
			glVertex2d(0.0, i);
			glVertex2d(this->_size.w(), i);
		}
		for (std::size_t i = 100; i < this->_size.w(); i += 100)
		{
			glVertex2d(i, 0);
			glVertex2d(i, this->_size.h());
		}
		glEnd();

		glDisable(GL_LINE_STIPPLE);
		glPopMatrix();
	}
}
