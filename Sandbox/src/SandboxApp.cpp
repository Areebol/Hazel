#include "hzpch.h"
#include <Hazel.h>
class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event.ToString());
	}
};

class SandBox : public Hazel::Application
{
public:
	SandBox() {
		//PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
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