#include<iostream>
using namespace std;

//交换函数
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

//模板：
template<typename T>//让编译器不要报T的错，T是一个通用数据类型
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
	//模板的使用：
	//1、自动类型推导
	Myswap(a,b);
	Myswap(c, d);

	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;
	//2、显示指定类型
	Myswap<int>(a, b);
	Myswap<double>(c, d);

	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;
	system("pause");
	return 0;
}