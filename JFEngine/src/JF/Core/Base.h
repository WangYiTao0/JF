#pragma once
#include <memory>

#include "JF/Core/PlatformDetection.h"


#ifdef JF_DEBUG
#if defined(JF_PLATFORM_WINDOWS)
#define JF_DEBUGBREAK() __debugbreak()
#elif defined(JF_PLATFORM_LINUX)
#include <signal.h>
#define JF_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define JF_ENABLE_ASSERTS
#else
#define JF_DEBUGBREAK()
#endif

#define JF_EXPAND_MACRO(x) x
#define JF_STRINGIFY_MACRO(x) #x
#define BIT(x) (1 << x)

#define JF_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }


namespace JF {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "JF/Core/Log.h"
#include "JF/Core/Assert.h"
