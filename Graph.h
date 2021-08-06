#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iostream>
#include <unordered_map>

#include "node.h"


using namespace std;

#ifndef  graph_h

#define graph_h


class Graph {

public:
	//void addToMap(node lists);
	//void addToVector(node list);
	//int mrCompare(string name, string name2);

	int readFileAndStore(char *fileName);
	void findSuggestions(string name);
	void sortSuggestions();
	void printSuggestions(int exist, string name, char *fileName);



private:
	unordered_map<string, node> stringmap;
	vector<node>recommended;
	//vector <node> mrVector;
};

#endif