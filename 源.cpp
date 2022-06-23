struct S
{
	int a;//分子
	int b;//分母
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
		cin >> s1.a >> a >> s1.b;//输入
		cin >> s2.a >> a >> s2.b;
		printFS(addFS(s1, s2));
		printFS(subFS(s1, s2));
		printFS(mulFS(s1, s2));
		printFS(divFS(s1, s2));
		cout << endl;
	}
	return 0;
}

S addFS(S num1, S num2)//加法
{
	S result;
	result.a = num1.a * num2.b + num1.b * num2.a;
	result.b = num1.b * num2.b;
	return result;
}

S subFS(S num1, S num2)//减法
{
	S result;
	result.a = num1.a * num2.b - num1.b * num2.a;
	result.b = num1.b * num2.b;
	return result;
}

S mulFS(S num1, S num2)//乘法
{
	S result;
	result.a = num1.a * num2.a;
	result.b = num1.b * num2.b;
	return result;
}

S divFS(S num1, S num2)//除法
{
	S result;
	result.a = num1.a * num2.b;
	result.b = num1.b * num2.a;
	return result;
}

int getGCD(int a, int b)//最大公约数
{
	if (a < b)//如果a<b则换位
	{
		int ret = a;
		a = b;
		b = ret;
	}
	int c = 1;
	while (c)//辗转相除法
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void printFS(S num)//输出
{
	cout << num.a / abs(getGCD(num.a, num.b)) << "/" << num.b / abs(getGCD(num.a, num.b)) << endl;
}