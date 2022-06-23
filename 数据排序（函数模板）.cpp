#include<iostream>
using namespace std;

template<typename T>
void Sort(T arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[j] < arr[max])
			{
				max = j;
			}
		}
		T ret = arr[i];
		arr[i] = arr[max];
		arr[max] = ret;
	}
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char a;
		int n = 0;
		cin >> a;
		if (a == 'I')
		{
			cin >> n;
			int arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			Sort(arr, n);
		}
		else if (a == 'C')
		{
			cin >> n;
			char arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			Sort(arr, n);
		}
		else if (a == 'S')
		{
			cin >> n;
			string arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			Sort(arr, n);
		}
		else if (a == 'D')
		{
			cin >> n;
			double arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			Sort(arr, n);
		}

	}
	return 0;
}