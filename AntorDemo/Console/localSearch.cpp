#include "localSearch.h"
#include <chrono>
#include "tourEvaluator.h"
#include "acceptanceCriterion.h"
#include <iostream>
#include "logger.h"
#include "nullLogger.h"

localSearch::localSearch(searchOperator* searchOperator, tourEvaluator* tourEvaluator, acceptanceCriterion* acceptanceCriterion, logger* logger)
{
	_searchOperator = searchOperator;
	_tourEvaluator = tourEvaluator;
	_acceptanceCriterion = acceptanceCriterion;
	if (logger == NULL)
	{
		_logger = new nullLogger();
	}
	else
	{
		_logger = logger;
	}
}


localSearch::~localSearch()
{
}

tour* localSearch::LocalSearch(tour* initial, int timeSeconds)
{
	tour* bestSolution = new tour(initial);
	tour* workingSolution = new tour(initial);

	if (NULL != _logger)
	{
		_logger->logInfo("Starting calculation");
	}
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
