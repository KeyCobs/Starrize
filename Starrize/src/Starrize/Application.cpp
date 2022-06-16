#include "Application.h"

#include "Starrize/Events/ApplicationEvent.h"
#include "Starrize/Log.h"

namespace Starrize
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SR_TRACE(e);
		while (true);
	}

}

