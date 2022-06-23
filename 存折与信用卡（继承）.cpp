#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class CAccount
{
public:
	CAccount(long a, char n[], float b);
	void deposit(float b);
	void withdraw(float b);
	void check();
protected:
	long account;
	char name[10];
	float balance;
};

CAccount::CAccount(long a, char n[], float b) :account(a), balance(b)
{
	strcpy(name, n);
}
void CAccount::deposit(float b)
{
	balance += b;
	cout << "saving ok!" << endl;
}
void CAccount::withdraw(float b)
{
	if (b <= balance)
	{
		balance -= b;
		cout << "withdraw ok!" << endl;
	}
	else
	{
		cout << "sorry! over balance!" << endl;
	}
}
void CAccount::check()
{
	cout << "balance is " << balance << endl;
}

class CCreditcard :public CAccount
{
public:
	float getB();
	CCreditcard(long a, char n[], float b,float l);
	void withdraw(float b);
protected:
	float limit;
};

CCreditcard::CCreditcard(long a, char n[], float b, float l) :CAccount(a, n, b), limit(l) {}
float CCreditcard :: getB()
{
	return balance;
}
void CCreditcard::withdraw(float b)
{
	if (b <= balance + limit)
	{
		balance -= b;
		cout << "withdraw ok!" << endl;
	}
	else
	{
		cout << "sorry! over limit!" << endl;
	}
}

int main()
{
	long a;
	char n[10];
	float b, l;
	cin >> a >> n >> b;
	CAccount C(a, n, b);
	C.check();
	float val;
	cin >> val;
	C.deposit(val);
	C.check();
	cin >> val;
	C.withdraw(val);
	C.check();
	
	cin >> a >> n >> b >> l;
	CCreditcard CC(a, n, b, l);
    CC.check();
	cin >> val;
	CC.deposit(val);
	CC.check();
	cin >> val;
	CC.withdraw(val);
	cout<<"balance is "<<CC.getB();
	return 0;
}