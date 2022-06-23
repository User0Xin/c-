#include<iostream>
using namespace std;

bool check(int* arr, int val,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == val)
		{
			return false;
		}
	}
	return true;
}

class CSet
{
public:
	friend ostream& operator<<(ostream& cout, CSet& a);
	CSet operator+(CSet& c);
	CSet operator-(CSet& c);
	CSet operator*(CSet& c);
	CSet(int N, int* d);
	CSet();

	void print();
private:
	int n;
	int* data;
};

void CSet::print()
{
	for (int i = 0; i < n; i++)
	{
		cout << data[i] << " ";
	}
}

CSet::CSet()
{
	n = 0;
	data = new int[50];
	for (int i = 0; i < 50; i++)
	{
		data[i] = 0;
	}
}


CSet::CSet(int N, int* d) :n(N)
{
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = d[i];
	}
}



ostream& operator<<(ostream& cout, CSet& a)
{
	for (int j = 0; j < a.n; j++)
	{
		if (j != a.n - 1)
		{
			cout << a.data[j] << " ";
		}
		else
		{
			cout <<  a.data[j]<<endl;
		}
	}
	return cout;
}

CSet CSet::operator+(CSet& c)
{
	CSet temp;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		temp.data[i] = data[i];
		temp.n++;
	}
	for (int j = 0; j < c.n; j++)
	{
		if (check(data, c.data[j],c.n))
		{
			temp.data[i] = c.data[j];
			i++;
			temp.n++;
		}
	}
	return temp;
}
CSet CSet::operator-(CSet& c)
{
	CSet temp;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (check(c.data, data[i],c.n))
		{
			temp.data[j] = data[i];
			j++;
			temp.n++;
		}
	}
	return temp;
}
CSet CSet::operator*(CSet& c)
{
	CSet temp;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (!check(c.data, data[i],c.n))
		{
			temp.data[j] = data[i];
			j++;
			temp.n++;
		}
	}
	return temp;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n1, n2;
		int* d1, * d2;
		cin >> n1;
		d1 = new int[n1];
		for (int j = 0; j < n1; j++)
		{
			cin >> d1[j];
		}
		cin >> n2;
		d2 = new int[n2];
		for (int j = 0; j < n2; j++)
		{
			cin >> d2[j];
		}
		CSet C1(n1, d1);
		CSet C2(n2, d2);
		cout << "A:" << C1;
		cout << "B:" << C2;
		CSet C3 = C1 + C2;
		cout << "A+B:" << C3;
		CSet C4 = C1 * C2;
		cout << "A*B:" << C4;
		CSet C5 = C1 - C2;
		CSet C6 = C2 - C1;
		CSet C7 = C5 + C6;
		cout << "(A-B)+(B-A):" << C7;
		cout << endl;
	}
	return 0;
}