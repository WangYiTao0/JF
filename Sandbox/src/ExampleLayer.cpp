
#include <JFEngine.h>

#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
	: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
{

	m_VertexArray.reset(JF::VertexArray::Create());

	float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
	};

	std::shared_ptr<JF::VertexBuffer> vertexBuffer;
	vertexBuffer.reset(JF::VertexBuffer::Create(vertices, sizeof(vertices)));
	JF::BufferLayout layout = {
		{ JF::ShaderDataType::Float3, "a_Position" },
		{ JF::ShaderDataType::Float4, "a_Color" }
	};
	vertexBuffer->SetLayout(layout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	uint32_t indices[3] = { 0, 1, 2 };
	std::shared_ptr<JF::IndexBuffer> indexBuffer;
	indexBuffer.reset(JF::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
	m_VertexArray->SetIndexBuffer(indexBuffer);

	m_SquareVA.reset(JF::VertexArray::Create());

	float squareVertices[3 * 4] = {
		-0.75f, -0.75f, 0.0f,
		 0.75f, -0.75f, 0.0f,
		 0.75f,  0.75f, 0.0f,
		-0.75f,  0.75f, 0.0f
	};

	std::shared_ptr<JF::VertexBuffer> squareVB;
	squareVB.reset(JF::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout({
		{ JF::ShaderDataType::Float3, "a_Position" }
		});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	std::shared_ptr<JF::IndexBuffer> squareIB;
	squareIB.reset(JF::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

	std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

	m_Shader.reset(new JF::Shader(vertexSrc, fragmentSrc));

	std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

	std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

	m_BlueShader.reset(new JF::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
}

void ExampleLayer::OnUpdate(JF::Timestep ts)
{
	if (JF::Input::IsKeyPressed(JF_KEY_LEFT))
		m_CameraPosition.x -= m_CameraMoveSpeed * ts;
	else if (JF::Input::IsKeyPressed(JF_KEY_RIGHT))
		m_CameraPosition.x += m_CameraMoveSpeed * ts;

	if (JF::Input::IsKeyPressed(JF_KEY_UP))
		m_CameraPosition.y += m_CameraMoveSpeed * ts;
	else if (JF::Input::IsKeyPressed(JF_KEY_DOWN))
		m_CameraPosition.y -= m_CameraMoveSpeed * ts;

	if (JF::Input::IsKeyPressed(JF_KEY_A))
		m_CameraRotation += m_CameraRotationSpeed * ts;
	if (JF::Input::IsKeyPressed(JF_KEY_D))
		m_CameraRotation -= m_CameraRotationSpeed * ts;

	JF::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	JF::RenderCommand::Clear();

	m_Camera.SetPosition(m_CameraPosition);
	m_Camera.SetRotation(m_CameraRotation);

	JF::Renderer::BeginScene(m_Camera);

	JF::Renderer::Submit(m_BlueShader, m_SquareVA);
	JF::Renderer::Submit(m_Shader, m_VertexArray);

	JF::Renderer::EndScene();
}

void ExampleLayer::OnImGuiRender()
{

}

void ExampleLayer::OnEvent(JF::Event& event)
{

}
