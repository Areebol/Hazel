#include "hzpch.h"
#include <Hazel.h>

#include "imgui/imgui.h"

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_WARN("KEY_TAB(Pool)");
	}

	void OnEvent(Hazel::Event& event) override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_WARN("KEY_TAB(Event)");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Text");
		ImGui::Text("Hello World!");
		ImGui::End();
	}
};

class SandBox : public Hazel::Application
{
public:
	SandBox() {
		PushLayer(new ExampleLayer());
	}
	~SandBox() {

	}
	void Run() {
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}