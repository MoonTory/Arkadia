#include "Arkadia.h"
#include <iostream>

class Sandbox : public Arkadia::Application
{
public:
	Sandbox()
	{
		std::cout << "Hello World!\n";
		std::cin.get();
	}

	~Sandbox() {}
};

namespace Arkadia
{

	Application *CreateApplication()
	{
		return new Sandbox();
	}
}
