#include<iostream>
#include<math.h>
using namespace std;

class Point
{
public:
	friend double Distance(Point& a, Point& b);//友元的声明
	Point(double xx, double yy);
private:
	double x, y;
};
//构造
Point::Point(double xx, double yy)
{
	x = xx;
	y = yy;
}
double Distance(Point& a, Point& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1, y1);
		Point p2(x2, y2);
		cout<<(int)Distance(p1, p2)<<endl;
	}
	return 0;
}