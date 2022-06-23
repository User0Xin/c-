#include<iostream>
#include<math.h>
using namespace std;

class CPoint
{
public:
	CPoint();
	void set(double x0, double y0, double z0);
	double getx();
	double gety();
	double getz();
private:
	double x;
	double y;
	double z;
};
CPoint::CPoint() {}
void CPoint::set(double x0, double y0, double z0)
{
	x = x0;
	y = y0;
	z = z0;
}
double CPoint::getx()
{
	return x;
}
double CPoint::gety()
{
	return y;
}
double CPoint::getz()
{
	return z;
}
class CCube
{
public:
	CCube(double x1, double y1,double z1, double x2, double y2,double z2);
	CCube(CCube &C);
	int collide(CCube r);
	~CCube();
private:
	CPoint* point;
};

CCube::CCube(double x1, double y1, double z1, double x2, double y2, double z2)
{
	point = new CPoint[2];
	point[0].set(x1, y1, z1);
	point[1].set(x2, y2, z2);

}
CCube::CCube(CCube &C)
{
	point = new CPoint[2];
	point[0] = C.point[0];
	point[1] = C.point[1];
}
CCube::~CCube()
{
	if (point != NULL)
	{
		delete[]point;
		point = NULL;
	}
}
int CCube::collide(CCube r)
{
	double X1 = (point[0].getx() + point[1].getx()) / 2;
	double Y1 = (point[0].gety() + point[1].gety()) / 2;
	double Z1 = (point[0].getz() + point[1].getz()) / 2;
	double X2 = (r.point[0].getx() + r.point[1].getx()) / 2;
	double Y2 = (r.point[0].gety() + r.point[1].gety()) / 2;
	double Z2 = (r.point[0].getz() + r.point[1].getz()) / 2;
	double R1 = sqrt((point[0].getx() - point[1].getx()) * (point[0].getx() - point[1].getx()) +
		(point[0].gety() - point[1].gety()) * (point[0].gety() - point[1].gety()) +
		(point[0].getz() - point[1].getz()) * (point[0].getz() - point[1].getz()))/2;
	double R2 = sqrt((r.point[0].getx() - r.point[1].getx()) * (r.point[0].getx() - r.point[1].getx()) +
		(r.point[0].gety() - r.point[1].gety()) * (r.point[0].gety() - r.point[1].gety()) +
		(r.point[0].getz() - r.point[1].getz()) * (r.point[0].getz() - r.point[1].getz()))/2;
	if (sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2) + (Z1 - Z2) * (Z1 - Z2)) <= R1 + R2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		double x1, y1, z1, x2, y2, z2,x3,y3,z3,x4,y4,z4;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
		CCube C1(x1, y1, z1, x2, y2, z2);
		CCube C2(x3, y3, z3, x4, y4, z4);
		if (C1.collide(C2))
		{
			cout << "collide" << endl;
		}
		else
		{
			cout << "have distance" << endl;
		}
	}
	return 0;
}