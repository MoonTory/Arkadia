#pragma once

#ifdef ARK_PLATFORM_WINDOWS
#ifdef ARK_DYNAMIC_LINK
#ifdef ARK_BUILD_DLL
#define ARK_API __declspec(dllexport)
#else
#define ARK_API __declspec(dllimport)
#endif
#else
#define ARK_API
#endif
#endif

#ifdef ARK_ENABLE_ASSERTS
#define ARK_ASSERT(x, ...)                                   \
    {                                                        \
        if (!(x))                                            \
        {                                                    \
            ARK_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                  \
        }                                                    \
    }
#define ARK_CORE_ASSERT(x, ...)                                   \
    {                                                             \
        if (!(x))                                                 \
        {                                                         \
            ARK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                       \
        }                                                         \
    }
#else
#define ARK_ASSERT(x, ...)
#define ARK_CORE_ASSERT(x, ...)
#endif

#define ARK_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define BIT(x) (1 << x)