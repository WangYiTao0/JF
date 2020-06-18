#include "jfpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace JF {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case JF::ShaderDataType::Float:    return GL_FLOAT;
		case JF::ShaderDataType::Float2:   return GL_FLOAT;
		case JF::ShaderDataType::Float3:   return GL_FLOAT;
		case JF::ShaderDataType::Float4:   return GL_FLOAT;
		case JF::ShaderDataType::Mat3:     return GL_FLOAT;
		case JF::ShaderDataType::Mat4:     return GL_FLOAT;
		case JF::ShaderDataType::Int:      return GL_INT;
		case JF::ShaderDataType::Int2:     return GL_INT;
		case JF::ShaderDataType::Int3:     return GL_INT;
		case JF::ShaderDataType::Int4:     return GL_INT;
		case JF::ShaderDataType::Bool:     return GL_BOOL;
		}

		JF_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		JF_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		JF_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		JF_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		JF_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		JF_PROFILE_FUNCTION();

		JF_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			m_VertexBufferIndex++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		JF_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}