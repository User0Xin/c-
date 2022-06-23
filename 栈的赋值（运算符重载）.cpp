#include<iostream>
using namespace std;

class stack
{
public:
	int* sp, *top, max;
	void inflate(int lenth);

public:
	stack(int size = 10);
	stack(stack& s);
	int pop();
	void push(int value);
	stack& operator=(stack& rightValue);
	void show();
};

stack::stack(int size) :max(size) 
{
	sp = new int[size];
	top = sp;
}
stack::stack(stack& s)
{
	max = s.max;
	sp = new int[max];
	top = sp + (s.top - s.sp);
	for (int i = 0; i < top - sp; i++)
	{
		sp[i] = s.sp[i];
	}
}
int stack::pop()
{
	int temp = *top;
	if (top != sp)
	{
		top--;
	}
	return temp;
}
void stack::push(int value)
{
	if (top == sp + max)
	{
		inflate(2);
	}
	*top = value;
	top++;

}
stack& stack::operator=(stack& rightValue)
{
	stack temp(rightValue);
	int n0 = rightValue.top - rightValue.sp;
	for (int i = 0; i < n0; i++)
	{
		rightValue.pop();
	}
	int n = top - sp;
	for (int i = 0; i < n; i++)
	{
		rightValue.push(sp[i]);
	}
	for (int i = 0; i < n; i++)
	{
		this->pop();
	}
	for (int i = 0; i < n; i++)
	{
		this->push(temp.sp[i]);
	}
	return *this;
}
void stack::show()
{
	for (int i = 0; i < top - sp; i++)
	{
		cout << sp[i];
	}
	cout << endl;
}
void stack::inflate(int lenth)
{
	int *temp = new int[max+lenth];
	for (int i = 0; i < max; i++)
	{
		temp[i] = sp[i];
	}
	int n = top - sp;
	max += lenth;
	sp = temp;
	top = sp + n;
}

int main()
{
	int n1, n2;
	stack S1, S2;
	cin >> n1 >> n2;
	for (int i = 0; i < n1; i++)
	{
		int val;
		cin >> val;
		S1.push(val);
	}
	for (int i = 0; i < n2; i++)
	{
		int val;
		cin >> val;
		S2.push(val);
	}
	S1 = S2;
	S1.show();
	S2.show();
	return 0;
}