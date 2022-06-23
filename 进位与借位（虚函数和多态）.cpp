#include<iostream>
using namespace std;

class Group
{
public:
	virtual int add(int x, int y) = 0;//输出加法的运算结果
	virtual int sub(int x, int y) = 0;//输出减法的运算结果
};

class GroupA:public Group
{
public:
	int add(int x, int y);
	int sub(int x, int y);
};

int GroupA::add(int x, int y)
{
	return x + y;
}
int GroupA::sub(int x, int y)
{
	return x - y;
}

class GroupB:public Group
{
public:
	int add(int x, int y);
	int sub(int x, int y);
};

int GroupB::add(int x, int y)
{
	return x + y;
}
int GroupB::sub(int x, int y)
{
	int result = x - y;
	int i = 10;
	while (1)
	{
		if ((x-y) % i/(i/10) != 0)
		{
			result += i;
		}
		i *= 10;
		if ((i/10) > x - y)
		{
			break;
		}
	}
	return result;
}

class GroupC:public Group
{
public:
	int add(int x, int y);
	int sub(int x, int y);
};

int GroupC::add(int x, int y)
{
	int result = x + y;
	int i = 10;
	while (1)
	{
		if (x % i / (i / 10) + y % i / (i / 10) >= 10)
		{
			result -= i;
		}
		i *= 10;
		if ((i / 10) > x || (i / 10) > y)
		{
			break;
		}
	}
	return result;
}
int GroupC::sub(int x, int y)
{
	int result = x - y;
	int i = 10;
	while (1)
	{
		if ((x - y) % i / (i / 10) != 0)
		{
			result += i;
		}
		i *= 10;
		if (i  > x - y)
		{
			break;
		}
	}
	return result;
}


int main()
{
	int t;
	cin >> t;
	Group* G;
	int input;	
	for (int i = 0; i < t; i++)
	{
		cin >> input;
		if (input == 1)
		{
			G = new GroupA;
			char a[10];
			cin >> a;
			int i;
			for (i = 0; i < 10; i++)
			{
				if (!isdigit(a[i]))
				{
					break;
				}
			}
			int num1 = 0, num2 = 0;
			int del = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				num1 += (a[j] - '0') * del;
				del *= 10;
			}
			int k = i;
			while (1)
			{
				if (a[k] == '\0')
				{
					break;
				}
				k++;
			}
			k--;
			for (int j = k, del = 1; j > i; j--)
			{
				num2 += (a[j] - '0') * del;
				del *= 10;
			}
			if (a[i] == '+')
			{
				cout << G->add(num1, num2) << endl;
			}
			else
			{
				cout << G->sub(num1, num2) << endl;
			}
		}
		else if (input == 2)
		{
			G = new GroupB;
			char a[10];
			cin >> a;
			int i;
			for (i = 0; i < 10; i++)
			{
				if (!isdigit(a[i]))
				{
					break;
				}
			}
			int num1 = 0, num2 = 0;
			int del = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				num1 += (a[j] - '0') * del;
				del *= 10;
			}
			int k = i;
			while (1)
			{
				if (a[k] == '\0')
				{
					break;
				}
				k++;
			}
			k--;
			for (int j = k, del = 1; j > i; j--)
			{
				num2 += (a[j] - '0') * del;
				del *= 10;
			}
			if (a[i] == '+')
			{
				cout << G->add(num1, num2) << endl;
			}
			else
			{
				cout << G->sub(num1, num2) << endl;
			}
		}
		else
		{
			G = new GroupC;
			char a[10];
			cin >> a;
			int i;
			for (i = 0; i < 10; i++)
			{
				if (!isdigit(a[i]))
				{
					break;
				}
			}
			int num1 = 0, num2 = 0;
			int del = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				num1 += (a[j] - '0') * del;
				del *= 10;
			}
			int k = i;
			while (1)
			{
				if (a[k] == '\0')
				{
					break;
				}
				k++;
			}
			k--;
			for (int j = k, del = 1; j > i; j--)
			{
				num2 += (a[j] - '0') * del;
				del *= 10;
			}
			if (a[i] == '+')
			{
				cout << G->add(num1, num2) << endl;
			}
			else
			{
				cout << G->sub(num1, num2) << endl;
			}

		}
	}
	return 0;
}