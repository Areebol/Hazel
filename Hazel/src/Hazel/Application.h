#pragma once

#include"Core.h"

namespace Hazel {
	class HARZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}