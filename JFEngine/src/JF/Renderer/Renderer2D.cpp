#include "jfpch.h"
#include "Renderer2D.h"

#include "VertexArray.h"
#include "Shader.h"
#include "RenderCommand.h"

#include <glm/gtc/matrix_transform.hpp>

namespace JF {

	struct Renderer2DStorage
	{
		Ref<VertexArray> QuadVertexArray;
		Ref<Shader> TextureShader;
		Ref<Texture2D> WhiteTexture;
	};

	static Renderer2DStorage* s_Data;

	void Renderer2D::Init()
	{
		JF_PROFILE_FUNCTION();

		s_Data = new Renderer2DStorage();
		s_Data->QuadVertexArray = VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Ref<VertexBuffer> squareVB;
		squareVB.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ ShaderDataType::Float3, "a_Position" },
			{ ShaderDataType::Float2, "a_TexCoord" }
			});
		s_Data->QuadVertexArray->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Ref<IndexBuffer> squareIB;
		squareIB.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		s_Data->QuadVertexArray->SetIndexBuffer(squareIB);

		s_Data->WhiteTexture = Texture2D::Create(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		s_Data->WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

		s_Data->TextureShader = Shader::Create("assets/shaders/Texture.glsl");
		s_Data->TextureShader->Bind();
		s_Data->TextureShader->SetInt("u_Texture", 0);
	
	}

	void Renderer2D::Shutdown()
	{
		JF_PROFILE_FUNCTION();
		delete s_Data;
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		JF_PROFILE_FUNCTION();
		s_Data->TextureShader->Bind();
		s_Data->TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
	}

	void Renderer2D::EndScene()
	{
		JF_PROFILE_FUNCTION();
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		JF_PROFILE_FUNCTION();
		s_Data->TextureShader->SetFloat4("u_Color", color);
		s_Data->WhiteTexture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data->TextureShader->SetMat4("u_Transform", transform);
		s_Data->QuadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture)
	{
		JF_PROFILE_FUNCTION();
		s_Data->TextureShader->SetFloat4("u_Color", glm::vec4(1.0f));
		texture->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		s_Data->TextureShader->SetMat4("u_Transform", transform);

		s_Data->QuadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}

	//void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color)
	//{
	//	DrawRotatedQuad({ position.x, position.y, 0.0f }, size, rotation, color);
	//}

	//void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color)
	//{
	//	JF_PROFILE_FUNCTION();

	//	constexpr size_t quadVertexCount = 4;
	//	const float textureIndex = 0.0f; // White Texture
	//	constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
	//	const float tilingFactor = 1.0f;

	//	if (s_Data.QuadIndexCount >= Renderer2DData::MaxIndices)
	//		FlushAndReset();

	//	glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
	//		* glm::rotate(glm::mat4(1.0f), glm::radians(rotation), { 0.0f, 0.0f, 1.0f })
	//		* glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });

	//	for (size_t i = 0; i < quadVertexCount; i++)
	//	{
	//		s_Data.QuadVertexBufferPtr->Position = transform * s_Data.QuadVertexPositions[i];
	//		s_Data.QuadVertexBufferPtr->Color = color;
	//		s_Data.QuadVertexBufferPtr->TexCoord = textureCoords[i];
	//		s_Data.QuadVertexBufferPtr->TexIndex = textureIndex;
	//		s_Data.QuadVertexBufferPtr->TilingFactor = tilingFactor;
	//		s_Data.QuadVertexBufferPtr++;
	//	}

	//	s_Data.QuadIndexCount += 6;

	//	s_Data.Stats.QuadCount++;
	//}

	//void Renderer2D::DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	//{
	//	DrawRotatedQuad({ position.x, position.y, 0.0f }, size, rotation, texture, tilingFactor, tintColor);
	//}

	//void Renderer2D::DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	//{
	//	JF_PROFILE_FUNCTION();

	//	constexpr size_t quadVertexCount = 4;
	//	constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };

	//	if (s_Data.QuadIndexCount >= Renderer2DData::MaxIndices)
	//		FlushAndReset();

	//	float textureIndex = 0.0f;
	//	for (uint32_t i = 1; i < s_Data.TextureSlotIndex; i++)
	//	{
	//		if (*s_Data.TextureSlots[i].get() == *texture.get())
	//		{
	//			textureIndex = (float)i;
	//			break;
	//		}
	//	}

	//	if (textureIndex == 0.0f)
	//	{
	//		if (s_Data.TextureSlotIndex >= Renderer2DData::MaxTextureSlots)
	//			FlushAndReset();

	//		textureIndex = (float)s_Data.TextureSlotIndex;
	//		s_Data.TextureSlots[s_Data.TextureSlotIndex] = texture;
	//		s_Data.TextureSlotIndex++;
	//	}

	//	glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
	//		* glm::rotate(glm::mat4(1.0f), glm::radians(rotation), { 0.0f, 0.0f, 1.0f })
	//		* glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });

	//	for (size_t i = 0; i < quadVertexCount; i++)
	//	{
	//		s_Data.QuadVertexBufferPtr->Position = transform * s_Data.QuadVertexPositions[i];
	//		s_Data.QuadVertexBufferPtr->Color = tintColor;
	//		s_Data.QuadVertexBufferPtr->TexCoord = textureCoords[i];
	//		s_Data.QuadVertexBufferPtr->TexIndex = textureIndex;
	//		s_Data.QuadVertexBufferPtr->TilingFactor = tilingFactor;
	//		s_Data.QuadVertexBufferPtr++;
	//	}

	//	s_Data.QuadIndexCount += 6;

	//	s_Data.Stats.QuadCount++;
	//}

}