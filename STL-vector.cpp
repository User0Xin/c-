#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void myprint(int val)
{
	cout << val << endl;
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//������
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	//��һ�ֱ�������
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//�ڶ���
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//������
	for_each(v.begin(), v.end(), myprint);
}

//����������
void test02()
{
	//����С����
	vector<int>a;
	vector<int>b;
	vector<int>c;
	vector<int>d;
	vector<int>e;
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i+1);
		b.push_back(i + 1);
		c.push_back(i + 1);
		d.push_back(i + 1);
		e.push_back(i + 1);
	}

	//����������
	vector<vector<int>>A;

	//��С�����ŵ���������
	A.push_back(a);
	A.push_back(b);
	A.push_back(c);
	A.push_back(d);
	A.push_back(e);

	//����
	for (vector<vector<int>>::iterator it = A.begin(); it != A.end(); it++)
	{
		//*(it)-------vector<int>����
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit<<" ";
		}
		cout << endl;
	}
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}