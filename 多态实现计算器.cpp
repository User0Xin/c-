#include<iostream>
using namespace std;
#include<string>

//������������
class AbstrustCalculator
{
public:

	virtual int getResult()//�麯��
	{
		return 0;
	}

	int m_Num1;//������1
	int m_Num2;//������2
};

//�ӷ���������
class AddCalculator:public AbstrustCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//������������
class SubCalculator :public AbstrustCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//�˷���������
class MulCalculator :public AbstrustCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

//��һ�֣���ָ��
void test01()
{
	//�ӷ�
	AbstrustCalculator* abc = new AddCalculator;//�ø����ָ��ָ�����࣬�γɶ�̬
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getResult() << endl;
	delete abc;
	//����
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getResult() << endl;
	delete abc;
	//�˷�
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getResult() << endl;
	delete abc;
	abc = NULL;

}

//�ڶ��֣�������
void deal(AbstrustCalculator& deal)//�ø�������ָ�����࣬�γɶ�̬
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