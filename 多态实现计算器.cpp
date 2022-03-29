#include<iostream>
using namespace std;
#include<string>

//计算器抽象类
class AbstrustCalculator
{
public:

	virtual int getResult()//虚函数
	{
		return 0;
	}

	int m_Num1;//操作数1
	int m_Num2;//操作数2
};

//加法计算器类
class AddCalculator:public AbstrustCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//减法计算器类
class SubCalculator :public AbstrustCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//乘法计算器类
class MulCalculator :public AbstrustCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

//第一种：用指针
void test01()
{
	//加法
	AbstrustCalculator* abc = new AddCalculator;//用父类的指针指向子类，形成多态
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getResult() << endl;
	delete abc;
	//减法
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getResult() << endl;
	delete abc;
	//乘法
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getResult() << endl;
	delete abc;
	abc = NULL;

}

//第二种：用引用
void deal(AbstrustCalculator& deal)//用父类引用指向子类，形成多态
{
	cout<<deal.getResult()<<endl;
}
int main()
{
	test01();

	
	AddCalculator add;
	add.m_Num1 = 10;
	add.m_Num2 = 20;
	SubCalculator sub;
	sub.m_Num1 = 10;
	sub.m_Num2 = 20;
	MulCalculator mul;
	mul.m_Num1 = 10;
	mul.m_Num2 = 20;
	deal(add);
	deal(sub);
	deal(mul);
	system("pause");
	return 0;
}