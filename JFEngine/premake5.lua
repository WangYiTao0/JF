project "JFEngine"
kind "StaticLib"
language "c++"
cppdialect "c++17"
staticruntime "on"

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../bin-obj/" .. outputdir .. "/%{prj.name}")

pchheader "jfpch.h"
pchsource "src/jfpch.cpp"

files
{
    "src/**.h",
    "src/**.cpp"
}

defines
{
    "_CRT_SECURE_NO_WARNINGS",
}

includedirs
{
    "src",
    "3rdPart/spdlog/include",
    "%{IncludeDir.GLFW}",
}

links
{
    "GLFW",
    "opengl32.lib"
}

filter "system:windows"
    systemversion "latest"

    defines
    {
    }

filter "configurations:Debug"
    defines "JF_DEBUG"
    runtime "Debug"
    symbols "on"

filter "configurations:Release"
    defines "JF_RELEASE"
    runtime "Release"
    optimize "on"