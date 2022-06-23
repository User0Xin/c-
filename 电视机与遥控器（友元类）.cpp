#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Remote;
class Tv
{
public:
	friend class Remote;
	Tv(string s, int v,int c,string m,string i);
	void onoff();
	bool ison()const;
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode();
	void set_input();
	void settings()const;
private:
	string state;
	int volume;
	int maxchannel;
	int channel;
	string mode;
	string input;
};

Tv::Tv(string s, int v, int c, string m, string i)
{
	state = s;
	maxchannel = 100;
	volume = v;
	channel = c;
	mode = m;
	input = i;
}
void Tv::onoff()
{
	if (ison())
	{
		state = "off";
	}
	else
	{
		state = "on";
	}
}
bool Tv::ison()const
{
	if (state == "on")
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Tv::volup()
{
	if (volume < 20)
	{
		volume++;
		return true;
	}
	else
	{
		return false;
	}
}
bool Tv::voldown()
{
	if (volume >0)
	{
		volume--;
		return true;
	}
	else
	{
		return false;
	}
}
void Tv::chanup()
{
	if (channel < maxchannel)
	{
		channel++;
	}
}
void Tv::chandown()
{
	if (channel >0 )
	{
		channel--;
	}
}
void Tv::set_mode()
{
	if (mode == "Cable")
	{
		mode = "Antenna";
	}
	else
	{
		mode = "Cable";
	}
}
void Tv::set_input()
{
	if (input == "VCR")
	{
		input = "TV";
	}
	else
	{
		input = "VCR";
	}
}
void Tv::settings()const
{
	cout << state << " " << volume << " " << channel << " " << mode << " " << input << endl;
}

class Remote
{
private:
	string mode;
public:
	Remote(string m) :mode(m) {}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown();}
	void onoff(Tv& t) { t.onoff(); };
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode();}
	void set_input(Tv& t) { t.set_input();}
};

int main()
{
	string s, m, i;
	int v, c;
	cin >> s >> v >> c >> m >> i;
	Tv T(s, v, c, m, i);
	Remote R("Tv");
	string input;
	while (cin >> input)
	{
		
		if (input == "volup")
		{
			if (T.ison())
			{
				R.volup(T);
			}
		}
		else if (input == "voldown")
		{
			if (T.ison())
			{
				R.voldown(T);
			}
		}
		else if (input == "onoff")
		{
			R.onoff(T);
		}
		else if (input == "chanup")
		{
			if (T.ison())
			{
				R.chanup(T);
			}
		}
		else if (input == "chandown")
		{
			if (T.ison())
			{
				R.chandown(T);
			}
		}
		else if (input == "setchan")
		{
			if (T.ison())
			{
				int C;
				cin >> C;
				R.set_chan(T, C);
			}
		}
		else if (input == "set_mode")
		{
			if (T.ison())
			{
				R.set_mode(T);
			}
		}
		else if (input == "set_input")
		{
			if (T.ison())
			{
				R.set_input(T);
			}
		}
	}
	T.settings();
	return 0;
}