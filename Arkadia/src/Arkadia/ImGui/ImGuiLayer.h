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

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}