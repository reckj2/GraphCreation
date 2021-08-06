#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

//#include "Graph.h"

using namespace std;

#ifndef  node_h

#define node_h


class node {

public:
	node();

//	int readFileAndStore(string name, char *fileName);

	void setName(string name);
	string getName();
	void setFollower(string name);
	void setFollowing(string name);

	void printFollowers(int exist, string name, char *fileOutName);
	//int mrCompare(string name, string name2);
	//void mrLookAtFollowing(vector<string>foll, vector<string>folling);
	//vector<string> getFollowers();
	string getFollower(int i);
	string getFollowing(int i);
	//vector<string> getFollowing();
	int getNumofFol();
	int getActNum();
	void setNumofFol(int i);

	int getNumFollowing();
//	void setNumFollowing(int i);

private:
	string userName;
	vector <string> followers;
	vector <string> following;
	int numOfFol;
	//int numFollowing;


};

#endif