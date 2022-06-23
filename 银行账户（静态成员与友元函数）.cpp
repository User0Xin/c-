#include<iostream>
using namespace std;

class Account
{
public:
	friend void Update(Account* a);
	Account() {};
	Account(string accno, string name, float balance);
	~Account();
	void setI(float I);
	void Deposit(float amount);//存
	void Withdraw(float amount);//取
	float GetBalance();//获取存款
	void Show();//展示信息
	static int GetCount();//获取账号数目
	static float GetInterestRate();//获取利息
private:
	static int count;
	static float InterestRate;
	string _accno, _accname;
	float _balance;
};
int Account::count = 0;
float Account::InterestRate = 0;
Account::Account(string accno, string name, float balance)
{
	_accno = accno;
	_accname = name;
	_balance = balance;
	count++;
}
Account::~Account()
{}
void Account::setI(float I)
{
	InterestRate = I;
}
void Account::Deposit(float amount)
{
	_balance += amount;
}
void Account::Withdraw(float amount)
{
	_balance -= amount;
}
float Account::GetBalance()
{
	return _balance;
}
void Update(Account* a)
{
	a->_balance = a->_balance * (1+a->InterestRate);
}
void Account::Show()
{
	cout << _accno << " " << _accname << " ";
}
int Account::GetCount()
{
	return count;
}
float Account::GetInterestRate()
{
	return InterestRate;
}


int main()
{
	float I;
	cin >> I;
	int n;
	cin >> n;
	Account** A = new Account*[n];
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		int  in, out;
		float b;
		string no,name;
		cin >> no >> name >> b >> in >> out;
		A[i] = new Account(no, name, b);
		A[i]->setI(I);
		A[i]->Show();
		A[i]->Deposit(in);
		cout << A[i]->GetBalance() << " ";
		Update(A[i]);
		cout << A[i]->GetBalance() << " ";
		A[i]->Withdraw(out);
		cout << A[i]->GetBalance() << endl;
		sum += A[i]->GetBalance();
	}
	cout << sum;
	return 0;
}