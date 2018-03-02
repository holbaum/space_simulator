/*
 * Point.h
 *
 *  Created on: Nov 28, 2017
 *      Author: henryk
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	Point();
	Point(int _x, int _y);


	~Point();
	Point operator +(const Point &p);
	Point operator -(const Point &p);
	bool operator ==(const Point &p);

	int getX();
	int getY();
private:
	int x;
	int y;
};

#endif /* POINT_H_ */
