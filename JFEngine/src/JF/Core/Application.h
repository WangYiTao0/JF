#pragma once
#include "Base.h"

#include "Window.h"
#include "JF/Core/LayerStack.h"
#include "JF/Events/Event.h"
#include "JF/Events/ApplicationEvent.h"

#include "Window.h"

namespace JF
{
	class  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}