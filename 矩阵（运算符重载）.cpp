#include<iostream>
using namespace std;

class CArray
{
	int n, m;
	int** data;
public:
	int* operator[](int n);
	int operator()(int i, int j);
	CArray() {}
	CArray(int nValue, int mValue) :n(nValue), m(mValue) 
	{
		data = new int* [n];
		for (int i = 0; i < n; i++)
			data[i] = new int[m];
	}
	CArray& operator=(CArray& c);
	~CArray()
	{
		for (int i = 0; i < n; i++)
		{
			delete[]data[i];
		}
		delete[]data;
	}
};

int* CArray::operator[](int n)
{
	return data[n];
}
int CArray::operator()(int i, int j)
{
	return data[i][j];
}

CArray& CArray::operator=(CArray& c)
{
	n = c.n;
	m = c.m;
	data = new int* [c.n];
	for (int i = 0; i < c.n; i++)
	{
		data[i] = new int[c.m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			data[i][j] = c.data[i][j];
		}
	}
	return *this;
}

int main()
{
	int t;
	int n, m;
	int i, j;

	cin >> t;
	while (t--)
	{
		cin >> n >> m;

		CArray matrixA(n, m);
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; j++)
			{
				cin >> matrixA[i][j];
			}
		}
		cout << "MatrixA:" << endl;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; j++)
			{
				cout << matrixA(i, j) << " ";
			}
			cout << endl;
		}
		cout << "MatrixB:" << endl;
		CArray matrixB;
		matrixB = matrixA;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; j++)
			{
				cout << matrixB[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}