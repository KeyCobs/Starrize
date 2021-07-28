#pragma once

#ifdef SR_PLATFORM_WINDOWS
	#ifdef SR_BUILD_DLL
		#define STARRIZE_API __declspec(dllexport)
	#else
		#define STARRIZE_API __declspec(dllimport)
	#endif
#else
	#error Starrize only support windows
#endif