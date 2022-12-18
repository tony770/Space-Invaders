#include "pch.h"
#include "Unit.h"

namespace Pen
{
	Unit::Unit(const std::string& picFile) : mPicture(picFile)
	{
	}

	Unit::Unit(std::string&& picFile) : mPicture(picFile)
	{
	}

	void Unit::SetCoord(int x, int y, int z)
	{
		mXcoord = x;
		mYcoord = y;
		mZcoord = z;
	}

	int Unit::ChangeX(int xDiff)
	{
		mXcoord += xDiff;
		return mXcoord;
	}

	int Unit::ChangeY(int yDiff)
	{
		mYcoord += yDiff;
		return mYcoord;
	}

	int Unit::ChangeZ(int zDiff)
	{
		mZcoord += zDiff;
		return mZcoord;
	}

	int Unit::GetX() const
	{
		return mXcoord;
	}

	int Unit::GetY() const
	{
		return mYcoord;
	}

	int Unit::GetZ() const
	{
		return mZcoord;
	}

	int Unit::GetWidth() const
	{
		return mPicture.GetWidth();
	}

	int Unit::GetHeight() const
	{
		return mPicture.GetHeight();
	}


	void Unit::Draw()
	{
		Renderer::Draw(mPicture, mXcoord, mYcoord, mZcoord);
	}

	void Unit::Delete()
	{
		Renderer::Clear();
	}

	bool Unit::OverlapWith(const Unit& other) const
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
	void Unit::SetID(int ID)
	{
		mID = ID;
	}
	int Unit::GetID() const
	{
		return mID;
	}
}