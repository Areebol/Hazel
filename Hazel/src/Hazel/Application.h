#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}