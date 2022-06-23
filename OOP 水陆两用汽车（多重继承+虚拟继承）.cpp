#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Vehicle
{
public:
	Vehicle(int w);
	void setWeight(int w);
	void display();
	int weight;
};
Vehicle::Vehicle(int w) :weight(w)
{
	cout << "����Vehicle�๹�캯��" << endl;
}
void Vehicle::setWeight(int w)
{
	weight = w;
	cout << "������������" << endl;
}
void Vehicle::display()
{
}

class Car :public virtual Vehicle
{
public:
	Car(int w, int a);
	void setAird(int a);
	void display();
	int aird;
};

Car::Car(int w, int a) :Vehicle(w), aird(a)
{
	cout << "����Car�๹�캯��" << endl;
}
void Car::setAird(int a)
{
	aird = a;
	cout << "�������ÿ�������" << endl;
}
void Car::display() {}

class Boat :public virtual Vehicle
{
public:
	Boat(int w, double T);
	void setTonnage(double T);
	void display();
	double tonnage;
};

Boat::Boat(int w, double T) :Vehicle(w), tonnage(T)
{
	cout << "����Boat�๹�캯��" << endl;
}
void Boat::setTonnage(double T)
{
	tonnage = T;
	cout << "����������ˮ��" << endl;
}
void Boat::display() {}

class AmphibianCar :public Car, public Boat
{
public:
	AmphibianCar(int w, int a, double T);
	void display();
};

AmphibianCar::AmphibianCar(int w, int a, double T) :Car(w, a), Boat(w, T), Vehicle(w)
{
	cout << "����AmphibianCar�๹�캯��" << endl;
}
void AmphibianCar::display()
{
	cout << "������" << weight << "�֣�����������" << aird << "CC����ˮ����" << fixed << setprecision(2) << tonnage << "��" << endl;
}


int main()
{
	int w1, a1, w2, a2;
	double t1, t2;
	cin >> w1 >> a1 >> t1 >> w2 >> a2 >> t2;
	AmphibianCar A(w1, a1, t1);
	A.display();
	A.setWeight(w2);
	A.setAird(a2);
	A.setTonnage(t2);
	A.display();
	return 0;
}