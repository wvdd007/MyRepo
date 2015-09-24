/* 
 * File:   tour.h
 * Author: nvr
 *
 * Created on September 13, 2015, 7:48 PM
 */

#ifndef TOUR_H
#define	TOUR_H

#include "problem.h"

class tour{
public:
    tour(problem *prob);
    tour(tour *copy);
    ~tour();
    
    void set(tour *t);
    void swapCities(int cityPositionSource, int cityPositionDest);
    int getInstanceSize();
    int getCity(int index);
    void print();
    
private:
    
    void initializeTour(int n);
    
	problem * _problem;
	int _instanceSize;
	int* _citySequence;
};

#endif	/* TOUR_H */

