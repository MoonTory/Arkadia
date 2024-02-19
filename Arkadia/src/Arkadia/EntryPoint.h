#pragma once

#ifdef ARK_PLATFORM_WINDOWS

extern Arkadia::Application *Arkadia::CreateApplication();

int main(int argc, char **argv)
{
    Arkadia::Log::Init();

    auto app = Arkadia::CreateApplication();

    app->Run();

    delete app;
}

#endif