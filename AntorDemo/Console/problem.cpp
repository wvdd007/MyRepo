#include "problem.h"

#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>


problem::problem(const std::string filename)
{
		std::ifstream tourFile(filename.c_str());
		std::string lineContainer;

		std::vector<double> *xcos = new std::vector<double>();
		std::vector<double> *ycos = new std::vector<double>();

		double tempx = 0, tempy = 0;

		if (tourFile.is_open()) {

			while (std::getline(tourFile, lineContainer)) {

				std::size_t comment = lineContainer.find(";");

				if (comment != std::string::npos) {
					continue;
				}

				std::stringstream ss(lineContainer);
				comment = lineContainer.find(".");

				if (comment != std::string::npos) {
					//std::cout << lineContainer << std::endl;
					ss >> tempx;
					//std::cout << tempx << std::endl;
					ss >> tempy;
					//std::cout << tempy << std::endl;
					xcos->push_back(tempx);
					ycos->push_back(tempy);
				}
			}

			tourFile.close();

			int instanceSize = xcos->size();
			this->_instanceSize = instanceSize;
			initializeTour(instanceSize);
			double dist = 0;

			for (int i = 0; i < instanceSize; i++) {

				for (int j = 0; j < instanceSize; j++) {

					dist = sqrt(pow(xcos->at(i) - xcos->at(j), 2) + pow(ycos->at(i) - ycos->at(j), 2));
					this->setDistance(dist, i, j);

				}

			}

			delete xcos;
			delete ycos;

		}
		else {
			std::cout << "ERROR: problem when opening file..." << std::endl;
			std::cout << "**Make sure the format is correct:" << std::endl;
			std::cout << "**Lines containing a semicolon are skipped" << std::endl;
			std::cout << "**Other lines contain coordinates (decimal dot) separated by comma, or they are empty" << std::endl;
			throw new std::exception("Failed to load input file");
		}
}


problem::~problem()
{
}

void problem::initializeTour(int n) {

	this->_instanceSize = n;

	this->_citySequence = new int[n];

	//initialize a random tour.
	for (int i = 0; i < n; i++) {

		_citySequence[i] = i;

	}

	this->_distances = new double*[n];

	for (int i = 0; i < n; i++) {

		_distances[i] = new double[n];

	}


}


void problem::setDistance(double distance, int citySource, int cityDest) {

	// assume valid indices and an existing "distances" array.
	_distances[citySource][cityDest] = distance;

}

double problem::getDistance(int citySource, int cityDest) {

	// assume valid indices and an existing "distances" array.
	return _distances[citySource][cityDest];

}

int problem::getInstanceSize() {

	return _instanceSize;

}