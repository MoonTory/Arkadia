#pragma once

#include "Arkadia/Core/Layer.h"
#include "Arkadia/Events/KeyEvent.h"
#include "Arkadia/Events/MouseEvent.h"
#include "Arkadia/Events/ApplicationEvent.h"

namespace Arkadia {

    class ARK_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);

        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
        bool OnMouseMovedEvent(MouseMovedEvent& event);
        bool OnMouseScrolledEvent(MouseScrolledEvent& event);
        bool OnKeyPressedEvent(KeyPressedEvent& event);
        bool OnKeyReleasedEvent(KeyReleasedEvent& event);
        bool OnKeyTypedEvent(KeyTypedEvent& event);
        bool OnWindowResizeEvent(WindowResizeEvent& event);
    private:
        float m_Time = 0.0f;
    };
}