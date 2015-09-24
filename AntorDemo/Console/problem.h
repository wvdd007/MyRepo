#pragma once

#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>



class problem
{
public:
	problem(const std::string filename);
	~problem();

	int getInstanceSize();
	
	double getDistance(int citySource, int cityDest);
	void setDistance(double distance, int citySource, int cityDest);
private:

	void initializeTour(int n);

	int _instanceSize;
	int* _citySequence;
	double** _distances;
};

