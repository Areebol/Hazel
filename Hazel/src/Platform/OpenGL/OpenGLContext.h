#pragma once

#include "Hazel/Renderer/GraphicsContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>


namespace Hazel {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		// ��ʼ��Context
		virtual void Init() override;
		// ����Buffer��Context
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}