#pragma once
#include "tour.h"
#include <time.h>

double evaluateTour(tour* tour);

void inspectNeighbourhood(tour* tour2, tour* local_improvement_solution);

int tourcompare(tour* tour2, tour* best_solution);

bool tourAccepted(tour* tour2, tour* working_solution);

class main2
{
public:
	main2();
	~main2();

	static int main(int argc, char** argv)
	{
		srand(time(NULL));
		problem* prob = new problem(std::string("city.txt"));

		tour* t = new tour(prob);
		double initialEvaluation = evaluateTour(t);

		tour* bestSolution = new tour(t);
		tour* workingSolution = new tour(t);

		time_t time = clock();
		clock_t timeSeconds;
		while (((clock() - time)) < 10 * CLOCKS_PER_SEC)
		{
			tour* localImprovementSolution = t;
			inspectNeighbourhood(workingSolution, localImprovementSolution);

			if (tourcompare(localImprovementSolution, bestSolution) == 1)
				bestSolution->set(localImprovementSolution);

			if (tourAccepted(localImprovementSolution, workingSolution))
				workingSolution->set(localImprovementSolution);
			else
				localImprovementSolution->set(workingSolution);
		}

		return 0;
	}
};
