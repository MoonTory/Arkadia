#pragma once

#include "Arkadia/Core.h"
#include "Arkadia/Window.h"

namespace Arkadia
{

    class ARK_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application *CreateApplication();

}