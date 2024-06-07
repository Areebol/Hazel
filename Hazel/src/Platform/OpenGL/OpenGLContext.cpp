#include "hzpch.h"
#include "OpenGLContext.h"

namespace Hazel {
	Hazel::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	:m_WindowHandle(windowHandle)
	{
		// window handle����Ϊ��
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		// ��window handle����context
		glfwMakeContextCurrent(m_WindowHandle);
		// ��ʼ��glad��
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		// ����window handle��ǰ�󻺳���
		glfwSwapBuffers(m_WindowHandle);
	}
}