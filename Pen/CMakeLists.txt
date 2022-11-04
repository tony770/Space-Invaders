set(SOURCE_FILES
	PenApp.cpp
	PenWindow.cpp
	GLFWcode/GLFWimplementation.cpp
   )

set(HEADER_FILES
	Pen.h
	PenApp.h
	PenUtil.h
	PenWindow.h
	WindowImplementation.h
	GLFWcode/GLFWimplementation.h
   )

add_library(Pen SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DPEN_LIB)

target_precompile_headers(Pen PRIVATE pch.h)

include_directories(../glfw/include/)
include_directories(../Pen)

target_link_libraries(Pen glfw)