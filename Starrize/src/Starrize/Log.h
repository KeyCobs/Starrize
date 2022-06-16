#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Starrize
{
	class STARRIZE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define SR_CORE_TRACE(...)    ::Starrize::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SR_CORE_INFO(...)     ::Starrize::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SR_CORE_WARN(...)     ::Starrize::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SR_CORE_ERROR(...)    ::Starrize::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SR_CORE_FATAL(...)    ::Starrize::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SR_TRACE(...)		  ::Starrize::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SR_INFO(...)		  ::Starrize::Log::GetClientLogger()->info(__VA_ARGS__)
#define SR_WARN(...)		  ::Starrize::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SR_ERROR(...)		  ::Starrize::Log::GetClientLogger()->error(__VA_ARGS__)
#define SR_FATAL(...)		  ::Starrize::Log::GetClientLogger()->fatal(__VA_ARGS__)