#include "pch.h"
#include "PenWindow.h"
#include "GLFWcode/GLFWimplementation.h"


namespace Pen
{

	void PenWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new PenWindow;

#ifdef PEN_WINDOWS
			mInstance->mImplementation = new GLFWimplementation;
#elif defined PEN_MAC
			mInstance->mImplementation = new GLFWimplementation;
#else	
			mInstance->mImplementation = new GLFWimplementation;
#endif
		}
	}

	PenWindow* Pen::PenWindow::GetWindow()
	{
		return mInstance;
	}

	void Pen::PenWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);
	}

	void Pen::PenWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}
}
