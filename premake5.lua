include "./3rdPart/premake/premake_customization/solution_items.lua"

workspace "JF3d"
    architecture "x64"
    targetdir "build"
    startproject "JF_Editor"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    solution_items
	{
		".editorconfig"
	}

    flags
    {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to 

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/JFEngine/3rdPart/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/JFEngine/3rdPart/glad/include"
IncludeDir["ImGui"] = "%{wks.location}/JFEngine/3rdPart/imgui"
IncludeDir["glm"] = "%{wks.location}/JFEngine/3rdPart/glm"
IncludeDir["stb_image"] = "%{wks.location}/JFEngine/3rdPart/stb_image"
IncludeDir["entt"] = "%{wks.location}/JFEngine/3rdPart/entt/include"
IncludeDir["Vulkan"] = "%{wks.location}/JFEngine/3rdPart/Vulkan/1.2.148.1/Include"

LibraryDir = {}
LibraryDir["Vulkan"] = "%{wks.location}/JFEngine/3rdPart/Vulkan/1.2.148.1/Lib/vulkan-1.lib"

-- Projects
group "Dependencies"
    include "3rdPart/premake"
    include "JFEngine/3rdPart/glfw"
    include "JFEngine/3rdPart/glad"
    include "JFEngine/3rdPart/imgui"
group ""

include "JFEngine"
include "JF_Editor"
include "Sandbox"

