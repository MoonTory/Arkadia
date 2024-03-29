#pragma once

namespace Arkadia
{
    namespace Graphics
    {
        class Context
        {
        public:
            virtual void Init() = 0;
            virtual void SwapBuffers() = 0;
        };
    }
}