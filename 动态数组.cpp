#include<iostream>
using namespace std;
#include<iomanip>
int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char select;//�û�ѡ��
		cin >> select;
		int n = 0;//���鳤��
		if (select == 'I')
		{
			cin >> n;
			int* arr1 = new int[n];//��������
			for (int j = 0; j < n; j++)
			{
				cin >> *(arr1 + j);
			}
			int sum = 0;
			for (int j = 0; j < n; j++)// ���
			{
				sum += *(arr1 + j);
			}
			double result = sum / n;
			cout << result << endl;
			delete[] arr1;
		}
		else if (select == 'C')
		{
			cin >> n;
			char* arr2 = new char[n];//��������
			for (int j = 0; j < n; j++)
			{
				cin >> *(arr2 + j);
			}
			char max = *arr2;
			for (int j = 0; j < n; j++)//�����ֵ
			{
				if (*(arr2 + j) > max)
				{
					max = *(arr2 + j);
				}
			}
			cout << max << endl;
			delete[] arr2;
		}
		else if (select == 'F')
		{
			cin >> n;
			double* arr3 = new double[n];
			for (int j = 0; j < n; j++)
			{
				cin >> *(arr3 + j);
			}
			double min = *arr3;//��������
			for (int j = 0; j < n; j++)//����Сֵ
			{
				if (*(arr3 + j) < min)
				{
					min = *(arr3 + j);
				}
			}
			cout << min << endl;
			delete[] arr3;
		}
	}
	return 0;
}