#include "tourEvaluator.h"

tourEvaluator::tourEvaluator(problem * problem)
{
	this->_problem = problem;
}

/**
 * @param t the tour
 * @DESCRIPTION Default implementation. It calculates the total distance traveled.
 */
double tourEvaluator::evaluateTour(tour *t){
    
    double evaluation = 0;
    int instanceSize = t->getInstanceSize();
    
    for(int i = 0; i < instanceSize-1; i++){
        
        evaluation += this->_problem->getDistance(t->getCity(i),t->getCity(i+1));
        
    }
    
    evaluation += this->_problem->getDistance(t->getCity(instanceSize-1),t->getCity(0));
    
    return evaluation;
    
}

/**
 * @param t1, t2 tours to be compared
 * @DESCRIPTION       Default implementation. A tour is assumed to be better if the evaluation is lower.
 * @RETURN -1 when tour1 is "worse" than tour2, 0 when they are "equal" and 1 when tour1 is better than tour2.
 */
int tourEvaluator::compare(tour* tour1, tour* tour2){
    
    double eval1 = evaluateTour(tour1);
    double eval2 = evaluateTour(tour2);
    
    if(eval1 < eval2){
        
        return 1;
    
    } else if (eval2 < eval2) {
        
        return -1;
    
    }
    
    return 0;
}