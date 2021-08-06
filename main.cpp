#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#include "Graph.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[]) {

	Graph userMap;
	int exist = 0;
	//string temp;
	exist = userMap.readFileAndStore(argv[1]);
	//vector<node> unordered;
	if (exist != 0) {
		userMap.findSuggestions(argv[2]);
		userMap.sortSuggestions();
	}

	userMap.printSuggestions(exist, argv[2], argv[3]);
	/*temp = argv[3];
	if (temp.compare("output9.txt") == 0 || temp.compare("output10.txt") == 0) {
		ofstream outp;

		outp.open(temp);

	}*/
	
	//Graph userMapWest;
	//userMapWest.addToMap(userMap);
	//userMap.printFollowers();

	
	//userMap.printFollowers(exist, argv[2], argv[3]);

	return 0;


}