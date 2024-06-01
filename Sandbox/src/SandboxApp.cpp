#include <Hazel.h>

class SandBox : public Hazel::Application
{
public:
	SandBox() {

	}
	~SandBox() {

	}
	void Run() {
		while(true)
			printf("hello\n");
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}