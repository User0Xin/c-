#include<iostream>
using namespace std;

template<class T>
class CNode
{
public:
	T data;
	CNode<T>* next;
};
template<class T>
class CList
{
private:
	CNode<T>* head;
	int data;
public:
	CList();
	void append(T a); //�ӵ��������
	void insert(T a, int n); //�ڵ�n�������
	void remove(int n); //�Ƴ���n�����
	T get(int n); //���ص�n����������
	void set(T a, int n); //����n���ڵ�����ݸĳ�a
	void print();
	~CList();
};
template<class T>
CList<T>::CList()
{
	head = new CNode<T>;
	data = 0;
	head->next = NULL;
}
template<class T>
void CList<T>::append(T a) //�ӵ��������
{
	CNode <T>* N = head;
	while (N->next)
	{
		N = N->next;
	}
	CNode<T> *C=new CNode<T>;
	C->data = a;
	C->next = NULL;
	N->next = C;
	data++;
}
template<class T>
void CList<T>::insert(T a, int n) //�ڵ�n�������
{
	if (n < 0 || n > data+1)
	{
		return;
	}
	CNode <T> *N = head;
	for (int i = 0; i < n; i++)//�Ƶ�Ҫ�ӵ���һ��
	{
		N = N->next;
	}
	CNode<T> *C=new CNode<T>;
	C->next = N->next;
	N->next = C;
	C->data = a;
	data++;
}
template<class T>
void CList<T>::remove(int n) //�Ƴ���n�����
{
	if (n < 0 || n > data)
	{
		return;
	}
	CNode <T> *N = head;
	for (int i = 0; i < n - 1; i++)//�Ƶ�Ҫɾ����һ��
	{
		N = N->next;
	}
	CNode<T>*q = N->next;
	N->next = q->next;
	delete q;
	data--;
}
template<class T>
T CList<T>::get(int n) //���ص�n����������
{
	if (n < 0 || n > data )
	{
		cout << "error" << endl;
		return NULL;
	}
	CNode <T> *N = head;
	for (int i = 0; i < n ; i++)
	{
		N = N->next;
	}
	return N->data;
}
template<class T>
void CList<T>::set(T a, int n) //����n���ڵ�����ݸĳ�a
{
	if (n < 0 || n > data)
	{
		return;
	}
	CNode <T> *N = head;
	for (int i = 0; i < n; i++)
	{
		N = N->next;
	}
	N->data = a;
}
template<class T>
void CList<T>::print()
{
	CNode <T> *N = head->next;
	while (N!=NULL)
	{
		if (N->next != NULL)
		{
			cout << N->data << " ";
		}
		else
		{
			cout << N->data << endl;
		}
		N = N->next;
	}
}
template<class T>
CList<T>::~CList()
{
	CNode<T>*N = head->next;
	CNode<T>*M = head;
	while (N!=NULL)
	{
		M = N->next;
		delete N;
		N = M;
	}
	delete head;
	head = NULL;
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
			CList<int> C;
			for(int i=0;i<n;i++)
			{
				int x;
				cin >> x;
				C.append(x);
			}
			int index;
			int val;
			cin >> index >> val;
			C.insert(val,index);
			cin >> index;
			int y = C.get(index);
			if (y!=NULL)
			{
				cout << y << endl;
			}
			cin >> index;
			C.remove(index);
			cin >> index >> val;
			C.set(val, index);
			C.print();
		}
		else if (input == 'D')
		{
			int n;
			cin >> n;
			CList<double> C;
			for (int i = 0; i < n; i++)
			{
				double x;
				cin >> x;
				C.append(x);
			}
			int index;
			double val;
			cin >> index >> val;
			C.insert(val, index);
			cin >> index;
			double y = C.get(index);
			if (y != NULL)
			{
				cout << y << endl;
			}
			cin >> index;
			C.remove(index);
			cin >> index >> val;
			C.set(val, index);
			C.print();
		}
		else if (input == 'S')
		{
			int n;
			cin >> n;
			CList<string> C;
			for (int i = 0; i < n; i++)
			{
				string x;
				cin >> x;
				C.append(x);
			}
			int index;
			string val;
			cin >> index >> val;
			C.insert(val, index);
			cin >> index;
			string y = C.get(index);
			if (y.c_str()!=NULL)
			{
				cout << y << endl;
			}
			cin >> index;
			C.remove(index);
			cin >> index >> val;
			C.set(val, index);
			C.print();
		}
	}
	return 0;
}