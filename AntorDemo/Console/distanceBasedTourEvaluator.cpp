#include "distanceBasedTourEvaluator.h"


/**
* @param t the tour
* @DESCRIPTION Default implementation. It calculates the total distance traveled.
*/
double distanceBasedTourEvaluator::evaluateTour(tour *t) {

	double evaluation = 0;
	int instanceSize = t->getInstanceSize();

	for (int i = 0; i < instanceSize - 1; i++) {

		evaluation += this->_problem->getDistance(t->getCity(i), t->getCity(i + 1));

	}

	evaluation += this->_problem->getDistance(t->getCity(instanceSize - 1), t->getCity(0));

	return evaluation;

}