#pragma once

#include "JF/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace JF {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define JF_CORE_TRACE(...)    ::JF::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JF_CORE_INFO(...)     ::JF::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JF_CORE_WARN(...)     ::JF::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JF_CORE_ERROR(...)    ::JF::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JF_CORE_CRITICAL(...) ::JF::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define JF_TRACE(...)         ::JF::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JF_INFO(...)          ::JF::Log::GetClientLogger()->info(__VA_ARGS__)
#define JF_WARN(...)          ::JF::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JF_ERROR(...)         ::JF::Log::GetClientLogger()->error(__VA_ARGS__)
#define JF_CRITICAL(...)      ::JF::Log::GetClientLogger()->critical(__VA_ARGS__)
