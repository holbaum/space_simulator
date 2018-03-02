/*
 * SpaceGraphic.h
 *
 *  Created on: Nov 28, 2017
 *      Author: henryk
 */

#ifndef SPACEGRAPHIC_H_
#define SPACEGRAPHIC_H_

#include "CImg.h"
#include "Point.h"
#include "PackageForDraw.h"
#include <map>
#include <string>
#include <array>

class SpaceGraphic {
public:
	SpaceGraphic();
	SpaceGraphic(int _h, int _w);

	void initColorMap();
	virtual ~SpaceGraphic();

	void drawCircle(Point _p, int _rad, std::string col);
	void clearCircle(Point _p, int rad);
	void drawPoint(Point _p);
	void draw_collision(Point _p);
	void draw(Package_For_Draw pckg);
//	void graphicLoop();

	void repaint();


	bool checkIfCanvasClosed();
	void wait(int _t);
	std::string get_random_color();


private:
	cimg_library::CImg<unsigned char> spaceImage;
	cimg_library::CImgDisplay spaceCanvas;

	std::map <std::string, std::array<unsigned char,3>> colorMap;


};

#endif /* SPACEGRAPHIC_H_ */
