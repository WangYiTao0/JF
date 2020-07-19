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

    flags
    {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to 

IncludeDir = {}
IncludeDir["GLFW"] = "3rdPart/glfw/include"
IncludeDir["Glad"] = "3rdPart/glad/include"
IncludeDir["ImGui"] = "3rdPart/imgui"
IncludeDir["glm"] = "3rdPart/glm"
IncludeDir["stb_image"] = "3rdPart/stb_image"
IncludeDir["entt"] = "3rdPart/entt/include"

-- Projects
group "Dependencies"
    include "JFEngine/3rdPart/glfw"
    include "JFEngine/3rdPart/glad"
    include "JFEngine/3rdPart/imgui"

    include "JF_Audio/vendor/OpenAL-Soft"
	include "JF_Audio/vendor/libogg"
	include "JF_Audio/vendor/Vorbis"
group "Core"
    include "JFEngine"
    include "JF_Audio"

group "test"
    include "JF_Editor"
    include "Sandbox"

