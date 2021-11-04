#ifndef YGL_RANDOM_RANDOMIZER_H_
#define YGL_RANDOM_RANDOMIZER_H_

#pragma once

#include <iostream>
#include <string>
#include <random>
#include <cstddef>
#include <ctime>
#include <algorithm>

#include "math/math.h"
#include "math/range.h"
#include "random/random.h"

namespace ygl
{
	namespace random
	{
		class randomizer
		{
			public:

				randomizer();

				randomizer(const ygl::random::randomizer& obj);

				~randomizer();

				void seed();

				template <class RandomAccessIterator>
				void shuffle(RandomAccessIterator first, RandomAccessIterator last)
				{
					auto dist = [this](const ptrdiff_t n)
					{
						return std::uniform_int_distribution<ptrdiff_t>(0, n - 1)(this->_randomer);
					};

					std::random_shuffle(first, last, dist);
				}

				template <typename T>
				T unique(const std::vector<T> vec, const T& begin, const T& end)
				{

					std::size_t index = static_cast<std::size_t>((std::rand() % end) + begin);

					return vec[index];
				}

			protected:

				ygl::random::randomer	_randomer;
		};
	}
}

#endif /* YGL_RANDOM_RANDOMIZER_H_ */
