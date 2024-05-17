#pragma once

#ifdef LH_PLATFORM_WINDOWS

extern Lighthouse::Application* Lighthouse::CreateApplication();

int main(int argc, char** argv) {
	
	auto app = Lighthouse::CreateApplication();
	app->Run();
	delete app;
}

#endif