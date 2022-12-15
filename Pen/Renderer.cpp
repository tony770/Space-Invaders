#include "pch.h"
#include "Renderer.h"

namespace Pen
{
	Renderer::Renderer()
	{
#ifdef PEN_OPENGL
		mImplementation = new OpenGLRenderer{};
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}

	void Renderer::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new Renderer;
		}
	}

	void Renderer::Draw(Picture& picture, int x, int y, int z, Shader& shader)
	{
		mImplementation->Draw(picture, x, y, z, shader);
	}

}