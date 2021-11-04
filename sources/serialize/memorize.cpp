#include "serialize/memorize.h"

ygl::serialize::memorize::memorize() :
	_rows(0),
	_filename("Unamed")
{
}

ygl::serialize::memorize::memorize(const memorize& obj) :
	_rows(0),
	_filename("Unamed")
{
	*this = obj;
}

ygl::serialize::memorize::memorize(const std::string& filename) :
	_rows(0),
	_filename(filename)
{
	this->initialize(this->_filename);
}

ygl::serialize::memorize::~memorize()
{
	this->destroy();
}

bool ygl::serialize::memorize::initialize(const std::string& filename)
{
	this->_filename = filename;

	std::streampos size;
	char* memblock;

	std::fstream stream(this->_filename.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

	if (!stream.is_open())
	{
		std::cerr << "ERROR: Could not load data from '" << this->_filename << "'." << std::endl;
		return false;
	}

	size = stream.tellg();
	memblock = new char [size];

	stream.seekg(0, std::ios::beg);
	stream.read(memblock, size);
	stream.close();

	std::string garbage = memblock;

	delete[] memblock;

	std::vector<std::string> str  = ygl::basic::explode_to_string(garbage, ',');

	for (std::size_t i = 0; i < str.size(); i++)
	{
		std::vector<std::string> line  = ygl::basic::explode_to_string(str[i], '=');

		this->_data.insert(std::pair<std::string, std::string>(line[0], line[1]));
	}

	this->_rows = this->_data.size();

	return true;
}

void ygl::serialize::memorize::destroy()
{
	const char *path = this->_filename.c_str();
	std::ofstream stream(path, std::ios::binary);

	if (!stream.is_open())
	{
		std::cerr << "ERROR: in ygl::serialize::memorize::release(), could not save data from '" << path << "'." << std::endl;
		exit(0);
	}

	typedef std::map<std::string, std::string>::iterator it_type;
	std::string str;

	for (it_type it = this->_data.begin(); it != this->_data.end(); it++)
	{
		str += it->first + "=" + it->second + ',';
	}

	std::string buffer;

	for (std::size_t i = 0; i < str.size(); ++i)
	{
		std::bitset<8> b(str.c_str()[i]);

		buffer += b.to_string();

		if (((i + 1) % 8) == 0)
		{
			buffer += "\n";
		}
		else
		{
			buffer += ' ';
		}
	}

	stream.write(buffer.c_str(), buffer.length());
	stream.close();
}

bool ygl::serialize::memorize::copy(ygl::serialize::memorize& obj)
{
	typedef std::map<std::string, std::string>::iterator it_type;

	for(it_type it = this->_data.begin(); it != this->_data.end(); it++)
	{
		obj.attach(it->first, it->second);
	}

	if (this->_data.size() != obj.rows())
	{
		return false;
	}

	return true;
}

bool ygl::serialize::memorize::attach(const std::string& key, const std::string& value)
{
	this->_data.insert(std::pair<std::string, std::string>(key, value));

	if (this->_rows == this->_data.size())
	{
		return false;
	}

	this->_rows += 1;

	return true;
}

std::size_t ygl::serialize::memorize::rows() const
{
	return this->_rows;
}

const std::string& ygl::serialize::memorize::filename() const
{
	return this->_filename;
}

std::string ygl::serialize::memorize::stamp(std::size_t index)
{
	if (index < this->_rows)
	{
		typedef std::map<std::string, std::string>::iterator it_type;
		std::size_t i = 0;

		for(it_type it = this->_data.begin(); it != this->_data.end(); it++, i++)
		{
			if (i == index)
			{
				return std::string(it->first + std::string(" ") + it->second);
			}
		}
	}

	const std::string& out = std::string();

	return out;
}
