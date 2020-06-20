#include "jfpch.h"
#include "Application.h"

#include "JF/Core/Log.h"

#include "JF/Renderer/Renderer.h"

#include "Input.h"

#include "GLFW/glfw3.h"


namespace JF {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		JF_PROFILE_FUNCTION();

		JF_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(JF_BIND_EVENT_FN(Application::OnEvent));
		
		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}


	Application::~Application()
	{
		JF_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer* layer)
	{
		JF_PROFILE_FUNCTION();
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		JF_PROFILE_FUNCTION();
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		JF_PROFILE_FUNCTION();
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(JF_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(JF_BIND_EVENT_FN(Application::OnWindowResize));
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::Run()
	{
		JF_PROFILE_FUNCTION();
		while (m_Running)
		{
			JF_PROFILE_SCOPE("RunLoop");

			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			Renderer::EndScene();

			if (!m_Minimized)
			{
				{
					JF_PROFILE_SCOPE("LayerStack OnUpdate");
					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}
			}


			m_ImGuiLayer->Begin();
			{
				JF_PROFILE_SCOPE("LayerStack OnImGuiRender");

				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		JF_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

}