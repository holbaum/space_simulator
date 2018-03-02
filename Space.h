/*
 * Space.h
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#ifndef SPACE_H_
#define SPACE_H_
#include <vector>
#include "DrawableC.h"
#include "CelestialBody.h"
#include "SpaceGraphic.h"
#include <memory>
#include <string>

class Space : public DrawableC{
public:
	Space();
	Space(int _h, int _w, int starsQuantity);

	void generateSky(int value);
	void draw(SpaceGraphic &gr);
	void updateSpace();
	virtual ~Space();

	void addCelestialBody(Point p, int weight, int rad, std::string col);
	void updateBodiesKnowledge();

private:
	std::vector<std::shared_ptr<Body>> bodies;
	std::vector<Point> stars;

	SpaceGraphic sGraphic;
	int height, width;
	int speed = 100;
};

#endif /* SPACE_H_ */
