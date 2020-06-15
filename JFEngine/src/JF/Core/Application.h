#pragma once
#include "Core.h"
#include "JF/Events/Event.h"

namespace JF
{
	class  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}