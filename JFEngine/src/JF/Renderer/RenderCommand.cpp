#include "jfpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace JF {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}