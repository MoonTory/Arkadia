#pragma once

#ifdef ARK_PLATFORM_WINDOWS
#ifdef ARK_BUILD_DLL
#define ARK_API __declspec(dllexport)
#else
#define ARK_API __declspec(dllimport)
#endif
#endif

#define BIT(x) (1 << x)