#pragma once

#ifdef JF_PLATFORM_WINDOWS

extern JF::Application* JF::CreateApplication();

int main(int argc, char** argv)
{
	JF::Log::Init();
	JF_CORE_INFO("Initialized Log!");

	auto app = JF::CreateApplication();

	app->Run();

	delete app;
}

#endif // JF_PLATFORM_WINDOWS
