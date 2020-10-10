#pragma once

#include "JF/Core/Layer.h"

#include "JF/Events/ApplicationEvent.h"
#include "JF/Events/KeyEvent.h"
#include "JF/Events/MouseEvent.h"

namespace JF {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}