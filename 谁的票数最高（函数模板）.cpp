#include<iostream>
#include<algorithm>
using namespace std;

int mycmp(int a[], int b[])
{
	return a[1] > b[1];
}

template<typename T>
void check(T a[], int n)
{
	int** result = new int*[n];
	a[49] = '=';
	for (int i = 0; i < n; i++)
	{
		result[i] = new int[2]{49,0};
	}
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < n; j++)
		{
			if (a[result[j][0]] == a[i])
			{
				result[j][1]++;
				break;
			}
		}
		if (j == n)
		{
			result[x][0] = i;
			result[x][1] = 1;
			x++;
		}
	}
	sort(result, result+n, mycmp);
	cout << a[result[0][0]] << " " << result[0][1] << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char a;
		int n =0;
		cin >> a;
		if (a == 'I')
		{
			cin >> n;
			int arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			check(arr, n);
		}
		else if (a == 'C')
		{
			cin >> n;
			char arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			check(arr, n);
		}
		else if (a == 'S')
		{
			cin >> n;
			string arr[50];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			check(arr, n);
		}
	}
	return 0;
}