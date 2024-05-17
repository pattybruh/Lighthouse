#pragma once

#include "Core.h"

namespace Lighthouse{
	class LIGHTHOUSE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//def in client
	Application* CreateApplication();
}