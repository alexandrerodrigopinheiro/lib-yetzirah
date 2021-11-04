#ifndef YGL_MATH_MATH_H_
#define YGL_MATH_MATH_H_

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <random>

#include "basic/basic.h"
#include "math/circle.h"
#include "math/color.h"
#include "math/point.h"
#include "math/range.h"
#include "math/rotate.h"
#include "math/size.h"
#include "math/vertex.h"
#include "random/random.h"
#include "surface.h"

namespace ygl
{
	namespace math
	{
		extern const std::size_t S11;
		extern const std::size_t S12;
		extern const std::size_t S13;
		extern const std::size_t S14;
		extern const std::size_t S21;
		extern const std::size_t S22;
		extern const std::size_t S23;
		extern const std::size_t S24;
		extern const std::size_t S31;
		extern const std::size_t S32;
		extern const std::size_t S33;
		extern const std::size_t S34;
		extern const std::size_t S41;
		extern const std::size_t S42;
		extern const std::size_t S43;
		extern const std::size_t S44;
		extern const std::size_t BLOCK_SIZE_8;
		extern const std::size_t BLOCK_SIZE_16;
		extern const std::size_t BLOCK_SIZE_32;
		extern const std::size_t BLOCK_SIZE_64;
		extern const std::size_t BLOCK_SIZE_126;
		extern const std::size_t LIFE;
		extern const std::string BASE64;
		extern const double PI;
		extern const double GRAVITY;

		inline int to_hex(const std::string& hex)
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

		inline double stagger(double org, double dst)
		{
			return (dst * 100.f / org) / 100.f;
		}

		inline double factorial(double num)
		{
			if(num <= 1)
			{
				return 1;
			}
			double fac = 1;
			for(double i = 1; i <= num; i++)
			{
				fac *= i;
			}
			return fac;
		}

		inline double choose(double a, double b )
		{
			return factorial(a) / (factorial(b ) * factorial(a - b ));
		}

		template <class T>
		inline int numumber_digits(T number)
		{
		    return ygl::basic::to_string(number).length();
		}

		template<typename T>
		inline T clamp(T value, T begin, T end)
		{
			if (value < begin)
			{
				return begin;
			}
			if (value > end)
			{
				return end;
			}
			return value;
//			return std::min(std::max(value, std::min(begin, end)), std::max(begin, end));
		}

		template<typename T>
		inline T wrap(T value, T begin, T end)
		{
			if (value < begin)
			{
				return end;
			}
			if (value > end)
			{
				return begin;
			}
			return value;
//			return std::min(std::max(value, std::min(begin, end)), std::max(begin, end));
		}

		template<typename T>
		inline double normal(T org, T max)
		{
			return (double)org / (double)max;
		}

		template<typename T>
		inline double normal_channel(T org)
		{
			return ((double)org / (double)255);
		}

		template<typename T>
		inline double normal_opacity(T org)
		{
			return (double)org / (double)100;
		}

		template<typename T>
		inline double normalize_module(T org, T max)
		{
			return ((double)org * 1.0) / (double)max;
		}

		inline double normalize_color(uint8_t color)
		{
			return normal(color, (uint8_t)255);
		}

		template<typename T>
		inline T normalize_channel(T channel)
		{
			T tmp = channel;
			tmp = tmp > (T)255 ? (T)255 : tmp;
			return tmp;
		}

		inline bool is_math(const std::string& str)
		{
			for (std::size_t i = 0; i < str.length(); i++)
			{
				char arg = str[i];
				if ((isalnum(arg) || (arg == '+') || (arg == '/')))
				{
					return true;
				}
			}
			return false;
		}

		inline bool is_math(char arg)
		{
			if ((isalnum(arg) || (arg == '+') || (arg == '/')))
			{
				return true;
			}
			return false;
		}

		template<typename T>
		inline double torad(T angle)
		{
		    return (static_cast<double>(angle) * 3.1415926535897932384626433832795028841971693993751058209749445923078164062) / 180;
		}

		template<typename T>
		inline ygl::math::point<T> shake(const ygl::math::point<T>& point, int max)
		{
			T bump_x = ygl::random::number() % (max + 1);
			T bump_y = ygl::random::number() % (max + 1);
			bool sing_x = (ygl::random::number() % (max + 1) > max / 2 ? true : false);
			bool sing_y = (ygl::random::number() % (max + 1) > max / 2 ? true : false);
			T x;
			T y;
			if (sing_x)
			{
				T y = point.x() - bump_x;
			}
			if (sing_y)
			{
				T y = point.y() - bump_y;
			}
		    return ygl::math::point<T>(x, y);
		}

		template<typename T>
		inline ygl::math::point<T> normal(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction)
		{
			ygl::math::point<T> out = position;

			out.sum_x(velocity.x());
			out.sum_y(velocity.y() + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
			return out;
		}

		template<typename T>
		inline ygl::math::point<T> _circle(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle)
		{
			ygl::math::point<T> out = position;
			out.sum_x(velocity.x() * std::cos(angle));
			out.sum_y(velocity.y() * std::sin(angle) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
			return out;
		}

		template<typename T>
		inline ygl::math::point<T> spiral(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle)
		{
			ygl::math::point<T> out = position;
			out.sum_x(velocity.x() * std::cos(angle) * std::atan(angle));
			out.sum_y(velocity.y() * std::sin(angle) * std::atan(angle) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
			return out;
		}

		template<typename T>
		inline ygl::math::point<T> tan_cos(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle)
		{
			ygl::math::point<T> out = position;
			out.sum_x(velocity.x() * std::tan(angle));
			out.sum_y(velocity.y() * std::cos(angle) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
			return out;
		}

		template<typename T>
		inline ygl::math::point<T> tan_sin(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle)
		{
			ygl::math::point<T> out = position;
			out.sum_x(velocity.x() * std::tan(angle));
			out.sum_y(velocity.y() * std::sin(angle) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
			return out;
		}

		template<typename T>
		inline ygl::math::point<T> random_1(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle, std::size_t moment)
		{
			ygl::math::point<T> out = position;
			out.sum_x(velocity.x() * std::exp(std::cos(angle + ygl::math::torad(moment))));
			out.sum_y(velocity.y() * std::abs(std::sin(angle)) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
			return out;
		}

		template<typename T>
		inline ygl::math::point<T> random_2(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle, std::size_t moment)
		{
		    double displace = ygl::math::torad(moment);
		    ygl::math::point<T> out = position;
		    out.sum_x(velocity.x() * std::exp(std::cos(angle + displace)));
		    out.sum_y(velocity.y() * std::sin(angle + displace) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
		    return out;
		}

		template<typename T>
		inline ygl::math::point<T> random_3(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle, std::size_t moment)
		{
		    double displace = ygl::math::torad(moment);
		    ygl::math::point<T> out = position;
		    out.sum_x(velocity.x() * std::exp(std::cos(angle + displace)));
			out.sum_y(velocity.y() * (std::sin(angle + displace) * std::cos(displace)) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
			return out;
		}

		template<typename T>
		inline ygl::math::point<T> random_4(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle, std::size_t moment)
		{
		    double displace = ygl::math::torad(moment);
		    ygl::math::point<T> out = position;
		    out.sum_x(velocity.x() * std::exp(std::cos(angle + displace)));
		    out.sum_y(velocity.y() * (std::cos(angle) * std::cos(displace)) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
		    return out;
		}

		template<typename T>
		inline ygl::math::point<T> random_5(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle, std::size_t moment)
		{
		    double displace = ygl::math::torad(moment);
		    ygl::math::point<T> out = position;
		    out.sum_x(velocity.x() * std::cos(displace));
		    out.sum_y(velocity.y() * std::sin(angle) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
		    return out;
		}

		template<typename T>
		inline ygl::math::point<T> random_6(const ygl::math::point<T>& position, const ygl::math::point<T>& velocity, double gravity, double friction, double angle, std::size_t moment)
		{
		    double displace = ygl::math::torad(moment);
		    ygl::math::point<T> out = position;
		    out.sum_x(velocity.x() * std::log(displace));
		    out.sum_y(velocity.y() * std::tan(angle) + gravity);
			if (out.x() > 0)
			{
				out.sub_x(friction);
			}
			if (out.x() < 0)
			{
				out.sum_x(friction);
			}
			if (out.y() > 0)
			{
				out.sub_y(friction);
			}
			if (out.y() < 0)
			{
				out.sum_y(friction);
			}
		    return out;
		}

		template<typename T>
		inline T rule_of_three(T ref, T max, T arg)
		{
			return (arg * max) / ref;
		}

		template<typename T>
		inline T delta(const T& begin, const T& end)
		{
			return begin - end;
		}

		template<typename T>
		inline T invert(T arg)
		{
			return -(arg);
		}

		template<typename T>
		inline T next_power_of_two(T arg)
		{
			return static_cast<T>(std::pow(2, std::ceil(std::log10(static_cast<double>(arg)) / std::log10(static_cast<double>(2)))));
		}

		template<typename T>
		inline bool is_power_of_two(T arg)
		{
			return (arg & (arg - 1)) != 0;
		}

		template<typename T>
		inline int round(T x)
		{
			return (int)(x + 0.5);
		}

		template<typename T>
		inline int power_of_two(T x)
		{
			double logbase2 = std::log(x) / std::log(2);
			return round(std::pow(2, std::ceil(logbase2)));
		}

		template<typename T>
		inline double normalize(T arg, double normalizing, double min, double max)
		{
			double out = static_cast<double>(arg);
			out = out < min ? min : out;
			out = out > max ? max : out;
			return out / normalizing;
		}

		template<typename T>
		inline bool in_range(const T& value, const ygl::math::range<T>& range)
		{
			return range.in_range(value);
		}

		template<typename T>
		inline bool in_range(const T& value, const T& begin, const T& end)
		{
			return value >= std::min(begin, end) && value <= std::max(begin, end);
		}

		template<typename T>
		inline bool range_intersection(const ygl::math::range<T>& org, const ygl::math::range<T>& dst)
		{
			return std::max(org.begin(), org.end()) >= std::min(dst.begin(), dst.end()) && std::min(org.begin(), org.end()) <= std::max(dst.begin(), dst.end());
		}

		template<typename T>
		inline bool range_intersection(const T& org_begin, const T& org_end, const T& dst_begin, const T& dst_end)
		{
			return std::max(org_begin, org_end) >= std::min(dst_begin, dst_end) && std::min(org_begin, org_end) <= std::max(dst_begin, dst_end);
		}

		inline double displacement_oblique(double frame, double aceleration, double velocity)
		{
			return (velocity * frame) - ((aceleration * std::pow(frame,2)) / 2);
		}

		inline double displacement_right(double frame, double velocity)
		{
			return frame * velocity;
		}

		template<typename T>
		inline T degrees_to_radians(const T& degrees)
		{
			return degrees / 180 * 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
		}

		template<typename T>
		inline T radians_to_degrees(const T& radians)
		{
			return radians * 180 / 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
		}

		template<typename T>
		inline T linear(const ygl::math::point<T>& point_0, const ygl::math::point<T>& point_1, int time)
		{
			ygl::math::point<T> final = ygl::math::point<T>();
			final.x(1 - time) * point_0.x() + time * point_1.x();
			final.y(1 - time) * point_0.y() + time * point_1.y();
			return final;
		}

		template<typename T>
		inline T quadratic_bezier(const ygl::math::point<T>& point_0, const ygl::math::point<T>& point_1, const ygl::math::point<T>& point_2, int time, const ygl::math::point<T>& point_end)
		{
			ygl::math::point<T> final = point_end || ygl::math::point<T>();
			final.x(std::pow((double)1 - time, 2) * point_0.x() + (1 - time) * 2 * time * point_1.x() + time * time * point_2.x());
			final.y(std::pow((double)1 - time, 2) * point_0.y() + (1 - time) * 2 * time * point_1.y() + time * time * point_2.y());
			return final;
		}

		template<typename T>
		inline T cubic_bezier(const ygl::math::point<T>& point_0, const ygl::math::point<T>& point_1, const ygl::math::point<T>& point_2, const ygl::math::point<T>& point_3, int time, const ygl::math::point<T>& point_end)
		{
			ygl::math::point<T> final = point_end || ygl::math::point<T>();
			final.x(
				std::pow((double)1 - time, 3) * point_0.x() +
				std::pow((double)1 - time, 2) * 3 * time * point_1.x() +
				(1 - time) * 3 * time * time * point_2.x() + time * time * time * point_3.x()
			);
			final.y(
				std::pow((double)1 - time, 3) * point_0.y() +
				std::pow((double)1 - time, 2) * 3 * time * point_1.y() +
				(1 - time) * 3 * time * time * point_2.y() + time * time * time * point_3.y()
			);
			return final;
		}

		template<typename T>
		inline T curve_bezier(const ygl::math::point<T>* points, std::size_t size, int time)
		{
			ygl::math::point<T> point;
			for(std::size_t i = 0; i < size; i++)
			{
				point += points[i] * ygl::math::choose(size - 1, i) * std::pow((double)1 - time, (double)size - 1 - i) * std::pow((double)time, (double)i);
			}
			return point;
		}

		template<typename T>
		inline ygl::math::point<T> perspective(std::size_t depth, const T& far)
		{
			return ygl::math::point<T>(far / (far + depth), far / (far + depth));
		}

		template<typename T>
		inline T far_scale(std::size_t depth, double angle)
		{
			return (T)(depth / std::tan(angle)) * (T)2;
		}

		template<typename T>
		inline T distance(const ygl::math::point<T>& begin, const ygl::math::point<T>& end)
		{
			T dx = end.x() - begin.x();
			T dy = end.y() - begin.y();
			return static_cast<T>(sqrt(static_cast<double>(dx * dx + dy + dy)));
		}

		template<typename T>
		inline T distance(const T& begin_x, const T& begin_y, const T& end_x, const T& end_y)
		{
			T dx = end_x - begin_x;
			T dy = end_y - begin_y;
			return static_cast<T>(sqrt(static_cast<double>(dx * dx + dy + dy)));
		}

		template<typename T>
		inline bool point_intersection_point(const ygl::math::point<T>& org, const ygl::math::point<T>& dst)
		{
			return org.x() == dst.x() && org.y() == dst.y();
		}

		template<typename T>
		inline bool circle_intersection_circle(const ygl::math::circle<T>& org, const ygl::math::circle<T>& dst)
		{
			return distance(org.x(), org.y(), dst.x(), dst.y()) <= org.radius() + dst.radius();
		}

		template<typename T>
		inline bool rectangle_intersection_rectangle(const ygl::math::surface<T>& org, const ygl::math::surface<T>& dst)
		{
			return range_intersection(org.x(), org.x() + org.w(), dst.x(), dst.x() + dst.w()) && range_intersection(org.y(), org.y() + org.h(), dst.y(), dst.y() + dst.h());
		}

		template<typename T>
		inline bool circle_intersection_rectangle(const ygl::math::circle<T>& circle, const ygl::math::surface<T>& rectangle)
		{
			return range_intersection(circle.x() - circle.radius(), circle.x() + circle.radius(), rectangle.x(), rectangle.x() + rectangle.w()) && range_intersection(circle.y() - circle.radius(), circle.y() + circle.radius(), rectangle.y(), rectangle.y() + rectangle.h());
		}

		template<typename T>
		inline bool point_intersection_circle(const ygl::math::point<T>& point, const ygl::math::circle<T>& circle)
		{
			return distance(point.x(), point.y(), circle.x(), circle.y()) < circle.radius();
		}

		template<typename T>
		inline bool point_intersection_rectangle(const ygl::math::point<T>& point, const ygl::math::surface<T>& rectangle)
		{
			return in_range(point.x(), rectangle.x(), rectangle.x() + rectangle.w()) && in_range(point.y(), rectangle.y(), rectangle.y() + rectangle.h());
		}

		template<typename T>
		inline bool within_manhattan_distance_3d(const ygl::math::point<T> v1, const ygl::math::point<T> v2, double distance)
		{
			double dx = std::abs(v2.x() - v1.x());
			if (dx > distance)
			{
				return false; // too far in x direction
			}
			double dy = std::abs(v2.y() - v1.y());
			if (dy > distance)
			{
				return false; // too far in y direction
			}
			double dz = std::abs(v2.z() - v1.z());
			if (dz > distance)
			{
				return false; // too far in z direction
			}
			return true; // we're within the cube
		}

		template<typename T>
		inline double manhattan_distance_3d(const ygl::math::point<T> v1, const ygl::math::point<T> v2)
		{
			double dx = std::abs((double)v2.x() - (double)v1.x());
			double dy = std::abs((double)v2.y() - (double)v1.y());
			double dz = std::abs((double)v2.z() - (double)v1.z());
			return dx + dy + dz;
		}

		template<typename T>
		inline T manhattan_distance_2d(const ygl::math::point<T> p1, const ygl::math::point<T> p2)
		{
			T dx = std::abs(p2.x() - p1.x());
			T dy = std::abs(p2.y() - p1.y());
			return dx + dy;
		}

		template<typename T>
		inline bool within_manhattan_distance_2d(const ygl::math::point<T> p1, const ygl::math::point<T> p2, T distance)
		{
			T dx = std::abs(p2.x() - p1.x());
			T dy = std::abs(p2.y() - p1.y());
			return dx + dy < distance;
		}

		template<typename T>
		inline ygl::math::point<T> normalise_point(const ygl::math::point<T>& point)
		{
			ygl::math::point<T> tmp = point;
			T magnitude = std::sqrt((point.x() * point.x()) + (point.y() * point.y()));
			// As long as the magnitude isn't zero, divide each element by the magnitude
			// to get the normalised value between -1 and +1
			if (magnitude != 0)
			{
				tmp.x(point.x() / magnitude);
				tmp.y(point.y() / magnitude);
			}
			return tmp;
		}

		template<typename T>
		inline ygl::math::point<T> point_to(const ygl::math::point<T>& p1, const ygl::math::point<T>& p2)
		{
			ygl::math::point<T> tmp(p2.x() - p1.x(), p2.y() - p1.y());
			normalise_point(tmp);
			return tmp;
		}

		template<typename T>
		inline T point_product(const ygl::math::point<T>& p1, const ygl::math::point<T>& p2)
		{
			return p1.x() * p2.x() + p1.y() * p2.y();
		}

		template<typename T>
		inline ygl::math::point<T> cross_product(const ygl::math::point<T>& v1, const ygl::math::point<T>& v2)
		{
			return ygl::math::point<T>(v1.y() * v2.z() - v1.z() * v2.y(), v1.z() * v2.x() - v1.x() * v2.z(), v1.x() * v2.y() - v1.y() * v2.x());
		}

		template<typename T>
		inline ygl::math::color<T> color_random(T min = 0, T max = 255)
		{
			T r = std::rand() % max + min;
			T g = std::rand() % max + min;
			T b = std::rand() % max + min;
			return ygl::math::color<T>(r, g, b);
		}

		template<typename T>
		inline ygl::math::color<T> color_interpolate_with(const ygl::math::color<T>& org, const ygl::math::color<T>& dst, double factor)
		{
			T r = dst.r() * factor + (org.r() * (1.0f - factor));
			T g = dst.g() * factor + (org.g() * (1.0f - factor));
			T b = dst.b() * factor + (org.b() * (1.0f - factor));
//			if (red > 1.0f)
//			{
//				red = 1.0f;
//			}
//			if (green > 1.0f)
//			{
//				green = 1.0f;
//			}
//			if (blue > 1.0f)
//			{
//				blue = 1.0f;
//			}
			return ygl::math::color<T>(r, g, b);
		}

		template<typename T>
		inline T opacity_random(T min = 0, T max = 100)
		{
			return T(std::rand() % max + min);
		}
		// interpolation

		inline std::vector<double> linear(double begin, double end, int interval)
		{
			std::vector<double> vec;
			double size = (end - begin) / 10;
			vec.push_back(begin);
			for (int i = 1; i < interval - 1; i++)
			{
				vec.push_back(vec.back() + size);
			}
			vec.push_back(end);
			return vec;
		}

		inline std::vector<ygl::math::pointd> sinusoidal(double interval, double height, double speed)
		{
			std::vector<ygl::math::pointd> vec;
			for (double angle = 0; angle < interval; angle += speed)
			{
				vec.push_back(ygl::math::pointd(angle * height, std::sin(angle) * height, 0.0));
			}
			return vec;
		}

		inline double lerp(double norm, double min, double max)
		{
			return (max - min) * norm + min;
		}

		inline double normalize(double value, double min, double max)
		{
			return (value - min) / (max - min);
		}

		inline double map(double value, double src_min, double src_max, double dst_min, double dst_max)
		{
			return lerp(normalize(value, src_min, src_max), dst_min, dst_max);
		}

		inline double distance(const ygl::math::pointd& p0, const ygl::math::pointd& p1)
		{
			double dx = p1.x() - p0.x();
			double dy = p1.y() - p0.y();
			return std::sqrt(dx * dx + dy * dy);
		}

		inline int rand_range(int min, int max)
		{
			return min + std::rand() * (max - min);
		}

		inline int rand_int(int min, int max)
		{
			return std::floor(min + std::rand() * (max - min + 1));
		}

		inline double degrees_to_radians(double degrees)
		{
			return degrees / 180 * 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
		}

		inline double radians_to_degrees(double radians)
		{
			return radians * 180 / 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
		}

		inline double round_to_places(double value, double places)
		{
			double mult = std::pow(10, places);

			return round(value * mult) / mult;
		}

		inline double round_nearest(double value, double nearest)
		{
			return round(value / nearest) * nearest;
		}

		inline double linear(int frame, double begin, double end, int interval)
		{
			return ((end - begin) / interval) * frame;
		}

		inline ygl::math::pointd sinusoidal_point(int frame, double height, double speed)
		{
			return ygl::math::pointd((speed * frame) * height, std::sin(speed * frame) * height, 0.0);
		}

		inline double sinusoidal(int frame, double speed)
		{
			return std::sin(speed * frame);
		}

		inline ygl::math::pointd lissajous_curve(int frame, double radius, double speed)
		{
			return ygl::math::pointd(std::cos(frame * speed) * radius, std::sin(frame * speed) * radius, 0.0);
		}

		template<typename T>
		inline double angle_normalize(T angle)
		{
			T f_angle = angle;
			while(f_angle > 360.0)
			{
				f_angle -= 360.0;
			}
			while(f_angle < 0.0)
			{
				f_angle += 360.0;
			}
			return f_angle;
		}

		template<typename T>
		inline ygl::math::vertex<T> apply_scale(const ygl::math::vertex<T>& vertex, const ygl::math::size<T>& scale)
		{
			ygl::math::point<T> p1(vertex.a().x() * scale.w(), vertex.a().y() * scale.h(), vertex.d().z() * scale.l());
			ygl::math::point<T> p2(vertex.b().x() * scale.w(), vertex.b().y() * scale.h(), vertex.d().z() * scale.l());
			ygl::math::point<T> p3(vertex.c().x() * scale.w(), vertex.c().y() * scale.h(), vertex.d().z() * scale.l());
			ygl::math::point<T> p4(vertex.d().x() * scale.w(), vertex.d().y() * scale.h(), vertex.d().z() * scale.l());
			return ygl::math::vertex<T>(p1, p2, p3, p4);
		}

		template<typename T>
		inline ygl::math::vertex<T> apply_pivot(const ygl::math::vertex<T>& vertex, const ygl::math::point<T>& pivot)
		{
			T f_w = vertex.c().x() * pivot.x();
			T f_h = vertex.c().y() * pivot.y();
			T f_l = vertex.c().z() * pivot.z();
			ygl::math::point<T> p1(vertex.a().x() - f_w, vertex.a().y() - f_h, vertex.a().z() - f_l);
			ygl::math::point<T> p2(vertex.b().x() - f_w, vertex.b().y() - f_h, vertex.b().z() - f_l);
			ygl::math::point<T> p3(vertex.c().x() - f_w, vertex.c().y() - f_h, vertex.c().z() - f_l);
			ygl::math::point<T> p4(vertex.d().x() - f_w, vertex.d().y() - f_h, vertex.d().z() - f_l);
			return ygl::math::vertex<T>(p1, p2, p3, p4);
		}

		template<typename T>
		inline ygl::math::vertex<T> apply_translation(const ygl::math::vertex<T>& vertex, const ygl::math::point<T>& position)
		{
			ygl::math::point<T> p1(vertex.a().x() + position.x(), vertex.a().y() + position.y(), vertex.a().z() + position.z());
			ygl::math::point<T> p2(vertex.b().x() + position.x(), vertex.b().y() + position.y(), vertex.b().z() + position.z());
			ygl::math::point<T> p3(vertex.c().x() + position.x(), vertex.c().y() + position.y(), vertex.c().z() + position.z());
			ygl::math::point<T> p4(vertex.d().x() + position.x(), vertex.d().y() + position.y(), vertex.d().z() + position.z());
			return ygl::math::vertex<T>(p1, p2, p3, p4);
		}

		template<typename T>
		inline ygl::math::vertex<T> apply_rotation(const ygl::math::vertex<T>& vertex, const ygl::math::rotate<T>& rotate)
		{
			T f_angle_b = ygl::math::angle_normalize(rotate.b());
			  f_angle_b = ygl::math::rule_of_three(360.0, 6.284, f_angle_b);
			ygl::math::point<T> p1(
				vertex.a().x() * std::cos(f_angle_b) - vertex.a().y() * std::sin(f_angle_b),
				vertex.a().x() * std::sin(f_angle_b) + vertex.a().y() * std::cos(f_angle_b),
				vertex.a().x() * std::sin(f_angle_b) + vertex.a().y() * std::cos(f_angle_b)
			);
			ygl::math::point<T> p2(
				vertex.b().x() * std::cos(f_angle_b) - vertex.b().y() * std::sin(f_angle_b),
				vertex.b().x() * std::sin(f_angle_b) + vertex.b().y() * std::cos(f_angle_b),
				vertex.b().x() * std::sin(f_angle_b) + vertex.b().y() * std::cos(f_angle_b)
			);
			ygl::math::point<T> p3(
				vertex.c().x() * std::cos(f_angle_b) - vertex.c().y() * std::sin(f_angle_b),
				vertex.c().x() * std::sin(f_angle_b) + vertex.c().y() * std::cos(f_angle_b),
				vertex.c().x() * std::sin(f_angle_b) + vertex.c().y() * std::cos(f_angle_b)
			);
			ygl::math::point<T> p4(
				vertex.d().x() * std::cos(f_angle_b) - vertex.d().y() * std::sin(f_angle_b),
				vertex.d().x() * std::sin(f_angle_b) + vertex.d().y() * std::cos(f_angle_b),
				vertex.d().x() * std::sin(f_angle_b) + vertex.d().y() * std::cos(f_angle_b)
			);
			return ygl::math::vertex<T>(p1, p2, p3, p4);
		}

		template<typename T>
		inline ygl::math::point<T> perspective(const ygl::math::point<T>& position, const T& far)
		{
			return ygl::math::point<T>(far / (far + position.z()), far / (far + position.z()));
		}

		template<typename T>
		inline T far_scale(const ygl::math::point<T>& position, double angle)
		{
			return (T)(position.z() / std::tan(angle)) * (T)2;
		}

		template<typename T>
		inline bool square_intersection_square(const ygl::math::surface<T>& org, const ygl::math::surface<T>& dst)
		{
			return range_intersection(org.x(), org.x() + org.w(), dst.x(), dst.x() + dst.w()) && range_intersection(org.y(), org.y() + org.h(), dst.y(), dst.y() + dst.h());
		}

		template<typename T>
		inline bool circle_intersection_square(const ygl::math::circle<T>& circle, const ygl::math::surface<T>& square)
		{
			return range_intersection(circle.x() - circle.radius(), circle.x() + circle.radius(), square.x(), square.x() + square.w()) && range_intersection(circle.y() - circle.radius(), circle.y() + circle.radius(), square.y(), square.y() + square.h());
		}

		template<typename T>
		inline bool point_intersection_square(const ygl::math::point<T>& point, const ygl::math::surface<T>& square)
		{
			return in_range(point.x(), square.x(), square.x() + square.w()) && in_range(point.y(), square.y(), square.y() + square.h());
		}
	}
}

#endif /* YGL_MATH_MATH_H_ */
