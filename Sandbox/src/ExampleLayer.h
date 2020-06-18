#pragma once

class ExampleLayer : public JF::Layer
{
public:
	ExampleLayer();

	void OnUpdate(JF::Timestep ts) override;

	virtual void OnImGuiRender() override;

	void OnEvent(JF::Event& e) override;

private:
	JF::ShaderLibrary m_ShaderLibrary;
	JF::Ref<JF::Shader> m_Shader;
	JF::Ref<JF::VertexArray> m_VertexArray;

	JF::Ref<JF::Shader> m_FlatColorShader;
	JF::Ref<JF::VertexArray> m_SquareVA;

	JF::Ref<JF::Texture> m_Texture, m_JFTexture;


	JF::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};