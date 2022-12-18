cmake_minimum_required(VERSION 3.24)

project(final_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DPEN_WINDOWS)
elseif(APPLE)
	add_definitions(-DPEN_MAC)
else()
	add_definitions(-DPEN_LINUX)
endif()

add_definitions(-DPEN_DEBUG)
add_definitions(-DPEN_OPENGL)

add_subdirectory(Engine22)
add_subdirectory(Pen)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT Engine22)

file(COPY Engine22/Assets DESTINATION ${PROJECT_BINARY_DIR}/Engine22)
file(COPY Engine22/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Engine22/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)