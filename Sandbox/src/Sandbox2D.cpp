#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"
#include <chrono>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_Texture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Hazel::Timestep ts)
{
	HZ_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	{
		HZ_PROFILE_SCOPE("Hazel::RenderCommand::Prpare");
	}		
		// Render
		Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hazel::RenderCommand::Clear();

	{
		HZ_PROFILE_SCOPE("Hazel::Renderer2D::Render");
		Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		//Hazel::Renderer2D::DrawRotatedQuad({ 1.0f,0.0f }, { 0.8f ,0.8f }, glm::radians(-45.0f), m_SquareColor);
		//Hazel::Renderer2D::DrawRotatedQuad({ -1.0f,2.0f }, { 0.8f ,0.8f }, glm::radians(25.0f), m_SquareColor);
		//Hazel::Renderer2D::DrawRotatedQuad({ -1.0f,0.0f,-0.1f }, { 1.f , 1.f }, glm::radians(125.0f), m_Texture);
		//Hazel::Renderer2D::DrawQuad({ -1.0f, -1.0f, -0.1f }, { 2.0f, 2.0f }, m_Texture, 10.0f);
		//Hazel::Renderer2D::DrawQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f }, m_Texture, 20.0f);
		Hazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		for (float y = -5.0f; y < 5.0f; y += 0.2f) {
			for (float x = -5.0f; x < 5.0f; x += 0.2f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f , (y + 5.0f) / 10.0f , 0.7f };
				Hazel::Renderer2D::DrawQuad({ x, y }, { 0.1f, 0.1f }, color);
			}
		}
		Hazel::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	HZ_PROFILE_FUNCTION();
	ImGui::Begin("Settings");
	auto stats = Hazel::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());	
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Hazel::Event& e)
{
	m_CameraController.OnEvent(e);
}