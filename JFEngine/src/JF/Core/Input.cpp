#include "jfpch.h"
#include "JF/Core/Input.h"

#ifdef JF_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace JF {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef JF_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		JF_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}