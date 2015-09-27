#pragma once
#include "searchOperator.h"
class countingSearchOperator : 	public searchOperator
{
public:

	countingSearchOperator(searchOperator * decoree)
	{
		_decoree = decoree;
		_counter = 0;
	}

	void inspectNeighbourhood(tour* currentSolution, tour* neighbour) override {
		_counter++;
		_decoree->inspectNeighbourhood(currentSolution, neighbour);
	}

	int getCounter() { return _counter;  }

private:
	searchOperator* _decoree;
	int _counter;

};

