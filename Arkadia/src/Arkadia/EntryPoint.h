#pragma once

#ifdef ARK_PLATFORM_WINDOWS

#include "Log.h"

extern Arkadia::Application* Arkadia::CreateApplication();

int main(int argc, char** argv)
{
    Arkadia::Log::Init();

    ARK_CORE_WARN("Initialized Log!");

    auto app = Arkadia::CreateApplication();

    app->Run();

    delete app;
}

#endif