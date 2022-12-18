#include "pch.h"
#include "Laser.h"

namespace Pen
{
	Laser::Laser(const std::string& picFile) : mPicture(picFile)
	{
	}

	Laser::Laser(std::string&& picFile) : mPicture(picFile)
	{
	}
	void Laser::SetCoord(int x, int y, int z)
	{
		mXcoord = x;
		mYcoord = y;
	}
	int Laser::ChangeX(int xDiff)
	{
		mXcoord += xDiff;
		return mXcoord;
	}
	int Laser::ChangeY(int yDiff)
	{
		mYcoord += yDiff;
		return mYcoord;
	}
	int Laser::GetX() const
	{
		return mXcoord;
	}
	int Laser::GetY() const
	{
		return mYcoord;
	}
	void Laser::Draw()
	{
		Renderer::Draw(mPicture, mXcoord, mYcoord, 1);
	}
	bool Laser::OverlapWith(const Laser& other) const
	{
		int oneLeft{ GetX() };
		int oneRight{ GetX() + mPicture.GetWidth() };
		int anotherLeft{ other.GetX() };
		int anotherRight{ other.GetX() + other.mPicture.GetWidth() };

		int oneBottom{ GetY() };
		int oneTop{ GetY() + mPicture.GetHeight() };
		int anotherBottom{ other.GetY() };
		int anotherTop{ other.GetY() + other.mPicture.GetHeight() };

		bool collideX{ false };
		if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
			(anotherLeft <= oneLeft && oneLeft <= anotherRight))
			collideX = true;

		bool collideY{ false };
		if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
			(anotherBottom <= oneBottom && oneBottom <= anotherTop))
			collideY = true;

		return collideX && collideY;
	}
}