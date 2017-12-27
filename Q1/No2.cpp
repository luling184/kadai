// /* テンプレートを使った例
# include <iostream>
using namespace std;

class Vector3D
{
public:
    int x, y, z;
    
    Vector3D() {}
    Vector3D(int _x, int _y, int _z)
        : x(_x)
        , y(_y)
        , z(_z)
    {
    }
};
    
ostream& operator<<(ostream& stream, const Vector3D& value){
    return stream << '(' << value.x << "," << value.y << "," << value.z <<')';
}

template <typename Type>
void swap(Type *a, Type *b)
{
    Type tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);
    
    cout << a << endl;
    cout << b << endl;
    
    swap(a, b);
    
    cout << a << endl;
    cout << b << endl;
    
    return 0;
}

//*/

/* int型のみに対応

# include <iostream>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a, b;
    a = 10;
    b = 20;
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    
    swap(&a, &b);
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    
    return 0;
}

//*/