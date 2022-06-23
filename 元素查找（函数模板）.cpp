#include<iostream>
using namespace std;

template<typename T>
int Search(T a[], int n,T x)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return i+1;
		}
	}
	if (i == n)//×ßÍê£¨Î´ÕÒµ½£©
	{
		return 0;
	}
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
			int key;
			cin >> key;
			cout << Search(arr, n, key) << endl;
		}
		else if (a == 'C')
		{
			cin >> n;
			char arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			char key;
			cin >> key;
			cout << Search(arr, n, key) << endl;
		}
		else if (a == 'S')
		{
			cin >> n;
			string arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			string key;
			cin >> key;
			cout << Search(arr, n, key) << endl;
		}
		else if (a == 'D')
		{
			cin >> n;
			double arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			double key;
			cin >> key;
			cout << Search(arr, n, key) << endl;
		}
	}
	return 0;
}