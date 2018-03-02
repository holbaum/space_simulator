/*
 * SpaceGraphic.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: henryk
 */

#include "SpaceGraphic.h"
#include <iostream>
#include <utility>
#include <random>

using namespace std;
using namespace cimg_library;

using Array = array<unsigned char,3>;
using Pair = pair<string,Array>;
SpaceGraphic::SpaceGraphic():SpaceGraphic(800,600)
{
	// TODO Auto-generated constructor stub

}

SpaceGraphic::SpaceGraphic(int _h, int _w)
{
	initColorMap();
	spaceImage = CImg <unsigned char> (_h, _w,1, 3);
	spaceImage.fill(0);
	spaceCanvas = CImgDisplay(spaceImage, "Space Simulator", 0, false, false);
	spaceCanvas.display(spaceImage);
//	graphicLoop();
}

void SpaceGraphic::initColorMap()
{

	colorMap.insert(Pair("black",Array{0,0,0}));
	colorMap.insert(Pair("white",Array{255,255,255}));
	colorMap.insert(Pair("yellow",Array{255,255,0}));
	colorMap.insert(Pair("red",Array{255,0,0}));
	colorMap.insert(Pair("green",Array{0,255,0}));
	colorMap.insert(Pair("blue",Array{0,0,255}));
	colorMap.insert(Pair("orange",Array{255,140,0}));

}

string SpaceGraphic::get_random_color()
{
	std::default_random_engine gen;
	std::uniform_int_distribution<int> dist(1,colorMap.size());
	vector<string> keys;
	transform(colorMap.begin(),
			colorMap.end(),
			back_inserter(keys),
			[](const pair<string, array<unsigned char,3>> &elem){return elem.first;});

	return keys[dist(gen)];
}

//void SpaceGraphic::graphicLoop()
//{
//		while (!spaceCanvas.is_closed()) {
//
//
//
//		   spaceCanvas.wait();
//
//		    }
//}

void SpaceGraphic::draw(Package_For_Draw pckg)
{
	Draw_Message draw_message = pckg.draw_message;

	switch(draw_message)
	{
		case star:
		case spaceship:
		case planet:
			clearCircle(pckg.old_position, pckg.size);
			drawCircle(pckg.position,pckg.size,pckg.color);
			break;
		case collision:
			draw_collision(pckg.position);
			break;
		case clear:
			clearCircle(pckg.position, pckg.size);

	}



	spaceCanvas.display(spaceImage);

}

void SpaceGraphic::drawCircle(Point _p,int rad, string col)
{
	spaceImage.draw_circle(_p.getX(),_p.getY(),rad,colorMap[col].data(),1);
}

void SpaceGraphic::clearCircle(Point _p,int rad)
{
	spaceImage.draw_circle(_p.getX(),_p.getY(),rad+40,colorMap["black"].data(),1);
}


void SpaceGraphic::drawPoint(Point _p)
{
	spaceImage.draw_point(_p.getX(), _p.getY(), colorMap["white"].data(), 1);
}

void SpaceGraphic::draw_collision(Point _p)
{
	int i = 40;
	spaceImage.draw_circle(_p.getX(),_p.getY(),i, colorMap["yellow"].data(), 1);
	i = 20;
	spaceImage.draw_circle(_p.getX(),_p.getY(),i, colorMap["orange"].data(), 1);
	i = 10;
	spaceImage.draw_circle(_p.getX(),_p.getY(),i, colorMap["red"].data(), 1);
}


void SpaceGraphic::repaint()
{
	//spaceCanvas.paint();
//	spaceCanvas.display();
}

bool SpaceGraphic::checkIfCanvasClosed()
{
	return spaceCanvas.is_closed();
}

void SpaceGraphic::wait(int _t)
{
	spaceCanvas.wait(_t);
}


SpaceGraphic::~SpaceGraphic()
{
	// TODO Auto-generated destructor stub
}

