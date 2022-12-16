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
		PenWindow::GetWindow()->Create(1000, 800, "Test Window");

		Renderer::Init();
	}

	void PenApp::OnUpdate()
	{

	}

	void PenApp::Run()
	{
		PEN_LOG("Pen Running...");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x{ 200 }, y{ 200 };
		PenWindow::GetWindow()->SetKeyPressedCallback([&](const KeyPressedEvent& event) {
			if (event.GetKeyCode() == PEN_KEY_LEFT) x -= 10;
			else if (event.GetKeyCode() == PEN_KEY_RIGHT) x += 10;
			});
		Picture pic{ "Assets/Textures/test.png" };

		while (true)
		{
			Renderer::Clear();

			OnUpdate();

			Pen::Renderer::Draw(pic, x, y, 1);

			std::this_thread::sleep_until(mNextFrameTime);

			PenWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
			
		}
	}
}

