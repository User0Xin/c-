#include<iostream>
using namespace std;

class CTime
{
public:
	CTime(int H, int M, int S);
	CTime& operator++();
	CTime& operator++(int);
	void print();
private:
	int h;
	int m;
	int s;
	
};

CTime::CTime(int H, int M, int S) :h(H),m(M),s(S){}
CTime& CTime::operator++()
{
	s++;
	if (s == 60)
	{
		s = 0;
		m++;
	}
	if (m == 60)
	{
		m = 0;
		h++;
	}
	if (h == 24)
	{
		h = 0;
	}
	return *this;
}
CTime& CTime::operator++(int)
{
	CTime temp = *this;
	s++;
	if (s == 60)
	{
		s = 0;
		m++;
	}
	if (m == 60)
	{
		m = 0;
		h++;
	}
	if (h == 24)
	{
		h = 0;
	}
	return temp;
}

void CTime::print()
{
	cout << h << ":" << m << ":" << s << endl;
}

int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	CTime obj(h, m, s); //����һ��ʱ������󲢳�ʼ��ʱ����
	obj.print(); //�����ʼʱ��
	obj++;
	obj.print();  //�������1���ʱ��
	++obj;
	obj.print(); //����ٵ���1���ʱ��	
	return 0;
}