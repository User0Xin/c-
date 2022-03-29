#pragma once
#include<iostream>
#include"point.h"
using namespace std;

class circle
{
public:
	void setR(int x);
	void setcenter(point center);
private:
	int R;
	point center;
};
