#include<iostream>
using namespace std;

template<class T>
class Matrix
{
public:
	Matrix(int m, int n, T** a);
	void transport();
	void print();
private:
	int m;
	int n;
	T** arr;
};

template<class T>
Matrix<T>::Matrix(int m, int n, T** a)
{
	this->m = m;
	this->n = n;
	arr = new T* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = a[i][j];
		}
	}
}

template<class T>
void Matrix<T>::transport()
{
	T temp[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[j][i] = arr[i][j];
		}
	}
	int t = m;
	m = n;
	n = t;
	arr = new T * [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}
}
template<class T>
void Matrix<T>::print()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != n - 1)
			{
				cout << arr[i][j] << " ";
			}
			else
			{
				cout << arr[i][j] << endl;
			}
		}
	}
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char input;
		cin >> input;
		if (input == 'I')
		{
			int m, n;
			cin >> m >> n;
			int** arr = new int* [m];
			for (int i = 0; i < m; i++)
			{
				arr[i] = new int[n];
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> arr[i][j];
				}
			}
			Matrix<int> M(m, n, arr);
			M.transport();
			M.print();
		}
		else if (input == 'D')
		{
			int m, n;
			cin >> m >> n;
			double** arr = new double* [m];
			for (int i = 0; i < m; i++)
			{
				arr[i] = new double[n];
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> arr[i][j];
				}
			}
			Matrix<double> M(m, n, arr);
			M.transport();
			M.print();
		}
		else if (input == 'C')
		{
			int m, n;
			cin >> m >> n;
			char** arr = new char* [m];
			for (int i = 0; i < m; i++)
			{
				arr[i] = new char[n];
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> arr[i][j];
				}
			}
			Matrix<char> M(m, n, arr);
			M.transport();
			M.print();
		}
	}
	return 0;
}
