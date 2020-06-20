#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::OnAttach()
{
	JF_PROFILE_FUNCTION();

	m_CheckerboardTexture = JF::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	JF_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(JF::Timestep ts)
{
	JF_PROFILE_FUNCTION();
	// Update
	{
		JF_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}
	// Render
	JF::Renderer2D::ResetStats();
	{
		JF_PROFILE_SCOPE("Renderer Prep");
		JF::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		JF::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		JF_PROFILE_SCOPE("Renderer Draw");
		JF::Renderer2D::BeginScene(m_CameraController.GetCamera());
		JF::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		JF::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		JF::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		JF::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		JF::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		JF::Renderer2D::EndScene();

		JF::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				JF::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		JF::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	JF_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	auto stats = JF::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());


	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(JF::Event& e)
{
	m_CameraController.OnEvent(e);
}