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

	//输入测试案例数t
	cin >> t;
	while (t--)
	{
		//输入互联网用户注册时的用户名,id,登陆密码
		cin >> i_xm >> i_id >> i_mm;

		//输入银行开户用户名,id
			cin >> b_xm >> b_id;

		//输入互联网用户登陆时的id,登陆密码
		cin >> ib_id >> ib_mm;

		CInternetBankCustomer ib_user;

		ib_user.registerUser(i_xm, i_id, i_mm);
		ib_user.openAccount(b_xm, b_id);

		if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
		{
			cout << "Password or ID incorrect" << endl;
				continue;
		}

		//输入天数
		cin >> no_of_days;
		for (i = 0; i < no_of_days; i++)
		{
			//输入操作代码, 金额, 当日万元收益
			cin >> op_code >> money >> interest;
			switch (op_code)
			{
			case 'S':  //从银行向互联网金融帐户存入
			case 's':
				if (ib_user.deposit(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
						continue;
				}
				break;
			case 'T':  //从互联网金融转入银行帐户
			case 't':
				if (ib_user.withdraw(money) == 0)
				{
					cout << "Internet bank balance not enough" << endl;
					continue;
				}
				break;
			case 'D':  //直接向银行帐户存款
			case 'd':
				ib_user.CBankCustomer::deposit(money);
				break;
			case 'W':  //直接从银行帐户取款
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
			//输出用户名,id
			//输出银行余额
			//输出互联网金融账户余额
			ib_user.print();
			if (i != no_of_days)
			{
				cout << endl;
			}
		}
	}
	return 0;
}