#include<iostream>
using namespace std;

template<typename T>
class BoundArray
{
public:
	BoundArray(T *a,int n);
	void Sort();
	int Search(T a);
	void show();
	~BoundArray();
private:
	T* arr;
	int num;
};
template<typename T>
BoundArray<T>::BoundArray(T* a,int n)
{
	arr = new T[n];
	num = n;
	try
	{
		for (int i = 0; i < n; i++)
		{
			if (i >= num)
			{
				throw i;
			}
			arr[i] = a[i];
		}
	}
	catch (int)
	{
		
	}
}
template<typename T>
void BoundArray<T>::Sort()
{
	try
	{
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = 0; j < num - i - 1; j++)
			{
				if (j + 1 >= num)
				{
					throw j + 1;
				}
				if (arr[j] > arr[j + 1])
				{
					T temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	catch (int)
	{
		
	}
}

template<typename T>
int BoundArray<T>::Search(T a)
{
	int i;
	try
	{
		for (i = 0; i < num; i++)
		{
			if (i >= num)
			{
				throw i;
			}
			if (arr[i] == a)
			{
				return i;
			}
		}
	}
	catch (int)
	{
		
	}
	if (i == num)
	{
		return -1;
	}
}

template<typename T>
BoundArray<T>::~BoundArray()
{
	delete[]arr;
}

template<typename T>
void BoundArray<T>::show()
{
	for (int i = 0; i < num; i++)
	{
		try
		{
			if (i == num)
			{
				throw i;
			}
			cout << arr[i] << " ";		
		}
		catch (int)
		{
			
		}
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char input;
		cin >> input;
		if (input == 'I')
		{
			int n;
			cin >> n;
			int* arr = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			BoundArray<int> a(arr, n);
			a.Sort();
			a.show();
			int b;
			cin >> b;
			cout << a.Search(b) << endl;
		}
		else if (input == 'D')
		{
			int n;
			cin >> n;
			double* arr = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			BoundArray<double> a(arr, n);
			a.Sort();
			a.show();
			double b;
			cin >> b;
			cout << a.Search(b) << endl;
		}
		else if (input == 'C')
		{
			int n;
			cin >> n;
			char* arr = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			BoundArray<char> a(arr, n);
			a.Sort();
			a.show();
			char b;
			cin >> b;
			cout << a.Search(b) << endl;
		}
	}
	return 0;
}