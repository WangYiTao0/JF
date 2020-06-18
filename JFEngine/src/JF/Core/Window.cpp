#include "jfpch.h"
#include "Window.h"

#ifdef JF_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace JF
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef JF_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		JF_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}

