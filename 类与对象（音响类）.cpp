#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Studio
{
public:
	//�вι���
	Studio(int type, string name, int price, int state);
	//��ѯ
	void Print();
	//���
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
	switch (type)//�������
	{
	case 1:
		if (state)
		{
			cout << "�ڽ�Ƭ[" << name << "]�ѳ���" << endl;
		}
		else
		{
			cout << "�ڽ�Ƭ[" << name << "]δ����" << endl;
		}
		break;
	case 2:
		if (state)
		{
			cout << "CD[" << name << "]�ѳ���" << endl;
		}
		else
		{
			cout << "CD[" << name << "]δ����" << endl;
		}
		break;
	case 3:
		if (state)
		{
			cout << "VCD[" << name << "]�ѳ���" << endl;
		}
		else
		{
			cout << "VCD[" << name << "]δ����" << endl;
		}
		break;
	case 4:
		if (state)
		{
			cout << "DVD[" << name << "]�ѳ���" << endl;
		}
		else
		{
			cout << "DVD[" << name << "]δ����" << endl;
		}
		break;
	default:
		break;
	}
}
void Studio::Fee(int day)
{
	if (state)//�������
	{
		cout << "��ǰ���Ϊ" << day * price << endl;
	}
	else
	{
		cout << "δ�������" << endl;
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

