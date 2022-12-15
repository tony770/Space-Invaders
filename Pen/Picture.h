#pragma once

#include "pch.h"
#include "PenUtil.h"

namespace Pen
{
	class PEN_API Picture
	{
	public:

		Picture(const std::string& sourceFile);
		Picture(const std::string&& sourceFile);

		int GetHeight() const;
		int GetWidth() const;

		void Activate();

	private:
		PictureImplementation* mImplementation{ nullptr };

	};
}