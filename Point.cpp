/*
 * Point.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: henryk
 */

#include "Point.h"

Point::Point():x{0},y{0}{};

Point::Point(int _x, int _y):x{_x},y{_y}{};

Point::~Point() {
	// TODO Auto-generated destructor stub
}

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}

Point Point::operator +(const Point &p)
{
	return Point(this->x + p.x, this->y + p.y);
}

Point Point::operator -(const Point &p)
{
	return Point(this->x - p.x, this->y - p.y);
}

bool Point::operator ==(const Point &p)
{
	if((x == p.x)&&(y == p.y)) return true;
	else return false;
}
