#include<iostream>
#include <iomanip>
#include<string>
#include<algorithm>
using namespace std;

struct card
{
	string a;
	int num;
	int hua;
};
string num[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
string hua[6] = { "����","÷��","����","����","С��","����" };
int mycompare2(card c1, card c2);

int search1(string s);
int search2(string s);
int main()
{
	int n;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		int t;
		cin >> t;
		card* C = new card[t];//��̬�����ṹ������
		string str[6][100];//���ڽ��ղ�ͬ������
		for (int i = 0; i < t; i++)//����
		{
			cin >> C[i].a;
		}
		for (int i = 0; i < t; i++)
		{
			C[i].num = search1(C[i].a);
			C[i].hua = search2(C[i].a);
		}

		sort(C, C + t, mycompare2);
		for (int i = 0; i < t; i++)
		{
			if (i != t - 1)
			{
				cout << C[i].a << " ";
			}
			else
			{
				cout << C[i].a << endl;
			}
		}
		delete[] C;
	}
	return 0;
}

int search1(string s)
{
	int index = -1;
	for (int i = 0; i < 13; i++)
	{
		index = s.find(num[i], 0);
		if (index != -1)
		{
			return i;
		}
	}
}
int search2(string s)
{
	int index = -1;
	for (int i = 0; i < 13; i++)
	{
		index = s.find(hua[i], 0);
		if (index != -1)
		{
			return i;
		}
	}
}

int mycompare2(card c1, card c2)//�ȽϷ���
{
	if (c1.hua == c2.hua)
	{
		return c1.num > c2.num;
	}
	else
	{
		return c1.hua > c2.hua;
	}
}