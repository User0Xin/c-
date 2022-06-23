#include<iostream>
using namespace std;

class Ctan
{
public:
	Ctan(Ctan& C);
	Ctan(int X, int Y, int** A);
	Ctan operator+(Ctan& b);
	Ctan operator-(Ctan& b);
	int** geta();
private:
	int x, y;
	int** a;

};

Ctan::Ctan(Ctan& C)
{
	x = C.x;
	y = C.y;
	a = new int* [x];
	for (int i = 0; i < x; i++)
	{
		a[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			a[i][j] = C.a[i][j];
		}
	}
}

Ctan::Ctan(int X, int Y, int** A) :x(X), y(Y)
{
	a = new int* [X];
	for (int i = 0; i < X; i++)
	{
		a[i] = new int[Y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			a[i][j] = A[i][j];
		}
	}
}

Ctan Ctan::operator+(Ctan& b)
{
	Ctan temp = b;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			temp.a[i][j] = a[i][j] + b.a[i][j];
		}
	}
	return temp;
}

Ctan Ctan::operator-(Ctan& b)
{
	Ctan temp = b;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			temp.a[i][j] = a[i][j] - b.a[i][j];
		}
	}
	return temp;
}

int** Ctan::geta()
{
	return a;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> x >> y;
		int** arr;
		arr = new int* [x];
		for (int j = 0; j < x; j++)
		{
			arr[j] = new int[y];
		}
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				cin >> arr[j][k];
			}
		}
		Ctan T1(x, y, arr);
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				cin >> arr[j][k];
			}
		}
		Ctan T2(x, y, arr);
		Ctan T3 = T2;
		T3 = T1 + T2;
		cout << "Add:" << endl;
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{

				cout << T3.geta()[j][k] << " ";
			}
			cout << endl;
		}
		T3 = T1 - T2;
		cout << "Minus:" << endl;
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{

				cout << T3.geta()[j][k] << " ";
			}
			cout << endl;
		}
		cout << "-----------------" << endl;
	}
	return 0;
}