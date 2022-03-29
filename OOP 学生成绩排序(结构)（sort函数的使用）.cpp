#include<iostream>
#include <iomanip>
#include<string>
#include<algorithm>
using namespace std;

struct S
{
	string name;
	int age;
	int grade;
};

int mysort(S s1, S s2);

int main()
{
	int n;
	cin >> n;

	S* stu = new S[n];//��̬�����ṹ������
	for (int i = 0; i < n; i++)//����
	{
		cin >> stu[i].name >> stu[i].age >> stu[i].grade;
	}

	sort(stu, stu + n, mysort);//����
	for (int i = 0; i < n; i++)//���
	{
		cout << stu[i].name << " " << stu[i].age << " " << stu[i].grade << endl;
	}
	delete[] stu;
	return 0;
}

int mysort(S s1, S s2)//���򷽷�
{
	if (s1.grade != s2.grade)
	{
		return s1.grade < s2.grade;
	}
	else if (s1.name != s2.name)
	{
		return s1.name < s2.name;
	}
	else
	{
		return s1.age < s2.age;
	}
}