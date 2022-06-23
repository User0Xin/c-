#include<iostream>
#include<iomanip>
using namespace std;

void change(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

int main()
{	
	string a= "hello";
	string b = "world";
	change(a, b);
	cout << a << b;

	return 0;
}

