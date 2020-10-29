#include <iostream>
#include "Graph.h"
using namespace std;

Graph::Graph(int numOfVertices) {
	this->numOfVertices = numOfVertices;
	makeEmpty();
}

Graph::Graph(const Graph& other)
{
	this->numOfVertices = other.numOfVertices;

	graph = new int* [numOfVertices];
	for (int i = 0; i < numOfVertices; i++) {
		this->graph[i] = new int[numOfVertices];
		for (int j = 0; j < numOfVertices; j++) {
			this->graph[i][j] = other.graph[i][j];
		}
	}
}

Graph::~Graph() {
	for (int i = 0; i < numOfVertices; i++)
	{
		delete[] this->graph[i];
	}
	delete[] this->graph;
}

void Graph::makeEmpty() {
	graph = new int* [numOfVertices];

	for (int i = 0; i < numOfVertices; i++)
	{
		this->graph[i] = new int[numOfVertices];
		for (int j = 0; j < numOfVertices; j++)
		{
			this->graph[i][j] = 0;
		}
	}
}

bool Graph::isAdjacent(int vertex1, int vertex2) {
	if (isVertexValid(vertex1) && isVertexValid(vertex2))
		return graph[vertex1 - 1][vertex2 - 1] > 0;
	else
		return false;
}

void Graph::getAdjList(LinkedList &adjList, int vertex) {
	if (isVertexValid(vertex)) {
		for (int i = 0; i < numOfVertices; i++)
		{
			if (graph[vertex - 1][i] > 0)
			{
				adjList.AddNewItem(i + 1);
			}
		}
	}
	else
		handleInvalidInput();

}

void Graph::addEdge(int vertex1, int vertex2, int weight) {
	if (isVertexValid(vertex1) && isVertexValid(vertex2) && weight > 0 && (isAdjacent(vertex1,vertex2) == false))
		graph[vertex1 - 1][vertex2 - 1] = weight;
	else
		handleInvalidInput();
}

void Graph::removeEdge(int vertex1, int vertex2) {
	if (isVertexValid(vertex1 - 1) && isVertexValid(vertex2 - 1))
		graph[vertex1-1][vertex2-1] = 0;
	else { //values are invalid. (According to the instructions we shouldn't exit the program in this case)
		return;
	}
}

int Graph::getEdgeWeight(int u, int v) {
	if (!isVertexValid(u) || !isVertexValid(v)){
		handleInvalidInput();
	}
	return this->graph[u - 1][v - 1];
}

void Graph::setEdgeWeight(int u, int v, int weight) {
	if (isVertexValid(u) && isVertexValid(v))
		this->graph[u - 1][v - 1] = weight;
	else
		handleInvalidInput();
}

int Graph::getNumOfVertices() {
	return this->numOfVertices;
}

bool Graph::isVertexValid(int vertex) {
	return (vertex > 0 && vertex <= numOfVertices);
}

void Graph::handleInvalidInput() {
	cout << "Invalid input - values out of range" << endl;
	exit(1);
}