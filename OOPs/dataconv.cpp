/*
* Data Conversion using Constructor and Operator function in the same class.
*/


# include <iostream>
# include <math.h>

using namespace std;

class polar
{
    float r, theta;
public:

    polar()
    {
        r = 0;
        theta = 0;
    }

    polar(float a, float b)
    {
        r = a;
        theta = b;
    }

    float gettheta()
    {
        return theta;
    }

    float getr()
    {
        return r;
    }

    void print()
    {
        cout << "\n\nPolar Coordinates-\n"
        << "R\t= " << r
        << "\nTheta\t= " << theta;
    }
};

class rectangle
{
    float x, y;
public:

    rectangle()
    {
        x = 0;
        y = 0;
    }

    rectangle(float a, float b)
    {
        x = a;
        y = b;
    }

    rectangle(polar p)
    {
        x = p.getr() * cos(p.gettheta() * 3.141 / 180.0);
        y = p.getr() * sin(p.gettheta() * 3.141 / 180.0);
    }

    operator polar()
    {
        float r, theta;
        r = sqrt(x*x+y*y);
        theta = atan(x/y) * 180 / 3.141;
        return polar(r, theta);
    }

    void print()
    {
        cout << "\n\nRectangular Coordinates-\n"
        << "X\t= " << x
        << "\nY\t= " << y;
    }

};

int main()
{
    polar a(10, 30), c;

    rectangle b(5, 5), d;

    a.print();
    d = a;
    d.print();

    cout << "\n\n";

    b.print();
    c = b;
    c.print();

    return 0;
}