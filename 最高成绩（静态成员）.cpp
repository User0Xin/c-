#include<iostream>
using namespace std;

class Student 
{

private:

	int id;//学号

	int score; //成绩

	static int  maxscore;//最高分数

	static int maxid;//最高分数学生学号

public:

	Student(int ti = 0, int ts = 0):id(ti), score(ts){}

	static void findMax(Student& st); //寻找最高成绩和学号

	static int getMaxScore(); //返回最高成绩

	static int getMaxID();//返回最高成绩的学号

};
int Student::maxid = 0;
int Student::maxscore = 0;

void Student::findMax(Student& st)//虽然是静态成员函数但是在加了指向对象的指针后就可以访问非静态变量
{
	if (st.score>maxscore)
	{
		maxscore = st.score;
		maxid = st.id;
	}
}
int Student::getMaxScore()
{
	return maxscore;
}
int Student::getMaxID()
{
	return maxid;
}
int main()
{
	int n;
	cin >> n;
	Student max(0, 0);
	for (int i = 0; i < n; i++)
	{
		int id, score;
		cin >> id >> score;
		Student S(id, score);
		max.findMax(S);
	}
	cout << max.getMaxID() << "--" << max.getMaxScore() << endl;
	return 0;
}