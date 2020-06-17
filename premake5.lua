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

-- Projects
group "Dependencies"
    include "JFEngine/3rdPart/glfw"
group ""

include "JFEngine"
include "Sandbox"

