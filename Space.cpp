/*
 * Space.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#include "Space.h"
#include "Point.h"
#include "Collision.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <exception>
#include <typeinfo>


using namespace std;

//default dimension of space
Space::Space():Space(800,600,20)
{
	// TODO Auto-generated constructor stub

}

Space::Space(int _h,int _w, int starsQuantity):height{_h},width{_w}
{

	sGraphic = SpaceGraphic(_h, _w);
	generateSky(starsQuantity);
	speed = 10;



}


void Space::generateSky(int value)
{
	srand(time(NULL));
	int it = 0 ;

	while(it++<value)
		stars.push_back(Point(rand()%height, rand()%width));

	draw(sGraphic);


}

void Space::updateSpace()
{
	int cycles = 0;
	const string collision_name = "9Collision";

	while(!sGraphic.checkIfCanvasClosed())
	{
	updateBodiesKnowledge();
	for(auto &cBody: bodies)
	{
		cBody->draw(sGraphic);

		//Body
		if(!(cBody->calculateForce(bodies))) break;

		if(collision_name.compare((typeid(*cBody).name()))==0)
		{
			//reduce life from collision
			if(cBody->reduce_life() == 0)
			{
				cBody->create_new_planets(bodies);
				cBody->draw_clear(sGraphic);
				auto element = find(bodies.begin(),bodies.end(),cBody);
				bodies.erase(element);
				break;
			}
		}

	}
	sGraphic.repaint();
	sGraphic.wait(speed);
	cycles++;
	}
}

void Space::draw(SpaceGraphic &gr)
{
	for_each(stars.begin(), stars.end(),[&gr](Point p){gr.drawPoint(p);});
}

void Space::addCelestialBody(Point pos, int weight, int rad, string col)
{
	auto spBody = make_shared<CelestialBody>(CelestialBody(pos, weight, rad, col));
	if(spBody!= nullptr)
	{
		bodies.push_back(spBody);
	}
	else
		throw runtime_error("Error adding CelestialBody");
}

void Space::updateBodiesKnowledge()
{
	for(auto &i : bodies)
	{
		for(auto &j: bodies)
		{
			if(i!=j)
				i->addGalaxyToBody(j);
		}
	}
}


Space::~Space() {
	// TODO Auto-generated destructor stub
	if(bodies.size()>0)
	{
		for(auto& i: bodies)
			i.reset();
	}
}

