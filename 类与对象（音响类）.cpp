#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Studio
{
public:
	//有参构造
	Studio(int type, string name, int price, int state);
	//查询
	void Print();
	//租金
	void Fee(int day);

private:
	int type;
	string name;
	int price;
	int state;
};
Studio::Studio(int type, string name, int price, int state)
{
	this->type = type;
	this->name = name;
	this->price = price;
	this->state = state;
}
void Studio::Print()
{
	switch (type)//分类输出
	{
	case 1:
		if (state)
		{
			cout << "黑胶片[" << name << "]已出租" << endl;
		}
		else
		{
			cout << "黑胶片[" << name << "]未出租" << endl;
		}
		break;
	case 2:
		if (state)
		{
			cout << "CD[" << name << "]已出租" << endl;
		}
		else
		{
			cout << "CD[" << name << "]未出租" << endl;
		}
		break;
	case 3:
		if (state)
		{
			cout << "VCD[" << name << "]已出租" << endl;
		}
		else
		{
			cout << "VCD[" << name << "]未出租" << endl;
		}
		break;
	case 4:
		if (state)
		{
			cout << "DVD[" << name << "]已出租" << endl;
		}
		else
		{
			cout << "DVD[" << name << "]未出租" << endl;
		}
		break;
	default:
		break;
	}
}
void Studio::Fee(int day)
{
	if (state)//计算租金
	{
		cout << "当前租金为" << day * price << endl;
	}
	else
	{
		cout << "未产生租金" << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int type, price, state, input;
		string name;
		cin >> type >> name >> price >> state;
		Studio S(type, name, price, state);
		cin >> input;
		S.Print();
		if (input)
		{
			S.Fee(input);
		}
	}
	return 0;
}

