/* 
 * File:   searchAlgorithm.h
 * Author: nvr
 *
 * Created on September 13, 2015, 8:26 PM
 */

#ifndef SEARCHALGORITHM_H
#define	SEARCHALGORITHM_H

#include "tour.h"
#include "searchOperator.h"
#include "acceptanceCriterion.h"


class searchAlgorithm {
    
public:
    searchAlgorithm();
    ~searchAlgorithm();
    void initialize(tour *t, searchOperator *so, tourEvaluator *te, acceptanceCriterion *ac);
    void localSearch(double timeSeconds);
    tour* getBestSolution();
    
protected:    
    searchOperator *searchop;
    tourEvaluator *evaluator;
    acceptanceCriterion *acceptance;
    
    tour *_workingSolution;
    tour *_localImprovementSolution;
    tour *_bestSolution;
    
};


#endif	/* SEARCHALGORITHM_H */

