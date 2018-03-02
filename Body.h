/*
 * Body.h
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#ifndef BODY_H_
#define BODY_H_
#include <vector>
#include <memory>
#include "SpaceGraphic.h"
#include "DrawableC.h"
#include <string>
#include "Vector_set.h"


class Body : public DrawableC
{
public:
	Body();
	Body(Point position, int _weight,std::string col, int siz);

	void addGalaxyToBody(std::weak_ptr<Body> b);

//	void upgradePosition();

	bool calculateForce(std::vector<std::shared_ptr<Body>> &universe);
	virtual void draw(SpaceGraphic &);
	virtual void draw_clear(SpaceGraphic &);
	virtual int reduce_life();
	virtual void create_new_planets(std::vector<std::shared_ptr<Body>> &);

	virtual ~Body();

	bool detectCollision(Body* body, int dist);
	int getWeight();
	Point getPosition() const;
	Point getPreviousPos();
	int calculateDistance(Point &vectorVal);
	int getGalaxyCount();
	int getSize();




private:
	Point position;
	Point oldPosition;
	int weight = 0;
	Physics::Vector_set forces;
	Physics::Vector_value velocity;
	int galaxyCount = 0;
	int size = 0;



	int normaLizationFactor = 10000;

	std::vector<std::weak_ptr<Body>> others;


};

#endif /* BODY_H_ */
