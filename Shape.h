#include <iostream>
using namespace std;

enum class ShapeType
{
    circle = 'c',
    square = 's',
};

class Shape {
private:
    int mId;
public:
    virtual void RequestParams() {};

    void SetId(int id)
    {
        mId = id;
    }

    int GetId()
    {
        return mId;
    }

    virtual ~Shape(){}
};

class Square : public Shape {
private:
    double mX,mY;
    double mSize;
public:
    void RequestParams()
    {
        cout << "Enter left corner coords" << endl;
        cin >> mX >> mY;
        cout << "Enter the size" << endl;
        cin >> mSize;
    }

    ShapeType MyType()
    {
        return ShapeType::square;
    }
};

class Circle : public Shape {
private:
    int mId;
    double mX,mY;
    double mRadius;
public:
    void RequestParams()
    {
        cout << "Enter center coords" << endl;
        cin >> mX >> mY;
        cout << "Enter the radius" << endl;
        cin >> mRadius;
    }

    ShapeType MyType()
    {
        return ShapeType::circle;
    }
};