#include<iostream>
using namespace std;

template<class T>
class Bet
{
public:
	Bet(T a[], int N);
	void insert(int N, T val);
	void Delete(int N);
	void print();
	
private:
	T arr[100];
	int n;
};
template<class T>
Bet<T>::Bet(T a[], int N)
{
	n = N;
	for (int i = 0; i < n; i++)
	{
		arr[i] = a[i];
	}
}
template<class T>
void Bet<T>::insert(int N, T val)
{
	for (int i = n - 1; i >= N ; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[N] = val;
	n++;
}
template<class T>
void Bet<T>::Delete(int N)
{
	for (int i = N; i < n-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}
template<class T>
void Bet<T>::print()
{
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			cout << arr[i] << " ";
		}
		else
		{
			cout << arr[i] << endl;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	Bet<int> b1(arr, n);
	int index, val;
	cin >> index>> val;
	b1.insert(index, val);
	cin >> index;
	b1.Delete(index);
	b1.print();

	cin >> n;
	double* arr1 = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	Bet<double> b2(arr1, n);
	double val1;
	cin >> index >> val1;
	b2.insert(index, val1);
	cin >> index;
	b2.Delete(index);
	b2.print();
	return 0;
}