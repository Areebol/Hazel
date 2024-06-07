#pragma once

namespace Hazel {
	class GraphicsContext {
	public:
		// 初始化Context
		virtual void Init() = 0;
		// 交换Buffer的Context
		virtual void SwapBuffers() = 0;
	};
}