#include<iostream>
using namespace std;

class AbstructDrink//������
{
public:
	//��ˮ
	void Boil()
	{
		cout << "��ˮ" << endl;
	}

	//����
	virtual void pao() = 0;

	//���뱭��
	void pour()
	{
		cout << "���뱭��" << endl;
	}

	//����
	virtual void Poursomething() = 0;
	
	//����
	void Do()
	{
		Boil();
		pao();
		pour();
		Poursomething();
	}
};

//�忧��
class coffee:public AbstructDrink
{
public:
	void pao()//��д
	{
		cout << "�忧��" << endl;
	}
	void Poursomething()
	{
		cout << "���Ǻ�ţ��" << endl;
	}
};

//���
class tea :public AbstructDrink
{
public:
	void pao()//��д
	{
		cout << "���Ҷ" << endl;
	}
	void Poursomething()
	{
		cout << "������" << endl;
	}
};

void Dowork(AbstructDrink& abc)
{
	abc.Do();
}

void test01()
{
	coffee coffee;
	tea tea;
	Dowork(coffee);
	cout << "--------------------" << endl;
	Dowork(tea);
}
int main()
{
	test01();
	system("pause");
	return 0;
}