workspace "DoAnTotNghiep"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release"
	}
	
project "GameEngine"
	location "GameEngine"
	kind "StaticLib"
	language "C++"
		
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/GameManager/**.h",
		"%{prj.name}/src/GameManager/**.cpp",
		"%{prj.name}/src/GameObject/**.h",
		"%{prj.name}/src/GameObject/**.cpp",
		"%{prj.name}/src/GameStateManager/**.h",
		"%{prj.name}/src/GameStateManager/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/include",
		"%{prj.name}/include/GLFW/include",
		"%{prj.name}/include/GLAD/include",
		"%{prj.name}/include/freetype",
		"%{prj.name}/include/Soloud",

	}

	libdirs
	{
		"%{prj.name}/lib/freetype",
		"%{prj.name}/lib/glfw",
		"%{prj.name}/lib/Soloud"
	}

	links
	{
		"opengl32.lib",
		"freetype",
		"glfw3",
		"soloud_static"
	}
	
	filter "system:windows"
		staticruntime "Off"
		systemversion "latest"

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "NDEBUG"
		optimize "On"
		
	filter "architecture:x64"
		targetdir ("bin/%{cfg.buildcfg}-x64/%{prj.name}")
		objdir ("bin-int/%{cfg.buildcfg}-x64/%{prj.name}")
		

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
		
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/GameStates/**.h",
		"%{prj.name}/src/GameStates/**.cpp"
	}
	
	includedirs
	{
		"GameEngine/src",
		"GameEngine/include",
		"GameEngine/include/GLFW/include",
		"GameEngine/include/GLAD/include",
		"GameEngine/include/freetype",
		"GameEngine/include/Soloud",
	}

	links
	{
		"GameEngine"
	}	

	filter "system:windows"
		staticruntime "Off"
		systemversion "latest"

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "NDEBUG"
		optimize "On"
	
	filter "architecture:x64"
		targetdir ("bin/%{cfg.buildcfg}-x64/%{prj.name}")
		objdir ("bin-int/%{cfg.buildcfg}-x64/%{prj.name}")