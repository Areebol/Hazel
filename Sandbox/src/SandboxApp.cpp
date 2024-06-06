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
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_WARN("KEY_TAB(Pool)");
	}

	void OnEvent(Hazel::Event& event) override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_WARN("KEY_TAB(Event)");
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