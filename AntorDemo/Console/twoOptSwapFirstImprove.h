/* 
 * File:   twoOptSwapFirstImprove.h
 * Author: nvr
 *
 * Created on September 16, 2015, 3:28 PM
 */

#ifndef TWOOPTSWAPFIRSTIMPROVE_H
#define	TWOOPTSWAPFIRSTIMPROVE_H

#include "searchOperator.h"
#include "tourEvaluator.h"

class twoOptSwapFirstImprove : public searchOperator{
    
    public:
	twoOptSwapFirstImprove(tourEvaluator* te);
	virtual void inspectNeighbourhood(tour *currentTour, tour *neighbour) override;

private:
	tourEvaluator* _evaluator;
};

#endif	/* TWOOPTSWAPFIRSTIMPROVE_H */

