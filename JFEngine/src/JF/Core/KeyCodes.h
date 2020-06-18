#pragma once

namespace JF
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define JF_KEY_SPACE           ::JF::Key::Space
#define JF_KEY_APOSTROPHE      ::JF::Key::Apostrophe    /* ' */
#define JF_KEY_COMMA           ::JF::Key::Comma         /* , */
#define JF_KEY_MINUS           ::JF::Key::Minus         /* - */
#define JF_KEY_PERIOD          ::JF::Key::Period        /* . */
#define JF_KEY_SLASH           ::JF::Key::Slash         /* / */
#define JF_KEY_0               ::JF::Key::D0
#define JF_KEY_1               ::JF::Key::D1
#define JF_KEY_2               ::JF::Key::D2
#define JF_KEY_3               ::JF::Key::D3
#define JF_KEY_4               ::JF::Key::D4
#define JF_KEY_5               ::JF::Key::D5
#define JF_KEY_6               ::JF::Key::D6
#define JF_KEY_7               ::JF::Key::D7
#define JF_KEY_8               ::JF::Key::D8
#define JF_KEY_9               ::JF::Key::D9
#define JF_KEY_SEMICOLON       ::JF::Key::Semicolon     /* ; */
#define JF_KEY_EQUAL           ::JF::Key::Equal         /* = */
#define JF_KEY_A               ::JF::Key::A
#define JF_KEY_B               ::JF::Key::B
#define JF_KEY_C               ::JF::Key::C
#define JF_KEY_D               ::JF::Key::D
#define JF_KEY_E               ::JF::Key::E
#define JF_KEY_F               ::JF::Key::F
#define JF_KEY_G               ::JF::Key::G
#define JF_KEY_H               ::JF::Key::H
#define JF_KEY_I               ::JF::Key::I
#define JF_KEY_J               ::JF::Key::J
#define JF_KEY_K               ::JF::Key::K
#define JF_KEY_L               ::JF::Key::L
#define JF_KEY_M               ::JF::Key::M
#define JF_KEY_N               ::JF::Key::N
#define JF_KEY_O               ::JF::Key::O
#define JF_KEY_P               ::JF::Key::P
#define JF_KEY_Q               ::JF::Key::Q
#define JF_KEY_R               ::JF::Key::R
#define JF_KEY_S               ::JF::Key::S
#define JF_KEY_T               ::JF::Key::T
#define JF_KEY_U               ::JF::Key::U
#define JF_KEY_V               ::JF::Key::V
#define JF_KEY_W               ::JF::Key::W
#define JF_KEY_X               ::JF::Key::X
#define JF_KEY_Y               ::JF::Key::Y
#define JF_KEY_Z               ::JF::Key::Z
#define JF_KEY_LEFT_BRACKET    ::JF::Key::LeftBracket   /* [ */
#define JF_KEY_BACKSLASH       ::JF::Key::Backslash     /* \ */
#define JF_KEY_RIGHT_BRACKET   ::JF::Key::RightBracket  /* ] */
#define JF_KEY_GRAVE_ACCENT    ::JF::Key::GraveAccent   /* ` */
#define JF_KEY_WORLD_1         ::JF::Key::World1        /* non-US #1 */
#define JF_KEY_WORLD_2         ::JF::Key::World2        /* non-US #2 */

/* Function keys */
#define JF_KEY_ESCAPE          ::JF::Key::Escape
#define JF_KEY_ENTER           ::JF::Key::Enter
#define JF_KEY_TAB             ::JF::Key::Tab
#define JF_KEY_BACKSPACE       ::JF::Key::Backspace
#define JF_KEY_INSERT          ::JF::Key::Insert
#define JF_KEY_DELETE          ::JF::Key::Delete
#define JF_KEY_RIGHT           ::JF::Key::Right
#define JF_KEY_LEFT            ::JF::Key::Left
#define JF_KEY_DOWN            ::JF::Key::Down
#define JF_KEY_UP              ::JF::Key::Up
#define JF_KEY_PAGE_UP         ::JF::Key::PageUp
#define JF_KEY_PAGE_DOWN       ::JF::Key::PageDown
#define JF_KEY_HOME            ::JF::Key::Home
#define JF_KEY_END             ::JF::Key::End
#define JF_KEY_CAPS_LOCK       ::JF::Key::CapsLock
#define JF_KEY_SCROLL_LOCK     ::JF::Key::ScrollLock
#define JF_KEY_NUM_LOCK        ::JF::Key::NumLock
#define JF_KEY_PRINT_SCREEN    ::JF::Key::PrintScreen
#define JF_KEY_PAUSE           ::JF::Key::Pause
#define JF_KEY_F1              ::JF::Key::F1
#define JF_KEY_F2              ::JF::Key::F2
#define JF_KEY_F3              ::JF::Key::F3
#define JF_KEY_F4              ::JF::Key::F4
#define JF_KEY_F5              ::JF::Key::F5
#define JF_KEY_F6              ::JF::Key::F6
#define JF_KEY_F7              ::JF::Key::F7
#define JF_KEY_F8              ::JF::Key::F8
#define JF_KEY_F9              ::JF::Key::F9
#define JF_KEY_F10             ::JF::Key::F10
#define JF_KEY_F11             ::JF::Key::F11
#define JF_KEY_F12             ::JF::Key::F12
#define JF_KEY_F13             ::JF::Key::F13
#define JF_KEY_F14             ::JF::Key::F14
#define JF_KEY_F15             ::JF::Key::F15
#define JF_KEY_F16             ::JF::Key::F16
#define JF_KEY_F17             ::JF::Key::F17
#define JF_KEY_F18             ::JF::Key::F18
#define JF_KEY_F19             ::JF::Key::F19
#define JF_KEY_F20             ::JF::Key::F20
#define JF_KEY_F21             ::JF::Key::F21
#define JF_KEY_F22             ::JF::Key::F22
#define JF_KEY_F23             ::JF::Key::F23
#define JF_KEY_F24             ::JF::Key::F24
#define JF_KEY_F25             ::JF::Key::F25

/* Keypad */
#define JF_KEY_KP_0            ::JF::Key::KP0
#define JF_KEY_KP_1            ::JF::Key::KP1
#define JF_KEY_KP_2            ::JF::Key::KP2
#define JF_KEY_KP_3            ::JF::Key::KP3
#define JF_KEY_KP_4            ::JF::Key::KP4
#define JF_KEY_KP_5            ::JF::Key::KP5
#define JF_KEY_KP_6            ::JF::Key::KP6
#define JF_KEY_KP_7            ::JF::Key::KP7
#define JF_KEY_KP_8            ::JF::Key::KP8
#define JF_KEY_KP_9            ::JF::Key::KP9
#define JF_KEY_KP_DECIMAL      ::JF::Key::KPDecimal
#define JF_KEY_KP_DIVIDE       ::JF::Key::KPDivide
#define JF_KEY_KP_MULTIPLY     ::JF::Key::KPMultiply
#define JF_KEY_KP_SUBTRACT     ::JF::Key::KPSubtract
#define JF_KEY_KP_ADD          ::JF::Key::KPAdd
#define JF_KEY_KP_ENTER        ::JF::Key::KPEnter
#define JF_KEY_KP_EQUAL        ::JF::Key::KPEqual

#define JF_KEY_LEFT_SHIFT      ::JF::Key::LeftShift
#define JF_KEY_LEFT_CONTROL    ::JF::Key::LeftControl
#define JF_KEY_LEFT_ALT        ::JF::Key::LeftAlt
#define JF_KEY_LEFT_SUPER      ::JF::Key::LeftSuper
#define JF_KEY_RIGHT_SHIFT     ::JF::Key::RightShift
#define JF_KEY_RIGHT_CONTROL   ::JF::Key::RightControl
#define JF_KEY_RIGHT_ALT       ::JF::Key::RightAlt
#define JF_KEY_RIGHT_SUPER     ::JF::Key::RightSuper
#define JF_KEY_MENU            ::JF::Key::Menu
