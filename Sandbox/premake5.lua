
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
		"src/**.cpp",
    }
    
    includedirs
    {
		"../JFEngine/3rdPart/spdlog/include",
        "../JFEngine/src",
		"../JFAudio/src",
		"../JFEngine/3rdPart",
		"../JFEngine/%{IncludeDir.glm}",
		"../JFEngine/%{IncludeDir.Glad}",
		"../JFEngine/%{IncludeDir.ImGui}",
		"../JFEngine/%{IncludeDir.entt}",
    }

    links
    {
		"JFEngine",
		"JF_Audio",
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
