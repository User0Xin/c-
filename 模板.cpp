#include<iostream>
using namespace std;

//��������
void myswap(int &a, int &b)//int
{
	int temp = a;
	a = b;
	b = temp;
}

void myswap(double &a, double &b)//double
{
	int temp = a;
	a = b;
	b = temp;
}

//ģ�壺
template<typename T>//�ñ�������Ҫ��T�Ĵ�T��һ��ͨ����������
void Myswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 1;
	int b = 2;
	double c = 0.1;
	double d = 0.2;
	//ģ���ʹ�ã�
	//1���Զ������Ƶ�
	Myswap(a,b);
	Myswap(c, d);

	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;
	//2����ʾָ������
	Myswap<int>(a, b);
	Myswap<double>(c, d);

	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;
	system("pause");
	return 0;
}