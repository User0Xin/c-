#include<iostream>
using namespace std;

struct SNode
{
	int data;
	SNode* next;
};

int insertNode(SNode* head, int pos, int value);
void PrintBack(SNode* head);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		SNode* head = new SNode;
		head->data = 0;
		head->next = NULL;
		int n, j;
		cin >> n;
		for (j = 1; j < n + 1; j++)
		{
			int val;
			cin >> val;
			insertNode(head, j, val);//��������
		}
		PrintBack(head);//�������
	}
	return 0;
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

void PrintBack(SNode* head)
{
	SNode* q = NULL;
	while (true)
	{
		SNode* p = head;
		int flag = 0;
		while (p->next != q)
		{
			p = p->next;
			if (p->next == q)
			{
				cout << p->data << " ";
				flag = 1;
			}
		}
		if (flag == 1)//���������ѭ���Ž�p����q
		{
			q = p;
		}
		if (p->next == q)//q�Ѿ��Ƶ���һ�����
		{
			cout << endl;
			break;
		}
	}
}
