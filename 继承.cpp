#include<iostream>
using namespace std;

class father
{
public:
	void set(int a)
	{
		m_a = a;
	}
	int get()
	{
		return m_a;
	}
private:
	int m_a;
};

class son :virtual public father//virtual��̳н�����μ̳�����
{
public:
	int m_b;
	int m_a;
};

class grandson :virtual public father
{
	
};
class a :public son, public grandson
{

};
void test01()
{
	son s1;
	a a;
	s1.m_a = 20;
	s1.m_b = 30;
	s1.father::set(10);
	cout << s1.father::get()<< endl;
	cout << s1.m_a << endl;
	cout << s1.m_b << endl;
	cout << s1.get() << endl;
	cout << a.get() << endl;//�������virtual��仰�ͻᱨ��a.get()ָ����ȷ����֪����son�Ļ���grandson��
}
int main()
{
	test01();
	system("pause");
	return 0;
}