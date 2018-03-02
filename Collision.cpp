/*
 * Collision.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: henryk
 */

#include "Collision.h"
#include "CelestialBody.h"
#include <iostream>
#include <memory>


Collision::Collision():Collision{Point(0,0),0,0}
{
	// TODO Auto-generated constructor stub

}
Collision::Collision(Point pos, int size, int weig):Body{pos,weig,"black", size}
{

}

Collision::~Collision() {
	// TODO Auto-generated destructor stub

}

void Collision::draw(SpaceGraphic &gr)
{

	setColor(gr.get_random_color());
	gr.draw(Package_For_Draw(Draw_Message::collision,getPosition(),Point(0,0),getColor(),0));

}

void Collision::draw_clear(SpaceGraphic &gr)
{
	gr.draw(Package_For_Draw(Draw_Message::collision,getPosition(),Point(0,0),"black",0));
}

int Collision::reduce_life()
{
	if(cycle_of_life>0)
		return cycle_of_life--;
	else
		return 0;
}


void Collision::create_new_planets(std::vector<std::shared_ptr<Body>> &bodies)
{
	auto spBody = std::make_shared<CelestialBody>(CelestialBody(getPosition(), getWeight(), getSize(), getColor()));
	bodies.push_back(spBody);
}
