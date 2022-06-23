#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void mysort(vector<T>&arr)
{
	int min = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		min = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main()
{
	vector<int>arr = { 5,4,6,2,1 };
	mysort(arr);
	vector<int>::iterator itbegin = arr.begin();
	vector<int>::iterator itend = arr.end();
	while (itbegin != itend)
	{
		cout << *itbegin << " ";
		itbegin++;
	}
	return 0;
}