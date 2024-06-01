#pragma once

#ifdef HZ_PLATERFORM_WINDOWS
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	printf("Hazel Engine");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif 