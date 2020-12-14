#include <stdlib.h> 
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

class Vector
{
public:
    double x;
    double y;

    Vector(Point A, Point B)
    {
        x = abs(A.x - B.x);
        y = abs(A.y - B.y);
    }

    void sum(const Vector& other) const
    {
        // cout << "(" << x << "," << y << ")"<< "+"
        cout << "x " << x + other.x << endl;
        cout << "y " << y + other.y << endl;

    }

    void dif(const Vector & other) const
    {
        cout << "x " << abs(x - other.x) << endl;
        cout << "y " << abs(y - other.y) << endl;
    }

    bool is_colinear(const Vector & other) const
    {
        return x/y == other.x/other.y;
    }

    double len() const
    {
        return sqrt(x*x + y*y);
    }

    double angle(const Vector & other) const
    {
        double a = (other.x*x + other.y*y) / (len()* other.len());
        return acos(a);
    }
};

double area(const Point& p1, const Point& p2, const Point& p3)
{
    return 1/2* abs((p2.x - p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y - p1.y));
}

double area(const Point points[50], int size)
{
    if(size < 3) return -1;

    double area_n = 0;
    for(int i = 2; i < size; i++)
    {
        area_n += area(points[0], points[i - 1], points[i]);
    }
    return area_n;
}

int main()
{
    
    return 0;
}


