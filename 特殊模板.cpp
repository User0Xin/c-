#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;

};
template<class T>
bool myCompare(T a,T b)
{
	return true;
}
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Person p1("a", 11);
	Person p2("a", 11);
	if (myCompare(p1, p2))
	{
		cout << "1" << endl;
	}
	system("pause");
	return 0;
}