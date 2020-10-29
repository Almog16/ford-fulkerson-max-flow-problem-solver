#include "BFS.h"
using namespace std;

BFS::BFS(int numOfVertices) {
	//allocate memory for the arrays
	parents = new int[numOfVertices];
	distances = new int[numOfVertices];
}

BFS::~BFS() {
	//free the allocated memory
	delete[] this->parents;
	this->parents = nullptr;
	delete[] this->distances;
	this->distances = nullptr;
}

bool BFS::runBFS(int s, int t, int numOfVertices, Graph &G)
{
	Queue q = Queue();

	initializeArrays(numOfVertices,s);
	q.EnQueue(s);

	while(q.IsEmpty() == false)
	{
		int u = q.DeQueue();
		int v;
		LinkedList adjList = LinkedList();
		// get a list containing all of u's neighbors
		G.getAdjList(adjList, u+1);
		Node* currentV = adjList.First();

		//loop which goes over all of u's neighbors
		for(int i=0; i<adjList.GetLength(); i++, currentV = currentV->GetNext())
		{
			v = currentV->GetData()-1;
			//if we haven't visited v yet, the shortest path to it is through u
			if (distances[v] == NOT_VISITED)
			{
				distances[v] = distances[u] + 1;
				parents[v] = u;
				q.EnQueue(v);
			}
		}
	}

	return checkIfThereISAPathFromStoT(t);
}

void BFS::initializeArrays(int numOfVertices, int s) {
	for (int v = 0; v < numOfVertices; v++)
	{
		distances[v] = NOT_VISITED;
		parents[v] = NO_PARENT;
	}
	distances[s] = 0;
}

bool BFS::checkIfThereISAPathFromStoT(int t) {
	bool res;
	if (parents[t] != NO_PARENT) // if we found a path from s to t
	{
		res = true;
	}
	else
	{
		res = false;
	}
	return res;
}