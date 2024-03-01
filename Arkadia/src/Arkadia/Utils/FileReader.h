#pragma once

#include <string>

namespace Arkadia {

    namespace Utils {

        class FileReader
        {
        public:
            static std::string ReadFile(const std::string& filepath);
        };

    }
}