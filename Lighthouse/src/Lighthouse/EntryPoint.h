#pragma once

#ifdef LH_PLATFORM_WINDOWS

extern Lighthouse::Application* Lighthouse::CreateApplication();

int main(int argc, char** argv) {
	Lighthouse::Log::Init();
	LH_CORE_WARN("Initialized Core log");
	int x = 1;
	LH_INFO("Initialized Client log, var test: {0}", x);

	auto app = Lighthouse::CreateApplication();
	app->Run();
	delete app;
}

#endif