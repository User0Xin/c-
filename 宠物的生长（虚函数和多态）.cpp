#include<iostream>
#include<iomanip>
using namespace std;

bool isyear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


class CDate
{
public:
	CDate(int y1,int m1,int d1);
	int cal(CDate D);
private:
	int y;
	int m;
	int d;
};
CDate::CDate(int y1, int m1, int d1) :y(y1), m(m1), d(d1) {}
int CDate::cal(CDate D)
{
	int day1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (D.y == y && D.m == m)
	{
		return d - D.d;
	}
	else if (D.y == y)
	{
		int sum = 0;
		if (D.m > m)
		{
			return -1;
		}
		if (isyear(y))
		{
			
			for (int i = D.m; i < m; i++)
			{
				sum += day2[i-1];
			}
			sum += d - D.d;
			
			
		}
		else
		{
			for (int i = D.m; i < m; i++)
			{
				sum += day1[i - 1];
			}
			sum += d - D.d;
		}
		return sum;
	}
	else
	{
		int sum = 0;
		if (D.y > y)
		{
			return -1;
		}
		for (int i = D.y; i < y; i++)
		{
			if (isyear(D.y))
			{
				sum += 366;
			}
			else
			{
				sum += 365;
			}
		}
		if (D.m > m)
		{
			int del = 0;
			if (isyear(y))
			{
				for (int i = m; i < D.m; i++)
				{
					del += day2[i - 1];
				}
				del += d - D.d;
			}
			else
			{
				for (int i = m; i < D.m; i++)
				{
					del += day1[i - 1];
				}
				del +=  D.d-d;
			}
			sum -= del;
		}
		else
		{
			if (isyear(y))
			{
				for (int i = D.m; i < m; i++)
				{
					sum += day2[i - 1];
				}
				sum += d - D.d;
			}
			else
			{
				for (int i = D.m; i < m; i++)
				{
					sum += day1[i - 1];
				}
				sum += d - D.d;
			}
		}
		return sum;
	}
}

class Pet
{
protected:
	string name;//姓名
	int length;//身长
	int weight;//体重
	CDate current;//开始记录时间（日期类CDate包含年、月、日三个私有数据，其他方法根据需要自拟。）
public:
	Pet(string n,int l,int w,CDate c);
	virtual void display(CDate day) = 0;//输出目标日期时宠物的身长和体重
};

Pet::Pet(string n, int l, int w, CDate c) :name(n), length(l), weight(w), current(c) {}

class Cat :public Pet
{
public:
	Cat(string n, int l, int w, CDate c);
	void display(CDate day);
};

Cat::Cat(string n, int l, int w, CDate c) :Pet(n, l, w, c) {}

void Cat::display(CDate day)
{
	if (day.cal(current) < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		cout << name << " after " << day.cal(current) << " day: length=" << fixed << setprecision(2)
			<< length + 0.1 * day.cal(current) << ",weight=" << fixed << setprecision(2) << weight + 0.2 * day.cal(current) << endl;
	}
}

class Dog :public Pet
{
public:
	Dog(string n, int l, int w, CDate c);
	void display(CDate day);
};

Dog::Dog(string n, int l, int w, CDate c) :Pet(n, l, w, c) {}

void Dog::display(CDate day)
{
	if (day.cal(current) < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		cout << name << " after " << day.cal(current) << " day: length=" << fixed << setprecision(2)
			<< length + 0.2 * day.cal(current) << ",weight=" << fixed << setprecision(2) << weight + 0.1 * day.cal(current) << endl;
	}
}


int main()
{
	int t;
	cin >> t;
	int y, m, d;
	cin >> y >> m >> d;
	CDate cu(y, m, d);
	Pet* P;
	for (int i = 0; i < t; i++)
	{
		int input;
		string name;
		int w, l, y1, m1, d1;
		cin >> input;
		if (input == 1)
		{
			cin >> name >> l >> w >> y1 >> m1 >> d1;
			CDate da(y1, m1, d1);
			P = new Cat(name, l, w, cu);
			P->display(da);
		}
		else if (input == 2)
		{
			cin >> name >> l >> w >> y1 >> m1 >> d1;
			CDate da(y1, m1, d1);
			P = new Dog(name, l, w, cu);
			P->display(da);
		}
	}
	return 0;
}