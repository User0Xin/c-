#include<iostream>
using namespace std;

class CClock
{
public:
	friend ostream& operator<<(ostream& out, CClock& a);
	CClock() {}
	CClock(int h1, int m1, int s1);
	int get1();
	int get2();
	int get3();
private:
	int h;
	int m;
	int s;

};

int CClock::get1()
{
	return s;
}
int CClock::get2()
{
	return m;
}
int CClock::get3()
{
	return h;
}

CClock::CClock(int h1, int m1, int s1) :h(h1), m(m1), s(s1) {}

class CRmb
{
public:
	friend ostream& operator<<(ostream& out, CRmb& a);
	CRmb() {}
	CRmb(int y1, int f1, int j1);
	int get1();
	int get2();
	int get3();
private:
	int y;
	int f;
	int j;
};

CRmb::CRmb(int y1, int f1, int j1) :y(y1), f(f1), j(j1) {}

int CRmb::get1()
{
	return j;
}
int CRmb::get2()
{
	return f;
}
int CRmb::get3()
{
	return y;
}


template<class T1,class T2>
T1 add(T1 x, T2 y, int a)
{

	int b = 0, c = 0, d = 0;
	T1 t(d, c, b);
	b += x.get1() + y.get1();
	if (b >= a)
	{
		b = b % a;
		c++;
	}
	c += x.get2() + y.get2();
	if (c >= a)
	{
		c = c % a;
		d++;
	}
	d += x.get3() + y.get3();

	return t;
}

ostream& operator<<(ostream& out, CClock &a)
{
	out << a.get3() << " " << a.get2() << " " << a.get1();
	return out;
}

ostream& operator<<(ostream& out, CRmb& a)
{
	out << a.get3() << " " << a.get2() << " " << a.get1();
	return out;
}
int main()
{
	int h1, m1, s1, h2, m2, s2, y1, f1, j1, y2, f2, j2;
	cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2 >> y1 >> f1 >> j1 >> y2 >> f2 >> j2;
	CClock c1(h1, m1, s1), c2(h2, m2, s2),c;
	CRmb r1(y1, f1, j1), r2(y2, f2, j2),r;
	c = add(c1, c2, 60);
	cout << c << endl;
	r = add(r1, r2, 10);
	cout << r << endl;
	return 0;
}
