#include<iostream>
using namespace std;

class Studen
{
public://����Ȩ��
	
	//��Ա����
	string name;
	int Num;

	//��Ա����
	void Showname()
	{
		cout << "����Ϊ��" << name << endl;
	}
	void ShowNum()
	{
		cout << "ѧ��Ϊ��" << Num << endl;
	}

	//���ó�Ա����
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