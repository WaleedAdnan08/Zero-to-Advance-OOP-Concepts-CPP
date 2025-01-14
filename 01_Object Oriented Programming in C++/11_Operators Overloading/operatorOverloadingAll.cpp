#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
    int z;
    // static constexpr double PI=3.14359;
public:
    algebra(int x = 0, int y = 0, int z = 0)
    {
        setX(x);
        setY(y);
        setZ(z);
        cout << "Consstructor Executed:"
             << "\n";
    }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setZ(int z) { this->z = z; }
    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
    void setData(int x, int y, int z)
    {
        setX(x);
        setY(y);
        setZ(z);
    }
    void putData()
    {
        cout << "The value of x = " << x << "\n";
        cout << "The value of y = " << y << "\n";
        cout << "The value of z = " << z << "\n";
    }
    ~algebra()
    {
        cout << "Destrcutor Executed:"
             << "\n";
    }

    // OPERATORS_OVERLOADING
    /*
    • Unary Operators:
- (minus), !, ++ (pre and post), -- (pre and post), ~ ( bitwise not) , & (address of)
• Binary Operators:
    1. Arithmetic -, +, *, /, % , +=, -=, *=, /=, %=
    2. Relational ==, !=, >=,<=, <, >
    3. Assignment =
    4. Logical &&, ||
    5. Subscript []
    6. Member access ->
    */

    //   1. Arithmetic -, +, *, /, % , +=, -=, *=, /=, %=
    algebra operator+(const algebra &obj) const
    {
        return algebra(x + obj.x, y + obj.y, z + obj.z);
    }
    algebra operator+(const int &n) const
    {
        return algebra(x + n, y + n, z + n);
    }

    // 2. Relational ==, !=, >=,<=, <, >
    bool operator==(const algebra &obj) const
    {
        return (x == obj.x && y == obj.y && z == obj.z);
    }
    bool operator!=(const algebra &obj) const
    {
        return !(*this == obj);
    }
    bool operator>=(const algebra &obj) const
    {
        return (x >= obj.x && y >= obj.y && z >= obj.z);
    }

    // 3. Assignment =
    algebra& operator=(const algebra &obj)
    {
        x = obj.x;
        y = obj.y;
        z = obj.z;
        return *this;
    }

    // 4.Arithematic_Assignment  +=, -=, *=, /=, %=

    algebra operator+=(const algebra &obj)
    {
        x += obj.x;
        y += obj.y;
        z += obj.z;

        return *this;
    }

    //-5 Uniary operators
    algebra &operator-()
    {
        x = -x;
        y = -y;
        z = -z;
        return *this;
    }
    algebra &operator++() // Pre-increment
    {
        ++x;
        ++y;
        ++z;
        return *this;
    }
    algebra &operator++(int) // post increment
    {
        x++;
        y++;
        z++;
        return *this;
    }
};
int main()
{
    algebra a1;
    algebra a2;
    algebra a3;
    algebra result;
    a1.setData(1, 2, 3);
    a2.setData(4, 5, 6);
    a3.setData(7, 8, 9);
    a1.putData();
    a2.putData();
    a3.putData();

    //======================
    //*****Test 01:********
    //======================
    result = a2 + 2; // only fisrt data member do opeartion
    result = a2 + 10;
    result.putData();

    // //======================
    // //*****Test 02:********
    // //======================
    // result = a1 + a2 + a3; // cash_cading left to right
    // result.putData();

    // //======================
    // //*****Test 03:********
    // //======================
    // a3 >= a1 ? cout << "Object 3 is graeter than Object 2\n" : cout << "Object 2 is graeter than Object 3\n";

    // //======================
    // //*****Test 04:********
    // //======================
    // a2 = a3;
    // a2.putData();
    // a3.putData();

    // //======================
    // //*****Test 05:********
    // //======================
    // result = a1 += a2 += a3; // has right to left cash cading
    // result.putData();
    // // cash cading not implemented on the logiacal operators due to no returning of the object

    // //======================
    // //*****Test 06:********
    // //======================
    // ++a1;
    // a1.putData();

    // //======================
    // //*****Test 07:********
    // //======================
    // a1++;
    // a1.putData();

    //======================
    //*****Test 08:********
    //======================
    result = -a1;
    result.putData();

    return 0;
}