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
		JF_INFO("ExampleLayer::Update");
	}

	void OnEvent(JF::Event& event) override
	{
		JF_TRACE("{0}", event);
	}

};


class Sandbox : public JF::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};



JF::Application* JF::CreateApplication()
{
	return new Sandbox();
}
