#include"circle.h"

void circle::setR(int x)
{
	this->R = x;
}

void circle::setcenter(point center)
{
	center.setX(center.getX());
	center.setY(center.getY());
}