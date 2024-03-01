#pragma once

#include "Arkadia/Renderer/Context.h"

struct GLFWwindow;

namespace Arkadia
{

    namespace Graphics {

        class OpenGLContext : public Context
        {
        public:
            OpenGLContext(GLFWwindow* windowHandle);

            virtual void Init() override;
            virtual void SwapBuffers() override;

        private:
            GLFWwindow* m_WindowHandle;
        };
    }
}