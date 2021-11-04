#ifndef YGL_BASIC_BASIC_H_
#define YGL_BASIC_BASIC_H_

#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include <iosfwd>
#include <vector>
#include <sstream>
#include <memory>

#define ygl_basic_cast_size(arg) static_cast<std::size_t>(arg)
#define ygl_basic_cast_int(arg)  static_cast<int>(arg)

namespace ygl
{
	namespace basic
	{
		template<class... T>
		inline void unused(T&&...)
		{
		}

		inline void delay(std::size_t max)
		{
			std::size_t m_delay;

			do
			{
				m_delay++;
			} while(m_delay <= max);
		}

		template<typename T>
		inline void output(std::ostream& stream, const std::string& title, const T& arg)
		{
			stream << title << " { " << arg << " }";
		}

		template<typename T>
		inline void input(std::istream& stream, T& arg)
		{
			std::string garbage;

			stream >> garbage >> garbage >> arg >> garbage;
		}

		/*template<typename T>
		inline std::vector<T> explode(const std::string& str, const char delimiter)
		{
			std::vector<T> vec;
			vec.push_back(T());
			for (std::size_t i = 0, n = 0; i < str.length(); i++, n++)
			{
				if (str[i] == delimiter)
				{
					vec.push_back(T());
					n = 0;
				}
				else
				{
					vec[n] += ygl::basic::to<T>(str[i]);
				}
			}
			return vec;
		}*/

		inline std::vector<std::string> explode_to_string(const std::string& str, const char delimiter)
		{
			std::vector<std::string> vec;
			vec.push_back(std::string());
			for (std::size_t i = 0, n = 0; i < str.length(); i++, n++)
			{
				if (str[i] == delimiter)
				{
					vec.push_back(std::string());
					n = 0;
				}
				else
				{
					vec[n] += str[i];
				}
			}
			return vec;
		}

		inline std::vector<int> explode_to_int(const std::string& str, const char delimiter)
		{
			std::vector<int> vec;
			vec.push_back(int());
			for (std::size_t i = 0, n = 0; i < str.length(); i++, n++)
			{
				if (str[i] == delimiter)
				{
					vec.push_back(int());
					n = 0;
				}
				else
				{
					vec[n] += (int)str[i];
				}
			}
			return vec;
		}

		inline bool string_find(const std::string& str, const char target)
		{
			for (std::size_t i = 0; i < str.length(); i++)
			{
				if (str[i] == target)
				{
					return true;
				}
			}
			return false;
		}

		inline bool string_search(const std::string& str, const std::string& target)
		{
			for (std::size_t i = 0; i < str.length(); i++)
			{
				if (str.compare(i, target.length(), target) == 0)
				{
					return true;
				}
			}

			return false;
		}

		inline std::string string_purge(const std::string& str, char arg)
		{
			std::string out;
			for (std::size_t i = 0; i < str.length(); i++)
			{
				if (str[i] != arg)
				{
					out += str[i];
				}
			}
			return out;
		}

		inline const std::string string_remove(const std::string& str, const std::string& arg)
		{
			std::string out = str;
			for (std::size_t i = 0; i < out.length(); i++)
			{
				std::string tmp;
				for (std::size_t l = 0; l < arg.length(); l++)
				{
					tmp += out[i + l];
				}
				if (tmp == arg)
				{
					out.erase(i, arg.length());
				}
			}
			return out;
		}

		inline bool string_has(const std::string& str, const std::string& arg)
		{
			std::string out = str;
			for (std::size_t i = 0; i < out.length(); i++)
			{
				std::string tmp;
				for (std::size_t l = 0; l < arg.length(); l++)
				{
					tmp += out[i + l];
				}
				if (tmp == arg)
				{
					return true;
				}
			}
			return false;
		}

		template<typename T>
		inline std::string to_string(T arg)
		{
			std::stringstream iss;
			iss << arg;
			return std::string(iss.str());
		}

		/*X...*/
		template<typename T>
		inline std::string to_format(T arg, const std::string& format)
		{
			std::string val = ygl::basic::to_string(arg);
			std::string str;
			int digt = val.length();
			int size = format.length();
			if (digt >= size)
			{
				return val;
			}
			for (int i = 0; i < size; i++)
			{
				str += (i < digt ? '0' : val[i - digt]);
			}
			return str;
		}

		template<typename T>
		inline std::string to_monetary(T src)
		{
			std::string tmp = ygl::basic::to_string(src);
			std::string str;
			if (tmp.empty())
			{
				str = "0,00";
			}
			else if (tmp.length() == 1)
			{
				str = "0,0" + tmp;
			}
			else if (tmp.length() == 2)
			{
				str = "0," + tmp;
			}
			else if (tmp.length() == 3)
			{
				str  = tmp[0];
				str += ",";
				str += tmp[1];
				str += tmp[2];
			}
			else
			{
				for (std::size_t i = 0; i < tmp.length(); i++)
				{
					if (i == tmp.length() - 2)
					{
						str += ",";
					}

					str += tmp[i];
				}
			}
			return str;
		}

		template<typename T>
		inline T string_to(const std::string& arg)
		{
			std::istringstream iss(arg);
			T out;
			iss >> out;
			return out;
		}

		template<typename T, typename M>
		inline T to(M arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			T out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline int to_int(T arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			int out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline std::size_t to_uint(T arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			std::size_t out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline uint8_t to_uint8(T arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			uint8_t out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline uint16_t to_uint16(T arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			uint16_t out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline uint32_t to_uint32(T arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			uint32_t out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline uint64_t to_uint64(T arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			uint64_t out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline bool to_bool(T arg)
		{
			std::istringstream iss(ygl::basic::to_string(arg));
			bool out;
			iss >> out;
			return out;
		}

		template<typename T>
		inline T window_fluid(T x, T width, T min = 1024, T max = 1360)
		{
			if (width == min)
			{
				return (x - ((max - min) / (T)2));
			}
			return x;
		}

		/* ARRAY */
		template <typename T, std::size_t N>
		inline constexpr std::size_t array_size(T (&)[N])
		{
			return N;
		}

		template <typename T, std::size_t N>
		inline T* array_begin(T (&array)[N])
		{
			return &array[0];
		}

		template <typename T, std::size_t N>
		inline T* array_end(T (&array)[N])
		{
			return &array[N];
		}
	}
}

#endif /* YGL_BASIC_BASIC_H_ */
