#include<iostream>
using namespace std;

class BaseAccount
{
public:
	BaseAccount(string n, string a, int b);
	virtual void deposit(int n);
	virtual void withdraw(int n);
	virtual void display();
protected:
	string name;
	string account;
	int balance;
};

BaseAccount::BaseAccount(string n, string a, int b) :name(n), account(a), balance(b) {}
void BaseAccount::deposit(int n)
{
	balance += n;
}
void BaseAccount::withdraw(int n)
{
	if (n <= balance)
	{
		balance -= n;
	}
	else
	{
		cout << "insufficient" << endl;
	}
}
void BaseAccount::display() 
{
	cout << name << " " << account << " Balance:" << balance << endl;
}

class BasePlus :public BaseAccount
{
public:
	BasePlus(string n, string a, int b);
	void deposit(int n);
	void withdraw(int n);
	void display();
protected:
	int limit;
	int limit_sum;
};

BasePlus::BasePlus(string n, string a, int b) :BaseAccount(n, a, b), limit(5000), limit_sum(0) {}

void BasePlus::deposit(int n)
{
	if (limit_sum > 0 && limit_sum >= n)
	{
		limit_sum -= n;
	}
	else if(limit_sum > 0 && limit_sum < n)
	{
		balance += n - limit_sum;
		limit_sum = 0;	
	}
	else
	{
		balance += n;
	}
}

void BasePlus::withdraw(int n)
{
	if (n <= balance)
	{
		balance -= n;
	}
	else if (n <= balance + limit - limit_sum)
	{
		limit_sum += n - balance;
		balance = 0;		
	}
	else
	{
		cout << "insufficient" << endl;
	}
}
void BasePlus::display()
{
	cout << name << " " << account << " Balance:" << balance << " limit:" << limit-limit_sum << endl;
}

int main()
{
	int t;
	cin >> t;
	BaseAccount* B;
	for (int i = 0; i < t; i++)
	{
		string name, account;
		int balance;
		int d1, w1, d2, w2;
		cin >> name >> account >> balance;
		if (account[1] == 'A')
		{
			B = new BaseAccount(name, account, balance);
			cin >> d1 >> w1 >> d2 >> w2;
			B->deposit(d1);
			B->withdraw(w1);
			B->deposit(d2);
			B->withdraw(w2);
			B->display();
		}
		else if (account[1] == 'P')
		{
			B = new BasePlus(name, account, balance);
			cin >> d1 >> w1 >> d2 >> w2;
			B->deposit(d1);
			B->withdraw(w1);
			B->deposit(d2);
			B->withdraw(w2);
			B->display();
		}
	}
	return 0;
}
