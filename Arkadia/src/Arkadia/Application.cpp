#include "arkpch.h"
#include "Log.h"
#include "Application.h"
#include "Arkadia/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Arkadia
{

    Application::Application() {}

    Application::~Application() {}

    int Application::Run()
    {

        // Initialize GLFW
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW\n";
            return -1;
        }

        // Create a windowed mode window and its OpenGL context
        GLFWwindow *window = glfwCreateWindow(640, 480, "Hello GLFW", NULL, NULL);
        if (!window)
        {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            return -1;
        }

        // Make the window's context current
        glfwMakeContextCurrent(window);

        // Loop until the user closes the window
        while (!glfwWindowShouldClose(window))
        {
            // Render here

            // Swap front and back buffers
            glfwSwapBuffers(window);

            // Poll for and process events
            glfwPollEvents();
        }

        glfwTerminate(); // Clean up and close GLFW
        return 0;
    }

}