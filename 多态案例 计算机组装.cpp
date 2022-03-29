#include<iostream>
using namespace std;

//������
class Cpu
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

//���峧��
class IntelCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "Intel Cpu�ڹ���" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Intel �Կ��ڹ���" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel �ڴ��ڹ���" << endl;
	}
};

class AMDCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "AMD Cpu�ڹ���" << endl;
	}
};

class AMDVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "AMD �Կ��ڹ���" << endl;
	}
};

class AMDMemory :public Memory
{
public:
	void storage()
	{
		cout << "AMD �ڴ��ڹ���" << endl;
	}
};

//������
class Computer
{
public:
	Computer(Cpu* cpu,VideoCard* VideoCard,Memory* Memory)//�ø���ָ��ָ���������
	{
		m_cpu = cpu;
		m_VideoCard = VideoCard;
		m_Memory = Memory;
	}

	void Work()//��������
	{
		m_cpu->calculate();
		m_VideoCard->display();
		m_Memory->storage();
	}
	~Computer()//�����ͷŶ����ڴ�
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_VideoCard != NULL)
		{
			delete m_VideoCard;
			m_VideoCard = NULL;
		}
		if (m_Memory != NULL)
		{
			delete m_Memory;
			m_Memory = NULL;
		}
	}
private:
	Cpu* m_cpu;
	VideoCard* m_VideoCard;
	Memory* m_Memory;
};
int main()
{
	Computer C1(new IntelCpu,new IntelVideoCard,new IntelMemory);
	Computer C2(new AMDCpu, new AMDVideoCard, new AMDMemory);
	Computer C3(new IntelCpu, new IntelVideoCard, new AMDMemory);
	C1.Work();
	C2.Work();
	C3.Work();
	system("pause");
	return 0;
}