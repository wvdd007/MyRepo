/* 
 * File:   metropolisAcceptanceCriterion.h
 * Author: nvr
 *
 * Created on September 13, 2015, 8:50 PM
 */

#ifndef METROPOLISACCEPTANCECRITERION_H
#define	METROPOLISACCEPTANCECRITERION_H

#include "acceptanceCriterion.h"

class metropolisAcceptanceCriterion : public acceptanceCriterion{

public:
	metropolisAcceptanceCriterion(tourEvaluator *evaluator, problem* prob);
	virtual bool accept(tour *tnew, tour *told) override;
    
private:
    void setParams(problem *tour);
    void updateTemperature();
    
    int _iterationCounter;
    double _initTemperature;
    double _temperature;
    double _coolingRate;
    int _temperatureChangeIteration;
	tourEvaluator * _evaluator;
};

#endif	/* METROPOLISACCEPTANCECRITERION_H */

