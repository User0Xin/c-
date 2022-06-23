#include<iostream>
using namespace std;

class Student 
{

private:

	int id;//ѧ��

	int score; //�ɼ�

	static int  maxscore;//��߷���

	static int maxid;//��߷���ѧ��ѧ��

public:

	Student(int ti = 0, int ts = 0):id(ti), score(ts){}

	static void findMax(Student& st); //Ѱ����߳ɼ���ѧ��

	static int getMaxScore(); //������߳ɼ�

	static int getMaxID();//������߳ɼ���ѧ��

};
int Student::maxid = 0;
int Student::maxscore = 0;

void Student::findMax(Student& st)//��Ȼ�Ǿ�̬��Ա���������ڼ���ָ������ָ���Ϳ��Է��ʷǾ�̬����
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