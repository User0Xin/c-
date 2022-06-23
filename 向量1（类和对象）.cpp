#include<iostream>
using namespace std;

class CVector
{
public:
	CVector();
	CVector(int n1, int* a);
	void print();
	~CVector();
protected:
	int* data;
	int n;

};

CVector::CVector()
{
	n = 0;
	data = NULL;
}
CVector::CVector(int n1, int* a)
{
	n = n1;
	data = new int[n];
	if (a != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			data[i] = a[i];
		}
	}
	
}
void CVector::print()
{
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			cout << data[i] << " ";
		}
		else
		{
			cout << data[i] << endl;
		}
	}
}
CVector::~CVector()
{
	delete[]data;
	data = NULL;
}

class CStack:public CVector
{
public:
	CStack(int n1);
	void push(int val);
	bool isemp();
	bool isfull();
	void pop();
	void print();
private:
	int top;
};

CStack::CStack(int n1) :CVector(n1, NULL) 
{ 
	top = 0; 
}
void CStack::push(int val)
{
	if (!isfull())
	{
		data[top] = val;
		top++;
	}
}

void CStack::pop()
{
	if (!isemp())
	{
		top--;
	}
}
bool CStack::isemp()
{
	if (top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CStack::isfull()
{
	if (top == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CStack::print()
{
	if (!isemp())
	{
		for (int i = 0; i < top; i++)
		{
			if (i != top - 1)
			{
				cout << data[i] << " ";
			}
			else
			{
				cout << data[i];
			}
		}
	}
	else
	{
		cout << "empty" << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	CStack S(n);
	string input;
	while (true)
	{
		cin >> input;
		if (input == "in")
		{
			int v;
			cin >> v;
			S.push(v);
		}
		else if (input == "out")
		{
			S.pop();
		}
		else
		{
			S.print();
			break;
		}
	}
	return 0;
}