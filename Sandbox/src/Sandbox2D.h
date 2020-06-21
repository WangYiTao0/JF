#pragma once

#include "JFEngine.h"

class Sandbox2D : public JF::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(JF::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(JF::Event& e) override;
private:
	JF::OrthographicCameraController m_CameraController;

	// Temp
	JF::Ref<JF::VertexArray> m_SquareVA;
	JF::Ref<JF::Shader> m_FlatColorShader;

	JF::Ref<JF::Texture2D> m_CheckerboardTexture;


	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};