#pragma once
#include "tourEvaluator.h"

class distanceBasedTourEvaluator : public tourEvaluator
{
	

public:
	explicit distanceBasedTourEvaluator(problem* problem)
		: tourEvaluator(problem)
	{
	}

	/**
	* @param t the tour
	* @DESCRIPTION Default implementation. It calculates the total distance traveled.
	*/
	 double tourEvaluator::evaluateTour(tour *t) override;
};
