/*
 * Forces.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#include <algorithm>
#include <iostream>
#include "Vector_set.h"

using namespace std;
using namespace Physics;


Vector_set::Vector_set() {
	// TODO Auto-generated constructor stub

}

Vector_set::~Vector_set() {
	// TODO Auto-generated destructor stub
}

Point Vector_set::calculate_common_vector_value()
{
	sum_of_vector = Vector_value(Point(0,0));
	for_each(vector_of_values.begin(),vector_of_values.end(), [&](Vector_value i){sum_of_vector = sum_of_vector + i;  });

	//sum_of_vector = Vector_value(Point(modify_vector_value(sum_of_vector.vector_value().getX()),
	//		modify_vector_value(sum_of_vector.vector_value().getY())));
	sum_of_vector = Vector_value(Point(sum_of_vector.vector_value().getX(), sum_of_vector.vector_value().getY()));

	return sum_of_vector.vector_value();
}

int Vector_set::modify_vector_value(int val)
{
	short signum = 1;
	if(val < 0)
		signum = -1;
	val = abs(val);
	if(val > 100)
		return 4 * signum;
	else if(val > 50)
		return 3* signum;
	else if(val > 20)
		return 2* signum;
	else if(val > 5)
		return 1* signum;
	else
		return 0;
}
void Vector_set::addVector(Vector_value &vec)
{
	vector_of_values.push_back(vec);
}
void Vector_set::clear()
{
	vector_of_values.clear();
}
