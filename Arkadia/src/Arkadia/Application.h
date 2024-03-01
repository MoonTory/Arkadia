#pragma once

#include "Arkadia/Core.h"

#include "Arkadia/Window.h"
#include "Arkadia/Core/LayerStack.h"
#include "Arkadia/ImGui/ImGuiLayer.h"

#include "Arkadia/Events/Event.h"
#include "Arkadia/Events/KeyEvent.h"
#include "Arkadia/Events/ApplicationEvent.h"

#include "Arkadia/Renderer/Shader.h"
#include "Arkadia/Renderer/Buffer.h"
#include "Arkadia/Renderer/VertexArray.h"


namespace Arkadia
{

    class ARK_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnKeyPressed(KeyPressedEvent& e);
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

        unsigned int m_PolyMode = 0x1B02;

        bool m_Running = true;
        LayerStack m_LayerStack;
        ImGuiLayer* m_ImGuiLayer;
        std::unique_ptr<Window> m_Window;

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
        std::shared_ptr<VertexBuffer> m_VertexBuffer;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();

}