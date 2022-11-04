#include "pch.h"
#include "PenApp.h"
#include "PenUtil.h"
#include "PenWindow.h"

namespace Pen
{
	void PenApp::OnUpdate()
	{

	}

	void PenApp::Run()
	{

		PEN_LOG("Pen Running...");

		PenWindow::Init();
		PenWindow::GetWindow()->Create(600, 400, "Test Window");


		while (true)
		{
			PenWindow::GetWindow()->SwapBuffers();
			OnUpdate();
		}

	}
}