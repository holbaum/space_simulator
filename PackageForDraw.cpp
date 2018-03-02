/*
 * PackageForDraw.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: henryk
 */

#include "PackageForDraw.h"

Package_For_Draw::Package_For_Draw(Draw_Message mes, Point pos, Point old_pos, std::string col, int s)
:draw_message{mes}, position{pos}, old_position{old_pos},color{col}, size{s}
{

}
Package_For_Draw::Package_For_Draw(Draw_Message mes, Point pos, std::string col, int s)
:draw_message{mes}, position{pos},color{col}, size{s}
{}

Package_For_Draw::~Package_For_Draw()
{

}
