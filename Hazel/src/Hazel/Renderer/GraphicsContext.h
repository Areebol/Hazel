#pragma once

namespace Hazel {
	class GraphicsContext {
	public:
		// ��ʼ��Context
		virtual void Init() = 0;
		// ����Buffer��Context
		virtual void SwapBuffers() = 0;
	};
}