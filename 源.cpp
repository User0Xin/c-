struct S
{
	int a;//����
	int b;//��ĸ
};

S addFS(S num1, S num2);
S subFS(S num1, S num2);
S mulFS(S num1, S num2);
S divFS(S num1, S num2);
int getGCD(int a, int b);
void printFS(S num);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		S s1, s2;
		char a;
		cin >> s1.a >> a >> s1.b;//����
		cin >> s2.a >> a >> s2.b;
		printFS(addFS(s1, s2));
		printFS(subFS(s1, s2));
		printFS(mulFS(s1, s2));
		printFS(divFS(s1, s2));
		cout << endl;
	}
	return 0;
}

S addFS(S num1, S num2)//�ӷ�
{
	S result;
	result.a = num1.a * num2.b + num1.b * num2.a;
	result.b = num1.b * num2.b;
	return result;
}

S subFS(S num1, S num2)//����
{
	S result;
	result.a = num1.a * num2.b - num1.b * num2.a;
	result.b = num1.b * num2.b;
	return result;
}

S mulFS(S num1, S num2)//�˷�
{
	S result;
	result.a = num1.a * num2.a;
	result.b = num1.b * num2.b;
	return result;
}

S divFS(S num1, S num2)//����
{
	S result;
	result.a = num1.a * num2.b;
	result.b = num1.b * num2.a;
	return result;
}

int getGCD(int a, int b)//���Լ��
{
	if (a < b)//���a<b��λ
	{
		int ret = a;
		a = b;
		b = ret;
	}
	int c = 1;
	while (c)//շת�����
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void printFS(S num)//���
{
	cout << num.a / abs(getGCD(num.a, num.b)) << "/" << num.b / abs(getGCD(num.a, num.b)) << endl;
}