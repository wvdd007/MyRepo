/* 
 * File:   main.cpp
 * Author: nvr
 *
 * Created on September 13, 2015, 7:48 PM
 */

#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include "tour.h"
#include "problem.h"
#include "metropolisAcceptanceCriterion.h"
#include "searchAlgorithm.h"
#include "searchOperator.h"
#include "twoOptSwapRand.h"
#include <ctime>
#include "localSearch.h"

using namespace std;

//tour* generateTourFromFile(std::string filename) {
//    
//    std::ifstream tourFile(filename.c_str());
//    std::string lineContainer;
//    
//    std::vector<double> *xcos = new std::vector<double>();
//    std::vector<double> *ycos = new std::vector<double>();
//    
//    double tempx = 0, tempy = 0;
//    
//    if(tourFile.is_open()) {
//        
//        while ( std::getline (tourFile, lineContainer) ) {
//
//            std::size_t comment = lineContainer.find(";");
//            
//            if(comment != std::string::npos) {
//                continue;
//            }
//            
//            std::stringstream ss(lineContainer);
//            comment = lineContainer.find(".");
//            
//            if(comment != std::string::npos) {
//                //std::cout << lineContainer << std::endl;
//                ss >> tempx;
//                //std::cout << tempx << std::endl;
//                ss >> tempy;
//                //std::cout << tempy << std::endl;
//                xcos->push_back(tempx);
//                ycos->push_back(tempy);
//            }
//        }
//
//        tourFile.close();
//        
//        int instanceSize = xcos->size();
//        tour *t = new tour(instanceSize);
//        double dist = 0;
//        
//        for(int i = 0; i < instanceSize; i++) {
//            
//            for(int j = 0; j < instanceSize; j++) {
//                
//                dist = sqrt(pow(xcos->at(i) - xcos->at(j),2) + pow(ycos->at(i) - ycos->at(j),2));
//                t->setDistance(dist,i,j);
//                
//            }
//            
//        }
//     
//        delete xcos;
//        delete ycos;
//        
//        return t;
//        
//    } else {
//        std::cout << "ERROR: problem when opening file..." << std::endl;
//        std::cout << "**Make sure the format is correct:" << std::endl;
//        std::cout << "**Lines containing a semicolon are skipped" << std::endl;
//        std::cout << "**Other lines contain coordinates (decimal dot) separated by comma, or they are empty" << std::endl;
//		return NULL;
//    }
//            
//}

/*
 * 
 */
int main(int argc, char** argv) {

    srand(time(NULL));
    
    std::cout << "Welcome to a simple local search program" << std::endl;
    std::cout << "Reading city.txt..." << std::endl;
    
    problem* prob = new problem(std::string("city.txt"));
	if (prob == NULL)
	{
		return -1;
	}
    
	tour *t = new tour(prob);
	tourEvaluator *te = new tourEvaluator(prob);
	double initialEvaluation = te->evaluateTour(t);
    metropolisAcceptanceCriterion *mac = new metropolisAcceptanceCriterion(te, prob);
    searchOperator *so = new twoOptSwapRand();

	localSearch * search = new localSearch(so, te, mac);
	tour *best = search->LocalSearch(t,10);
    
    std::cout << "Best solution found: " << std::endl;
    best->print();

	double finalEvaluation = te->evaluateTour(best);
	double diffEval = initialEvaluation - finalEvaluation;
    double evalPerc = diffEval/initialEvaluation;
    
    std::cout << "Improvement in evaluation function: " << diffEval << ", corresponding to a gain of " << ((evalPerc)*100.0) << "%"<< std::endl;

    delete t;
    delete te;
    delete mac;
	delete search;
    delete so;
	delete best;
	delete prob;
    
}

