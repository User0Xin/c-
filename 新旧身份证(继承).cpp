#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<string>
using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate(int y, int m, int d);
	bool check(); //检验日期是否合法
	bool isLeap();
	void print();
	int gety();
	int getm();
	int getd();
};

CDate::CDate(int y, int m, int d) :year(y), month(m), day(d) {}
bool CDate::check()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day >= 1 && day <= 31)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day >= 1 && day <= 30)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			if (day >= 1 && day <= 29)
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
			if (day >= 1 && day <= 28)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}
void CDate::print()
{
	cout << year << "年" << month << "月" << day << "日";
}
int CDate::gety()
{
	return year;
}
int CDate::getm()
{
	return month;
}
int CDate::getd()
{
	return day;
}


class COldID
{
private:
	char* p_id15, * p_name; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldID(char* p_idval, char* p_nameval, CDate& day);
	bool check(); //验证15位身份证是否合法
	char* geti();
	CDate getb();
	~COldID();
};
COldID::COldID(char* p_idval, char* p_nameval, CDate& day) :birthday(day)
{
	p_id15 = new char[16];
	p_name = new char[10];
	strcpy(p_id15, p_idval);
	strcpy(p_name, p_nameval);
}
CDate COldID::getb()
{
	return birthday;
}
bool COldID::check()
{
	int y0 = (p_id15[6] - '0') * 10 + p_id15[7] - '0';
	int m0 = (p_id15[8] - '0') * 10 + p_id15[9] - '0';
	int d0 = (p_id15[10] - '0') * 10 + p_id15[11] - '0';
	if (y0 == birthday.gety() % 100 && m0 == birthday.getm() && d0 == birthday.getd())
	{
		return true;
	}
	else
	{
		return false;
	}
}

char* COldID::geti()
{
	return p_id15;
}

COldID::~COldID()
{
	delete[]p_id15;
	delete[]p_name;
	p_id15 = NULL;
	p_name = NULL;
}

class CNewID :public COldID
{
public:
	CNewID(char* p_idval, char* p_nameval, CDate& day, char* p_id, CDate& m, int y);
	bool Check();
	bool check1();
	bool check2();
	bool check3();
	void print();
private:
	char* p_id18;
	CDate make;
	int year1;
};

CNewID::CNewID(char* p_idval, char* p_nameval, CDate& day, char* p_id, CDate& m, int y) :COldID(p_idval, p_nameval, day), p_id18(p_id), year1(y), make(m) {}
bool CNewID::check3()
{
	int count = 0, i;
	for (i = 0; i < 6; i++)
	{
		if (p_id18[i] != geti()[i])
		{
			break;
		}
		count++;
	}
	for (; i < 15; i++)
	{
		if (p_id18[i + 2] != geti()[i])
		{
			break;
		}
		count++;
	}
	if (count != 15)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool CNewID::check2()
{
	if (make.gety() + year1 < 2017)
	{
		return false;
	}
	else if (make.gety() + year1 > 2017)
	{
		return true;
	}
	else
	{
		if (make.getm() < 5)
		{
			return false;
		}
		else if (make.getm() < 5)
		{
			return true;
		}
		else
		{
			if (make.getd() < 10)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}
bool CNewID::check1()
{
	int i;
	for (i = 0; i < 17; i++)
	{
		if (!(p_id18[i] <= '9' && p_id18[i] >= '0'))
		{
			break;
		}
	}
	if (i == 17 && (p_id18[i] == 'X' || p_id18[i] <= '9' && p_id18[i] >= '0'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CNewID::Check()
{
	int x = ((p_id18[0] - '0') * 7 + (p_id18[1] - '0') * 9 + (p_id18[2] - '0') * 10 + (p_id18[3] - '0') * 5 + (p_id18[4] - '0') * 8 + (p_id18[5] - '0') * 4 +
		(p_id18[6] - '0') * 2 + (p_id18[7] - '0') * 1 + (p_id18[8] - '0') * 6 + (p_id18[9] - '0') * 3 + (p_id18[10] - '0') * 7 + (p_id18[11] - '0') * 9
		+ (p_id18[12] - '0') * 10 + (p_id18[13] - '0') * 5 + (p_id18[14] - '0') * 8 + (p_id18[15] - '0') * 4 + (p_id18[16] - '0') * 2) % 11;
	char str[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	if (p_id18[17] != str[x])
	{
		return false;
	}
	else if (!getb().check())
	{
		return false;
	}
	else if (strlen(p_id18) != 18)
	{
		return false;
	}
	else if (!check1())
	{
		return false;
	}
	else if (!check2())
	{
		return false;
	}
	else if (!check3())
	{
		return false;
	}
	else if (!check())
	{
		return false;
	}
	else if (!make.check())
	{
		return false;
	}
	else
	{
		return true;
	}
}
void CNewID::print()
{
	cout << p_id18 << " ";
	make.print();
	if (year1 >= 100)
	{
		cout << " 长期" << endl;
	}
	else
	{
		cout << " " << year1 << "年" << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char name[10];
		int y, m, d;
		char id15[16];
		char id18[19];
		int y1, m1, d1;
		int y2;
		cin >> name >> y >> m >> d >> id15 >> id18 >> y1 >> m1 >> d1 >> y2;
		CDate b(y, m, d);
		CDate M(y1, m1, d1);
		CNewID C(id15, name, b, id18, M, y2);
		cout << name << endl;
		if (C.Check())
		{
			C.print();
		}
		else
		{
			cout << "illegal id" << endl;
		}
	}
	return 0;
}