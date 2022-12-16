#pragma once

#include "PenUtil.h"

namespace Pen
{
	class PEN_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class PEN_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};
}

