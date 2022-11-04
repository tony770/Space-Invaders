cmake_minimum_required(VERSION 3.24)

project(final_game)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

if(WIN32)
	add_definitions(-DPEN_WINDOWS)
elseif(APPLE)
	add_definitions(-DPEN_MAC)
else()
	add_definitions(-DPEN_LINUX)
endif()

add_definitions(-DPEN_DEBUG)

add_subdirectory(Engine22)
add_subdirectory(Pen)
add_subdirectory(glfw)

set(VS_STARTUP_PROJECT Engine22)