#include<iostream>
using namespace std;

class worker
{
protected:
	string name;
	string job;
	int state;
	int year;
public:
	worker(string n,string j,int s,int y);
	virtual void salary() = 0;
};

worker::worker(string n, string j, int s, int y) :name(n), job(j), state(s), year(y) {}

class Employee :public worker
{
public:
	Employee(string n, string j, int s, int y);
	void salary();
};

Employee::Employee(string n, string j, int s, int y) :worker(n, j, s, y) {}

void Employee::salary()
{
	if (state < 0 || year < 0)
	{
		cout << "error grade or year." << endl;
	}
	else
	{
		cout << name << ":Employee,Salary:" << 1000 + 500 * state + 50 * year << endl;
	}
}

class Teamleader :public worker
{
public:
	Teamleader(string n, string j, int s, int y);
	void salary();
};

Teamleader::Teamleader(string n, string j, int s, int y) :worker(n, j, s, y) {}

void Teamleader::salary()
{
	if (state < 0 || year < 0)
	{
		cout << "error grade or year." << endl;
	}
	else
	{
		cout << name << ":Teamleader,Salary:" << 3000 + 800 * state + 100 * year << endl;
	}
}

class Manager :public worker
{
public:
	Manager(string n, string j, int s, int y);
	void salary();
};

Manager::Manager(string n, string j, int s, int y) :worker(n, j, s, y) {}

void Manager::salary()
{
	if (state < 0 || year < 0)
	{
		cout << "error grade or year." << endl;
	}
	else
	{
		cout << name << ":Manager,Salary:" << 5000 + 1000 * state + 1000 * year << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	worker* w;
	for (int i = 0; i < t; i++)
	{
		string n, j;
		int s, y;
		cin >> n >> j >> s >> y;
		if (j == "Employee")
		{
			w = new Employee(n, j, s, y);
			w->salary();
		}
		else if (j == "Teamleader")
		{
			w = new Teamleader(n, j, s, y);
			w->salary();
		}
		else if (j == "Manager")
		{
			w = new Manager(n, j, s, y);
			w->salary();
		}
		else
		{
			cout << "error position." << endl;
		}
	}
	return 0;
}