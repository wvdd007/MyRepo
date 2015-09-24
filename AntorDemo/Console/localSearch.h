
#ifndef LOCALSEARCH_H
#define	LOCALSEARCH_H

#include "tour.h"
#include "searchOperator.h"
#include "tourEvaluator.h"
#include "acceptanceCriterion.h"


class  localSearch
{
public:
	localSearch(searchOperator* searchOperator, tourEvaluator* tourEvaluator, acceptanceCriterion* acceptanceCriterion);
	~localSearch();

	tour* LocalSearch(tour* initial, int timeInSeconds);

private:
	searchOperator* _searchOperator;
	tourEvaluator* _tourEvaluator;
	acceptanceCriterion* _acceptanceCriterion;
};

#endif
