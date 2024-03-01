#include "Arkadia.h"
#include <iostream>

class ExampleLayer : public Arkadia::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override { }

	void OnEvent(Arkadia::Event& event) override { }
};

class Sandbox : public Arkadia::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Arkadia::ImGuiLayer());
	}

	~Sandbox() { }
};

Arkadia::Application* Arkadia::CreateApplication()
{
	return new Sandbox();
}
