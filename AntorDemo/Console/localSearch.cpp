#include "localSearch.h"
#include <chrono>
#include "tourEvaluator.h"
#include "acceptanceCriterion.h"
#include <iostream>

localSearch::localSearch(searchOperator* searchOperator, tourEvaluator* tourEvaluator, acceptanceCriterion* acceptanceCriterion)
{
	_searchOperator = searchOperator;
	_tourEvaluator = tourEvaluator;
	_acceptanceCriterion = acceptanceCriterion;
}


localSearch::~localSearch()
{
}

tour* localSearch::LocalSearch(tour* initial, int timeSeconds)
{
	tour* bestSolution = new tour(initial);
	tour* workingSolution = new tour(initial);

	time_t time = clock();
	while (((clock() - time)) < timeSeconds * CLOCKS_PER_SEC)
	{
		tour* localImprovementSolution = initial;
		_searchOperator->inspectNeighbourhood(workingSolution, localImprovementSolution);

		if (_tourEvaluator->compare(localImprovementSolution, bestSolution) == 1)
		{
			bestSolution->set(localImprovementSolution);
		}

		if (_acceptanceCriterion->accept(localImprovementSolution, workingSolution))
		{
			workingSolution->set(localImprovementSolution);
		}
		else
		{
			localImprovementSolution->set(workingSolution);
		}
	}
	delete workingSolution;
	return bestSolution;
}
