project "Arkadia"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir("../bin/" .. OutputDir .. "/%{prj.name}")
    objdir("../bin-int/" .. OutputDir .. "/%{prj.name}")

    pchheader "arkpch.h"
    pchsource "Arkadia/src/arkpch.cpp"

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE"
    }

    files
    {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs 
    {
        "src",

        "vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    libdirs
    {
        "%{LibraryDir.GLFW}"
    }

    links
    {
        "glfw3",
        "OpenGL32",
        "gdi32",
    }

    filter "system:windows"
        systemversion "latest"
        defines {"ARK_PLATFORM_WINDOWS", "ARK_BUILD_DLL"}
        postbuildcommands {("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. OutputDir .. "/App/\"")}

    filter "configurations:Debug"
        defines {"DEBUG"}
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines {"RELEASE"}
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines {"DIST"}
        runtime "Release"
        optimize "On"
        symbols "Off"
