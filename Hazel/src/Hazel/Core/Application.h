#pragma once

#include "Core.h"

#include "Window.h"
#include "Hazel/Core/LayerStack.h"

#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"

#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/OrthographicCamera.h"

#include "Hazel/ImGui/ImGuiLayer.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application(const std::string& name = "Hazel App");
		virtual ~Application();

		void Run();
		void Close();

		void OnEvent(Event& e);
		bool OnWindowResize(WindowResizeEvent& e);
		// Layer
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime;
	private:
		static Application* s_Instance;
		bool m_Minimized = false;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}