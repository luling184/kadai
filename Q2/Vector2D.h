# define _VECTOR2D_H_
# ifndef _VECTOR2D_H_

class Vector2D
{
	double x, y;
	
	Vector2D() = default;
	
	Vector2D(double _x, double y);
	
	double lengthSquare() const;
	
	double dot(const Vector2D& other) const;
	
	double cross(const Vector2D& other) const;
	
	bool isZero() const;
	
	Vector2D operator +(const Vec2& other) const
    {
        return{ x + other.x, y + other.y };
    }
};

# endif // _VECTOR2D_H_