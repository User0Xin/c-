#include<iostream>
#include<iomanip>
using namespace std;
//提前声明Time让Date认识Time
class Time;
class Date
{
public:
	friend void Display(Date& a,Time& b);
	Date(int y, int m, int d);
private:
	int year;
	int month;
	int day;
};

Date::Date(int y, int m, int d) :year(y), month(m), day(d) {}

class Time
{
public:
	friend void Display(Date& a,Time& b);
	Time(int h, int m, int s);
private:
	int hour;
	int minute;
	int second;
};

Time::Time(int h, int m, int s) :hour(h), minute(m), second(s) {}

//输出
void Display(Date& a,Time& b)
{
	cout << a.year << "-" << setw(2) << setfill('0') << a.month <<"-" << setw(2) << setfill('0') << a.day << " "
		<< setw(2) << setfill('0') << b.hour << ":" << setw(2) << setfill('0') << b.minute << ":" << setw(2) << setfill('0') << b.second << endl;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int y, m, d, h, M, s;
		cin >> y >> m >> d >> h >> M >> s;
		Date D(y, m, d);
		Time T(h, M, s);
		Display(D, T);
	}
	return 0;
}