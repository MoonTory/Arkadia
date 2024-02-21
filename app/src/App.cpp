#include "Arkadia.h"
#include <iostream>

class Sandbox : public Arkadia::Application
{
public:
	Sandbox() {}

	~Sandbox() {}
};

namespace Arkadia
{

	Application *CreateApplication()
	{
		return new Sandbox();
	}
}
