
#ifndef LOCALSEARCH_H
#define	LOCALSEARCH_H

#include "tour.h"
#include "searchOperator.h"
#include "tourEvaluator.h"
#include "acceptanceCriterion.h"
#include "logger.h"


class  localSearch
{
public:
	localSearch(searchOperator* searchOperator, tourEvaluator* tourEvaluator, acceptanceCriterion* acceptanceCriterion, logger* logger);
	~localSearch();

	tour* LocalSearch(tour* initial, int timeInSeconds);

private:
	searchOperator* _searchOperator;
	tourEvaluator* _tourEvaluator;
	acceptanceCriterion* _acceptanceCriterion;
	logger *_logger;
};

#endif
