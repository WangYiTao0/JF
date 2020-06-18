#pragma once
#include <JFEngine.h>

#include <JF/Core/EntryPoint.h>

#include "ExampleLayer.h"
#include "Sandbox2D.h"

class Sandbox : public JF::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

JF::Application* JF::CreateApplication()
{
	return new Sandbox();
}
