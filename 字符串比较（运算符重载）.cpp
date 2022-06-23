#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

class str
{
	char* p;
public:
	str();
	str(char* s);
	friend bool operator>(str&a, str&b);
	friend bool operator<(str&a, str&b);
	friend bool operator==(str&a, str&b);
	void show()
	{
		cout << p << endl;
	}
};

str::str() {}
str::str(char* s)
{
	p = new char[strlen(s)];
	strcpy(p, s);
}

bool operator>(str&a, str&b)
{
	if (strcmp(a.p, b.p)>0)
	{
		a.show();
		return true;
	}
	else
	{
		b.show();
		return false;
	}
}

bool operator<(str& a, str& b)
{
	if (strcmp(a.p, b.p)<0)
	{
		a.show();
		return true;
	}
	else
	{
		b.show();
		return false;
	}
}

bool operator==(str& a, str& b)
{
	if (strcmp(a.p, b.p)==0)
	{
		a.show();
		return true;
	}
	else
	{
		b.show();
		return false;
	}
}

int main()
{
	char A[50];
	char B[50];
	char C[50];
	cin.getline(A,50);
	cin.getline(B, 50);
	cin.getline(C, 50);
	str a(A);
	str b(B);
	str c(C);
	a > b;
	a < c;
	b == c;
	return 0;
}