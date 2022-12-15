#pragma once

#include "PenUtil.h"
#include "ShaderImplementation.h"
#include "pch.h"

namespace Pen
{
	class PEN_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragementShader);
		Shader(std::string&& vertexFile, std::string&& fragementShader);

		void Activate();

		void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals);
		void ProvideFloatValues(std::string&& valueName, const std::vector<float>& vals);

	private:
		ShaderImplementation* mImplementation;
	};
}