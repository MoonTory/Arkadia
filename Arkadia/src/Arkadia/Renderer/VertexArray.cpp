#include "arkpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Arkadia
{
    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:    ARK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::OpenGL:  return new OpenGLVertexArray();
        }

        ARK_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}