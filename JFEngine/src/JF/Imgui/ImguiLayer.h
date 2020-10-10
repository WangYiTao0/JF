#pragma once

#include "JF/Core/Layer.h"


namespace JF {

	class ImGuiLayer : public Layer
	{
	public:
		virtual void Begin() = 0;
		virtual void End() = 0;

		virtual void BlockEvents(bool block) = 0;
		static ImGuiLayer* Create();
	};

}
