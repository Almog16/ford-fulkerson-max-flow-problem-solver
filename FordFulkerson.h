#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include "BFS.h"
#include "DijkstraVariation.h"
#include <string.h>
using namespace std;

class FordFulkerson
{
private:
	DijkstraVariation greedy;
	BFS bfs;
	Graph ResidualGraph_BFS, ResidualGraph_Greedy;
	int s, t, numOfVertices, numOfIterations, maxFlow;
	void updatePathCapacities(int minCapacityInPath, int* parents, Graph& ResidualGraph);
	void createMinCut(string type, LinkedList& S, LinkedList& T);
	int findResidualCapacityOfPathForBFS();


public:
	FordFulkerson(Graph &G, int s, int t);
	void runFordFulkerson();
	int FordFulkersonBFS();
	int FordFulkersonGreedy();
	void printMinCutAndMaxFlow(string type);
};

#endif // !FORDFULKERSON_H
