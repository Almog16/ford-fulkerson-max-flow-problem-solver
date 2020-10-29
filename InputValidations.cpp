#include "InputValidations.h"


int InputValidations::readAndValidateASingleIntFromLine(string line) {
	char currentChar;
	int length = line.length();
	int res = 0;
	bool startedReading = false, doneReading = false;
	for (int i = 0; i < length; i++) {
		currentChar = line[i];

		//if the current char isn't a whitespace
		if (currentChar != ' ' && currentChar != '\t') {
			//if the current char is a number
			if (currentChar >= '0' && currentChar <= '9') {
				//make sure the line contains only one number
				if (doneReading == false) {
					startedReading = true;
					res *= 10;
					res += (currentChar - '0');
				}
				//otherwise, it means the line contains two numbers, which is invalid
				else {
					handleInvalidInput();
				}
			}
			//if the current char is not a whitespace or a number, the input is invalid
			else {
				handleInvalidInput();
			}
		}
		//if the current char is a whitespace, and we have already read a number, it means we aren't expecting any more numbers
		else if (startedReading == true) {
			doneReading = true;
		}
	}
	return res;
}

void InputValidations::handleInvalidInput() {
	cout << "Invalid input" << endl;
	exit(1);
}

bool InputValidations::readAndValidateEdgeInputFromLine(string line, int& v1, int& v2, int& c) {
	int i = 0;
	int currentParameter = 1;
	char currentChar;
	int n;
	bool readEdge = false;
	int lineLength = line.length();
	while (i < lineLength) {
		currentChar = line[i];
		n = currentChar - ASCII_0;

		if (currentChar == ' ' || currentChar == '\t') {		//since spaces and tabs are allowed
			i++;
			continue;
		}
		else if (n >= 0 && n <= 9) {							//if it is a number, we want to read it
			switch (currentParameter) {
			case 1:
				readInt(i, line, v1);
				break;
			case 2:
				readInt(i, line, v2);
				break;
			case 3:
				readInt(i, line, c);
				break;
			default:											//if we have already read three numbers and we see another number, there are too many args in the line
				handleInvalidInput();
			}
			currentParameter++;									//in order to make sure next time we find a number, we read it into the next parameter
		}
		else {													//if currentChar isn't space/tab/number, the line is invalid
			handleInvalidInput();
		}
	}
	if (currentParameter == 4) {								//if we have already read all three args, we are done reading the edge
		readEdge = true;
	}
	return readEdge;
}


void InputValidations::readInt(int& i, string& line, int& out) {
	out = 0;
	int n = line[i] - ASCII_0;
	while (n >= 0 && n <= 9) {
		out *= 10;
		out += n;
		i++;
		n = line[i] - ASCII_0;
	}
}

Graph InputValidations::createGraphFromFile(const char* filename, int& s, int& t) {
	ifstream inputFile(filename);
	string currentLine;
	int n=0, m=-1, v1, v2, c;
	int edgeNumber = 0;

	if (inputFile.is_open()) {
		if (getline(inputFile, currentLine))
			n = InputValidations::readAndValidateASingleIntFromLine(currentLine);
		else {
			InputValidations::handleInvalidInput();
		}
		if (n < 1) {
			InputValidations::handleInvalidInput();
		}

		if (getline(inputFile, currentLine))
			m = InputValidations::readAndValidateASingleIntFromLine(currentLine);
		else {
			InputValidations::handleInvalidInput();
		}
		if (m < 0) {
			InputValidations::handleInvalidInput();
		}

		if (getline(inputFile, currentLine))
			s = InputValidations::readAndValidateASingleIntFromLine(currentLine);
		else {
			InputValidations::handleInvalidInput();
		}
		if (s<1 || s>n) {
			InputValidations::handleInvalidInput();
		}

		if (getline(inputFile, currentLine))
			t = InputValidations::readAndValidateASingleIntFromLine(currentLine);
		else {
			InputValidations::handleInvalidInput();
		}
		if (t < 1 || t > n || t == s) {
			InputValidations::handleInvalidInput();
		}

		Graph G(n);

		while (getline(inputFile, currentLine) && edgeNumber < m) {
			if (InputValidations::readAndValidateEdgeInputFromLine(currentLine, v1, v2, c)) {
				if (v1 < 1 || v1 > n || v2 < 1 || v2 > n || c < 1 || G.isAdjacent(v1, v2))
					InputValidations::handleInvalidInput();
				G.addEdge(v1, v2, c);
				edgeNumber++;
			}
		}
		if (edgeNumber < m) {
			InputValidations::handleInvalidInput();
		}

		return G;
		inputFile.close();
	}
	else {
		InputValidations::handleInvalidInput();
	}
}