#pragma once
#include "JF/Core/Base.h"

#ifdef JF_PLATFORM_WINDOWS

extern JF::Application* JF::CreateApplication();

int main(int argc, char** argv)
{
	JF::Log::Init();
	JF_CORE_INFO("Initialized Log!");

	JF_PROFILE_BEGIN_SESSION("Startup", "JF-Profile-Startup.json");
	auto app = JF::CreateApplication();
	JF_PROFILE_END_SESSION();

	JF_PROFILE_BEGIN_SESSION("Runtime", "JF-Profile-Runtime.json");
	app->Run();
	JF_PROFILE_END_SESSION();

	JF_PROFILE_BEGIN_SESSION("Shutdown", "JF-Profile-Shutdown.json");
	delete app;
	JF_PROFILE_END_SESSION();
}

#endif // JF_PLATFORM_WINDOWS
