//============================================================================
// Name        : GravitySimulator.cpp
// Author      : WiktorO
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CImg.h"
#include "Space.h"
using namespace std;
using namespace cimg_library;

int main() {

	//CelestialBody(Point initPosition, int weight, int radius);
	Space space(1000,800,50);
	cout<<"Space simulator starts...";
	space.addCelestialBody(Point(50,50),300, 5, "blue");
	space.addCelestialBody(Point(500,300),500, 10, "green");
	space.addCelestialBody(Point(250,400),1000, 20,"red");
	space.addCelestialBody(Point(800,600),300, 5,"blue");
	space.addCelestialBody(Point(600,400),500, 10,"green");
	space.addCelestialBody(Point(1000,500),1000, 20,"red");
	space.updateSpace();

	return 0;
}
