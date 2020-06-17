
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
        "../JFEngine/3rdPart/spdlog/include",
    }

    links
    {
        "JFEngine",
    }

filter "system:windows"
    systemversion "latest"

    defines
    {
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
