#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "metropolisAcceptanceCriterion.h"
#include "acceptanceCriterion.h"

metropolisAcceptanceCriterion::metropolisAcceptanceCriterion(tourEvaluator *evaluator, problem* initialTour) {
	_evaluator = evaluator;
	setParams(initialTour);
}

void metropolisAcceptanceCriterion::setParams(problem* tour){
    
    int instanceSize = tour->getInstanceSize();
    
    _temperatureChangeIteration = instanceSize*(instanceSize-1) + 1;
    _coolingRate = 0.95;
    
    double averageLength = 0;
    
    for(int i = 0; i < instanceSize; i++){
   
        for(int j = 0; j < instanceSize; j++) {
            
            averageLength += tour->getDistance(i, j);
            
        }
    
    }
    
    averageLength = averageLength/(instanceSize*(instanceSize - 1));
    _initTemperature = averageLength/50;
    _temperature = _initTemperature;
    
}

bool metropolisAcceptanceCriterion::accept(tour *tnew, tour *told){
    
    updateTemperature();
    double difference = (this->_evaluator->evaluateTour(tnew) - this->_evaluator->evaluateTour(told));
    
    if (difference <= 0) return true;
    
    double r = ((double)rand())/RAND_MAX;
    double energystate = exp( -difference / _temperature);
    
    if (r < energystate){
        
        return true;
        
    }
    
    return false;
    
}

void metropolisAcceptanceCriterion::updateTemperature(){
    
    _iterationCounter++;
    
    if(_iterationCounter < _temperatureChangeIteration) return;
    
    if(_temperature < 0.02*_initTemperature) return;
    
    _iterationCounter = 0;
    _temperature *= _coolingRate;
    
}