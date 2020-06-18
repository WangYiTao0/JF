#pragma once

namespace JF
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define JF_MOUSE_BUTTON_0      ::JF::Mouse::Button0
#define JF_MOUSE_BUTTON_1      ::JF::Mouse::Button1
#define JF_MOUSE_BUTTON_2      ::JF::Mouse::Button2
#define JF_MOUSE_BUTTON_3      ::JF::Mouse::Button3
#define JF_MOUSE_BUTTON_4      ::JF::Mouse::Button4
#define JF_MOUSE_BUTTON_5      ::JF::Mouse::Button5
#define JF_MOUSE_BUTTON_6      ::JF::Mouse::Button6
#define JF_MOUSE_BUTTON_7      ::JF::Mouse::Button7
#define JF_MOUSE_BUTTON_LAST   ::JF::Mouse::ButtonLast
#define JF_MOUSE_BUTTON_LEFT   ::JF::Mouse::ButtonLeft
#define JF_MOUSE_BUTTON_RIGHT  ::JF::Mouse::ButtonRight
#define JF_MOUSE_BUTTON_MIDDLE ::JF::Mouse::ButtonMiddle
