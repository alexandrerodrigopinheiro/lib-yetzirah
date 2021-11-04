#include "core/render.h"

ygl::core::render::render()
{
}

ygl::core::render::~render()
{
	this->destroy();
}

bool ygl::core::render::initialize()
{
	/* Really Nice Perspective Calculations */
	glShadeModel(GL_SMOOTH);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_DEPTH_TEST);

	glDisable(GL_CULL_FACE);

	glAlphaFunc(GL_NOTEQUAL, 0);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);

	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_ACCELERATED_VISUAL, 1);

	int m_acceleration;
	SDL_GL_GetAttribute(SDL_GLattr::SDL_GL_ACCELERATED_VISUAL, &m_acceleration);

	if (m_acceleration <= 0)
	{
		std::cerr << "Video: Could not be initialized video acceleration', failed" << std::endl;
	}
	else
	{
		std::cout << "Video: Video acceleration initialized, info" << std::endl;
	}

	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_ACCUM_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_ACCUM_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_ACCUM_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_ACCUM_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_MULTISAMPLESAMPLES, 2);

	int buffers;
	int samples;

	SDL_GL_GetAttribute(SDL_GLattr::SDL_GL_MULTISAMPLEBUFFERS, &buffers);
	SDL_GL_GetAttribute(SDL_GLattr::SDL_GL_MULTISAMPLESAMPLES, &samples);

	/* samples (2, 4, or 8 is about it) */
	if (buffers == 0 || samples == 0)
	{
//		throw ygl::error::exception("Could not create FSAA buffers '" + std::to_string(buffers) + "' - samples '" + std::to_string(samples) + "', failed");
		std::cerr << "Could not create FSAA buffers '" << buffers << "' - samples '" << samples << "', failed" << std::endl;
//		return false;
	}

	int max;

	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);

	std::cout << "Size supported texture maximum " << max << "x" << max << ", info." << std::endl;

	/* Frame rate swap at 1seg. */
	if (SDL_GL_SetSwapInterval(1) < 0)
	{
		throw ygl::error::exception("Could not create VSYNC, failed");

		return false;
	}

	glewExperimental = GL_TRUE;

	GLenum error = glewInit();

	if (error != GLEW_OK)
	{

		if (error == GLEW_ERROR_NO_GL_VERSION)
		{
			throw ygl::error::exception("Could not initialize OpenGL: GLEW_ERROR_NO_GL_VERSION, failed");
		}
		else if (error == GLEW_ERROR_GL_VERSION_10_ONLY)
		{
			throw ygl::error::exception("Could not initialize OpenGL: GLEW_ERROR_GL_VERSION_10_ONLY, failed" );
		}
		else if (error == GLEW_ERROR_GLX_VERSION_11_ONLY)
		{
			throw ygl::error::exception("Could not initialize OpenGL: GLEW_ERROR_GLX_VERSION_11_ONLY, failed" );
		}

		return false;
	}

	int max_texture_size;

	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_texture_size);

	std::size_t m_num = SDL_GetNumVideoDisplays();
	std::cout << "Total number of monitors available is " << m_num << std::endl;
	for (std::size_t i = 0; i < m_num; i++)
	{
	    SDL_Rect m_display_rect;
	    SDL_GetDisplayBounds(i, &m_display_rect);
	    std::cout
		<< "Monitor " << i + 1 << " with resolution of x:y:w:h["
		<< m_display_rect.x << ":"
		<< m_display_rect.y << ":"
		<< m_display_rect.w << ":"
		<< m_display_rect.h << "]"
		<< std::endl;
	}

	return true;
}

void ygl::core::render::destroy()
{
}

void ygl::core::render::renderize(const ygl::math::colord& color)
{
	glClearColor(
		(double)ygl::math::normal_channel(color.r()),
		(double)ygl::math::normal_channel(color.g()),
		(double)ygl::math::normal_channel(color.b()),
		1.0
	);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);
}


void ygl::core::render::refresh()
{
}

