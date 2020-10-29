#include "DijkstraVariation.h"
#include <algorithm>
using namespace std;

DijkstraVariation::DijkstraVariation(int numOfVertices) {
	//allocate memory for the arrays
	this->d = new int[numOfVertices];
	this->p = new int[numOfVertices];
}

DijkstraVariation::~DijkstraVariation() {
	//free the allocated memory
	delete[] d;
	d = nullptr;
	delete[] p;
	p = nullptr;
}

bool DijkstraVariation::runDijkstraVariation(int s, int t, int numOfVertices, Graph& g) {
	HeapItem* arrForHeap;
	initializeArrays(numOfVertices, s, arrForHeap);
	bool res;

	//create a Heap based on this->d
	Heap Q = Heap(arrForHeap, numOfVertices);

	while (Q.IsEmpty() == false) {
		findPathWithMaxCapacity(Q, g, s);
	}

	res = checkIfThereIsAPathFromStoT(t);

	delete[] arrForHeap;
	return res;
}

void DijkstraVariation::findPathWithMaxCapacity(Heap& Q, Graph &g, int s) {
	int adjListLen, uvEdgeCapacity, bestCapacityInPath, vIndex, v;
	HeapItem u = Q.DeleteMax();
	LinkedList adjList;
	//get a list containing all of u's neighbors
	g.getAdjList(adjList, u.data+1);
	adjListLen = adjList.GetLength();

	//a loop which goes through the list of u's neighbors
	for (Node* currentV = adjList.First(); currentV != nullptr; currentV = currentV->GetNext()) {
		v = currentV->GetData()-1;
		uvEdgeCapacity = g.getEdgeWeight(u.data+1, v+1);
		bestCapacityInPath = min(u.key, uvEdgeCapacity);

		//if this is an improving edge
		if (d[v] < bestCapacityInPath) {
			vIndex = Q.getIndex(v);
			p[v] = u.data;
			d[v] = bestCapacityInPath;
			Q.IncreaseKey(vIndex, bestCapacityInPath);
		}
	}
}

void DijkstraVariation::initializeArrays(int numOfVertices, int s, HeapItem*& arrForHeap) {
	arrForHeap = new HeapItem[numOfVertices];

	for (int v = 0; v < numOfVertices; v++) {
		arrForHeap[v].key = -(INT_MAX);
		arrForHeap[v].data = v;
		d[v] = -(INT_MAX);
		p[v] = NO_PARENT;
	}
	d[s] = INT_MAX;
	arrForHeap[s].key = INT_MAX;
}

bool DijkstraVariation::checkIfThereIsAPathFromStoT(int t) {
	bool res;
	if (p[t] != NO_PARENT) {
		res = true;
	}
	else {
		res = false;
	}
	return res;
}