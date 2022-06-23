#include<iostream>
#include<iomanip>
using namespace std;

class Vehicle
{
protected:
	string no;
public:
	Vehicle(){}
	Vehicle(string n);
	virtual void display() = 0;
};

Vehicle::Vehicle(string n) :no(n) {}

class car :public Vehicle
{
protected:
	int num;
	double weight;
public:
	car(int n, double w, string no);
	void display();
};

car::car(int n, double w,string no) :Vehicle(no),num(n), weight(w) {}

void car::display()
{
	cout << setw(3)<<setfill('0') << no << " " << 8 * num + 2.0 * weight << endl;
}

class Truck :public Vehicle
{
protected:
	double weight;
public:
	Truck(double w, string no);
	void display();
};

Truck::Truck(double w, string no) :Vehicle(no),weight(w) {}

void Truck::display()
{
	cout << setw(3) << setfill('0') << no << " " << 5.0 * weight << endl;
}

class Bus :public Vehicle
{
protected:
	int num;
public:
	Bus(int n,string no);
	void display();
};

Bus::Bus(int n, string no) :Vehicle(no), num(n){}

void Bus::display()
{
	cout << setw(3) << setfill('0') << no << " " << 3 * num << endl;
}
int main()
{
	int t;
	cin >> t;
	Vehicle* V;
	for (int i = 0; i < t; i++)
	{
		int input;
		int n;
		double w;
		string no;
		cin >> input;
		switch (input)
		{
		case 1:
			cin >> no >> n >> w;
			V = new car(n, w, no);
			V->display();
			break;
		case 2:
			cin >> no >> w;
			V = new Truck( w, no);
			V->display();
			break;
		case 3:
			cin >> no >> n;
			V = new Bus(n,no);
			V->display();
			break;
		}
	}
	return 0;
}