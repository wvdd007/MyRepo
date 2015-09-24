/* 
 * File:   acceptanceCriterion.h
 * Author: nvr
 *
 * Created on September 13, 2015, 8:38 PM
 */

#ifndef ACCEPTANCECRITERION_H
#define	ACCEPTANCECRITERION_H

#include "tourEvaluator.h"


class acceptanceCriterion{
    
public:
    virtual bool accept(tour *tnew, tour *told) = 0;
   
};

#endif	/* ACCEPTANCECRITERION_H */

