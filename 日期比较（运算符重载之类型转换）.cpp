#include<iostream>
#include<iomanip>
using namespace std;

class CDate
{
public:
	operator int();
	CDate(int a = 0);
	void Print();
private:
	int y;
	int m;
	int d;
};

CDate::CDate(int a)
{
	d = a % 100;
	m = a / 100 % 100;
	y = a / 10000;
}

CDate::operator int()
{
	return y * 10000 + m * 100 + d;
}

void CDate::Print()
{
	cout << y << "��" << setw(2) << setfill('0') << m << "��" << setw(2) << setfill('0') << d << "��" << endl;
}

int main()
{
	int t, t1, t2;
	CDate C1, C2;
	cin >> t;
	while (t--)
	{
		cin >> t1 >> t2;
		C1 = t1;
		C2 = t2;
		((C1 > C2) ? C1 : C2).Print(); //���ڴ��������ڴ���C1>C2�У����Զ���C1��C2ת��Ϊ�������бȽ�
	}

	return 0;

}