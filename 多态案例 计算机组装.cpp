#include<iostream>
using namespace std;

//抽象类
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

//具体厂商
class IntelCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "Intel Cpu在工作" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Intel 显卡在工作" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel 内存在工作" << endl;
	}
};

class AMDCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "AMD Cpu在工作" << endl;
	}
};

class AMDVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "AMD 显卡在工作" << endl;
	}
};

class AMDMemory :public Memory
{
public:
	void storage()
	{
		cout << "AMD 内存在工作" << endl;
	}
};

//电脑类
class Computer
{
public:
	Computer(Cpu* cpu,VideoCard* VideoCard,Memory* Memory)//用父类指针指向子类对象
	{
		m_cpu = cpu;
		m_VideoCard = VideoCard;
		m_Memory = Memory;
	}

	void Work()//工作函数
	{
		m_cpu->calculate();
		m_VideoCard->display();
		m_Memory->storage();
	}
	~Computer()//析构释放堆区内存
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