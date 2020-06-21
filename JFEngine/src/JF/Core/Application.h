#pragma once
#include "Base.h"

#include "Window.h"
#include "JF/Core/LayerStack.h"
#include "JF/Events/Event.h"
#include "JF/Events/ApplicationEvent.h"

#include "JF/Core/Timestep.h"

#include "JF/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace JF
{
	class  Application
	{
	public:
		Application(const std::string& name = "JF App");
		virtual ~Application();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		void Close();


		inline static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}