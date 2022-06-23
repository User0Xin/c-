#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
using namespace std;


class point 
{
public:
	friend bool operator>(point& p1, point& p2);
	point() {}
	void set(double x1, double y1);
	double distance();
	void print();
private:
	double x;
	double y;
};

void point::set(double x1, double y1)
{
	x = x1;
	y = y1;
}
double point::distance()
{
	return sqrt(x * x + y * y);
}

void point::print()
{
	cout << "(" <<fixed<<setprecision(1)<< x << ", " << fixed << setprecision(1) << y << ") ";
}

bool operator>(point& p1, point& p2)
{
	if (p1.distance() > p2.distance())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void mysort(T* arr,int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char input;
		cin >> input;
		if (input == 'I')
		{
			int n;
			cin >> n;
			int* arr = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			mysort(arr,n);
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		else if (input == 'S')
		{
			int n;
			cin >> n;
			string* arr = new string[n];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			mysort(arr,n);
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		else if (input == 'D')
		{
			int n;
			cin >> n;
			double* arr = new double [n] ;
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			mysort(arr,n);
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		else if (input == 'P')
		{
			int n;
			cin >> n;
			point* arr = new point[n];
			for (int i = 0; i < n; i++)
			{
				double x, y;
				cin >> x >> y;
				arr[i].set(x, y);
			}
			mysort(arr,n);
			for (int i = 0; i < n; i++)
			{
				arr[i].print();
			}
			cout << endl;
		}
	}
	return 0;
}