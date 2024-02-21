#pragma once

#include "Arkadia/Core.h"
#include "Arkadia/Window.h"
#include "Arkadia/Events/Event.h"
#include "Arkadia/Events/ApplicationEvent.h"

namespace Arkadia
{

    class ARK_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();

}