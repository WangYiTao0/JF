project "JFEngine"
kind "StaticLib"
language "c++"
cppdialect "c++17"
staticruntime "on"

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../bin-obj/" .. outputdir .. "/%{prj.name}")

--pchheader "aspch.h"
--pchsource "src/aspch.cpp"

files
{
    "src/**.h",
    "src/**.cpp"
}

defines
{
    "_CRT_SECURE_NO_WARNINGS",
    "JF_PLATFORM_WINDOWS"
}

includedirs
{
    "src"
}

links
{
 
}

filter "system:windows"
    systemversion "latest"

    defines
    {
    
    }

filter "configurations:Debug"
    defines "_DEBUG"
    runtime "Debug"
    symbols "on"

filter "configurations:Release"
    defines "_RELEASE"
    runtime "Release"
    optimize "on"