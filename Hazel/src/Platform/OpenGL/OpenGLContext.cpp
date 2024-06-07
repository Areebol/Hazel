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
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		// 交换window handle的前后缓冲区
		glfwSwapBuffers(m_WindowHandle);
	}
}