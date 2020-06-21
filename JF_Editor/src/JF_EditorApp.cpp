#include <JFEngine.h>
#include <JF/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace JF {

	class JFEditor : public Application
	{
	public:
		JFEditor()
			: Application("JF Editor")
		{
			PushLayer(new EditorLayer());
		}

		~JFEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new JFEditor();
	}

}