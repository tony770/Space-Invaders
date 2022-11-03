#pragma once

#include "PenUtil.h"

namespace Pen
{

	class PEN_API PenApp
	{
	public:

		virtual void OnUpdate();
		void Run();

	};
}