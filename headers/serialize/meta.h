#ifndef YGL_SERIALIZE_META_H_
#define YGL_SERIALIZE_META_H_

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "animatic.h"
#include "graphic/graphic.h"
#include "math/color.h"
#include "math/size.h"
#include "math/matrix.h"
#include "math/point.h"
#include "math/rotate.h"

namespace ygl
{
	namespace serialize
	{
		class meta
		{
			public:

				void scene(const std::string& scene);

				void type(const ygl::graphic::type& type);

				void filename(const std::string& filename);

				void name(const std::string& name);

				void matrix(const ygl::math::matrixd& matrix);

				void spot(std::size_t spot);

				void visible(bool visible);

				void flip(const ygl::graphic::flip& flip);

				void color(const ygl::math::colord& color);

				void pivot(const ygl::math::pointd& pivot);

				void position(const ygl::math::pointd& position);

				void scale(const ygl::math::sized& scale);

				void rotate(const ygl::math::rotated& rotate);

				void animatic(const std::vector<ygl::serialize::animatic>& animatic);

				void animatic(const ygl::serialize::animatic& animatic);

				const std::string& scene() const;

				const ygl::graphic::type& type() const;

				const std::string& filename() const;

				const std::string& name() const;

				const ygl::math::matrixd& matrix() const;

				std::size_t spot() const;

				bool visible() const;

				const ygl::graphic::flip& flip() const;

				const ygl::math::colord& color() const;

				const ygl::math::pointd& pivot() const;

				const ygl::math::pointd& position() const;

				const ygl::math::sized& scale() const;

				const ygl::math::rotated& rotate() const;

				std::vector<ygl::serialize::animatic>& animatic();

				ygl::serialize::animatic& animatic(std::size_t index);

				friend std::ostream& operator<<(std::ostream& stream, meta& meta)
				{
					stream << "META { ";
					stream << "SCENE { " << meta.scene() << " }, ";
					stream << meta.type() << ", ";
					stream << " FILENAME { " << meta.filename() << " }, ";
					stream << " NAME { " << meta.name() << " }, ";
					stream << meta.matrix() << ", ";
					stream << meta.spot() << ", ";
					stream << meta.visible() << ", ";
					stream << meta.flip() << ", ";
					stream << meta.color() << ", ";
					stream << meta.pivot() << ", ";
					stream << meta.position() << ", ";
					stream << meta.scale() << ", ";
					stream << meta.rotate() << ", ";

					for (std::size_t i = 0; i < meta.animatic().size(); i++)
					{
						if (i < meta.animatic().size() - 2)
						{
							stream << meta.animatic(i) << ", ";
						}
						else
						{
							stream << meta.animatic(i) << " }";
						}
					}

					return stream;
				}

				friend std::istream& operator>>(std::istream& stream, meta& meta)
				{
					std::string garbage;
					std::string scene;
					ygl::graphic::type type;
					std::string filename;
					std::string name;
					ygl::math::matrixd matrix;
					std::size_t spot;
					bool visible;
					ygl::graphic::flip flip;
					ygl::math::colord color;
					ygl::math::pointd pivot;
					ygl::math::pointd position;
					ygl::math::sized scale;
					ygl::math::rotated rotate;
					ygl::serialize::animatic animated;

					stream >> garbage >> garbage;
					stream >> garbage >> garbage >> scene >> garbage;
					stream >> garbage >> type;
					stream >> garbage >> garbage >> filename >> garbage;
					stream >> garbage >> garbage >> name >> garbage;
					stream >> matrix >> garbage;
					stream >> spot >> garbage;
					stream >> visible >> garbage;
					stream >> flip >> garbage;
					stream >> color >> garbage;
					stream >> pivot >> garbage;
					stream >> position >> garbage;
					stream >> scale >> garbage;
					stream >> rotate >> garbage;

					for (std::size_t i = 0; i < meta.animatic().size(); i++)
					{
						stream >> animated >> garbage;
						meta.animatic(animated);
					}

					return stream;
				}

			protected:

				std::string								_scene		{ "Untitled" };
				ygl::graphic::type						_type		{ ygl::graphic::type::TYPE_LAYER };
				std::string								_filename	{ "None" };
				std::string								_name		{ "Unnamed" };
				ygl::math::matrixd						_matrix		{ ygl::math::matrixd() };
				std::size_t								_spot		{ 0 };
				bool									_visible	{ true };
				ygl::graphic::flip						_flip		{ ygl::graphic::flip::FLIP_NONE };
				ygl::math::colord						_color		{ ygl::math::colord().WHITE() };
				ygl::math::pointd						_pivot		{ ygl::math::pointd() };
				ygl::math::pointd						_position	{ ygl::math::pointd() };
				ygl::math::sized						_scale		{ ygl::math::sized() };
				ygl::math::rotated						_rotate		{ ygl::math::rotated() };
				std::vector<ygl::serialize::animatic>	_animatic	{ std::vector<ygl::serialize::animatic>() };
		};
	}
}

#endif /* YGL_SERIALIZE_META_H_ */
