#include <time.h>

#include "searchAlgorithm.h"

searchAlgorithm::searchAlgorithm(){
    
}

searchAlgorithm::~searchAlgorithm(){

    delete _localImprovementSolution;
    delete _bestSolution;
    
}

void searchAlgorithm::initialize(tour *t, searchOperator *so, tourEvaluator *te, acceptanceCriterion *ac){
    
    this->_workingSolution = t;
    this->_localImprovementSolution = new tour(t);
    this->_bestSolution = new tour(t);
    
    this->searchop = so;
    this->evaluator = te;
    this->acceptance = ac;
    
}

/**
 * 
 * @DESCRIPTION The local search, based on a single solution. The operator is assumed to generate only feasible solutions. Therefore a validator is redundant.
 */
void searchAlgorithm::localSearch(double timeSeconds){
    
    double time = clock();
    
    while((clock()-time)/CLOCKS_PER_SEC < timeSeconds){
        
        searchop->inspectNeighbourhood(_workingSolution, _localImprovementSolution);
        
        if(evaluator->compare(_localImprovementSolution, _bestSolution) == 1){
            
            _bestSolution->set(_localImprovementSolution);

        }
        
        if(acceptance->accept(_localImprovementSolution, _workingSolution)){
            
            _workingSolution->set(_localImprovementSolution);
            
        }else {
            
            _localImprovementSolution->set(_workingSolution);
            
        }
        
    }
    
}

tour* searchAlgorithm::getBestSolution(){
    
    return new tour(_bestSolution);
    
}