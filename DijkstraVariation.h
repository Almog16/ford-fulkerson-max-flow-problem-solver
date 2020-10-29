/*
This class implements a variation of Dijkstra's algorithm.
It works similarly to the original algorithm, but its output is the path with the maximal residual capacity
(a path's residual capacity is the minimal capacity along the path)
*/

#include "Heap.h"
#include "Graph.h"

#define NO_PARENT -1

class DijkstraVariation {
private:
	void initializeArrays(int numOfVertices, int s, HeapItem*& arrForHeap);			//initialize the arrays which are being used in this function
	void findPathWithMaxCapacity(Heap& Q, Graph& g, int s);
	bool checkIfThereIsAPathFromStoT(int t);										//check if t is accessible from s
public:
	DijkstraVariation(int numOfVertices);
	~DijkstraVariation();
	bool runDijkstraVariation(int s, int t, int numOfVertices, Graph& G);			//the method which runs this algorithm
	int* d;
	int* p;
};