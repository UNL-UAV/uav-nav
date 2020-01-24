outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

includeDir = {}

workspace "UNL-UAV"
	startproject "Sandbox"
	location "workspace"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

	pchheader "pch.hpp"
	pchsource "src/pch.cpp"

	filter "configurations:Dist"
		postbuildcommands{
			"{COPY} bin/"..outputdir.."/* builds"
		}

	filter "system:windows"
		defines "SE_WINDOWS"

	filter "system:linux"
		defines "SE_LINUX" 

	filter "system:macosx"
		defines "SE_OSX"

project "Test"
	cppdialect "C++17"
	location "workspace/sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	files{
		"test/**.h",
		"test/**.hpp",
		"test/**.c",
		"test/**.cpp",
		"include/test/**.h",
		"include/test/**.hpp",
		"include/test/**.c",
		"include/test/**.cpp"	
	}
	includedirs{
		"src",
		"include",
		"include/test",
	}
	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"
	filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"
	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"