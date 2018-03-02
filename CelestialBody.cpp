/*
 * CelestialBody.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#include "CelestialBody.h"
#include "PackageForDraw.h"


CelestialBody::CelestialBody() {
	// TODO Auto-generated constructor stub

}

CelestialBody::CelestialBody(Point initPosition, int weight, int rad, std::string col):Body{initPosition,weight, col, rad}, radius{rad}
{
}


void CelestialBody::draw(SpaceGraphic &gr)
{
	gr.draw(Package_For_Draw(Draw_Message::planet,getPosition(),getPreviousPos(),getColor(),radius));
}

CelestialBody::~CelestialBody() {
	// TODO Auto-generated destructor stub
}

