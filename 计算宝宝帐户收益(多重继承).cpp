#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class CPeople
{
public:
	CPeople() {}
	CPeople(char i[],char n[]);
protected:
	char id[20];
	char name[10];
};

CPeople::CPeople(char i[], char n[])
{
	int j = 0;
	while (i[j] != '\0')
	{
		id[j] = i[j];
		j++;
	}
	id[j] = '\0';
	j = 0;
	while (n[j] != '\0')
	{
		name[j] = n[j];
		j++;
	}
	name[j] = '\0';
}

class CInternetUser :virtual public CPeople
{
public:
	void registerUser(char i[], char n[], char p[]);
	virtual bool login(char i[], char p[]);
protected:
	char password[20];

};

void CInternetUser::registerUser(char i[], char n[], char p[])
{
	int j = 0;
	while (i[j] != '\0')
	{
		id[j] = i[j];
		j++;
	}
	id[j] = '\0';
	j = 0;
	while (n[j] != '\0')
	{
		name[j] = n[j];
		j++;
	}
	name[j] = '\0';
	j = 0;
	while (p[j] != '\0')
	{
		password[j] = p[j];
		j++;
	}
	password[j] = '\0';
}

bool CInternetUser::login(char i[], char p[])
{
	if (strcmp(i, id)==0 && strcmp(p, password)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class CBankCustomer :virtual public CPeople
{
public:
	CBankCustomer():balance(0) {}
	CBankCustomer(char i[], char n[]) : CPeople(i, n), balance(0) {}
	void openAccount(char n[], char i[]);
	virtual int deposit(double n);
	virtual int withdraw(double n);
protected:
	double balance;
};
void CBankCustomer::openAccount(char n[], char i[])
{
	int j = 0;
	while (i[j] != '\0')
	{
		id[j] = i[j];
		j++;
	}
	id[j] = '\0';
	j = 0;
	while (n[j] != '\0')
	{
		name[j] = n[j];
		j++;
	}
	name[j] = '\0';
}
int CBankCustomer::deposit(double n)
{
	balance += n;
	return 1;
}
int CBankCustomer::withdraw(double n)
{
	if (balance >= n)
	{
		balance -= n;
		return 1;
	}
	else
	{
		return 0;
	}
}

class CInternetBankCustomer :public virtual CBankCustomer,public virtual CInternetUser
{
public:
	CInternetBankCustomer():CBankCustomer(), interset(0), Balance(0) {}
	void calculateProfit();
	bool login(char i[],char n[]);
	void setInterest(double i);
	int deposit(double n);
	int withdraw(double n);
	void print();
protected:
	double Balance;
	double Lbalance;
	double income;
	double interset;
	double Yinw;
};
 

void CInternetBankCustomer::calculateProfit()
{
	Balance = Balance + Lbalance / 10000 * Yinw;
	Lbalance = Balance;
}

int CInternetBankCustomer::deposit(double n)
{
	if (n >= balance)
	{
		return 0;
	}
	else
	{
		balance -= n;
		Balance += n;
		return 1;
	}
}
int CInternetBankCustomer::withdraw(double n)
{
	if (n >= Balance)
	{
		return 0;
	}
	else
	{
		Balance -= n;
		balance += n;
		return 1;
	}
}

bool CInternetBankCustomer::login(char i[], char p[])
{
	if (strcmp(i, id)==0&&strcmp(p,password)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CInternetBankCustomer::setInterest(double i)
{
	Yinw = interset;
	interset = i;
}

void CInternetBankCustomer::print()
{
	cout << "Name: " << name << " ID: " << id << endl << "Bank balance: " << balance << endl << "Internet bank balance: " << Balance << endl;
}

int main()
{
	int t, no_of_days, i;
	char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
	double money, interest;
	char op_code;

	//������԰�����t
	cin >> t;
	while (t--)
	{
		//���뻥�����û�ע��ʱ���û���,id,��½����
		cin >> i_xm >> i_id >> i_mm;

		//�������п����û���,id
			cin >> b_xm >> b_id;

		//���뻥�����û���½ʱ��id,��½����
		cin >> ib_id >> ib_mm;

		CInternetBankCustomer ib_user;

		ib_user.registerUser(i_xm, i_id, i_mm);
		ib_user.openAccount(b_xm, b_id);

		if (ib_user.login(ib_id, ib_mm) == 0)  //�������û���½,��id�����벻��;�Լ����п���������id�뻥��������������id��ͬ
		{
			cout << "Password or ID incorrect" << endl;
				continue;
		}

		//��������
		cin >> no_of_days;
		for (i = 0; i < no_of_days; i++)
		{
			//�����������, ���, ������Ԫ����
			cin >> op_code >> money >> interest;
			switch (op_code)
			{
			case 'S':  //�����������������ʻ�����
			case 's':
				if (ib_user.deposit(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
						continue;
				}
				break;
			case 'T':  //�ӻ���������ת�������ʻ�
			case 't':
				if (ib_user.withdraw(money) == 0)
				{
					cout << "Internet bank balance not enough" << endl;
					continue;
				}
				break;
			case 'D':  //ֱ���������ʻ����
			case 'd':
				ib_user.CBankCustomer::deposit(money);
				break;
			case 'W':  //ֱ�Ӵ������ʻ�ȡ��
			case 'w':
				if (ib_user.CBankCustomer::withdraw(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				break;
			default:
				cout << "Illegal input" << endl;
				continue;
			}
			ib_user.setInterest(interest);
			ib_user.calculateProfit();
			//����û���,id
			//����������
			//��������������˻����
			ib_user.print();
			if (i != no_of_days)
			{
				cout << endl;
			}
		}
	}
	return 0;
}