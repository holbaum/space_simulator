/*
 * Forces.h
 *
 *  Created on: Nov 27, 2017
 *      Author: henryk
 */

#ifndef VECTOR_SET_H_
#define VECTOR_SET_H_

#include <vector>

#include "Vector_value.h"
namespace Physics {
class Vector_set;


class Vector_set: public Vector_value {
public:
	Vector_set();
	virtual ~Vector_set();
	void addVector(Vector_value &vec);
	Point calculate_common_vector_value();
	int modify_vector_value(int val);
	void clear();
private:
	std::vector<Vector_value> vector_of_values;
	Vector_value sum_of_vector;
};
}
#endif /* VECTOR_SET_H_ */
