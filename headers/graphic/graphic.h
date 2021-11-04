#ifndef RGL_GRAPHIC_GRAPHIC_H_
#define RGL_GRAPHIC_GRAPHIC_H_

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>

#include "error/error.h"
#include "basic/basic.h"

namespace ygl
{
	namespace graphic
	{
		typedef enum type
		{
			TYPE_LAYER,
			TYPE_SHAPE,
			TYPE_SPRITE,
			TYPE_FONT,
			TYPE_EMITTER
		} type;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::type& type);

		std::istream& operator>>(std::istream& stream, ygl::graphic::type& type);

		ygl::graphic::type to_type(const std::string& type);

		typedef enum flip
		{
			FLIP_NONE = 0,
			FLIP_HORIZONTAL,
			FLIP_VERTICAL,
			FLIP_ALL
		} flip;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::flip& flip);

		std::istream& operator>>(std::istream& stream, ygl::graphic::flip& flip);

		ygl::graphic::flip to_flip(const std::string& flip);

		typedef enum align
		{
			ALIGN_NULL = 0,
			ALIGN_CENTER,
			ALIGN_RIGHT,
			ALIGN_LEFT
		} align;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::align& align);

		std::istream& operator>>(std::istream& stream, ygl::graphic::align& align);

		ygl::graphic::align to_align(const std::string& align);

		typedef enum weight
		{
			WEIGHT_NORMAL = 0,
			WEIGHT_BOLD,
			WEIGHT_ITALIC,
			WEIGHT_UNDERLINE,
			WEIGHT_STRIKETHROUGH
		} weight;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::weight& weight);

		std::istream& operator>>(std::istream& stream, ygl::graphic::weight& weight);

		ygl::graphic::weight to_weight(const std::string& weight);

		typedef enum hinting
		{
			HINTING_DEFAULT = 0,
			HINTING_LIGHT,
			HINTING_MONO
		} hinting;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::hinting& hinting);

		std::istream& operator>>(std::istream& stream, ygl::graphic::hinting& hinting);

		ygl::graphic::hinting to_hinting(const std::string& hinting);

		typedef enum orientation
		{
			ORIENTATION_GLOBAL = 0,
			ORIENTATION_LOCAL
		} orientation;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::orientation& orientation);

		std::istream& operator>>(std::istream& stream, ygl::graphic::orientation& orientation);

		ygl::graphic::orientation to_orientation(const std::string& orientation);

		typedef enum visible
		{
			VISIBLE_ON = 0,
			VISIBLE_OFF
		} visible;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::visible& visible);

		std::istream& operator>>(std::istream& stream, ygl::graphic::visible& visible);

		ygl::graphic::visible to_visible(const std::string& visible);

		typedef enum status
		{
			STATUS_NULL = -1,
			STATUS_ENABLED,
			STATUS_HOVER,
			STATUS_PRESSED,
			STATUS_RELEASED,
			STATUS_DISABLED,
		} status;

		std::ostream& operator<<(std::ostream& stream, const ygl::graphic::status& status);

		std::istream& operator>>(std::istream& stream, ygl::graphic::status& status);

		ygl::graphic::status to_status(const std::string& status);

		typedef struct texture
		{
			std::string file;
			unsigned char* data; //void*  pixels
			int width;
			int height;
			int depth;
			int pitch;
			uint32_t rmask;
			uint32_t gmask;
			uint32_t bmask;
			uint32_t amask;

			SDL_Surface* surface()
			{
				return SDL_CreateRGBSurfaceFrom((void*)data, width, height, depth, pitch, rmask, gmask, bmask, amask);
			}

			void copy(const SDL_Surface* surface)
			{
				file = std::string();
				data = (unsigned char*)surface->pixels;
				width = surface->w;
				height = surface->h;
				depth = surface->format->BytesPerPixel;
				pitch = surface->pitch;
				rmask = surface->format->Rmask;
				gmask = surface->format->Gmask;
				bmask = surface->format->Bmask;
				amask = surface->format->Amask;
			}

		} texture;

		inline bool sketcher(const std::string& org, const std::string& dst)
		{
			SDL_Surface* image = IMG_Load(org.c_str());

			if (image == NULL)
			{
				std::cerr << "ERROR: Filed initializing surface " << org << " -- " << IMG_GetError() << std::endl;
				exit(ygl::error::ERROR_LOAD_IMAGE);
			}

			std::ofstream stream(dst.c_str());

			if (!stream.is_open())
			{
				std::cerr << "WARNING: Could not save sketcher of '" << dst << "'." << std::endl;
				return false;
			}

			ygl::graphic::texture texture;

			texture.copy(image);

			stream << "const static ygl::graphic::texture " << dst << " = {\n";
			stream << texture.data << ",\n";
			stream << "\t" << texture.width << ",\n";
			stream << "\t" << texture.height << ",\n";
			stream << "\t" << texture.depth << ",\n";
			stream << "\t" << texture.pitch << ",\n";
			stream << "\t" << texture.rmask << ",\n";
			stream << "\t" << texture.gmask << ",\n";
			stream << "\t" << texture.bmask << ",\n";
			stream << "\t" << texture.amask << ",\n";
			stream << "};\n";

			SDL_FreeSurface(image);

			stream.close();

			return true;
		}
	}
}

#endif /* RGL_GRAPHIC_GRAPHIC_H_ */
