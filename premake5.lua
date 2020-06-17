workspace "JF3d"
    architecture "x64"
    targetdir "build"
    startproject "Sandbox"

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
IncludeDir["Imgui"] = "3rdPart/imgui/include"

-- Projects
group "Dependencies"
    include "JFEngine/3rdPart/glfw"
    include "JFEngine/3rdPart/glad"
    include "JFEngine/3rdPart/imgui"
group ""

include "JFEngine"
include "Sandbox"

