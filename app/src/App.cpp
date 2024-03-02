#include "Arkadia.h"

#include <iostream>

class ExampleLayer : public Arkadia::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		if (Arkadia::Input::IsKeyPressed(ARK_KEY_TAB))
			ARK_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(Arkadia::Event& event) override
	{
		if (event.GetEventType() == Arkadia::EventType::KeyPressed)
		{
			Arkadia::KeyPressedEvent& e = (Arkadia::KeyPressedEvent&)event;
			if (e.GetKeyCode() == ARK_KEY_TAB)
				ARK_TRACE("Tab key is pressed (event)!");
			ARK_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Arkadia::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() { }
};

Arkadia::Application* Arkadia::CreateApplication()
{
	return new Sandbox();
}
