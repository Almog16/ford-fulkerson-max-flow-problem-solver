#include "FordFulkerson.h"
#include <string>

using namespace std;

FordFulkerson::FordFulkerson(Graph &G, int s, int t) : bfs(G.getNumOfVertices()), ResidualGraph_BFS(G), ResidualGraph_Greedy(G), greedy(G.getNumOfVertices())
{
	this->maxFlow = 0;
	this->numOfVertices = G.getNumOfVertices();
	this->s = s-1;
	this->t = t-1;
	numOfIterations = 0;
}

void FordFulkerson::runFordFulkerson() {
	this->FordFulkersonBFS();
	this->printMinCutAndMaxFlow("BFS");
	this->FordFulkersonGreedy();
	this->printMinCutAndMaxFlow("Greedy");
}

int FordFulkerson::FordFulkersonBFS() {
	int minCapacityInPath;
	this->maxFlow = 0;
	this->numOfIterations = 0;

	while (bfs.runBFS(s, t, numOfVertices, ResidualGraph_BFS) == true) //while there is a path from s to t in the residual graph
	{
		numOfIterations++;
		minCapacityInPath = findResidualCapacityOfPathForBFS();
		updatePathCapacities(minCapacityInPath, bfs.parents, ResidualGraph_BFS);
		maxFlow += minCapacityInPath;
	}
	return maxFlow;
}

int FordFulkerson::FordFulkersonGreedy() {
	int minCapcityInPath;
	this->maxFlow = 0;
	this->numOfIterations = 0;

	while (greedy.runDijkstraVariation(s, t, numOfVertices, ResidualGraph_Greedy) == true) //while there is a path from s to t in the residual graph
	{
		numOfIterations++;
		minCapcityInPath = greedy.d[t];
		updatePathCapacities(minCapcityInPath, greedy.p, ResidualGraph_Greedy);
		this->maxFlow += minCapcityInPath;
	}
	return 0;
}

int FordFulkerson::findResidualCapacityOfPathForBFS() {
	int u, v = t;
	int minCapacityInPath = INT_MAX;

	for (int v = t; bfs.parents[v] != NO_PARENT; v = bfs.parents[v]) // find the residual capacity of the path
	{
		u = bfs.parents[v];
		minCapacityInPath = min(minCapacityInPath, ResidualGraph_BFS.getEdgeWeight(u+1,v+1));
	}
	return minCapacityInPath;
}

void FordFulkerson::updatePathCapacities(int minCapacityInPath, int* parents, Graph& ResidualGraph) {
	int u, v = t;
	int uvCapacity, vuCapacity;
	while (parents[v] != NO_PARENT) { // update the residual capacities graph along the path
		u = parents[v];
		uvCapacity = ResidualGraph.getEdgeWeight(u+1, v+1);
		vuCapacity = ResidualGraph.getEdgeWeight(v+1, u+1);
		ResidualGraph.setEdgeWeight(u+1, v+1, uvCapacity - minCapacityInPath);
		ResidualGraph.setEdgeWeight(v+1, u+1, vuCapacity + minCapacityInPath);
		v = u;
	}
}

void FordFulkerson::printMinCutAndMaxFlow(string type) {
	cout << type << " Method:" << endl;
	printf("Max flow = %d\n", this->maxFlow);
	LinkedList S, T;

	createMinCut(type, S, T);
	printf("Min cut: ");
	printf("S = ");
	S.printList(1);
	printf("T = ");
	T.printList(1);
	cout << endl;

	printf("Number of iterations = %d\n", this->numOfIterations);
}

void FordFulkerson::createMinCut(string type, LinkedList& S, LinkedList& T) {
	if (type.compare("BFS") == 0) {
		this->bfs.runBFS(s, t, numOfVertices, ResidualGraph_BFS);
	}
	else
	{
		this->bfs.runBFS(s, t, numOfVertices, ResidualGraph_Greedy);
	}

	for (int v = 0; v < numOfVertices; v++) {
		if (bfs.distances[v] != INT_MAX) {
			S.AddNewItem(v);
		}
		else {
			T.AddNewItem(v);
		}
	}
}