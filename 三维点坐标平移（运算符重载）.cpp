#include<iostream>
using namespace std;

class point
{
	int x;
	int y;
	int z;
public:
	point(int X = 0, int Y = 0, int Z = 0)
	{
		x = X;
		y = Y;
		z = Z;
	}
	friend point operator ++(point& a);
	friend point operator ++(point& a, int);
	friend point operator --(point& a);
	friend point operator--(point& a, int);
	void show()
	{
		cout << "x=" << x << " " << "y=" << y << " " << "z=" << z << endl;
	}
};

point operator++(point& a)
{
	a.x++;
	a.y++;
	a.z++;
	return a;
}

point operator ++(point& a, int)
{
	point temp = a;
	a.x++;
	a.y++;
	a.z++;
	return temp;
}

point operator --(point& a)
{
	a.x--;
	a.y--;
	a.z--;
	return a;
}

point operator--(point& a, int)
{
	point temp = a;
	a.x--;
	a.y--;
	a.z--;
	return temp;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	point p1(a, b, c);
	point p2(0, 0, 0);
	p1++;
	p1.show();
	p1--;
	p2 = p1++;
	p2.show();
	p1--;
	(++p1).show();
	p1.show();
	p1--;
	(p1--).show();
	p1++;
	p1.show();
	(--p1).show();
	p1.show();
	return 0;
}