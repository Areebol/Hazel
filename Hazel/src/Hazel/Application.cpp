#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"

namespace Hazel {
	Application::Application() {
	}
	Application::~Application() {

	}
	void Application::Run()
	{
		MouseScrolledEvent e(1,2);
		HZ_ERROR(e.ToString());

		while (true);
	}
}