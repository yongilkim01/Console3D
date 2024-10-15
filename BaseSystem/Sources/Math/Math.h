#pragma once

class FIntPoint
{
public:
	int x_ = 0;
	int y_ = 0;

	static const FIntPoint LEFT;
	static const FIntPoint RIGHT;
	static const FIntPoint UP;
	static const FIntPoint DOWN;

	FIntPoint()
	{

	}

	FIntPoint(int x, int y) : x_(x), y_(y)
	{

	}

	FIntPoint operator+(FIntPoint other) const
	{
		FIntPoint result;
		result.x_ = x_ + other.x_;
		result.y_ = y_ + other.y_;
		return result;
	}

	bool operator==(FIntPoint other) const
	{
		return x_ == other.x_ && y_ == other.y_;
	}

	FIntPoint& operator+=(FIntPoint other)
	{
		x_ += other.x_;
		y_ += other.y_;
		return *this;
	}


};

class FMath
{
};

