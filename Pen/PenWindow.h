#pragma once

#include "PenUtil.h"
#include "pch.h"
#include "WindowImplementation.h"
#include "Event.h"

namespace Pen
{
	class PEN_API PenWindow
	{
	public:

		static void Init();
		static PenWindow* GetWindow();

		virtual void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();

		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);

	private:
		inline static PenWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };

	};
}