/*
 * Force.h
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#ifndef VECTOR_VALUE_H_
#define VECTOR_VALUE_H_
#include "Point.h"

namespace Physics {
class Vector_value;


class Vector_value{
public:

	Vector_value(Point fValue);
	Vector_value();

	virtual ~Vector_value();

	void set_vector_value(Point &point);
	Point vector_value();
	Vector_value& operator +(const Vector_value &f);

private:
//	int value;
//	int angle;

	Point baseVectorForce;
//	Point myOrigin;
	Point value;

};

}

#endif /* VECTOR_VALUE_H_ */
