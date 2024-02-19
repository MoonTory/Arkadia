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

int main()
{
	auto app = new Sandbox();
	app->Run();

	return 0;
}