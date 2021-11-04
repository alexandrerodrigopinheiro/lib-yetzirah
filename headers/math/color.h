#ifndef YGL_MATH_COLOR_h_
#define YGL_MATH_COLOR_h_

#pragma once

#include <string>
#include <iostream>

#include "basic/basic.h"

namespace ygl
{
	namespace math
	{
		template<typename T>
		class color
		{
			public:

				color() :
					_r(0),
					_g(0),
					_b(0),
					_null(false)
				{
				}

				color(const ygl::math::color<T>& obj) :
					_r(obj.r()),
					_g(obj.g()),
					_b(obj.b()),
					_null(false)
				{
				}

				color(T r, T g, T b) :
					_r(this->clamp(r, (T)0, (T)255)),
					_g(this->clamp(g, (T)0, (T)255)),
					_b(this->clamp(b, (T)0, (T)255)),
					_null(false)
				{
				}

				color(T value) :
					_r(this->clamp(value, (T)0, (T)255)),
					_g(this->clamp(value, (T)0, (T)255)),
					_b(this->clamp(value, (T)0, (T)255)),
					_null(false)
				{
				}

				void fill(const ygl::math::color<T>& color)
				{
					this->_r = color.r();
					this->_g = color.g();
					this->_b = color.b();
				}

				void fill(T r, T g, T b)
				{
					this->_r = this->clamp(r, (T)0, (T)255);
					this->_g = this->clamp(g, (T)0, (T)255);
					this->_b = this->clamp(b, (T)0, (T)255);
				}

				void fill(T color)
				{
					this->_r = this->clamp(color, (T)0, (T)255);
					this->_g = this->clamp(color, (T)0, (T)255);
					this->_b = this->clamp(color, (T)0, (T)255);
				}

				void r(T r)
				{
					this->_r = this->clamp(r, (T)0, (T)255);
				}

				void g(T g)
				{
					this->_g = this->clamp(g, (T)0, (T)255);
				}

				void b(T b)
				{
					this->_b = this->clamp(b, (T)0, (T)255);
				}

				T r() const
				{
					return this->_r;
				}

				T g() const
				{
					return this->_g;
				}

				T b() const
				{
					return this->_b;
				}

				double normalized_r() const
				{
					return this->normalizer(this->_r);
				}

				double normalized_g() const
				{
					return this->normalizer(this->_g);
				}

				double normalized_b() const
				{
					return this->normalizer(this->_b);
				}

				ygl::math::color<T> null()
				{
					return ygl::math::color<T>(0, 0, 0, true);
				}

				bool is_null() const
				{
					return this->_null;
				}

				ygl::math::color<T> to_color(const std::string& r, const std::string& g, const std::string& b)
				{
					return ygl::math::color<T>(ygl::basic::to<T>(r), ygl::basic::to<T>(g), ygl::basic::to<T>(b));
				}

				ygl::math::color<T> ALICEBLUE()
				{
					return this->hex_to_color("F0F8FF");
				}

				ygl::math::color<T> ANTIQUEWHITE()
				{
					return this->hex_to_color("FAEBD7");
				}

				ygl::math::color<T> AQUA()
				{
					return this->hex_to_color("00FFFF");
				}

				ygl::math::color<T> AQUAMARINE()
				{
					return this->hex_to_color("7FFFD4");
				}

				ygl::math::color<T> AZURE()
				{
					return this->hex_to_color("F0FFFF");
				}

				ygl::math::color<T> BEIGE()
				{
					return this->hex_to_color("F5F5DC");
				}

				ygl::math::color<T> BISQUE()
				{
					return this->hex_to_color("FFE4C4");
				}

				ygl::math::color<T> BLACK()
				{
					return this->hex_to_color("000000");
				}

				ygl::math::color<T> BLANCHEDALMOND()
				{
					return this->hex_to_color("FFEBCD");
				}

				ygl::math::color<T> BLUE()
				{
					return this->hex_to_color("0000FF");
				}

				ygl::math::color<T> BLUELIGHT()
				{
					return this->hex_to_color("007DFF");
				}

				ygl::math::color<T> BLUEVIOLET()
				{
					return this->hex_to_color("8A2BE2");
				}

				ygl::math::color<T> BROWN()
				{
					return this->hex_to_color("A52A2A");
				}

				ygl::math::color<T> BURLYWOOD()
				{
					return this->hex_to_color("DEB887");
				}

				ygl::math::color<T> CADETBLUE()
				{
					return this->hex_to_color("5F9EA0");
				}

				ygl::math::color<T> CHARTREUSE()
				{
					return this->hex_to_color("7FFF00");
				}

				ygl::math::color<T> CHOCOLATE()
				{
					return this->hex_to_color("D2691E");
				}

				ygl::math::color<T> CORAL()
				{
					return this->hex_to_color("FF7F50");
				}

				ygl::math::color<T> CORNFLOWERBLUE()
				{
					return this->hex_to_color("6495ED");
				}

				ygl::math::color<T> CORNSILK()
				{
					return this->hex_to_color("FFF8DC");
				}

				ygl::math::color<T> CRIMSON()
				{
					return this->hex_to_color("DC143C");
				}

				ygl::math::color<T> CYAN()
				{
					return this->hex_to_color("00FFFF");
				}

				ygl::math::color<T> DARKBLUE()
				{
					return this->hex_to_color("00008B");
				}

				ygl::math::color<T> DARKCYAN()
				{
					return this->hex_to_color("008B8B");
				}

				ygl::math::color<T> DARKGOLDENROD()
				{
					return this->hex_to_color("B8860B");
				}

				ygl::math::color<T> DARKGRAY()
				{
					return this->hex_to_color("A9A9A9");
				}

				ygl::math::color<T> DARKGREEN()
				{
					return this->hex_to_color("006400");
				}

				ygl::math::color<T> DARKKHAKI()
				{
					return this->hex_to_color("BDB76B");
				}

				ygl::math::color<T> DARKMAGENTA()
				{
					return this->hex_to_color("8B008B");
				}

				ygl::math::color<T> DARKOLIVEGREEN()
				{
					return this->hex_to_color("556B2F");
				}

				ygl::math::color<T> DARKORANGE()
				{
					return this->hex_to_color("FF8C00");
				}

				ygl::math::color<T> DARKORCHID()
				{
					return this->hex_to_color("9932CC");
				}

				ygl::math::color<T> DARKRED()
				{
					return this->hex_to_color("8B0000");
				}

				ygl::math::color<T> DARKSALMON()
				{
					return this->hex_to_color("E9967A");
				}

				ygl::math::color<T> DARKSEAGREEN()
				{
					return this->hex_to_color("8FBC8F");
				}

				ygl::math::color<T> DARKSLATEBLUE()
				{
					return this->hex_to_color("483D8B");
				}

				ygl::math::color<T> DARKSLATEGRAY()
				{
					return this->hex_to_color("2F4F4F");
				}

				ygl::math::color<T> DARKSLATEGREY()
				{
					return this->hex_to_color("2F4F4F");
				}

				ygl::math::color<T> DARKTURQUOISE()
				{
					return this->hex_to_color("00CED1");
				}

				ygl::math::color<T> DARKVIOLET()
				{
					return this->hex_to_color("9400D3");
				}

				ygl::math::color<T> DEEPPINK()
				{
					return this->hex_to_color("FF1493");
				}

				ygl::math::color<T> DEEPSKYBLUE()
				{
					return this->hex_to_color("00BFFF");
				}

				ygl::math::color<T> DIMGRAY()
				{
					return this->hex_to_color("696969");
				}

				ygl::math::color<T> DODGERBLUE()
				{
					return this->hex_to_color("1E90FF");
				}

				ygl::math::color<T> FIREBRICK()
				{
					return this->hex_to_color("B22222");
				}

				ygl::math::color<T> FLORALWHITE()
				{
					return this->hex_to_color("FFFAF0");
				}

				ygl::math::color<T> FORESTGREEN()
				{
					return this->hex_to_color("228B22");
				}

				ygl::math::color<T> FUCHSIA()
				{
					return this->hex_to_color("FF00FF");
				}

				ygl::math::color<T> GAINSBORO()
				{
					return this->hex_to_color("DCDCDC");
				}

				ygl::math::color<T> GHOSTWHITE()
				{
					return this->hex_to_color("F8F8FF");
				}

				ygl::math::color<T> GOLD()
				{
					return this->hex_to_color("FFD700");
				}

				ygl::math::color<T> GOLDENROD()
				{
					return this->hex_to_color("DAA520");
				}

				ygl::math::color<T> GREY()
				{
					return this->hex_to_color("808080");
				}

				ygl::math::color<T> GREEN()
				{
					return this->hex_to_color("008000");
				}

				ygl::math::color<T> GREENYELLOW()
				{
					return this->hex_to_color("ADFF2F");
				}

				ygl::math::color<T> HONEYDEW()
				{
					return this->hex_to_color("F0FFF0");
				}

				ygl::math::color<T> HOTPINK()
				{
					return this->hex_to_color("FF69B4");
				}

				ygl::math::color<T> INDIANRED()
				{
					return this->hex_to_color("CD5C5C");
				}

				ygl::math::color<T> INDIGO ()
				{
					return this->hex_to_color("4B0082");
				}

				ygl::math::color<T> IVORY()
				{
					return this->hex_to_color("FFFFF0");
				}

				ygl::math::color<T> KHAKI()
				{
					return this->hex_to_color("F0E68C");
				}

				ygl::math::color<T> LAVENDER()
				{
					return this->hex_to_color("E6E6FA");
				}

				ygl::math::color<T> LAVENDERBLUSH()
				{
					return this->hex_to_color("FFF0F5");
				}

				ygl::math::color<T> LAWNGREEN()
				{
					return this->hex_to_color("7CFC00");
				}

				ygl::math::color<T> LEMONCHIFFON()
				{
					return this->hex_to_color("FFFACD");
				}

				ygl::math::color<T> LIGHTBLUE()
				{
					return this->hex_to_color("ADD8E6");
				}

				ygl::math::color<T> LIGHTCORAL()
				{
					return this->hex_to_color("F08080");
				}

				ygl::math::color<T> LIGHTCYAN()
				{
					return this->hex_to_color("E0FFFF");
				}

				ygl::math::color<T> LIGHTGOLDENRODYELLOW()
				{
					return this->hex_to_color("FAFAD2");
				}

				ygl::math::color<T> LIGHTGREY()
				{
					return this->hex_to_color("D3D3D3");
				}

				ygl::math::color<T> LIGHTGREEN()
				{
					return this->hex_to_color("90EE90");
				}

				ygl::math::color<T> LIGHTPINK()
				{
					return this->hex_to_color("FFB6C1");
				}

				ygl::math::color<T> LIGHTSALMON()
				{
					return this->hex_to_color("FFA07A");
				}

				ygl::math::color<T> LIGHTSEAGREEN()
				{
					return this->hex_to_color("20B2AA");
				}

				ygl::math::color<T> LIGHTSKYBLUE()
				{
					return this->hex_to_color("87CEFA");
				}

				ygl::math::color<T> LIGHTSLATEGRAY()
				{
					return this->hex_to_color("778899");
				}

				ygl::math::color<T> LIGHTSTEELBLUE()
				{
					return this->hex_to_color("B0C4DE");
				}

				ygl::math::color<T> LIGHTYELLOW()
				{
					return this->hex_to_color("FFFFE0");
				}

				ygl::math::color<T> LIME()
				{
					return this->hex_to_color("00FF00");
				}

				ygl::math::color<T> LIMEGREEN()
				{
					return this->hex_to_color("32CD32");
				}

				ygl::math::color<T> LINEN()
				{
					return this->hex_to_color("FAF0E6");
				}

				ygl::math::color<T> MAGENTA()
				{
					return this->hex_to_color("FF00FF");
				}

				ygl::math::color<T> MAROON()
				{
					return this->hex_to_color("800000");
				}

				ygl::math::color<T> MEDIUMAQUAMARINE()
				{
					return this->hex_to_color("66CDAA");
				}

				ygl::math::color<T> MEDIUMBLUE()
				{
					return this->hex_to_color("0000CD");
				}

				ygl::math::color<T> MEDIUMORCHID()
				{
					return this->hex_to_color("BA55D3");
				}

				ygl::math::color<T> MEDIUMPURPLE()
				{
					return this->hex_to_color("9370DB");
				}

				ygl::math::color<T> MEDIUMSEAGREEN()
				{
					return this->hex_to_color("3CB371");
				}

				ygl::math::color<T> MEDIUMSLATEBLUE()
				{
					return this->hex_to_color("7B68EE");
				}

				ygl::math::color<T> MEDIUMSPRINGGREEN()
				{
					return this->hex_to_color("00FA9A");
				}

				ygl::math::color<T> MEDIUMTURQUOISE()
				{
					return this->hex_to_color("48D1CC");
				}

				ygl::math::color<T> MEDIUMVIOLETRED()
				{
					return this->hex_to_color("C71585");
				}

				ygl::math::color<T> MIDNIGHTBLUE()
				{
					return this->hex_to_color("191970");
				}

				ygl::math::color<T> MINTCREAM()
				{
					return this->hex_to_color("F5FFFA");
				}

				ygl::math::color<T> MISTYROSE()
				{
					return this->hex_to_color("FFE4E1");
				}

				ygl::math::color<T> MOCCASIN()
				{
					return this->hex_to_color("FFE4B5");
				}

				ygl::math::color<T> NAVAJOWHITE()
				{
					return this->hex_to_color("FFDEAD");
				}

				ygl::math::color<T> NAVY()
				{
					return this->hex_to_color("000080");
				}

				ygl::math::color<T> OLDLACE()
				{
					return this->hex_to_color("FDF5E6");
				}

				ygl::math::color<T> OLIVE()
				{
					return this->hex_to_color("808000");
				}

				ygl::math::color<T> OLIVEDRAB()
				{
					return this->hex_to_color("6B8E23");
				}

				ygl::math::color<T> ORANGE()
				{
					return this->hex_to_color("FFA500");
				}

				ygl::math::color<T> ORANGERED()
				{
					return this->hex_to_color("FF4500");
				}

				ygl::math::color<T> ORCHID()
				{
					return this->hex_to_color("DA70D6");
				}

				ygl::math::color<T> PALEGOLDENROD()
				{
					return this->hex_to_color("EEE8AA");
				}

				ygl::math::color<T> PALEGREEN()
				{
					return this->hex_to_color("98FB98");
				}

				ygl::math::color<T> PALETURQUOISE()
				{
					return this->hex_to_color("AFEEEE");
				}

				ygl::math::color<T> PALEVIOLETRED()
				{
					return this->hex_to_color("DB7093");
				}

				ygl::math::color<T> PAPAYAWHIP()
				{
					return this->hex_to_color("FFEFD5");
				}

				ygl::math::color<T> PEACHPUFF()
				{
					return this->hex_to_color("FFDAB9");
				}

				ygl::math::color<T> PERU()
				{
					return this->hex_to_color("CD853F");
				}

				ygl::math::color<T> PINK()
				{
					return this->hex_to_color("FFC0CB");
				}

				ygl::math::color<T> PLUM()
				{
					return this->hex_to_color("DDA0DD");
				}

				ygl::math::color<T> POWDERBLUE()
				{
					return this->hex_to_color("B0E0E6");
				}

				ygl::math::color<T> PURPLE()
				{
					return this->hex_to_color("800080");
				}

				ygl::math::color<T> REBECCAPURPLE()
				{
					return this->hex_to_color("663399");
				}

				ygl::math::color<T> RED()
				{
					return this->hex_to_color("FF0000");
				}

				ygl::math::color<T> ROSYBROWN()
				{
					return this->hex_to_color("BC8F8F");
				}

				ygl::math::color<T> ROYALBLUE()
				{
					return this->hex_to_color("4169E1");
				}

				ygl::math::color<T> SADDLEBROWN()
				{
					return this->hex_to_color("8B4513");
				}

				ygl::math::color<T> SALMON()
				{
					return this->hex_to_color("FA8072");
				}

				ygl::math::color<T> SANDYBROWN()
				{
					return this->hex_to_color("F4A460");
				}

				ygl::math::color<T> SEAGREEN()
				{
					return this->hex_to_color("2E8B57");
				}

				ygl::math::color<T> SEASHELL()
				{
					return this->hex_to_color("FFF5EE");
				}

				ygl::math::color<T> SIENNA()
				{
					return this->hex_to_color("A0522D");
				}

				ygl::math::color<T> SILVER()
				{
					return this->hex_to_color("C0C0C0");
				}

				ygl::math::color<T> SKYBLUE()
				{
					return this->hex_to_color("87CEEB");
				}

				ygl::math::color<T> SLATEBLUE()
				{
					return this->hex_to_color("6A5ACD");
				}

				ygl::math::color<T> SLATEGRAY()
				{
					return this->hex_to_color("708090");
				}

				ygl::math::color<T> SNOW()
				{
					return this->hex_to_color("FFFAFA");
				}

				ygl::math::color<T> SPRINGGREEN()
				{
					return this->hex_to_color("00FF7F");
				}

				ygl::math::color<T> STEELBLUE()
				{
					return this->hex_to_color("4682B4");
				}

				ygl::math::color<T> TAN()
				{
					return this->hex_to_color("D2B48C");
				}

				ygl::math::color<T> TEAL()
				{
					return this->hex_to_color("008080");
				}

				ygl::math::color<T> THISTLE()
				{
					return this->hex_to_color("D8BFD8");
				}

				ygl::math::color<T> TOMATO()
				{
					return this->hex_to_color("FF6347");
				}

				ygl::math::color<T> TURQUOISE()
				{
					return this->hex_to_color("40E0D0");
				}

				ygl::math::color<T> VIOLET()
				{
					return this->hex_to_color("EE82EE");
				}

				ygl::math::color<T> WHEAT()
				{
					return this->hex_to_color("F5DEB3");
				}

				ygl::math::color<T> WHITE()
				{
					return this->hex_to_color("FFFFFF");
				}

				ygl::math::color<T> WHITESMOKE()
				{
					return this->hex_to_color("F5F5F5");
				}

				ygl::math::color<T> YELLOW()
				{
					return this->hex_to_color("FFFF00");
				}

				ygl::math::color<T> YELLOWGREEN()
				{
					return this->hex_to_color("9ACD32");
				}

				const ygl::math::color<T>& operator++()
				{
					this->_r++;
					this->_g++;
					this->_b++;
					return *this;
				}

				const ygl::math::color<T>& operator++(int)
				{
					++this->_r;
					++this->_g;
					++this->_b;
					return *this;
				}

				const ygl::math::color<T>& operator--()
				{
					this->_r--;
					this->_g--;
					this->_b--;
					return *this;
				}

				const ygl::math::color<T>& operator--(int)
				{
					--this->_r;
					--this->_g;
					--this->_b;
					return *this;
				}

				const ygl::math::color<T>& operator+(const ygl::math::color<T>& color)
				{
					this->_r = this->_r + color.r();
					this->_g = this->_g + color.g();
					this->_b = this->_b + color.b();
					return *this;
				}

				const ygl::math::color<T>& operator+=(const ygl::math::color<T>& color)
				{
					this->_r = this->_r + color.r();
					this->_g = this->_g + color.g();
					this->_b = this->_b + color.b();
					return *this;
				}

				const ygl::math::color<T>& operator-(const ygl::math::color<T>& color)
				{
					this->_r = this->_r - color.r();
					this->_g = this->_g - color.g();
					this->_b = this->_b - color.b();
					return *this;
				}

				const ygl::math::color<T>& operator-=(const ygl::math::color<T>& color)
				{
					this->_r = this->_r - color.r();
					this->_g = this->_g - color.g();
					this->_b = this->_b - color.b();
					return *this;
				}

				const ygl::math::color<T>& operator*(const ygl::math::color<T>& color)
				{
					this->_r = this->_r * color.r();
					this->_g = this->_g * color.g();
					this->_b = this->_b * color.b();
					return *this;
				}

				const ygl::math::color<T>& operator*=(const ygl::math::color<T>& color)
				{
					this->_r = this->_r * color.r();
					this->_g = this->_g * color.g();
					this->_b = this->_b * color.b();
					return *this;
				}

				const ygl::math::color<T>& operator/(const ygl::math::color<T>& color)
				{
					this->_r = this->_r / color.r();
					this->_g = this->_g / color.g();
					this->_b = this->_b / color.b();
					return *this;
				}

				const ygl::math::color<T>& operator/=(const ygl::math::color<T>& color)
				{
					this->_r = this->_r / color.r();
					this->_g = this->_g / color.g();
					this->_b = this->_b / color.b();
					return *this;
				}

				const ygl::math::color<T>& operator=(const ygl::math::color<T>& color)
				{
					this->_r = color.r();
					this->_g = color.g();
					this->_b = color.b();
					return *this;
				}

				bool operator==(const ygl::math::color<T>& color) const
				{
					return this->_r == color.r() && this->_g == color.g() && this->_b == color.b();
				}

				bool operator!=(const ygl::math::color<T>& color) const
				{
					return this->_r != color.r() || this->_g != color.g() || this->_b != color.b();
				}

				bool operator>(const ygl::math::color<T>& color) const
				{
					return this->_r > color.r() || this->_g > color.g() || this->_b > color.b();
				}

				bool operator>=(const ygl::math::color<T>& color) const
				{
					return this->_r >= color.r() || this->_g >= color.g() || this->_b >= color.b();
				}

				bool operator<(const ygl::math::color<T>& color) const
				{
					return this->_r < color.r() || this->_g < color.g() || this->_b < color.b();
				}

				bool operator<=(const ygl::math::color<T>& color) const
				{
					return this->_r <= color.r() || this->_g <= color.g() || this->_b <= color.b();
				}

				friend std::ostream& operator<<(std::ostream& stream, const ygl::math::color<T>& color)
				{
					return stream << "COLOR { R: " << color.r() << " G: " << color.g() << " B: " << color.b() << " }";
				}

				friend std::istream& operator>>(std::istream& stream, color& color)
				{
					std::string garbage;
					T r;
					T g;
					T b;

					stream >> garbage >> garbage >> garbage >> r >> garbage >> g >> garbage >> b >> garbage;

					color.fill(r, g, b);

					return stream;
				}

			private:

				color(T r, T g, T b, bool null) :
					_r(r),
					_g(g),
					_b(b),
					_null(null)
				{
				}

				int to_hex(const std::string& hex)
				{
					int value = 0;
					int a = 0;
					int b = hex.length() - 1;

					for (; b >= 0; a++, b--)
					{
						if (hex[b] >= '0' && hex[b] <= '9')
						{
							value += (hex[b] - '0') * (1 << (a * 4));
						}
						else
						{
							switch (hex[b])
							{
								case 'A':
								case 'a':
									value += 10 * (1 << (a * 4));
									break;
								case 'B':
								case 'b':
									value += 11 * (1 << (a * 4));
									break;
								case 'C':
								case 'c':
									value += 12 * (1 << (a * 4));
									break;
								case 'D':
								case 'd':
									value += 13 * (1 << (a * 4));
									break;
								case 'E':
								case 'e':
									value += 14 * (1 << (a * 4));
									break;
								case 'F':
								case 'f':
									value += 15 * (1 << (a * 4));
									break;
								default:
									exit(0);
									break;
							}
						}
					}

					return value;
				}

				ygl::math::color<T> hex_to_color(const std::string& hex)
				{
					std::string r = hex.substr(0, 2);
					std::string g = hex.substr(2, 2);
					std::string b = hex.substr(4, 2);

					return ygl::math::color<T>(this->to_hex(r), this->to_hex(g), this->to_hex(b));
				}

				T clamp(T value, T min, T max)
				{
					if (value > max) {
						return max;
					}
					if (value < min) {
						return min;
					}
					return value;
				}

				double normalizer(T org)
				{
					return (double)org / 255.0;
				}

			protected:

				T _r { 0 };
				T _g { 0 };
				T _b { 0 };
				bool _null  { false };
		};

		typedef ygl::math::color<int>    colori;
		typedef ygl::math::color<std::size_t>   colorui;
		typedef ygl::math::color<float>  colorf;
		typedef ygl::math::color<double> colord;
	}
}

#endif /* YGL_MATH_COLOR_H_ */
