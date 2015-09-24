/* 
 * File:   operator.h
 * Author: nvr
 *
 * Created on September 13, 2015, 8:32 PM
 */

#ifndef SEARCHOPERATOR_H
#define	SEARCHOPERATOR_H

#include "tour.h"


/// <summary>
/// Defines a search operator, the thing that is used to go from one solution to another.
/// </summary>
class searchOperator{
    
public:
	// pure abstract method
    virtual void inspectNeighbourhood(tour* currentSolution, tour *neighbour) = 0;
    
};

#endif	/* OPERATOR_H */

