#include "lhpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"

namespace Lighthouse {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(150, 200);
		LH_TRACE(e);

		MouseScrolledEvent e2(2, 4);
		LH_CRITICAL(e2);

		/*
		std::shared_ptr<Event> e = std::make_shared<WindowResizeEvent>(1280, 720);
		LH_TRACE(*e);
		*/

		while (true) {

		}
	}
}