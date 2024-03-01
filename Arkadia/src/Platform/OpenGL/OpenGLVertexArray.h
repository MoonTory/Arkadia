#pragma once

#include <vector>
#include <memory>
#include "Arkadia/Renderer/VertexArray.h"

namespace Arkadia
{

    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
    private:
        uint32_t m_RendererID;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
        std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
    };
}