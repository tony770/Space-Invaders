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

		mWidth = width;
		mHeight = height;
	}

	void Pen::PenWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	int PenWindow::GetWidth() const
	{
		return mWidth;
	}

	int PenWindow::GetHeight() const
	{
		return mHeight;
	}

	void PenWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		mImplementation->SetKeyPressedCallback(keyPressedCallback);
	}

	void PenWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		mImplementation->SetKeyReleasedCallback(keyReleasedCallback);
	}
}
