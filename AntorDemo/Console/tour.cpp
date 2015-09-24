#include <iostream>

#include "tour.h"
#include "problem.h"

tour::tour(problem* probl){
    
	this->_problem = probl;
    this->initializeTour(probl->getInstanceSize());

}

tour::tour(tour* copy){

	this->_problem = copy->_problem;

	const int instanceSize = _problem->getInstanceSize();
	this->initializeTour(instanceSize);
    set(copy);
}

void tour::initializeTour(int n){
    
    this->_instanceSize = n;
    
    this->_citySequence = new int[n];
    
    //initialize a random tour.
    for(int i = 0; i < n; i++){
        
        _citySequence[i] = i;
        
    }
    
}


tour::~tour(){
    delete[] _citySequence;
}

void tour::swapCities(int cityPositionSource, int cityPositionDest){
    
    // assume valid indices and existing arrays ;)
    int tempCityDest = _citySequence[cityPositionDest];
    _citySequence[cityPositionDest] = _citySequence[cityPositionSource];
    _citySequence[cityPositionSource] = tempCityDest;

}

void tour::set(tour* t){
    
    for(int i = 0; i < _instanceSize; i++) {
        
        this->_citySequence[i] = t->getCity(i);
        
    }
    
}

int tour::getInstanceSize(){
    
    return _instanceSize;
    
}

/**
 * @param index The index of the city, the first city is 0
 */
int tour::getCity(int index){
    
    // assume valid index and an existing array.
    return this->_citySequence[index];
    
}

void tour::print(){
    
    std::cout << "[ ";
    for(int i = 0; i < _instanceSize; i++){
        
        std::cout << this->_citySequence[i];
        if(i != _instanceSize-1) std::cout << ", "; 
        
    }
    
    std::cout << " ]" << std::endl;
    
}