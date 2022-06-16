workspace "Starrize"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Starrize"
	location "Starrize"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"SR_PLATFORM_WINDOWS",
			"SR_BUILD_DLL",

		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SR_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "SR_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "SR_DIST"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Starrize/vendor/spdlog/include",
		"Starrize/src"
	}

	links
	{
		"Starrize"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"SR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SR_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "SR_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "SR_DIST"
		optimize "on"