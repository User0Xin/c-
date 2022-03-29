#include<iostream>
using namespace std;

template<class T>
void Sort(T arr[], int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		int max = i;
		for (int j = i+1; j < sz; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
			}
		}
		T ret = arr[i];
		arr[i] = arr[max];
		arr[max] = ret;
	}
}

int main()
{
	int arr[] = { 0,2,1,3,4,5,6,7,9,8 };
	float arr1[] = { 0.1,0.2,0.3,0.4,0.5,0.6,0.9,0.8,0.7 };
	Sort(arr, sizeof(arr) / sizeof(arr[0]));
	Sort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " " << endl;
	}
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		cout << arr1[i] << " " << endl;
	}
	system("pause");
	return 0;
}