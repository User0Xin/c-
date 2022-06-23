#include<iostream>
#include<math.h>
using namespace std;

class CRect;
class CPoint
{
public:
	friend bool check(CRect C1, CRect C2);
	CPoint(int xx, int yy);
private:
	int x, y;
};

CPoint::CPoint(int xx, int yy) :x(xx), y(yy) {}

class CRect
{
public:
	friend bool check(CRect C1, CRect C2);
	CRect(CPoint p1, CPoint p2);
private:
	CPoint P1;
	CPoint P2;
};

CRect::CRect(CPoint p1, CPoint p2) :P1(p1), P2(p2) {}

bool check(CRect C1, CRect C2)
{
	double D1 = ((C1.P1.x + C1.P2.x) / 2 - (C2.P1.x + C2.P2.x) / 2) * ((C1.P1.x + C1.P2.x) / 2 - (C2.P1.x + C2.P2.x) / 2);
	double D2 = ((C1.P1.y + C1.P2.y) / 2 - (C2.P1.y + C2.P2.y) / 2)* ((C1.P1.y + C1.P2.y) / 2 - (C2.P1.y + C2.P2.y) / 2);
	double L1 = (C1.P1.x - C1.P2.x) * (C1.P1.x - C1.P2.x) + (C1.P1.y - C1.P2.y) * (C1.P1.y - C1.P2.y);
	double L2 = (C2.P1.x - C2.P2.x) * (C2.P1.x - C2.P2.x) + (C2.P1.y - C2.P2.y) * (C2.P1.y - C2.P2.y);
	if (sqrt(D1 + D2) > (sqrt(L1)+sqrt(L2))/2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int t;
	cin >> t;
	for (int i=0; i < t; i++)
	{
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		CPoint P1(x1, y1);
		CPoint P2(x2, y2);
		CPoint P3(x3, y3);
		CPoint P4(x4, y4);
		CRect C1(P1, P2);
		CRect C2(P3, P4);
		if (check(C1, C2))
		{
			cout << "overlapped" << endl;
		}
		else
		{
			cout << "not overlapped" << endl;
		}
	}
	return 0;
}