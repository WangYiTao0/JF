#pragma once

class ExampleLayer : public JF::Layer
{
public:
	ExampleLayer();

	void OnUpdate(JF::Timestep ts) override;

	virtual void OnImGuiRender() override;

	void OnEvent(JF::Event& event) override;

private:
	JF::ShaderLibrary m_ShaderLibrary;
	JF::Ref<JF::Shader> m_Shader;
	JF::Ref<JF::VertexArray> m_VertexArray;

	JF::Ref<JF::Shader> m_FlatColorShader;
	JF::Ref<JF::VertexArray> m_SquareVA;

	JF::Ref<JF::Texture> m_Texture, m_JFTexture;

	JF::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};