#include "arkpch.h"
#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Arkadia
{

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(ARK_BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application() {}

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(ARK_BIND_EVENT_FN(Application::OnWindowClose));

        ARK_CORE_INFO("{0}", e);
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

}