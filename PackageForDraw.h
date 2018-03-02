/*
 * PackageForDraw.h
 *
 *  Created on: Dec 12, 2017
 *      Author: henryk
 */

#ifndef PACKAGEFORDRAW_H_
#define PACKAGEFORDRAW_H_

#include <string>
#include "Point.h"

enum Draw_Message{
	planet,
	spaceship,
	star,
	collision,
	clear
};

struct Package_For_Draw {
	Package_For_Draw(Draw_Message mes, Point pos, Point old_pos, std::string col, int size);
	Package_For_Draw(Draw_Message mes, Point pos, std::string col = "black", int size = 0);
	virtual ~Package_For_Draw();

	Draw_Message draw_message;
	Point position;
	Point old_position;
	std::string color;
	int size;
};

#endif /* PACKAGEFORDRAW_H_ */
