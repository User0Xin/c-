#include<iostream>
#include<algorithm>
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


class Student
{
public:
	int operator-(Student& s);
	void set(string n, int y, int m, int d);
	bool cmp(Student& s);
	string getn();
private:
	string name;
	int y;
	int m;
	int d;
};

string Student::getn()
{
	return name;
}

void Student::set(string n, int y, int m, int d)
{
	name = n;
	this->y = y;
	this->m = m;
	this->d = d;
}

bool Student::cmp(Student& s)
{
	if (y > s.y)
	{
		return true;
	}
	else if(y==s.y)
	{
		if (m > s.m)
		{
			return true;
		}
 		else if(m==s.m)
		{
			if (d > s.d)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int Student::operator-(Student& s)
{
	int day1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (s.y == y && s.m == m)
	{
		return d - s.d;
	}
	else if (s.y == y)
	{
		int sum = 0;
		if (s.m > m)
		{
			return -1;
		}
		if (isyear(y))
		{

			for (int i = s.m; i < m; i++)
			{
				sum += day2[i - 1];
			}
			sum += d - s.d;


		}
		else
		{
			for (int i = s.m; i < m; i++)
			{
				sum += day1[i - 1];
			}
			sum += d - s.d;
		}
		return sum;
	}
	else
	{
		int sum = 0;
		if (s.y > y)
		{
			return -1;
		}
		for (int i = s.y; i < y; i++)
		{
			if (isyear(s.y))
			{
				sum += 366;
			}
			else
			{
				sum += 365;
			}
		}
		if (s.m > m)
		{
			int del = 0;
			if (isyear(y))
			{
				for (int i = m; i < s.m; i++)
				{
					del += day2[i - 1];
				}
				del += d - s.d;
			}
			else
			{
				for (int i = m; i < s.m; i++)
				{
					del += day1[i - 1];
				}
				del += s.d - d;
			}
			sum -= del;
		}
		else
		{
			if (isyear(y))
			{
				for (int i = s.m; i < m; i++)
				{
					sum += day2[i - 1];
				}
				sum += d - s.d;
			}
			else
			{
				for (int i = s.m; i < m; i++)
				{
					sum += day1[i - 1];
				}
				sum += d - s.d;
			}
		}
		return sum;
	}
}

bool mycmp(Student S1, Student S2)
{
	return S1.cmp(S2);
}
int main()
{
	int t = 0;
	Student s[50];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string n;
		int y, m, d;
		cin >> n >> y >> m >> d;
		s[i].set(n, y, m, d);
	}
	sort(s,s+t,mycmp);
	cout <<s[t-1].getn()<< "和"<<s[0].getn()<<"年龄相差最大，为" << s[0] - s[t-1] << "天。" << endl;
	return 0;
}