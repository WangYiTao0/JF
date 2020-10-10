
    project "JF_Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
    }
    
    includedirs
    {
		"%{wks.location}/JFEngine/3rdPart/spdlog/include",
        "%{wks.location}/JFEngine/src",
		"%{wks.location}/JFEngine/3rdPart",
		"%{IncludeDir.glm}",
		--"../JFEngine/%{IncludeDir.Glad}",
		--"../JFEngine/%{IncludeDir.ImGui}"
		"../JFEngine/%{IncludeDir.entt}",
    }

    links
    {
        "JFEngine",
	}
	
	defines
    {

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
