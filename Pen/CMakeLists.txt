set(SOURCE_FILES
	Event.cpp
	OpenGLcode/OpenGLPicture.cpp
	OpenGLcode/OpenGLShader.cpp
	OpenGLcode/OpenGLRenderer.cpp
	Picture.cpp
	Shader.cpp
	Renderer.cpp
	Unit.cpp
	PenApp.cpp
	PenWindow.cpp
	GLFWcode/GLFWimplementation.cpp
   )

set(HEADER_FILES
	Event.h
	Keys.h
	OpenGLcode/OpenGLPicture.h
	OpenGLcode/OpenGLShader.h
	OpenGLcode/OpenGLRenderer.h
	Picture.h
	Shader.h
	Renderer.h
	PictureImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	Unit.h
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
include_directories(../glad/include)
include_directories(../stbi)

target_link_libraries(Pen glfw glad stbi)