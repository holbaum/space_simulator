/*
 * CelestialBody.h
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#ifndef CELESTIALBODY_H_
#define CELESTIALBODY_H_

#include "Body.h"
#include "SpaceGraphic.h"
#include <string>

class CelestialBody: public Body {
public:
	CelestialBody();
	CelestialBody(Point initPosition, int weight, int radius,std::string col);
	void draw(SpaceGraphic &gr);

	void changeMovability(bool iM);
	bool isMovable();

	virtual ~CelestialBody();
private:

	bool isMoving = true;
	int radius = 0;

};

#endif /* CELESTIALBODY_H_ */
