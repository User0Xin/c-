#include<iostream>
using namespace std;

class CPoint
{
public:
	CPoint(int x1, int y1);
protected:
	int x;
	int y;
};

CPoint::CPoint(int x1, int y1) :x(x1), y(y1) {}

class CCircle :public CPoint
{
public:
	CCircle(int x1,int y1,int r1);
	double Cul();
protected:
	int r;
};

CCircle::CCircle(int x1, int y1, int r1) :CPoint(x1, y1), r(r1) {}
double CCircle::Cul()
{
	return 3.14 * r * r;
}

class CCylinder :public CCircle
{
public:
	CCylinder(int x1,int y1,int r1,int h1);
	double Cul();
protected:
	int h;
};

CCylinder::CCylinder(int x1, int y1, int r1, int h1) :CCircle(x1, y1, r1), h(h1) {}
double CCylinder::Cul()
{
	return 3.14 * r * r * h;
}
int main()
{
	int x, y, r;
	cin >> x >> y >> r;
	CCircle C(x, y, r);
	cout << "Circle:(" << x << "," << y << ")," << r << endl << "Area:" << C.Cul() << endl;
	int x1, y1, r1, h1;
	cin >> x1 >> y1 >> r1 >> h1;
	CCylinder CC(x1, y1, r1, h1);
	cout << "Cylinder:(" << x1 << "," << y1 << ")," << r1 << "," << h1 << endl << "Volume:" << CC.Cul() << endl;
	return 0;
}