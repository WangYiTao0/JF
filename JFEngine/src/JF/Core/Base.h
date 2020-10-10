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

#ifdef JF_ENABLE_ASSERTS
#define JF_ASSERT(x, ...) { if(!(x)) { JF_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define JF_CORE_ASSERT(x, ...) { if(!(x)) { JF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define JF_ASSERT(x, ...)
#define JF_CORE_ASSERT(x, ...)
#endif

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