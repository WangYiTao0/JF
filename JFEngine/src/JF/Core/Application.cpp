#include "jfpch.h"
#include "Application.h"

#include "JF/Events/ApplicationEvent.h"
#include "JF/Core/Log.h"

namespace JF {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			JF_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			JF_TRACE(e);
		}

		while (true);
	}

}