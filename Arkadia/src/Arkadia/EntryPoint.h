#pragma once

#ifdef ARK_PLATFORM_WINDOWS

extern Ark::Application *Ark::CreateApplication();

int main(int argc, char **argv)
{
    auto app = Ark::CreateApplication();

    app->Run();

    delete app;
}

#endif