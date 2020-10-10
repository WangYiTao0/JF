#include "jfpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace JF {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		JF_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		JF_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		JF_CORE_ASSERT(status, "Failed to initialize Glad!");

		JF_CORE_INFO("OpenGL Info:");
		JF_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		JF_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		JF_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	
		JF_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		JF_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}