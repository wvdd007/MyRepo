/* 
 * File:   twoOptSwap.h
 * Author: nvr
 *
 * Created on September 13, 2015, 8:46 PM
 */

#ifndef TWOOPTSWAPRAND_H
#define	TWOOPTSWAPRAND_H

#include "searchOperator.h"


class twoOptSwapRand : public searchOperator{
    
    public:
        twoOptSwapRand();
        ~twoOptSwapRand();
        virtual void inspectNeighbourhood(tour *currentTour, tour *neighbour) override;
    
};

#endif	/* TWOOPTSWAPRAND_H */

