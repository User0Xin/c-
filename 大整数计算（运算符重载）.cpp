#include<iostream>
using namespace std;

class CBigInteger
{
public:
	CBigInteger();
	CBigInteger(char* n);
	CBigInteger(const CBigInteger& C);
	CBigInteger operator+(CBigInteger& C);
	CBigInteger operator-(CBigInteger& C);
	CBigInteger operator*(CBigInteger& C);
	~CBigInteger();
	friend istream& operator>>(istream& in, CBigInteger& C);
	friend ostream& operator<<(ostream& out, CBigInteger C);
private:
	char* num;
};

CBigInteger::CBigInteger()
{
	num = new char[1001];
	for (int i = 0; i < 1001; i++)
	{
		num[i] = '0';
	}
}

CBigInteger::CBigInteger(const CBigInteger& C) {
	num = new char[1001];
	strcpy(num, C.num);
}

CBigInteger::CBigInteger(char* n)
{
	num = new char[1001];
	for (int i = 0; i < 1001; i++)
	{
		num[i] = '0';
	}
	strcpy(num, n);
}
CBigInteger CBigInteger::operator+(CBigInteger& C)
{
	CBigInteger temp;
	int i = 0;
	int j = 0, k = 0;
	while (num[j]< '9'|| num[j] > '0')
	{
		j++;
	}
	while(C.num[k] < '9' || C.num[k] > '0')
	{
		k++;
	}
	
	if (num[j] == '-' && C.num[k] == '-')
	{
		num[j] = '0';
		C.num[k] = '0';

		while (i < min(j, k))
		{
			int x = temp.num[i] - '0';
			x += num[i] - '0' + C.num[i] - '0';
			if (x >= 10)
			{
				x = x % 10;
				temp.num[i + 1]++;
			}
			temp.num[i] += x;
			i++;
		}
		while (i < max(j, k))
		{
			if (i == j)
			{
				temp.num[i] += C.num[i]-'0';
			}
			else
			{
				temp.num[i] += num[i]-'0';
			}
			i++;
		}
		temp.num[i] = '-';
	}
	else if (num[j] != '+' && C.num[k] == '-')
	{
		return *this - C;
	}
	else if (num[j] != '-' && C.num[k] == '+')
	{
		return C-*this;
	}
	else
	{
		num[j] = '0';
		C.num[k] = '0';

		while (i < min(j, k))
		{
			int x = temp.num[i] - '0';
			x += num[i] - '0' + C.num[i] - '0';
			if (x >= 10)
			{
				x = x % 10;
				temp.num[i + 1]++;
			}
			temp.num[i] += x;
			i++;
		}
		while (i < max(j, k))
		{
			if (i == j)
			{
				temp.num[i] += C.num[i]-'0';
			}
			else
			{
				temp.num[i] += num[i] - '0';
			}
			i++;
		}
		temp.num[i] = '+';
	}
	return temp;
}
CBigInteger CBigInteger::operator-(CBigInteger& C)
{
	CBigInteger temp;
	int i = 0;
	int j = 0, k = 0;
	while (num[j] < '9' || num[j] > '0')
	{
		j++;
	}
	while (C.num[k] < '9' || C.num[k] > '0')
	{
		k++;
	}

	if (num[j] == '+' && C.num[k] == '+')
	{
		num[j] = '0';
		C.num[k] = '0';
		if (num > C.num)
		{
			while (i < min(j, k))
			{
				int x = temp.num[i] - '0';
				x += num[i] - '0' - C.num[i] - '0';
				if (x <0)
				{
					x = x + 10;
					temp.num[i + 1]--;
				}
				temp.num[i] += x;
				i++;
			}
			while (i < max(j, k))
			{
				if (i == j)
				{
					temp.num[i] += C.num[i]-'0';
				}
				else
				{
					temp.num[i] += num[i]-'0';
				}
				i++;
			}
			temp.num[i] = '+';
		}
		else
		{
			temp = C - *this;
			int m=0;
			while (temp.num[m] != '+')
			{
				m++;
			}
			temp.num[m] == '-';
		}
	}
	else if (num[j] != '+' && C.num[k] == '-')
	{
		return *this + C;
	}
	else if (num[j] != '-' && C.num[k] == '+')
	{
		C.num[k] = '-';
		return C + *this;
	}
	else
	{
		return C - *this;
	}
	return temp;
}
CBigInteger CBigInteger::operator*(CBigInteger& C)
{

}
CBigInteger::~CBigInteger();


istream& operator>>(istream& in, CBigInteger& C) {
	char temp[1001];
	in >> temp;
	int i = 0;
	if (temp[0] == '0' && temp[1] != '\0')
		for (i = 0; temp[i] == '0'; i++);
	strcpy(C.num, temp + i);
	return in;
}

ostream& operator<<(ostream& out, CBigInteger C) {
	if (C.num[0] == '-')
	{
		out << '(' << C.num << ')';
	}
	else
	{
		out << C.num;
	}
	return out;
}

int main()
{
	int t;
	char op;
	CBigInteger bigNum1;
	CBigInteger bigNum2;

	cin >> t;
	while (t--)
	{
		cin >> bigNum1 >> op >> bigNum2;
		cout << bigNum1 << " " << op << " " << bigNum2 << " = ";
		if (op == '+')
		{
			cout << bigNum1 + bigNum2 << endl;
		}
		else if (op == '-')
		{
			cout << bigNum1 - bigNum2 << endl;
		}
		else if (op == '*')
		{
			cout << bigNum1 * bigNum2 << endl;
		}
	}
	return 0;
}