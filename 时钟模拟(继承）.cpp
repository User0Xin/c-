#include<iostream>
#include<iomanip>
using namespace std;

class Count
{
public:
	Count(int v);
	void increment();
protected:
	int value;
};

Count::Count(int v) :value(v) {}
void Count::increment()
{
	value++;
}

class Cul :public Count
{
public:
	Cul(int v, int min, int max);
	void increment();
	int getv();
protected:
	int min_value;
	int max_value;
};
Cul::Cul(int v, int min, int max) :Count(v), min_value(min), max_value(max) {}
void Cul::increment()
{
	if (value == max_value)
	{
		value = min_value;
	}
	else
	{
		value++;
	}
}
int Cul::getv()
{
	return value;
}
class Clock
{
public:
	Clock(int h, int m, int s);
	void add();
	void show();
private:
	Cul hour;
	Cul minute;
	Cul second;
};

Clock::Clock(int h, int m, int s) :hour(h, 0, 23), minute(m, 0, 59), second(s, 0, 59) {}
void Clock::add()
{
	second.increment();
	if (second.getv() == 0)
	{
		minute.increment();
		if (minute.getv() == 0)
		{
			hour.increment();
		}
	}
}
void Clock::show()
{
	cout << hour.getv() << ":" << minute.getv() << ":" << second.getv() << endl;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int h, m, s;
		cin >> h >> m >> s;
		Clock C(h, m, s);
		int input;
		cin >> input;
		for (int j = 0; j < input; j++)
		{
			C.add();
		}
		C.show();
	}
	return 0;
}