#include "hzpch.h"
#include "OpenGLContext.h"

namespace Hazel {
	Hazel::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
	{
		// window handle不能为空
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		// 由window handle创建context
		glfwMakeContextCurrent(m_WindowHandle);
		// 初始化glad库
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		// 初始化成功
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");
		// 提示OpenGL信息
		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO("	Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		HZ_CORE_INFO("	Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		HZ_CORE_INFO("	Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
	}

	void OpenGLContext::SwapBuffers()
	{
		// 交换window handle的前后缓冲区
		glfwSwapBuffers(m_WindowHandle);
	}
}