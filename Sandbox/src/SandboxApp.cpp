#include "hzpch.h"
#include <Hazel.h>
class SandBox : public Hazel::Application
{
public:
	SandBox() {

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