#pragma once
#include "hzpch.h"

#include "Hazel/Core/Core.h"
#include "Hazel/Core/Keycodes.h"

namespace Hazel {
	class HAZEL_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode keycode);
		static bool IsMouseButtonPressed(int button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}