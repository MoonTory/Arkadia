#pragma once

#include "Arkadia/Core.h"

namespace Arkadia
{

    class ARK_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application *CreateApplication();

}