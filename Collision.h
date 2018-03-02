/*
 * Collision.h
 *
 *  Created on: Dec 12, 2017
 *      Author: henryk
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include "Body.h"
#include "SpaceGraphic.h"

class Collision : public Body
{
public:
	Collision();
	Collision(Point pos, int size, int weig);
	virtual void draw(SpaceGraphic &gr);
	void draw_clear(SpaceGraphic &gr);
	int reduce_life();

	void create_new_planets(std::vector<std::shared_ptr<Body>> &bodies);

	virtual ~Collision();

	int cycle_of_life = 3;

private:


};

#endif /* COLLISION_H_ */
