// 実行してみよ

# include <iostream>

using namespace std;

class Vector2D
{
public:
    int x,  y;

    Vector2D() {}
    Vector2D (int _x, int _y)
        : x(_x)
        , y(_y)
    {
    }

    int dot(const Vector2D& other)
    {
        return this->x * other.x + this->y * other.y;
    }
};

int main()
{
    Vector2D vec1(2, 3);
    Vector2D vec2(4, 5);

    cout << vec1.x << " , " << vec1.y << endl;
    cout << vec2.x << " , " << vec2.y << endl;
    cout << vec1.dot(vec2) << endl;
	
	return 0;
}
