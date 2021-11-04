#include "serialize/loader.h"

ygl::serialize::loader::loader()
{
}

ygl::serialize::loader::~loader()
{
}

bool ygl::serialize::loader::load(const std::string& filename)
{
	std::ifstream stream(filename.c_str());

	if (!stream.is_open())
	{
		std::cerr << "ERROR: Could not load data from '" << filename << "'." << std::endl;
		return false;
	}

	std::string garbage;
	while(!stream.eof())
	{
		std::getline(stream, garbage);
		this->_lines.push_back(garbage);
		garbage.clear();
	}

	stream.close();
	return true;
}

void ygl::serialize::loader::resume()
{
	std::vector<std::string> str;
	for (std::size_t i = 0; i < this->_lines.size(); i++)
	{
		if (!ygl::basic::string_find(this->_lines[i], '!') && !ygl::basic::string_search(this->_lines[i], "</") && !this->_lines[i].empty())
		{
			this->_lines[i] = ygl::basic::string_purge(this->_lines[i], '\t');
			this->_lines[i] = ygl::basic::string_purge(this->_lines[i], '\n');
			str.push_back(this->_lines[i]);
		}
	}

	this->_lines.clear();

	if (str.size() != 0)
	{
		std::vector<std::string> tmp;

		tmp.push_back(str[0]);

		for (std::size_t i = 1; i < str.size() - 1; i++)
		{
			if (ygl::basic::string_search(str[i], "IMAGE") && ygl::basic::string_search(str[i], "/>"))
			{
				str[i].erase(str[i].length() - 2, 1);
				tmp.push_back(str[i]);
			}
			else if (ygl::basic::string_search(str[i], "IMAGE") && !ygl::basic::string_search(str[i], "/>"))
			{
				tmp.push_back(str[i] + "|");
			}
			else if (ygl::basic::string_search(str[i], "</IMAGE>"))
			{
				str[i].erase(str[i].length() - 1, 1);
			}

			if (ygl::basic::string_search(str[i], "ANIMATION") && ygl::basic::string_search(str[i], "/>"))
			{
				str[i].erase(str[i].length() - 2, 1);
				tmp[tmp.size() - 1] += str[i];
			}
			else if (ygl::basic::string_search(str[i], "ANIMATION") && !ygl::basic::string_search(str[i], "/>"))
			{
				tmp[tmp.size() - 1] += str[i] + "|";
			}

			if (ygl::basic::string_search(str[i], "KEYFRAME") && ygl::basic::string_search(str[i], "/>"))
			{
				str[i].erase(str[i].length() - 2, 1);
				tmp[tmp.size() - 1] += str[i];
			}
			else if (ygl::basic::string_search(str[i], "KEYFRAME") && !ygl::basic::string_search(str[i], "/>"))
			{
				tmp[tmp.size() - 1] += str[i] + "|";
			}
		}

		for (std::size_t i = 0; i < tmp.size(); i++)
		{
			if (!tmp[i].empty())
			{
				this->_lines.push_back(tmp[i]);
				this->_lines[i] = ygl::basic::string_purge(this->_lines[i], '<');
				this->_lines[i] = ygl::basic::string_purge(this->_lines[i], '>');
				this->_lines[i] = ygl::basic::string_purge(this->_lines[i], '"');
			}
		}
	}
}

void ygl::serialize::loader::fill()
{
	std::vector<std::string> split = ygl::basic::explode_to_string(this->_lines[0], ' ');
	std::vector<std::string> scene = ygl::basic::explode_to_string(split[1], '=');

	for (std::size_t i = 1; i < this->_lines.size(); i++)
	{
		ygl::serialize::meta tmp_meta;

		tmp_meta.scene(scene[1]);

		std::vector<std::string> childs = ygl::basic::explode_to_string(this->_lines[i], '|');

		for (std::size_t l = 0; l < childs.size(); l++)
		{
			std::vector<std::string> attrib = ygl::basic::explode_to_string(childs[l], ' ');

			if (attrib[0] == "IMAGE")
			{
				tmp_meta.type(ygl::graphic::to_type(attrib[0]));

				for (std::size_t j = 1; j < attrib.size(); j++)
				{
					std::vector<std::string> values = ygl::basic::explode_to_string(attrib[j], '=');

					for (std::size_t n = 0; n < values.size() - 1; n++)
					{
						if (values[n] == "FILENAME")
						{
							tmp_meta.filename(values[n + 1]);
						}
						else if (values[n] == "NAME")
						{
							tmp_meta.name(values[n + 1]);
						}
						else if (values[n] == "MATRIX")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.matrix(ygl::math::matrixd().to_matrix(str[0], str[1]));
						}
						else if (values[n] == "SPOTS")
						{
							tmp_meta.spot(ygl::basic::to_uint(values[n + 1]));
						}
						else if (values[n] == "VISIBLE")
						{
							tmp_meta.visible(ygl::graphic::to_visible(values[n + 1]));
						}
						else if (values[n] == "FLIP")
						{
							tmp_meta.flip(ygl::graphic::to_flip(values[n + 1]));
						}
						else if (values[n] == "COLOR")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.color(ygl::math::colord().to_color(str[0], str[1], str[2]));
						}
						else if (values[n] == "PIVOT")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.pivot(ygl::math::pointd().to_point(str[0], str[1], str[2]));
						}
						else if (values[n] == "POSITION")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.position(ygl::math::pointd().to_point(str[0], str[1], str[2]));
						}
						else if (values[n] == "SCALE")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.scale(ygl::math::sized().to_size(str[0], str[1], str[2]));
						}
						else if (values[n] == "ROTATION")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.rotate(ygl::math::rotated().to_rotate(str[0], str[1], str[2]));
						}
					}

				}
			}
			else if (attrib[0] == "ANIMATION")
			{
				tmp_meta.animatic(ygl::serialize::animatic());

				for (std::size_t j = 1; j < attrib.size(); j++)
				{
					std::vector<std::string> values = ygl::basic::explode_to_string(attrib[j], '=');

					for (std::size_t n = 0; n < values.size() - 1; n++)
					{
						if (values[n] == "NAME")
						{
							tmp_meta.animatic().back().name(ygl::basic::to_string(values[n + 1]));
						}
						else if (values[n] == "TIMELINE")
						{
							tmp_meta.animatic().back().size(ygl::basic::to_uint(values[n + 1]));
						}
						else if (values[n] == "PLAY")
						{
							tmp_meta.animatic().back().play(ygl::animation::to_play(values[n + 1]));
						}
						else if (values[n] == "CONTROL")
						{
							tmp_meta.animatic().back().control(ygl::animation::to_control(values[n + 1]));
						}
						else if (values[n] == "COURSE")
						{
							tmp_meta.animatic().back().course(ygl::animation::to_course(values[n + 1]));
						}
						else if (values[n] == "INTERPOLATION")
						{
							tmp_meta.animatic().back().interpolation(ygl::animation::to_interpolation(values[n + 1]));
						}
					}
				}
			}
			else if (attrib[0] == "KEYFRAME")
			{
				tmp_meta.animatic(0).keyframe(ygl::animation::keyframe());

				for (std::size_t j = 1; j < attrib.size(); j++)
				{
					std::vector<std::string> values = ygl::basic::explode_to_string(attrib[j], '=');

					for (std::size_t n = 0; n < values.size() - 1; n++)
					{
						if (values[n] == "FRAME")
						{
							tmp_meta.animatic().back().keyframe().back().frame(ygl::basic::to_uint(values[n + 1]));
						}
						else if (values[n] == "VISIBLE")
						{
							tmp_meta.animatic().back().keyframe().back().visible(ygl::graphic::to_visible(values[n + 1]));
						}
						else if (values[n] == "FLIP")
						{
							tmp_meta.animatic().back().keyframe().back().flip(ygl::graphic::to_flip(values[n + 1]));
						}
						else if (values[n] == "COLOR")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.animatic().back().keyframe().back().color(ygl::math::colord().to_color(str[0], str[1], str[2]));
						}
						else if (values[n] == "PIVOT")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.animatic().back().keyframe().back().pivot(ygl::math::pointd().to_point(str[0], str[1], str[2]));
						}
						else if (values[n] == "POSITION")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.animatic().back().keyframe().back().position(ygl::math::pointd().to_point(str[0], str[1], str[2]));
						}
						else if (values[n] == "SCALE")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.animatic().back().keyframe().back().scale(ygl::math::sized().to_size(str[0], str[1], str[2]));
						}
						else if (values[n] == "ROTATION")
						{
							std::vector<std::string> str = ygl::basic::explode_to_string(values[n + 1], ',');

							tmp_meta.animatic().back().keyframe().back().rotate(ygl::math::rotated().to_rotate(str[0], str[1], str[2]));
						}
					}
				}
			}
		}

		this->_meta.push_back(tmp_meta);
	}
}

const std::vector<ygl::serialize::meta>& ygl::serialize::loader::meta() const
{
	return this->_meta;
}

std::size_t ygl::serialize::loader::size() const
{
	return this->_meta.size();
}

const ygl::serialize::meta& ygl::serialize::loader::meta(std::size_t index) const
{
	if (index >= this->_meta.size())
	{
		std::cerr << "Illegal index '" << index << "', failed" << std::endl;
		exit(1);
	}

	return this->_meta[index];
}
