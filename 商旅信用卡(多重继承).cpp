#include<iostream>
#include<string>
using namespace std;

class Vip
{
public:
	Vip(int c,int n);
	void pay(int n);
	int card;
	int num;
};

Vip::Vip(int c, int n) :card(c), num(n) {}
void Vip::pay(int n)
{
	num += n;
}

class Xcard
{
public:
	Xcard(int C,string n,int m, float c, int N);
	void Pay(float n);
	void back(float n);
	int Card;
	string name;
	int max;
	float count;
	int Num;
};

Xcard::Xcard(int C, string n,int m,  float c, int N) :Card(C), name(n),max(m), count(c), Num(N) {}
void Xcard::Pay(float n)
{
	if (n + count <= max)
	{
		count += n;
		Num += n;
	}
}

void Xcard::back(float n)
{
	count -= n;
	Num -= (int)n;
}

class Newcard :public Vip, public Xcard
{
public:
	Newcard(int c, int C, string name, int m);
	void PAY(float n);
	void change(float n);
};

Newcard::Newcard(int c, int C, string name, int m) :Vip(c, 0), Xcard(C, name, m, 0, 0) {}
void Newcard::PAY(float n)
{
	count += n;
	num += n;
	Num += n;
}
void Newcard::change(float n)
{
	num += n / 2.0;
	Num -= n;
}

int main()
{
	int c, C, m;
	string name;
	cin >> c >> C >> name >> m;
	Newcard Nc(c, C, name, m);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char input;
		cin >> input;
		switch (input)
		{
			float n;
		case 'o':			
			cin >> n;
			Nc.PAY(n);
			break;
		case 'c':
			cin >> n;
			Nc.Pay(n);
			break;
		case 'q':
			cin >> n;
			Nc.back(n);
			break;
		case 't':
			cin >> n;
			Nc.change(n);
			break;
		default:
			break;
		}
	}
	cout << Nc.card << " " << Nc.num << endl << Nc.Card << " " << Nc.name << " " << Nc.count << " " << Nc.Num << endl;
	return 0;
}