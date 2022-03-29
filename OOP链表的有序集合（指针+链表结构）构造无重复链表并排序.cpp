#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

struct SNode
{
	int data;
	SNode* next;
};

void printList(SNode* head);
int insertNode(SNode* head, int pos, int value);
int removeNode(SNode* head, int pos);
void deleteList(SNode* head);
void Check(SNode* head);
void Sort(SNode* head);

int main()
{
	int n;
	while (cin >> n)
	{
		SNode* head = new SNode;
		head->data = 0;
		head->next = NULL;
		for (int i = 1; i < n + 1; i++)
		{
			int val;
			cin >> val;
			insertNode(head, i, val);//创建链表
		}
		Check(head);//检查重复
		Sort(head);//排序
		printList(head);//打印
		deleteList(head);//撤销链表
	}
	return 0;
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

void Check(SNode* head)//检查重复，有重复的就删除掉
{
	int n = 2;
	SNode* p = head->next;
	while (p->next)
	{
		int flag = 0;
		int i = n;
		SNode* q = p->next;
		while (i <= head->data)
		{
			if (q->data == p->data)
			{
				removeNode(head, i);
				flag = 1;
				break;
			}
			q = q->next;
			i++;
		}
		if (flag == 0)
		{
			p = p->next;
			n++;
		}
	}
}



void Sort(SNode* head)//排序
{
	for (int i = 0; i < head->data - 1; i++)
	{
		SNode* p = head;
		SNode* q = head->next;
		for (int j = 0; j < head->data - i - 1; j++)
		{
			p = p->next;
			q = q->next;
			if (p->data > q->data)
			{
				int ret;
				ret = p->data;
				p->data = q->data;
				q->data = ret;
			}
		}
	}
}