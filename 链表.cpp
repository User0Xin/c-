#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* create();
void display(Node* head);
int Insert(Node* head, int index, int val);
Node* del(Node* head, int index);
void distory(Node* head);

int main()
{
	Node* head = create();
	int i ;
	int val;
	while (cin >>i>> val)
	{
		Insert(head, i, val);

		display(head);
	}
	distory(head);
	return 0;
}

Node* create()
{
	Node* head = new Node;
	head->data = 0;
	head->next = NULL;
	return head;
}

void display(Node* head)
{
	if (head->next == NULL)
	{
		cout << "no data" << endl;
		return;
	}
	
	cout << head->data << ":" ;
	while (head->next)
	{
		head = head->next;
		cout << head->data << " ";
	}
	cout << endl;
}

int Insert(Node* head, int index, int val)
{
	if (index<1 || index>head->data + 1)
	{
		return 0;
	}
	Node* p = new Node;
	p->data = val;
	Node* q = new Node;
	q = head;
	for (int i = 1; i < index; i++)//将q移动到index的前一个结点位置
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	head->data++;
	return 1;
}

Node* del(Node* head, int index)
{
	if (index<1 || index>head->data)//检测index
	{
		return NULL;
	}
	Node* p = head;
	for (int i = 1; i < index; i++)//将p移动到index的前一个结点位置
	{
		p = p->next;
	}
	Node* q = p->next;
	p->next = q->next;

	return q;//返回被删除的结点的指针
}
void distory(Node* head)
{
	Node* p;
	while (head->next != NULL)
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}

	delete head;
	cout << "distory over" << endl;
}