#include<iostream>
#include<string>
using namespace std;

template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType T1, AgeType T2);
	NameType name;
	AgeType age;
};

template<class T1, class T2, class T3>
class Son:public Person<T1,T2>
{
public:
	Son(T1 t1,T2 t2,T3 t3):Person<T1,T2>(t1,t2)
	{
		sex = t3;
	}
	T3 sex;
};

template<class NameType,class AgeType>
Person<NameType, AgeType>::Person(NameType T1, AgeType T2)
{
	name = T1;
	age = T2;
}

int main()
{
	Son<string,int,string> P1("a",1, "b");

	cout << P1.age << endl << P1.name << endl << P1.sex << endl;
	system("pause");
	return 0;
}