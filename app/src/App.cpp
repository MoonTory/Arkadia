#include "Arkadia.h"
#include <iostream>

class Sandbox : public Ark::Application
{
public:
	Sandbox()
	{
		std::cout << "Hello World!\n";
		std::cin.get();
	}

	~Sandbox() {}
};

namespace Ark
{

	Application *CreateApplication()
	{
		return new Sandbox();
	}
}
