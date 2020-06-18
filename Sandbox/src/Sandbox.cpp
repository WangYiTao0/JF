#pragma once
#include <JFEngine.h>

#include <JF/Core/EntryPoint.h>

#include "ExampleLayer.h"
#include "imgui.h"

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
