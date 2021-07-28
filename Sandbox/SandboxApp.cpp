#include <Starrize.h>

class Sandbox : public Starrize::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Starrize::Application* Starrize::CreateApplication()
{
	return new Sandbox();
}