#pragma once

#include "Arkadia/Core.h"

namespace Arkadia
{

    class ARK_API Application
    {
    public:
        Application();
        virtual ~Application();

        int Run();
    };

    Application *CreateApplication();

}