#pragma once

#include "PenUtil.h"
#include "pch.h"
#include "WindowImplementation.h"

namespace Pen
{
	class PEN_API PenWindow
	{
	public:

		static void Init();
		static PenWindow* GetWindow();

		virtual void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();


	private:


		inline static PenWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };
	};
}