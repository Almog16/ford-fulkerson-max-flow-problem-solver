/*
This is an implementation of a simple, directed, weighted graph.
The implementation is based on adjacency matrix
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include "LinkedList.h"
using namespace std;

#define INVALID_INPUT 0

class Graph
{
private:
	int** graph;
	int numOfVertices;
	bool isVertexValid(int vertex);								//check if vertex is in the graph's range

public:
	Graph(int numOfVertices);
	Graph(const Graph& other);
	~Graph();
	void makeEmpty();											//create an empty graph
	bool isAdjacent(int vertex1, int vertex2);					//checks if vertex1 and vertex2 are adjacent
	void getAdjList(LinkedList &adjList, int vertex);			//returns a list containing all of the vertices which are adjacent to vertex
	void addEdge(int vertex1, int vertex2, int weight);			//adds an edge from vertex1 to vertex2 with capacity
	void removeEdge(int vertex1, int vertex2);					//removes the edge from vertex1 to vertex2
	int getEdgeWeight(int u, int v);							//returns the weight of the edge from u to v
	void setEdgeWeight(int u, int v, int weight);				//sets the weight of the edge from u to v
	int getNumOfVertices();										//getter for numOfVertices
	void handleInvalidInput();									//handler for invalid input
};

#endif // !GRAPH_H
