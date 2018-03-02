/*
 * DrawableC.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: henryk
 */

#include "DrawableC.h"

DrawableC::DrawableC():DrawableC{"black"} {
	// TODO Auto-generated constructor stub
}

DrawableC::DrawableC(std::string col):color{col}
{
}

std::string DrawableC::getColor()
{
	return color;
}

void DrawableC::setColor(std::string col)
{
	color = col;
}

DrawableC::~DrawableC() {
	// TODO Auto-generated destructor stub
}

