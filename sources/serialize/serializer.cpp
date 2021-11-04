#include "serialize/serializer.h"

ygl::serialize::serializer::serializer() :
	_rows(0),
	_filename("Unamed")
{
}

ygl::serialize::serializer::~serializer()
{
	this->destroy();
}

bool ygl::serialize::serializer::initialize(const std::string& filename)
{
	this->_filename = filename;
	std::ifstream stream(this->_filename.c_str());
	if (!stream.is_open())
	{
		std::cerr << "ERROR: Could not load data from '" << this->_filename << "'." << std::endl;
		return false;
	}
	std::string garbage;
	while(!stream.eof())
	{
		std::string first;
		std::string second;
		stream >> first >> garbage >> second;
		this->_data.insert(std::pair<std::string, std::string>(first, second));
	}
	stream.close();
	this->_rows = this->_data.size();
	return true;
}

void ygl::serialize::serializer::destroy()
{
	std::ofstream stream(this->_filename.c_str());
	if (!stream.is_open())
	{
		std::cerr << "ERROR: in serialize::release(), could not save data from '" << this->_filename << "'." << std::endl;
		exit(0);
	}
	for(auto it = this->_data.begin(); it != this->_data.end(); ++it)
	{
		stream << it->first << " " << it->second << '\n';
	}
	stream.close();
}

bool ygl::serialize::serializer::attach(const std::string& key, const std::string& value)
{
	this->_data.insert(std::pair<std::string, std::string>(key, value));
	if (this->_rows == this->_data.size())
	{
		return false;
	}
	this->_rows += 1;
	return true;
}

std::size_t ygl::serialize::serializer::get_rows() const
{
	return this->_rows;
}

const std::string& ygl::serialize::serializer::get_filename() const
{
	return this->_filename;
}

const std::string& ygl::serialize::serializer::get_value(const std::string& key)
{
	if (this->_data.count(key) <= 0)
	{
		exit(0);
	}
	return this->_data[key];
}

std::string ygl::serialize::serializer::get_stamp(std::size_t index)
{
	std::string str;
	if (index < this->_rows)
	{
		std::size_t i = 0;
		for(auto it = this->_data.begin(); it != this->_data.end(); ++it, i++)
		{
			if (i == index)
			{
				str = it->first + " " + it->second;
				return str;
			}
		}
	}
	return str;
}
