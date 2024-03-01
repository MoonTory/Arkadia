#include "arkpch.h"
#include "FileReader.h"

namespace Arkadia {

    namespace Utils {

        std::string FileReader::ReadFile(const std::string& filepath)
        {
            std::ifstream file(filepath);
            if (!file.is_open())
            {
                ARK_CORE_ERROR("Could not open file '{0}'", filepath);
                return "";
            }

            std::string result;
            std::string line;
            while (getline(file, line))
            {
                result += line + "\n";
            }

            file.close();
            return result;
        }
    }
}