workspace "KSTL" 
    architecture "x64"
    startproject "KSTLTest"

    configurations
    {
        "Debug", -- Used for debugging
        "Release", -- Strips out the default debugging tools but leaves in the console log developed for any engine errors
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {} 

    LibDir = {}


project "KSTL"
    location "KSTL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- pchheader "epch.h"
	-- pchsource "Engine/source/epch.cpp"

    files
    {
        "%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/source",
    }

    libdirs
    {
    }

    links
    {

    }


    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
            
        }

    filter "configurations:Debug"
        defines "_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "_RELEASE"
        runtime "Release"
        optimize "On"


project "KSTLTest"
    location "KSTLTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

    includedirs
    {
        "KSTL/source",
    }
    libdirs
    {
    }

    links
    {
        "KSTL",
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {

        }

    filter "configurations:Debug"
        defines "_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "_RELEASE"
        runtime "Release"
        optimize "On"
