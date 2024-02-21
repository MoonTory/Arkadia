#pragma once

#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Arkadia
{

    class ARK_API Log
    {
    public:
        static void Init();

        static inline std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        static inline std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define ARK_CORE_TRACE(...) ::Arkadia::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ARK_CORE_INFO(...) ::Arkadia::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ARK_CORE_WARN(...) ::Arkadia::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ARK_CORE_ERROR(...) ::Arkadia::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ARK_CORE_FATAL(...) ::Arkadia::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define ARK_TRACE(...) ::Arkadia::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ARK_INFO(...) ::Arkadia::Log::GetClientLogger()->info(__VA_ARGS__)
#define ARK_WARN(...) ::Arkadia::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ARK_ERROR(...) ::Arkadia::Log::GetClientLogger()->error(__VA_ARGS__)
#define ARK_FATAL(...) ::Arkadia::Log::GetClientLogger()->fatal(__VA_ARGS__)