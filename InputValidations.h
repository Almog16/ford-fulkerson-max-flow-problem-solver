#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "Graph.h"
using namespace std;

#define NOT_INITIALIZED -1
#define ASCII_0 48

class InputValidations {
public:
	static Graph createGraphFromFile(const char* fileName, int& s, int& t);					//creates a graph from text file
	static void handleInvalidInput();														//handler for invalid input
	static int readAndValidateASingleIntFromLine(string line);								//read and validate lines in which there should only be one number
	static bool readAndValidateEdgeInputFromLine(string line, int& v1, int& v2, int& c);	//read and validate edge input (three args per line)
	static void readInt(int& i, string& line, int& out);									//read a single number from string
};