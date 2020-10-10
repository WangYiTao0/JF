#pragma once

#include "JF/Core/Base.h"

#include "JF/Core/KeyCodes.h"
#include "JF/Core/MouseCodes.h"

namespace JF {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}