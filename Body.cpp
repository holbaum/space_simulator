/*
 * CelestialBody.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#include "CelestialBody.h"
#include "Collision.h"
#include <math.h>
#include <algorithm>
#include <iostream>

#include "Vector_value.h"


using namespace std;
using namespace Physics;

Body::Body() {
	// TODO Auto-generated constructor stub

}

Body::~Body() {
	// TODO Auto-generated destructor stub
}

Body::Body(Point pos, int wei, string col = "black", int siz = 0):DrawableC{col},position{pos},oldPosition{pos},weight{wei}, size{siz}
{
}

int Body::getGalaxyCount()
{
	return galaxyCount;
}

Point Body::getPreviousPos()
{
	return oldPosition;
}

void Body::addGalaxyToBody(weak_ptr<Body> b)
{
	others.push_back(b);
	galaxyCount++;
}

void Body::draw(SpaceGraphic &gr)
{
	//wrong need to add force to body position
	//gr.drawCircle(position,0);
}
int Body::getSize()
{
	return size;
}


bool Body::detectCollision(Body *body, int dist)
{
//	cout<<this->size + body->size<< "  "<< dist<< " |";
	if((this->size + body->size) >= dist)
		return true;
	return false;
}


bool Body::calculateForce(vector<shared_ptr<Body>> &universe)
{
	forces.clear();
	for(auto &i : others)
	{
		if(auto sharedTemp = i.lock())
		{
		Point relPosition = sharedTemp->getPosition() - position;
		int distance = calculateDistance(relPosition);
		if(detectCollision(sharedTemp.get(), distance))
		{
			auto element1 = find(universe.begin(),universe.end(),sharedTemp);
			universe.erase(element1);
			auto element2 = find_if(universe.begin(),universe.end(),[this](const shared_ptr<Body>& elem)
				{
					if (elem->getPosition()==getPosition())	return true;
					return false;
				}
			);
			universe.erase(element2);
			universe.push_back(make_shared<Collision>(Collision(sharedTemp->getPosition(),sharedTemp->getSize()+getSize(),(sharedTemp->getWeight() + weight))));
			cout<<"Collision: "<<position.getX()<< " "<< position.getY()<<endl;
			cout<<"Collision shared temp: "<<sharedTemp->getPosition().getX()<< " "<<sharedTemp->getPosition().getY()<<endl;
			return false;
		}
		float forceVal = 6.22*((sharedTemp->getWeight() * weight) / (pow(distance,2)));
		float ratioOfForceToDistance = 0;

		if (forceVal == 0)
			ratioOfForceToDistance = 0;
		else if(forceVal>=distance)
			ratioOfForceToDistance = 1;
		else
			ratioOfForceToDistance = distance / forceVal;

//		ratioOfForceToDistance = ratioOfForceToDistance / normaLizationFactor;

		Vector_value tempForce(Point(static_cast<int>(relPosition.getX() * ratioOfForceToDistance),
					static_cast<int>(relPosition.getY() * ratioOfForceToDistance)));
		forces.addVector(tempForce);
		}
		else
		{
			//cout<<R"(CalculateForce weakPointer lost)";
		}
	}
	Vector_value tempRelPos = forces.calculate_common_vector_value();
	oldPosition = position;
	position = position + tempRelPos.vector_value();
	return true;
}


int Body::getWeight()
{
	return weight;
}
void Body::draw_clear(SpaceGraphic &gr)
{

}

int Body::reduce_life()
{

}

void Body::create_new_planets(std::vector<std::shared_ptr<Body>> & body)
{

}

Point Body::getPosition() const
{
	return position;
}

int Body::calculateDistance(Point &vectorVal)
{
	return static_cast<int>(pow(pow(vectorVal.getX(),2) + pow(vectorVal.getY(),2),0.5));
}

