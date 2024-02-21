-- premake5.lua
workspace "Arkadia"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"

   -- Workspace-wide build options for MSVC
   -- filter "system:windows"
   --    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Arkadia/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Arkadia/vendor/Glad/include"

LibraryDir = {}
LibraryDir["GLFW"] = ("%{wks.location}/Arkadia/vendor/GLFW/lib")
LibraryDir["Glad"] = ("%{wks.location}/Arkadia/vendor/Glad/bin".. OutputDir .. "/Glad")

include "Arkadia/vendor/Glad/premake5.lua"

group ""

group "Arkadia"
	include "Arkadia/premake5.lua"
group ""

include "App/premake5.lua"