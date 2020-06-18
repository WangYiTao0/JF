#pragma once

class ExampleLayer : public JF::Layer
{
public:
	ExampleLayer();

	void OnUpdate(JF::Timestep ts) override;

	virtual void OnImGuiRender() override;

	void OnEvent(JF::Event& event) override;

private:
	std::shared_ptr<JF::Shader> m_Shader;
	std::shared_ptr<JF::VertexArray> m_VertexArray;

	std::shared_ptr<JF::Shader> m_BlueShader;
	std::shared_ptr<JF::VertexArray> m_SquareVA;

	JF::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
};