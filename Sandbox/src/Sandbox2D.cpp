#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
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
	{
		JF_PROFILE_SCOPE("Renderer Prep");
		JF::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		JF::RenderCommand::Clear();
	}

	{
		JF_PROFILE_SCOPE("Renderer Draw");
		JF::Renderer2D::BeginScene(m_CameraController.GetCamera());
		JF::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		JF::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		JF::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		JF::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	JF_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(JF::Event& e)
{
	m_CameraController.OnEvent(e);
}