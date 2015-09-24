#include <stdlib.h>

#include "twoOptSwapRand.h"

twoOptSwapRand::twoOptSwapRand(){}

twoOptSwapRand::~twoOptSwapRand(){}

void twoOptSwapRand::inspectNeighbourhood(tour* currentTour, tour* neighbour){
    
    int randomCitySource = rand()%(neighbour->getInstanceSize());
    int randomCityDest = randomCitySource;
    
    // generate two different random samples (assume an instance size > 1)
    while( (randomCityDest = rand()%(neighbour->getInstanceSize())) == randomCitySource);
    
    // make sure the destination sample is at a larger index than the source
    if(randomCityDest < randomCitySource){
    
        int temp = randomCityDest;
        randomCityDest = randomCitySource;
        randomCitySource = temp;
    
    }
    
    // perform reversal of the cities (2-0PT) between the generated samples
    while(randomCityDest>randomCitySource){
        
        neighbour->swapCities(randomCitySource++,randomCityDest--);
        
    }
    
}