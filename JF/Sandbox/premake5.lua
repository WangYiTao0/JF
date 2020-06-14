
    project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
    }
    
    includedirs
    {
        "../JFEngine/src",
    }

    links
    {
        "JFEngine",
    }

    filter "system:windows"
    systemversion "latest"

    defines
    {
        "JF_PLATFORM_WINDOWS",
    }

filter "configurations:Debug"
    defines "_DEBUG"
    runtime "Debug"
    symbols "on"

filter "configurations:Release"
    defines "_RELEASE"
    runtime "Release"
    optimize "on"
