#pragma once

#ifdef SR_PLATFORM_WINDOWS

extern Starrize::Application* Starrize::CreateApplication();

int main(int argc, char** argv)
{
	
	auto app = Starrize::CreateApplication();
	app->Run();
	delete app;
}
#endif