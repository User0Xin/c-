#include<iostream>
using namespace std;

class AbstructDrink//抽象类
{
public:
	//煮水
	void Boil()
	{
		cout << "煮水" << endl;
	}

	//冲泡
	virtual void pao() = 0;

	//倒入杯中
	void pour()
	{
		cout << "倒入杯中" << endl;
	}

	//加料
	virtual void Poursomething() = 0;
	
	//制作
	void Do()
	{
		Boil();
		pao();
		pour();
		Poursomething();
	}
};

//冲咖啡
class coffee:public AbstructDrink
{
public:
	void pao()//重写
	{
		cout << "冲咖啡" << endl;
	}
	void Poursomething()
	{
		cout << "加糖和牛奶" << endl;
	}
};

//冲茶
class tea :public AbstructDrink
{
public:
	void pao()//重写
	{
		cout << "冲茶叶" << endl;
	}
	void Poursomething()
	{
		cout << "加柠檬" << endl;
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