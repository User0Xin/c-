#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class point_1D
{
public:
	point_1D(double x1);
	double distance();
protected:
	double x;
};
point_1D::point_1D(double x1) :x(x1) {}
double point_1D::distance()
{
	return sqrt(x*x);
}

class point_2D:public point_1D
{
public:
	point_2D(double x1, double y1);
	double distance();
protected:
	double y;
};

point_2D::point_2D(double x1, double y1):point_1D(x1),y(y1){}
double point_2D::distance()
{
	return sqrt(x * x + y * y);
}

class point_3D :public point_2D
{
public:
	point_3D(double x1, double y1,double z1);
	double distance();
protected:
	double z;
};

point_3D::point_3D(double x1, double y1, double z1):point_2D(x1, y1), z(z1) {}
double point_3D::distance()
{
	return sqrt(x * x + y * y + z * z);
}

int main()
{
	int input;
	double x, y, z;
	while (1)
	{
		cin >> input;
		if (input == 1)
		{
			cin >> x;
			point_1D p1(x);
			cout << "Distance from Point (" << fixed << setprecision(2) << x << ") to original point is " << fixed << setprecision(2) << p1.distance() << endl;
		}
		else if (input == 2)
		{
			cin >> x >> y;
			point_2D p2(x, y);
			cout << "Distance from Point (" << fixed << setprecision(2) << x << ", " << y << ") to original point is " << fixed << setprecision(2) << p2.distance() << endl;
		}
		else if(input==3)
		{
			cin >> x >> y >> z;
			point_3D p3(x, y, z);
			cout << "Distance from Point (" << fixed << setprecision(2) << x << ", " << y << ", " << z << ") to original point is " << fixed << setprecision(2) << p3.distance() << endl;
		}
		else if (input == 0)
		{
			break;
		}
	}
	return 0;
}