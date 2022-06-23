#include<iostream>
using namespace std;

class CXGraph
{
public:
	friend ostream& operator<<(ostream& out, CXGraph c);
	CXGraph(int N);
	CXGraph& operator++();
	CXGraph operator++(int);
	CXGraph& operator--();
	CXGraph operator--(int);
private:
	int n;
};

CXGraph::CXGraph(int N) :n(N) {}
CXGraph& CXGraph::operator++()
{
	if (n != 21)
	{
		n += 2;
	}
	return *this;
}
CXGraph CXGraph::operator++(int)
{
	CXGraph temp = *this;
	if (n != 21)
	{
		n += 2;
	}
	return temp;
}
CXGraph& CXGraph::operator--()
{
	if (n != 1)
	{
		n -= 2;
	}
	return *this;
}
CXGraph CXGraph::operator--(int)
{
	CXGraph temp = *this;
	if (n != 1)
	{
		n -= 2;
	}
	return temp;
}

ostream& operator<<(ostream& out, CXGraph c)
{
	int i = 0, j = c.n, k;
	for (k = 0; k < c.n; k++)
	{
		for (i = 0; i<k; i++)
		{
			cout << " ";
		}
		for (i = 0; i < j;i++)
		{
			cout << "X";
		}
		cout << endl;
		j -= 2;
		if (j < 0)
		{
			break;
		}
	}
	j += 4;
	k--;
	for (; k >=0; k--)
	{
		for (i = 0; i < k; i++)
		{
			cout << " ";
		}
		for (i = 0; i < j; i++)
		{
			cout << "X";
		}
		cout << endl;
		j += 2;
	}
	return out;
}

int main()
{
	int t, n;
	string command;

	cin >> n;
	CXGraph xGraph(n);

	cin >> t;
	while (t--)
	{
		cin >> command;

		if (command == "show++")
			cout << xGraph++ << endl;
		else if (command == "++show")
			cout << ++xGraph << endl;
		else if (command == "show--")
			cout << xGraph-- << endl;
		else if (command == "--show")
			cout << --xGraph << endl;
		else if (command == "show")
			cout << xGraph << endl;
	}
	return 0;
}