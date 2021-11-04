#include "crypto/md5.h"

ygl::crypto::md5::md5() :
	_finalized(false)
{
	this->initialize();
}

ygl::crypto::md5::md5(const std::string& salt) :
	_finalized(false)
{
	this->initialize();
	this->update(salt.c_str(), salt.length());
	this->finalize();
}

ygl::crypto::md5::~md5()
{
}

void ygl::crypto::md5::salt(const std::string& salt)
{
	this->update(salt.c_str(), salt.length());
}

void ygl::crypto::md5::update(const unsigned char* input, std::size_t length)
{
	/** Compute number of bytes mod 64. */
	std::size_t index = this->_count[0] / 8 % ygl::math::BLOCK_SIZE_64;

	/** Update number of bits. */
	if ((this->_count[0] += (length << 3)) < (length << 3))
	{

		this->_count[1]++;
	}

	this->_count[1] += (length >> 29);

	/** Number of bytes we need to fill in buffer. */
	std::size_t firstpart = 64 - index;

	std::size_t i;

	/** Transform as many times as possible. */
	if (length >= firstpart)
	{
		/** Fill buffer first, transform. */
		memcpy(&this->_buffer[index], input, firstpart);
		this->transform(this->_buffer);

		/** Transform chunks of blocksize (64 bytes). */
		for (i = firstpart; i + ygl::math::BLOCK_SIZE_64 <= length; i += ygl::math::BLOCK_SIZE_64)
		{

			this->transform(&input[i]);
		}

		index = 0;
	}
	else
	{

		i = 0;
	}

	/** Buffer remaining input. */
	memcpy(&this->_buffer[index], &input[i], length - i);
}

void ygl::crypto::md5::update(const char* input , std::size_t length)
{

	this->update((const unsigned char*)input, length);
}

void ygl::crypto::md5::finalize()
{
	static unsigned char padding[64] = {
		0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
 
	if (!this->_finalized)
	{
		/** Save number of bits. */
		unsigned char bits[8];
		this->encode(bits, this->_count, 8);

		/** Pad out to 56 mod 64. */
		std::size_t index = this->_count[0] / 8 % 64;
		std::size_t padLen = (index < 56) ? (56 - index) : (120 - index);
		this->update(padding, padLen);

		/** Append length (before padding). */
		this->update(bits, 8);

		/** Store state in digest. */
		this->encode(this->_digest, this->_state, 16);

		/** Zeroize sensitive information. */
		std::memset(this->_buffer, 0, sizeof(this->_buffer));
		std::memset(this->_count, 0, sizeof(this->_count));
 
		this->_finalized=true;
	}
}

std::string ygl::crypto::md5::hash() const
{
	if (!this->_finalized)
	{
		return std::string();
	}
 
	char buf[33];

	for (int i=0; i<16; i++)
	{

		sprintf(buf + i * 2, "%02x", this->_digest[i]);
	}

	buf[32] = 0;

	return std::string(buf);
}

std::string ygl::crypto::md5::hash(const std::string& salt) const
{
	std::string tmp = salt;

	md5 hash = md5(tmp);

	return hash.hash();
}

void ygl::crypto::md5::initialize()
{
	this->_finalized = false;

	this->_count[0] = 0;
	this->_count[1] = 0;

	/** Load magic initialization constants. */
	this->_state[0] = 0x67452301;
	this->_state[1] = 0xefcdab89;
	this->_state[2] = 0x98badcfe;
	this->_state[3] = 0x10325476;
}

void ygl::crypto::md5::decode(std::size_t output[], const unsigned char input[], std::size_t len)
{
	for (std::size_t i = 0, j = 0; j < len; i++, j += 4)
	{
		output[i] = ((std::size_t)input[j]) | (((std::size_t)input[j+1]) << 8) | (((std::size_t)input[j+2]) << 16) | (((std::size_t)input[j+3]) << 24);
	}
}

void ygl::crypto::md5::encode(unsigned char output[], const std::size_t input[], std::size_t len)
{
	for (std::size_t i = 0, j = 0; j < len; i++, j += 4)
	{
		output[j] = input[i] & 0xff;
		output[j+1] = (input[i] >> 8) & 0xff;
		output[j+2] = (input[i] >> 16) & 0xff;
		output[j+3] = (input[i] >> 24) & 0xff;
	}
}

void ygl::crypto::md5::transform(const unsigned char block[64])
{
	std::size_t a = this->_state[0];
	std::size_t b = this->_state[1];
	std::size_t c = this->_state[2];
	std::size_t d = this->_state[3];
	std::size_t x[16];
	decode (x, block, ygl::math::BLOCK_SIZE_64);

	/** Round 1 */
	this->FF(a, b, c, d, x[ 0], ygl::math::S11, 0xd76aa478); /** 1 */
	this->FF(d, a, b, c, x[ 1], ygl::math::S12, 0xe8c7b756); /** 2 */
	this->FF(c, d, a, b, x[ 2], ygl::math::S13, 0x242070db); /** 3 */
	this->FF(b, c, d, a, x[ 3], ygl::math::S14, 0xc1bdceee); /** 4 */
	this->FF(a, b, c, d, x[ 4], ygl::math::S11, 0xf57c0faf); /** 5 */
	this->FF(d, a, b, c, x[ 5], ygl::math::S12, 0x4787c62a); /** 6 */
	this->FF(c, d, a, b, x[ 6], ygl::math::S13, 0xa8304613); /** 7 */
	this->FF(b, c, d, a, x[ 7], ygl::math::S14, 0xfd469501); /** 8 */
	this->FF(a, b, c, d, x[ 8], ygl::math::S11, 0x698098d8); /** 9 */
	this->FF(d, a, b, c, x[ 9], ygl::math::S12, 0x8b44f7af); /** 10 */
	this->FF(c, d, a, b, x[10], ygl::math::S13, 0xffff5bb1); /** 11 */
	this->FF(b, c, d, a, x[11], ygl::math::S14, 0x895cd7be); /** 12 */
	this->FF(a, b, c, d, x[12], ygl::math::S11, 0x6b901122); /** 13 */
	this->FF(d, a, b, c, x[13], ygl::math::S12, 0xfd987193); /** 14 */
	this->FF(c, d, a, b, x[14], ygl::math::S13, 0xa679438e); /** 15 */
	this->FF(b, c, d, a, x[15], ygl::math::S14, 0x49b40821); /** 16 */

	/** Round 2 */
	this->GG(a, b, c, d, x[ 1], ygl::math::S21, 0xf61e2562); /** 17 */
	this->GG(d, a, b, c, x[ 6], ygl::math::S22, 0xc040b340); /** 18 */
	this->GG(c, d, a, b, x[11], ygl::math::S23, 0x265e5a51); /** 19 */
	this->GG(b, c, d, a, x[ 0], ygl::math::S24, 0xe9b6c7aa); /** 20 */
	this->GG(a, b, c, d, x[ 5], ygl::math::S21, 0xd62f105d); /** 21 */
	this->GG(d, a, b, c, x[10], ygl::math::S22,  0x2441453); /** 22 */
	this->GG(c, d, a, b, x[15], ygl::math::S23, 0xd8a1e681); /** 23 */
	this->GG(b, c, d, a, x[ 4], ygl::math::S24, 0xe7d3fbc8); /** 24 */
	this->GG(a, b, c, d, x[ 9], ygl::math::S21, 0x21e1cde6); /** 25 */
	this->GG(d, a, b, c, x[14], ygl::math::S22, 0xc33707d6); /** 26 */
	this->GG(c, d, a, b, x[ 3], ygl::math::S23, 0xf4d50d87); /** 27 */
	this->GG(b, c, d, a, x[ 8], ygl::math::S24, 0x455a14ed); /** 28 */
	this->GG(a, b, c, d, x[13], ygl::math::S21, 0xa9e3e905); /** 29 */
	this->GG(d, a, b, c, x[ 2], ygl::math::S22, 0xfcefa3f8); /** 30 */
	this->GG(c, d, a, b, x[ 7], ygl::math::S23, 0x676f02d9); /** 31 */
	this->GG(b, c, d, a, x[12], ygl::math::S24, 0x8d2a4c8a); /** 32 */

	/** Round 3 */
	this->HH(a, b, c, d, x[ 5], ygl::math::S31, 0xfffa3942); /** 33 */
	this->HH(d, a, b, c, x[ 8], ygl::math::S32, 0x8771f681); /** 34 */
	this->HH(c, d, a, b, x[11], ygl::math::S33, 0x6d9d6122); /** 35 */
	this->HH(b, c, d, a, x[14], ygl::math::S34, 0xfde5380c); /** 36 */
	this->HH(a, b, c, d, x[ 1], ygl::math::S31, 0xa4beea44); /** 37 */
	this->HH(d, a, b, c, x[ 4], ygl::math::S32, 0x4bdecfa9); /** 38 */
	this->HH(c, d, a, b, x[ 7], ygl::math::S33, 0xf6bb4b60); /** 39 */
	this->HH(b, c, d, a, x[10], ygl::math::S34, 0xbebfbc70); /** 40 */
	this->HH(a, b, c, d, x[13], ygl::math::S31, 0x289b7ec6); /** 41 */
	this->HH(d, a, b, c, x[ 0], ygl::math::S32, 0xeaa127fa); /** 42 */
	this->HH(c, d, a, b, x[ 3], ygl::math::S33, 0xd4ef3085); /** 43 */
	this->HH(b, c, d, a, x[ 6], ygl::math::S34,  0x4881d05); /** 44 */
	this->HH(a, b, c, d, x[ 9], ygl::math::S31, 0xd9d4d039); /** 45 */
	this->HH(d, a, b, c, x[12], ygl::math::S32, 0xe6db99e5); /** 46 */
	this->HH(c, d, a, b, x[15], ygl::math::S33, 0x1fa27cf8); /** 47 */
	this->HH(b, c, d, a, x[ 2], ygl::math::S34, 0xc4ac5665); /** 48 */

	/** Round 4 */
	this->II(a, b, c, d, x[ 0], ygl::math::S41, 0xf4292244); /** 49 */
	this->II(d, a, b, c, x[ 7], ygl::math::S42, 0x432aff97); /** 50 */
	this->II(c, d, a, b, x[14], ygl::math::S43, 0xab9423a7); /** 51 */
	this->II(b, c, d, a, x[ 5], ygl::math::S44, 0xfc93a039); /** 52 */
	this->II(a, b, c, d, x[12], ygl::math::S41, 0x655b59c3); /** 53 */
	this->II(d, a, b, c, x[ 3], ygl::math::S42, 0x8f0ccc92); /** 54 */
	this->II(c, d, a, b, x[10], ygl::math::S43, 0xffeff47d); /** 55 */
	this->II(b, c, d, a, x[ 1], ygl::math::S44, 0x85845dd1); /** 56 */
	this->II(a, b, c, d, x[ 8], ygl::math::S41, 0x6fa87e4f); /** 57 */
	this->II(d, a, b, c, x[15], ygl::math::S42, 0xfe2ce6e0); /** 58 */
	this->II(c, d, a, b, x[ 6], ygl::math::S43, 0xa3014314); /** 59 */
	this->II(b, c, d, a, x[13], ygl::math::S44, 0x4e0811a1); /** 60 */
	this->II(a, b, c, d, x[ 4], ygl::math::S41, 0xf7537e82); /** 61 */
	this->II(d, a, b, c, x[11], ygl::math::S42, 0xbd3af235); /** 62 */
	this->II(c, d, a, b, x[ 2], ygl::math::S43, 0x2ad7d2bb); /** 63 */
	this->II(b, c, d, a, x[ 9], ygl::math::S44, 0xeb86d391); /** 64 */

	this->_state[0] += a;
	this->_state[1] += b;
	this->_state[2] += c;
	this->_state[3] += d;

	/** Zeroize sensitive information. */
	std::memset(x, 0, sizeof(x));
}

inline std::size_t ygl::crypto::md5::F(std::size_t x, std::size_t y, std::size_t z)
{
	return (x&y) | (~x&z);
}

inline std::size_t ygl::crypto::md5::G(std::size_t x, std::size_t y, std::size_t z)
{
	return (x&z) | (y&~z);
}

inline std::size_t ygl::crypto::md5::H(std::size_t x, std::size_t y, std::size_t z)
{
	return x^y^z;
}

inline std::size_t ygl::crypto::md5::I(std::size_t x, std::size_t y, std::size_t z)
{
	return y ^ (x | ~z);
}

inline std::size_t ygl::crypto::md5::rotate_left(std::size_t x, int n)
{
	return (x << n) | (x >> (32 - n));
}

inline void ygl::crypto::md5::FF(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac)
{
	a = rotate_left(a + F(b,c,d) + x + ac, s) + b;
}

inline void ygl::crypto::md5::GG(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac)
{
	a = rotate_left(a + G(b,c,d) + x + ac, s) + b;
}

inline void ygl::crypto::md5::HH(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac)
{
	a = rotate_left(a + H(b,c,d) + x + ac, s) + b;
}

inline void ygl::crypto::md5::II(std::size_t &a, std::size_t b, std::size_t c, std::size_t d, std::size_t x, std::size_t s, std::size_t ac)
{
	a = rotate_left(a + I(b,c,d) + x + ac, s) + b;
}
