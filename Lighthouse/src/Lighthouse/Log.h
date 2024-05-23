#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lighthouse{
	class LIGHTHOUSE_API Log
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

//core log macros
#define LH_CORE_ERROR(...) ::Lighthouse::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LH_CORE_WARN(...) ::Lighthouse::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LH_CORE_INFO(...) ::Lighthouse::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LH_CORE_TRACE(...) ::Lighthouse::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LH_CORE_CRITICAL(...) ::Lighthouse::Log::GetCoreLogger()->critical(__VA_ARGS__)
//client log macros
#define LH_ERROR(...) ::Lighthouse::Log::GetClientLogger()->error(__VA_ARGS__)
#define LH_WARN(...) ::Lighthouse::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LH_INFO(...) ::Lighthouse::Log::GetClientLogger()->info(__VA_ARGS__)
#define LH_TRACE(...) ::Lighthouse::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LH_CRITICAL(...) ::Lighthouse::Log::GetClientLogger()->critical(__VA_ARGS__)