#include<iostream>
#include<algorithm>
using namespace std;

int compare(int a, int b)
{
	return a > b;
}
class Solution
{
public:
	int binaryGap(int n)
	{
		int ret = n;
		int x=1;
		int count = 1;
		while (1)
		{
			x = x * 2;
			if (x > n)
			{
				break;
			}
			count++;
		}
		int arr[33];
		int j = 0;
		for (int i = 0; i < count; i++)
		{
			if(n%2!=0)
			{
				arr[j] = i;
				j++;
			}
			n = n >> 1;
		}
		if (j == 1)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < j-1; i++)
			{
				arr[i] = arr[i + 1] - arr[i];
			}
			sort(arr, arr + j-1, compare);
			return arr[0];
		}
	}
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	cout<<s.binaryGap(n);

}