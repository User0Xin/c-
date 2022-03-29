#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct SNode
{
	int data;
	SNode* next;
};

void createList(SNode*& head, int* value, int n);
void printList(SNode* head);
int insertNode(SNode* head, int pos, int value);
int removeNode(SNode* head, int pos);
void deleteList(SNode* head);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		SNode* head = new SNode;
		head->data = 0;
		head->next = NULL;
		int n, j, m, o;
		cin >> n;
		int* value = new int[n];
		for (j = 0; j < n; j++)
		{
			cin >> value[j];
		}
		createList(head, value, n);//创建
		printList(head);//输出
		//插入
		cin >> m;
		for (j = 0; j < m; j++)
		{
			int val, index;
			cin >> index >> val;
			if (insertNode(head, index, val))
			{
				printList(head);//输出
			}
		}
		//删除
		cin >> o;
		for (j = 0; j < o; j++)
		{
			int  index;
			cin >> index;
			if (removeNode(head, index))
			{
				printList(head);//输出
			}
		}
		//撤销
		deleteList(head);
		delete[] value;
		value = NULL;
	}
	return 0;
}

void createList(SNode*& head, int* value, int n)
{
	SNode* q = head;
	for (int i = 0; i < n; i++)
	{
		SNode* p = new SNode;
		p->next = NULL;
		p->data = value[i];
		q->next = p;
		q = q->next;
		head->data++;
	}
}

void printList(SNode* head)
{
	while (head->next)
	{
		head = head->next;
		if (head->next)
		{
			cout << head->data << " ";
		}
		else
		{
			cout << head->data << endl;
		}
	}
}

int insertNode(SNode* head, int pos, int value)
{
	if (pos<1 || pos>head->data + 1)
	{
		cout << "error" << endl;
		return 0;
	}

	SNode* p = head;
	for (int i = 1; i < pos; i++)
	{
		p = p->next;
	}

	SNode* q = new SNode;
	q->data = value;
	q->next = p->next;
	p->next = q;

	head->data++;
	return 1;
}

int removeNode(SNode* head, int pos)
{
	if (pos<1 || pos>head->data)
	{
		cout << "error" << endl;
		return 0;
	}
	SNode* p = head;
	for (int i = 1; i < pos; i++)
	{
		p = p->next;
	}
	SNode* q = p->next;
	p->next = q->next;
	head->data--;
	delete q;
	q = NULL;
	return 1;
}

void deleteList(SNode* head)
{
	SNode* p = head->next;
	SNode* q;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	delete head;
	head = NULL;
}