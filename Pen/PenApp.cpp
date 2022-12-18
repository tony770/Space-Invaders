#include "pch.h"
#include "PenApp.h"
#include "PenUtil.h"
#include "PenWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"
#include "Event.h"
#include "Keys.h"
#include "Unit.h"


namespace Pen
{
	PenApp::PenApp()
	{
		PenWindow::Init();
		PenWindow::GetWindow()->Create(1200, 1000, "Game Window");

		Renderer::Init();
	}

	void PenApp::OnUpdate()
	{

	}

	void PenApp::Run()
	{
		PEN_LOG("Pen Running...");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			Renderer::Clear();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			PenWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
			
		}
	}
}

