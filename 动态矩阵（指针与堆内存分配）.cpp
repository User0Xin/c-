#include<iostream>
using namespace std;
#include<string.h>

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n, j, k;
		cin >> m >> n;
		//��̬��������
		int** p = new int* [m];
		for (j = 0; j < m; j++)
		{
			*(p + j) = new int[n];
		}
		//����
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < n; k++)
			{
				cin >> p[j][k];
			}
		}
		int max = p[0][0];
		int min = p[0][0];
		//�����������С
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (p[j][k] > max)
				{
					max = p[j][k];
				}
				if (p[j][k] < min)
				{
					min = p[j][k];
				}
			}
		}
		//���
		cout << min << " " << max << endl;

		for (j = 0; j < m; j++)//�ͷſռ�
		{
			delete[](*(p + j));
		}
		delete[] p;
	}

	return 0;
}