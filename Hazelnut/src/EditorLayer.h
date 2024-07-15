#pragma 

#include "Hazel.h"

namespace Hazel {

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;
	
		virtual void OnAttach() override;
		virtual void OnDetach() override;
	
		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		OrthographicCameraController m_CameraController;
	
		// Temp
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Texture2D> m_Texture;	
		Ref<Framebuffer> m_Framebuffer;
		glm::vec4 m_SquareColor = { 0.0f, 0.0f, 0.0f, 1.0f };
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
	};

}