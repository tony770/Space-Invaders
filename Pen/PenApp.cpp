#include "pch.h"
#include "PenApp.h"
#include "PenUtil.h"

namespace Pen
{
	void PenApp::OnUpdate()
	{

	}

	void PenApp::Run()
	{
		PEN_LOG("Pen Running...");

		while (true)
		{
			

			OnUpdate();
		}
	}
}