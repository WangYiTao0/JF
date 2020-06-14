#pragma once

#include <JFEngine.h>

#ifdef JF_PLATFORM_WINDOWS

extern JF::Application* JF::CreateApplication();

int main(int argc, char** argv)
{
	auto app = JF::CreateApplication();

	app->Run();

	delete app;
}

#endif // JF_PLATFORM_WINDOWS
