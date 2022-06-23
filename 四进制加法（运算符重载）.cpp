#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class Cfour
{
public:
	Cfour(char* X);
	Cfour& operator+(Cfour& c);
	void show();
private:
	char* x;
};

Cfour::Cfour(char* X)
{
	x = new char[strlen(X)];
	strcpy(x, X);
}
Cfour& Cfour::operator+(Cfour& c)
{
	int a=strlen(c.x);
	int b=strlen(x);
	char arr[50];
	for (int i = 0; i < 50; i++)
	{
		arr[i] = '0';
	}
	int i = 0;
	while (1)
	{
		if (a == 0)
		{
			while (b != 0)
			{
				arr[i] += x[b - 1]-'0';
				if (arr[i] >= '4')
				{
					arr[i] = arr[i] - 4;
					arr[i + 1]++;
				}
				b--;
				i++;
			}
			if (arr[i] != '0')
			{
				i++;
			}
			break;
		}
		else if (b == 0)
		{
			while (a != 0)
			{
				arr[i] += c.x[a - 1]-'0';
				if (arr[i] >= '4')
				{
					arr[i] = arr[i] - 4;
					arr[i + 1]++;
				}
				a--;
				i++;
			}
			if (arr[i] != '0')
			{
				i++;
			}
			break;
		}
		arr[i] += x[b-1] + c.x[a-1]-'0'-'0';
		if (arr[i] >= '4')
		{
			arr[i] = arr[i] - 4;
			arr[i + 1]++;
		}
		a--;
		b--;
		i++;
	}
	int j = 0;
	for (j = 0; j < i; j++)
	{
		x[j] = arr[i - j-1 ];
	}
	x[j] = '\0';
	return *this;
}

void Cfour::show()
{
	cout << x << endl;
}

int main()
{
	int t;
	char str[50];
	cin >> t;
	cin >> str;
	Cfour C(str);
	for (int i = 0; i < t-1; i++)
	{
		cin >> str;
		Cfour C2(str);
		C = C + C2;

	}
	C.show();
	return 0;
}