#pragma once

#ifdef SR_PLATFORM_WINDOWS

extern Starrize::Application* Starrize::CreateApplication();

int main(int argc, char** argv)
{
	Starrize::Log::Init();
	SR_CORE_WARN("Initialized Log!");
	int a = 5;
	SR_INFO("Hello! var={0}", a);

	auto app = Starrize::CreateApplication();
	app->Run();
	delete app;
}
#endif