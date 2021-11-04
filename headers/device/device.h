#ifndef YGL_DEVICE_H_
#define YGL_DEVICE_H_

#pragma once

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

namespace ygl
{
	namespace device
	{
		typedef enum button
		{
			BUTTON_INVALID = 0,
			BUTTON_EXIT,
			BUTTON_PLAY,
			BUTTON_AUTOPLAY,
			BUTTON_EXTRABALL,
			BUTTON_DECREASE_SPEED,
			BUTTON_INCREASE_SPEED,
			BUTTON_MAXIMUM_PATTERN,
			BUTTON_DECREASE_PATTERN,
			BUTTON_INCREASE_PATTERN,
			BUTTON_MAXIMUM_BET,
			BUTTON_DECREASE_BET,
			BUTTON_INCREASE_BET,
			BUTTON_CREDIT,
			BUTTON_CHANGE_PATTERN,
			BUTTON_SETTING,
			BUTTON_CASHOUT,
			BUTTON_LOG,
			BUTTON_HELP,
			BUTTON_DEBUG_FULLSCREEN,
			BUTTON_DEBUG_INFO,
			BUTTON_DEBUG_RULER,
		} button;

		std::ostream& operator<<(std::ostream& stream, const ygl::device::button& button);

		std::istream& operator>>(std::istream& stream, ygl::device::button& button);

		ygl::device::button to_button(const std::string& arg);

		typedef enum type
		{
			TYPE_NONE,
			TYPE_BUTTON,
			TYPE_KEYBOARD,
			TYPE_MOUSE,
			TYPE_TOUCH
		} type;

		std::ostream& operator<<(std::ostream& stream, const ygl::device::type& type);

		std::istream& operator>>(std::istream& stream, ygl::device::type& type);

		ygl::device::type to_type(const std::string& arg);

		typedef enum click
		{
			CLICK_NONE,
			CLICK_RELEASED,
			CLICK_PRESSED,
		} click;

		std::ostream& operator<<(std::ostream& stream, const ygl::device::click& click);

		std::istream& operator>>(std::istream& stream, ygl::device::click& click);

		ygl::device::click to_click(const std::string& arg);

		typedef enum key
		{
			KEY_NONE,
			KEY_RELEASED,
			KEY_PRESSED,
		} key;

		std::ostream& operator<<(std::ostream& stream, const ygl::device::key& key);

		std::istream& operator>>(std::istream& stream, ygl::device::key& key);

		ygl::device::key to_key(const std::string& arg);

		typedef enum cursor
		{
			CURSOR_NONE,
			CURSOR_MOTION,
			CURSOR_RELEASED,
			CURSOR_PRESSED,
		} cursor;

		std::ostream& operator<<(std::ostream& stream, const ygl::device::cursor& cursor);

		std::istream& operator>>(std::istream& stream, ygl::device::cursor& cursor);

		ygl::device::cursor to_cursor(const std::string& arg);

		typedef enum finger
		{
			FINGER_NONE,
			FINGER_MOTION,
			FINGER_RELEASED,
			FINGER_PRESSED,
		} finger;

		std::ostream& operator<<(std::ostream& stream, const ygl::device::finger& finger);

		std::istream& operator>>(std::istream& stream, ygl::device::finger& finger);

		ygl::device::finger to_finger(const std::string& arg);
	}
}

#endif /* DEVICES_H_ */
