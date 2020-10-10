#include "jfpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

#include "JF/Core/Application.h"

#include "JF\Renderer\RendererAPI.h"
#include "Platform\OpenGL\OpenGLImguiLayer.h"

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace JF {

	ImGuiLayer* ImGuiLayer::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLImGuiLayer();
		//case RendererAPI::API::Vulkan:  return new VulkanImGuiLayer();
		}
		JF_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
}
