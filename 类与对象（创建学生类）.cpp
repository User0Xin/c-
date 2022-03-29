#include<iostream>
using namespace std;

class Studen
{
public://访问权限
	
	//成员变量
	string name;
	int Num;

	//成员方法
	void Showname()
	{
		cout << "姓名为：" << name << endl;
	}
	void ShowNum()
	{
		cout << "学号为：" << Num << endl;
	}

	//设置成员变量
	void Setname(string name)
	{
		this->name = name;
	}
	void SetNum(int Num)
	{
		this->Num = Num;
	}
};
int main()
{
	Studen xiao;
	xiao.Setname("xiaomin");
	xiao.SetNum(123);
	xiao.Showname();
	xiao.ShowNum();
	system("pause");
}