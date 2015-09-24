/* 
 * File:   tourEvaluator.h
 * Author: nvr
 *
 * Created on September 13, 2015, 8:10 PM
 */

#ifndef TOUREVALUATOR_H
#define	TOUREVALUATOR_H

#include "tour.h"


class tourEvaluator{

public:
	tourEvaluator(problem* problem);

    virtual double evaluateTour(tour *t);
    virtual int compare(tour *tour1, tour *tour2); //RETURNS -1 when tour1 is "worse" than tour2, 0 when they are "equal" and 1 when tour1 is better than tour2.
    
protected:
	problem* _problem;
};

#endif	/* TOUREVALUATOR_H */