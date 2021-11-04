#ifndef YGL_RANDOM_RANDOM_H_
#define YGL_RANDOM_RANDOM_H_

#pragma once

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>

#include "math/range.h"

namespace ygl
{
	namespace random
	{

		typedef std::mt19937 randomer;

		template<typename T>
		inline std::vector<T> cut(const std::vector<T>& vec)
		{
			std::vector<T> first;
			std::vector<T> second;
			std::vector<T> out;

			for (std::size_t i = 0; i < vec.size(); i++)
			{
				if (i < vec.size() / 2)
				{
					first.push_back(vec[i]);
				}
				else
				{
					second.push_back(vec[i]);
				}
			}

			for (std::size_t i = 0; i < second.size(); i++)
			{
				out.push_back(second[i]);
			}

			for (std::size_t i = 0; i < first.size(); i++)
			{
				out.push_back(first[i]);
			}

			return out;
		}

		inline int unique_number(int src[], std::size_t size, int min, int max)
		{
			int arg = std::rand() % max + min;

			for (std::size_t i = 0; i < size; i++)
			{
				if (src[i] == arg)
				{
					i = 0;
					arg = std::rand() % max + min;
				}
			}

			return arg;
		}

		inline void seed()
		{
			std::srand((unsigned long long int)time(NULL));
		}

		inline int number()
		{
			return std::rand();
		}

		inline int get_number(int min, int max)
		{
			return std::rand() % max + min;
		}

		inline int get_number(int src[], std::size_t min, std::size_t max)
		{
			return src[(rand() % (max - min)) + min];
		}

		inline void fill_unique_number(int src[], std::size_t size, int min, int max)
		{
			for (std::size_t i = 0; i < size; i++)
			{
				src[i] = ygl::random::unique_number(src, size, min, max);
			}
		}

		inline int* fill_unique_number(std::size_t size, int min, int max)
		{
			int* vec = new int[size];

			for (std::size_t i = 0; i < size; i++)
			{
				vec[i] = ygl::random::unique_number(vec, size, min, max);
			}

			return vec;
		}

		inline void fill_reference_number(int dst[], std::size_t dstsize, int org[], std::size_t orgsize)
		{
			int* vec = new int[dstsize];

			ygl::random::fill_unique_number(vec, dstsize, 0, orgsize - 1);

			for (std::size_t i = 0; i < dstsize; i++)
			{
				dst[i] = org[vec[i]];
			}
		}

		template<typename T>
		inline T random_range(const ygl::math::range<T> range)
		{
			return range.get_begin() + rand() * (range.get_end() - range.get_begin());
		}

		template<typename T>
		inline T random_int(const ygl::math::range<T> range)
		{
			return std::floor(range.get_begin() + rand() * (range.get_end() - range.get_begin() + 1));
		}

		inline int random_range(int begin, int end)
		{
			return begin + std::rand() * (end - begin);
		}

		template<typename T>
		inline T random_int(T min, T max)
		{
			return std::floor(min + rand() * (max - min + 1));
		}
	}
}

#endif /* YGL_RANDOM_RANDOM_H_ */
