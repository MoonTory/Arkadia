project "App"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("../bin-int/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs
    {
        "src",

        "../Arkadia/src",
        "../Arkadia/vendor",
        "%{IncludeDir.SpdLog}",
    }

    libdirs
    {
        "%{LibraryDir.Arkadia}",
        "%{LibraryDir.GLFW}",
        "%{LibraryDir.Glad}",
        "%{LibraryDir.ImGui}",
    }

    links
    {
        "Arkadia",
        "glfw3",
        "Glad",
        "ImGui",
        "OpenGL32",
        "gdi32"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "ARK_PLATFORM_WINDOWS", "WINDOWS" }


    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

   filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

   filter "configurations:Dist"
        defines { "DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"