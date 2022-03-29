#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, const Person& p);//��Ϊ��Ԫ����˽������
public:
	void operator()(Person& p1, Person& p2)//()����
	{
		m_a = p1.getm_a() + p2.getm_a();
	}
	Person& operator++()//ǰ��++����
	{
		m_a++;
		return *this;
	}
	Person operator++(int)//����++����
	{
		Person temp = *this;
		m_a++;
		return temp;
	}
	Person()
	{
	}
	Person(int a,int b)
	{
		m_a = a;
		m_b = b;
	}
	void seta(int a)
	{
		m_a = a;
	}
	void setb(int b)
	{
		m_b = b;
	}
	int getm_a()const
	{
		return m_a;
	}
	int getm_b()const
	{
		return m_b;
	}
private:
	int m_a;
	int m_b;
};
ostream& operator<<(ostream& cout, const Person& p1)//����λ������
{
	cout << "a = " << p1.getm_a() << "b = " << p1.getm_b();
	return cout;
}
Person operator+(const Person& p1, const Person& p2)//�Ӻ�����
{
	Person temp;
	temp.seta(p1.getm_a() + p2.getm_a());
	temp.setb(p1.getm_b() + p2.getm_b());
	return temp;
}


int main()
{
	Person p1(10, 20);
	Person p2(10, 20);
	Person p3 = p1 + p2;
	cout << p3 << endl;
	++p3;
	p3++;
	cout << p3 << endl;
	p3(p1,p2); 
	cout << p3 << endl;
	system("pause");
}