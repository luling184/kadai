# include "Vector2D.h"

Vector2D::Vector2D(int _x, int _y)
	: x(_x)
	, y(_y)
{
}

double Vector2D::lengthSquare() const
{
	return x*x + y*y;
}

double Vector2D::dot(const Vector2D& other) const
{
	// a*b*cosθは計算速度的によろしくない
	return x*other.x + y*other.y;
}

double Vector2D::cross(const Vector2D& other) const
{
	// a*b*sinθは計算速度的によろしくない
	return x*other.y - y*other.x;
}

bool Vector2D::isZero() const
{
	return x == 0.0 && y == 0.0;
}