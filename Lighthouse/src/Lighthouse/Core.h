#pragma once

#ifdef LH_PLATFORM_WINDOWS
	#ifdef LH_BUILD_DLL
		#define LIGHTHOUSE_API __declspec(dllexport)
	#else
		#define LIGHTHOUSE_API __declspec(dllimport)
	#endif
#else
	#error Lighthouse only on Windows
#endif