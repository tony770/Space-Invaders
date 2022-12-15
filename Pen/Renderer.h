#pragma once

#include "PenUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplementation.h"

namespace Pen
{
	class PEN_API Renderer
	{
	public:

		static void Init();

		static void Draw(Picture& picture, int x, int y, int z, Shader& shader = mDefaultShader);

	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation;

		Renderer();

		inline static Shader mDefaultShader{ "Assets/Shaders/defaultPenVertex.glsl",
			"Assets/Shaders/defaultPenFragment.glsl" };

	};
}
