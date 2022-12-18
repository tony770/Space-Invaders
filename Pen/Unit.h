#pragma once

#include "PenUtil.h"
#include "Picture.h"
#include "Renderer.h"

namespace Pen
{
	class PEN_API Unit
	{
	public:
		Unit(const std::string& picFile);
		Unit(std::string&& picFile);

		void SetCoord(int x, int y, int z);

		int ChangeX(int xDiff);
		int ChangeY(int yDiff);
		int ChangeZ(int zDiff);

		int GetX() const;
		int GetY() const;
		int GetZ() const;
		int GetWidth() const;
		int GetHeight() const;

		void Draw();
		void Delete();
		bool OverlapWith(const Unit& other) const;

		void SetID(int ID);
		int GetID() const;

	private:
		Picture mPicture;
		int mXcoord{ 0 };
		int mYcoord{ 0 };
		int mZcoord{ 0 };
		int mID;

		friend class Renderer;
	};
}