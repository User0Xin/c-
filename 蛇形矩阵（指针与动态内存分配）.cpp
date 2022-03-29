#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int N, j, k;
		int m = 0, n = 0;
		cin >> N;
		//动态开辟数组
		int** p = new int* [N];
		for (j = 0; j < N; j++)
		{
			*(p + j) = new int[N];
		}
		int sign = 0;
		int x = 0;//圈数
		for (j = 1; j <= N * N; j++)
		{
			p[m][n] = j;
			if (n < N - 1 - x && sign == 0)
			{
				n++;
			}
			else if (m < N - 1 - x && sign == 0)
			{
				m++;
			}
			else
			{
				sign = 1;
				if (n > x)
				{
					n--;
				}
				else if (m > x + 1)
				{
					m--;
				}
				else
				{
					x++;
					sign = 0;
					n++;
				}
			}
		}
		for (j = 0; j < N; j++)//输出
		{
			for (k = 0; k < N; k++)
			{
				if (k != N - 1)
				{
					cout << p[j][k] << " ";
				}
				else
				{
					cout << p[j][k] << endl;
				}
			}
		}
		cout << endl;
		for (j = 0; j < N; j++)//释放空间
		{
			delete[](*(p + j));
		}
		delete[] p;
	}
}