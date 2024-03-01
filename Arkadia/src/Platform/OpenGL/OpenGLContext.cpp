#include "arkpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Arkadia
{

    namespace Graphics {

        OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
            : m_WindowHandle(windowHandle)
        {
            ARK_CORE_ASSERT(windowHandle, "Window handle is null!");
        }

        void OpenGLContext::Init()
        {
            glfwMakeContextCurrent(m_WindowHandle);
            int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
            ARK_CORE_ASSERT(success, "Failed to initialize Glad!");
        }

        void OpenGLContext::SwapBuffers()
        {
            glfwSwapBuffers(m_WindowHandle);
        }
    }
}