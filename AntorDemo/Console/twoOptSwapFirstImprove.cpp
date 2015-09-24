#include <stdlib.h>

#include "twoOptSwapFirstImprove.h"
#include "tourEvaluator.h"

twoOptSwapFirstImprove::twoOptSwapFirstImprove(tourEvaluator* te)
{
	_evaluator = te;
}

// assume the current tour and neighbour to be equal.
void twoOptSwapFirstImprove::inspectNeighbourhood(tour* currentTour, tour* neighbour){
    
    int instanceSize = currentTour->getInstanceSize();
    int idxSrc, idxDest;
    
    for(int sourceCity = 0; sourceCity < instanceSize-1; sourceCity++) {
        
        for(int destCity = sourceCity+1; destCity < instanceSize; destCity++) {
            
            idxSrc = sourceCity;
            idxDest = destCity;
            
            // perform reversal of the cities (2-0PT) between the generated samples
            while(idxDest > idxSrc){

                neighbour->swapCities(idxSrc++, idxDest--);

            }
            
            if(_evaluator->compare(neighbour, currentTour) > -1){ 
				// improve or equal tours are allowed.
              	return;
                
            } else {
                
                neighbour->set(currentTour);
                
            }
        
        }
        
    }
    
}
