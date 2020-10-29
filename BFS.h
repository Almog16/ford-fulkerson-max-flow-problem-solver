/*
This class is an implementation of the BFS algorithm
*/

#ifndef BFS_H
#define BFS_H

#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <list>
#include "Graph.h"
#include "Queue.h"

using namespace std;

#define NO_PARENT -1
#define NOT_VISITED INT_MAX

class BFS
{
private:
	void initializeArrays(int numOfVertices, int s);			//initialize distances[] and parents[]
	bool checkIfThereISAPathFromStoT(int t);					//check if t is accessible from s
public:
	BFS(int numOfVertices);
	~BFS();
	int* distances;
	int* parents;

	bool runBFS(int s, int t, int numOfVertices, Graph &G);		//the method which runs the algorithm
};

#endif // !BFS_H
