#include<iostream>
#include<iomanip>
using namespace std;

class Player
{
public:
	Player() {}
	Player(double h, double w);
protected:
	double height;
	double weight;
};

Player::Player(double h, double w) :height(h), weight(w) {}

class MVP :public Player
{
public:
	MVP(double h, double w,double y, double s, double b, double a);
	void print();
protected:
	double year;
	double score;
	double block;
	double assist;
};

MVP::MVP(double h, double w, double y, double s, double b, double a) :Player(h, w), year(y), score(s), block(b), assist(a) {}
void MVP::print()
{
	cout << "MVP年份:" << fixed << setprecision(0) << year << " 得分:" << fixed << setprecision(1) << score << " 篮板:" << fixed << setprecision(1) << block << " 助攻:" << fixed << setprecision(1) << assist << endl;
}
class DPOY:public Player
{
public:
	DPOY() {}
	DPOY(double h, double w, double y, double b, double s, double r);
	void set(double y, double b, double s, double r);
	double getb();
	double getr();
	double gets();
	void print();
protected:
	double year;
	double block;
	double steal;
	double rebound;
};

DPOY::DPOY(double h, double w, double y, double b, double s, double r) :Player(h, w), year(y), block(b), steal(s), rebound(r) {}
void DPOY::set(double y, double b, double s, double r)
{
	year = y;
	block = b;
	steal = s;
	rebound = r;
}
double DPOY::getb()
{
	return block;
}
double DPOY::getr()
{
	return rebound;
}
double DPOY::gets()
{
	return steal;
}
void DPOY::print()
{
	cout << "DPOY年份:" << fixed << setprecision(0) << year << " 盖帽:" << fixed << setprecision(1) << rebound << " 篮板:" << fixed << setprecision(1) << block << " 抢断:" << fixed << setprecision(1) << steal << endl;
}
int main()
{
	string name;
	double h, w;
	cin >> name >> h >> w;
	double s, b, a, r, st;
	DPOY* D = new DPOY[100];
	cout << "球员姓名:" << name << " 身高:" << h << " 体重:" << w << endl;
	for (int i = 0; i < 11; i++)
	{
		cin >> s >> b >> a >> r >> st;
		MVP M(h, w, i+2010, s, b, a);
		D[i].set(i+2010, b, st, r);
		if (s > 25 && b > 6 && a > 6)
		{
			M.print();
		}
	}
	for (int i = 0; i < 11; i++)
	{
		if (D[i].getb() > 12 && D[i].getr() > 2.5 && D[i].gets() > 1.5)
		{
			D[i].print();
		}
	}
	delete[]D;
	return 0;
}