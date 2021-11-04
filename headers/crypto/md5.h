#ifndef YGL_CRYPTO_MD5_H_
#define YGL_CRYPTO_MD5_H_

#pragma once

#include <iostream>
#include <string>
#include <cstring>

#include "math/math.h"

namespace ygl
{
	namespace crypto
	{
		class md5
		{
			public:

				md5();

				md5(const std::string& salt);

				~md5();

				void salt(const std::string& salt);

				void update(const unsigned char* input, std::size_t length);

				void update(const char* input, std::size_t length);

				void finalize();

				std::string hash() const;

				std::string hash(const std::string& salt) const;

				friend std::ostream& operator<<(std::ostream& out, const md5& md5)
				{
					return out << md5.hash();
				}

			private:

				void initialize();

				void transform(const unsigned char block[64]);

				static void decode(std::size_t output[], const unsigned char input[], std::size_t  len);

				static void encode(unsigned char output[], const std::size_t input[], std::size_t  len);

				/** Low level logic operations. */
				static inline std::size_t F(std::size_t x, std::size_t y, std::size_t z);

				static inline std::size_t G(std::size_t x, std::size_t y, std::size_t z);

				static inline std::size_t H(std::size_t x, std::size_t y, std::size_t z);

				static inline std::size_t I(std::size_t x, std::size_t y, std::size_t z);

				static inline std::size_t rotate_left(std::size_t x, int n);

				static inline void FF(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac);

				static inline void GG(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac);

				static inline void HH(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac);

				static inline void II(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac);

			protected:

				bool			_finalized;
				unsigned char	_buffer[64];	/** Bytes that didn't fit in last 64 byte chunk. */
				unsigned char	_digest[16];	/** The result. */
				std::size_t			_count[2];		/** 64bit counter for number of bits (lo, hi). */
				std::size_t			_state[4];		/** Digest so far. */
		};
	}
}

#endif /* YGL_CRYPTO_MD5_H_ */
