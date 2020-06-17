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
    "src/**.cpp",
    "3rdPart/stb_image/**.h",
    "3rdPart/stb_image/**.cpp",
    "3rdPart/glm/glm/**.hpp",
    "3rdPart/glm/glm/**.inl",
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
    "%{IncludeDir.Glad}",
    "%{IncludeDir.ImGui}",
    "%{IncludeDir.glm}",
    "%{IncludeDir.stb_image}",
}

links
{
    "GLFW",
    "Glad",
    "ImGui",
    "opengl32.lib",
}

filter "system:windows"
    systemversion "latest"

    defines
    {
        "GLFW_INCLUDE_NONE"
    }

	filter "configurations:Debug"
		defines "JF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "JF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "JF_DIST"
		optimize "On"