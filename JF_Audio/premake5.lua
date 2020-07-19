
project "JF_Audio"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("../bin/" .. outputdir .. "/%{prj.name}")
	objdir("../bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"AL_LIBTYPE_STATIC"
	}

	includedirs
	{
		"src",
		"vendor/OpenAL-Soft/include",
		"vendor/OpenAL-Soft/src",
		"vendor/OpenAL-Soft/src/common",
		"vendor/libogg/include",
		"vendor/Vorbis/include",
		"vendor/minimp3"
	}

	links
	{
		"OpenAL-Soft",
		"Vorbis"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "JF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JF_DIST"
		runtime "Release"
		optimize "on"



