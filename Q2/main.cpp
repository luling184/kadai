# include <iostream>

# include "Vector2D.hpp"

int main()
{
	Vector2D vec1(2, 3);
    Vector2D vec2(4, 5);

    cout << vec1.x << " , " << vec1.y << endl;
    cout << vec2.x << " , " << vec2.y << endl;
    cout << vec1.dot(vec2) << endl;
	
	return 0;
}