/*
 * DrawableC.h
 *
 *  Created on: Nov 28, 2017
 *      Author: henryk
 */

#ifndef DRAWABLEC_H_
#define DRAWABLEC_H_

#include "SpaceGraphic.h"
#include <string>

class DrawableC {
public:
	DrawableC();
	DrawableC(std::string col);
	std::string getColor();
	void setColor(std::string col);
	virtual void draw(SpaceGraphic&) = 0 ;
	virtual ~DrawableC();

private:
	std::string color;
};

#endif /* DRAWABLEC_H_ */
