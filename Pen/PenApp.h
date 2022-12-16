#pragma once

#include "pch.h"
#include "PenUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Pen
{

	class PEN_API PenApp
	{
	public:

		PenApp();
		virtual void OnUpdate();
		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
