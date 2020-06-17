#pragma once
#include <JFEngine.h>

class ExampleLayer : public JF::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (JF::Input::IsKeyPressed(JF_KEY_TAB))
			JF_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(JF::Event& event) override
	{
		if (event.GetEventType() == JF::EventType::KeyPressed)
		{
			JF::KeyPressedEvent& e = (JF::KeyPressedEvent&)event;
			if (e.GetKeyCode() == JF_KEY_TAB)
				JF_TRACE("Tab key is pressed (event)!");
			JF_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};


class Sandbox : public JF::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new JF::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};



JF::Application* JF::CreateApplication()
{
	return new Sandbox();
}
