#pragma once

#ifdef HZ_PLATERFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HARZEL_API __declspec(dllexport)
	#else
		#define HARZEL_API __declspec(dllimport)
	#endif
#else 
	#error Hazel only support windows!
#endif