#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class Customer
{
public:
	Customer(char* name);
	~Customer();
	static void changeYear(int r);
	void Display();
private:
	static int TotalCustNum;
	static int Rent;
	static int Year;
	int CustID;
	char* CustName;
};
//初始化静态成员
int Customer::TotalCustNum = 0;
int Customer::Rent = 0;
int Customer::Year = 0;

//构造
Customer::Customer(char* name)
{
	CustName = new char[100];
	strcpy(CustName, name);
	TotalCustNum++;
	Rent += 150;
}
//析构
Customer::~Customer()
{
	delete[] CustName;
}

void Customer::changeYear(int r)
{
	Year = r;
}

void Customer::Display()
{
	CustID = Year * 10000 + TotalCustNum;
	cout << CustName << " " << CustID << " " << TotalCustNum<<" " << Rent << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int year;
		cin >> year;
		char str[100];
		cin >> str;
		while (str[0]!='0')
		{
			Customer C(str);
			C.changeYear(year);
			C.Display();
			cin >> str;
		}
	}
	return 0;
}