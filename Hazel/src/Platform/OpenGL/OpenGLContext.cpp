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
		// ��ʼ���ɹ�
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");
		// ��ʾOpenGL��Ϣ
		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO("	Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		HZ_CORE_INFO("	Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		HZ_CORE_INFO("	Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
	}

	void OpenGLContext::SwapBuffers()
	{
		// ����window handle��ǰ�󻺳���
		glfwSwapBuffers(m_WindowHandle);
	}
}