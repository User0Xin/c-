#include<iostream>
#include<iomanip>
using namespace std;

class Date
{
public:
	Date(int y, int m, int d);
protected:
	int year;
	int month;
	int day;
};

Date::Date(int y, int m, int d) :year(y), month(m), day(d) {}

class Time
{
public:
	Time(int h, int m, int s);
protected:
	int hour;
	int minute;
	int second;
};
Time::Time(int h, int m, int s) :hour(h), minute(m), second(s) {}


class Schedule :public Date, public Time
{
public:
	friend bool before(const Schedule& s1, const Schedule& s2);
	Schedule(int y, int m, int d, int h, int mi, int s,int i);
	void show();
	int ID;
};

Schedule::Schedule(int y, int m, int d, int h, int mi, int s, int i) :Date(y, m, d), Time(h, mi, s), ID(i) {}
void Schedule::show()
{
	cout << "The urgent schedule is No." << ID << ": " << year << "/" << setw(2) << setfill('0') << month << "/" << day << " "
		<< setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
}
bool before(const Schedule& s1, const Schedule& s2)
{
	if (s1.year < s2.year)
	{
		return true;
	}
	else if (s1.year > s2.year)
	{
		return false;
	}
	else if (s1.year == s2.year)
	{
		if (s1.month < s2.month)
		{
			return true;
		}
		else if (s1.month > s2.month)
		{
			return false;
		}
		else if (s1.month == s2.month)
		{
			if (s1.day < s2.day)
			{
				return true;
			}
			else if (s1.day > s2.day)
			{
				return false;
			}
			else if (s1.day == s2.day)
			{
				if (s1.hour < s2.hour)
				{
					return true;
				}
				else if (s1.hour > s2.hour)
				{
					return false;
				}
				else if (s1.hour == s2.hour)
				{
					if (s1.minute < s2.minute)
					{
						return true;
					}
					else if (s1.minute > s2.minute)
					{
						return false;
					}
					else if (s1.minute == s2.minute)
					{
						if (s1.second < s2.second)
						{
							return true;
						}
						else if (s1.second > s2.second)
						{
							return false;
						}
						else if (s1.second == s2.second)
						{
							if (s1.ID < s2.ID)
							{
								return true;
							}
							else
							{
								return false;
							}
						}
					}
				}
			}
		}
	}

}

int main()
{ 
	int id, y, m, d, h, mi, s;
	Schedule S1(9999, 0, 0, 0, 0, 0, 0);
	while (cin >> id >> y >> m >> d >> h >> mi >> s)
	{
		Schedule S2(y, m, d, h, mi, s, id);
		if (before(S2, S1))
		{
			S1 = S2;
		}
	}
	S1.show();
	return 0;
}