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
IncludeDir["SpdLog"] = "%{wks.location}/Arkadia/vendor/spdlog/include"
IncludeDir["GLFW"] = "%{wks.location}/Arkadia/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Arkadia/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Arkadia/vendor/imgui"

LibraryDir = {}
LibraryDir["GLFW"] = ("%{wks.location}/Arkadia/vendor/GLFW/lib")
LibraryDir["Glad"] = ("%{wks.location}/Arkadia/vendor/Glad/bin".. OutputDir .. "/Glad")
LibraryDir["ImGui"] = ("%{wks.location}/Arkadia/vendor/imgui/bin".. OutputDir .. "/ImGui")

include "Arkadia/vendor/Glad/premake5.lua"
include "Arkadia/vendor/imgui/premake5.lua"

group ""

group "Arkadia"
	include "Arkadia/premake5.lua"
group ""

include "App/premake5.lua"