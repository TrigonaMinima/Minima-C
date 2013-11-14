# include <iostream>

using namespace std;

class point
{
	public :
		double x, y;
};

point operator+ (point& p1, point& p2)
{
	point sum = {p1.x+p2.x, p1.y+p2.y};
	return sum;
}

ostream& operator<< (ostream& out, point& p)
{
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}

int main()
{
	point a = {1.2, -3.4}, b = {7.0, 9.0}, c;
	cout << a << '\t' << b << endl;
	c = a+b;
	cout << c << endl;
	return 0;
}
