/*
This program implements two versions of FordFulkerson's method for finding the maximal flow of a simple, directed, weighted graph.
The difference between the methods is mainly the way in which they look for a better path in each iteration.
The first method uses BFS for the aformentioned purpose, and the second one uses a greedy approach - it looks for the path in which the improvement is maximal in each iteration.

How to use:
	the main function of this program takes a file's path as its input.

	The file must be in the following format:
	four args, each on a new line:
		<(integer) number of vertices in the graph> - must be at least one
		<(integer) number of edges in the graph> - must be at least zero
		<(integer) source vertex number> - must be between 1 and numOfVertices
		<(integer) target vertex number> - must be between 1 and numOfVertices and must be different from source

	three args which represent an edge in the graph. Each edge input must be on a separate line.
	<(inetegers) {vertex1} {vertex2} {capacity}> this stands for an edge from vertex1 to vertex2, with flow capacity of {capacity}
		- there should be at least <numberOfEdges> such lines. There may be more, but they will be ignored.
		- only spaces and tabs are allowed between the args in each line
		- there can be empty lines in between these lines. They will be ignored
		- capacity must be greater than zero
		- vertices must be valid - between one and numOfVertices
		- parallel edges are not allowed (two edges from vertex1 to vertex2)
*/

#include"FordFulkerson.h"
#include "InputValidations.h"

int main(int argc, char* argv[]) {

	const char* filename = argv[1];
	int s, t;
	Graph G = InputValidations::createGraphFromFile(filename, s, t);
	FordFulkerson F(G, s, t);
	F.runFordFulkerson();

	return 0;
}
