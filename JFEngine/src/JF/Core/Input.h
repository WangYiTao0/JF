#pragma once

#include <glm/glm.hpp>
#include "JF/Core/KeyCodes.h"
#include "JF/Core/MouseCodes.h"

namespace JF {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}