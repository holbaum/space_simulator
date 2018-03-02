/*
 * Force.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#include "Vector_value.h"
using namespace Physics;
Vector_value::Vector_value():value{Point()}
{

}
Vector_value::Vector_value(Point fvalue):value{fvalue}
{

}



Vector_value::~Vector_value() {
	// TODO Auto-generated destructor stub
}

Point Vector_value::vector_value()
{
	return value;
}

void Vector_value::set_vector_value(Point &point)
{
	value = point;
}



Vector_value& Vector_value::operator +(const Vector_value &addForce)
{
	this->value  = this->value + addForce.value;
	return *this;
}






