#pragma once
#include <JFEngine.h>

class Sandbox : public JF::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};



JF::Application* JF::CreateApplication()
{
	return new Sandbox();
}
