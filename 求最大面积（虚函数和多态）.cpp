#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

class Geometry 
{
public:
	virtual double getArea() = 0; //����������������С�������λ
};

int mycmp(Geometry* t1, Geometry* t2)
{
	return t1->getArea() > t2->getArea();
}

class Rect :public Geometry
{
protected:
	double len;
	double wei;
public:
	Rect(double l,double w);
	double getArea();
};

Rect::Rect(double l, double w) :len(l), wei(w) {}
double Rect::getArea()
{
	return len * wei;
}

class Circle :public Geometry
{
protected:
	double r;
public:
	Circle(double r);
	double getArea();
};

Circle::Circle(double R) :r(R){}
double Circle::getArea()
{
	return 3.14*r*r;
}

class TotalArea 
{
public:
	static void computerMaxArea(Geometry** t, int n);//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
};

void TotalArea::computerMaxArea(Geometry** t, int n)
{
	sort(t, t + n, mycmp);
	cout << "������=" <<fixed<<setprecision(2)<< t[0]->getArea();
}

int main()
{
	int t;
	cin >> t;
	Geometry** T = new Geometry * [t];
	for (int i = 0; i < t; i++)
	{
		int input, r,l, w;
		cin >> input;
		if (input == 1)
		{
			cin >> l >> w;
			T[i] = new Rect(l, w);
		}
		else if(input==2)
		{
			cin >> r;
			T[i] = new Circle(r);
		}
	}
	TotalArea Ta;
	Ta.computerMaxArea(T, t);
	return 0;
}