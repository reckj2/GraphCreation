#include "node.h"
//#include "Graph.h"

#include <iostream>

node::node() {
	userName = "none";
}

//int node::readFileAndStore(string name, char *fileName) {
//	node userName1;
//	//Graph followerG;
//	//Graph userG;
//	string input;
//	string follower;
//	string user;
//	ifstream inp;
//	int exist = 0;
//
//	userName1.setName(name);
//
//	inp.open(fileName);
//
//
//	if (!inp.is_open()) {
//		cout << "This file doesn't open/exist: " << fileName << endl;
//		return exist;
//	}
//
//	while (!inp.eof()) {
//		getline(inp, input);
//	
//		istringstream lineStream(input);
//		lineStream >> user;
//		lineStream >> follower;
//
//		for (unsigned int i = 0; i < user.size(); i++) {
//			if (user[i] == '*') {
//				return exist;
//			}
//		}
//		for (unsigned int i = 0; i < follower.size(); i++) {
//			if (follower[i] == '*') {
//				return exist;
//			}
//		}
//		if (name.compare(user) == 0) {
//			followers.push_back(follower);
//			exist = 1;
//		}
//		else if (name.compare(follower) == 0) {
//			following.push_back(user);
//			exist = 1;
//		}
//
//	}
//	return exist;
//}

void node::setName(string name) {
	userName = name;
}

string node::getName() {
	return userName;
}

void node::setFollower(string name) {
	followers.push_back(name);
}

void node::setFollowing(string name) {
	following.push_back(name);
}

void node::printFollowers(int exist, string user, char *fileOutName) {
	//unsigned int inc;
	ofstream outp;

	outp.open(fileOutName);

	if (exist == 0) {
		return;
	}
	outp << "Looking for new accounts for " << user << " (" << followers.size() << ") " << "to follow" << endl;
}

//int node::mrCompare(string name, string name2) {
//	if (name.compare(name2) == 0) {
//		return 1;
//	}
//	return 0;
//}

string node::getFollower(int i) {
	string temp;
	temp = followers.at(i);
	return temp;
}

string node::getFollowing(int i) {
	string temp;
	temp = following.at(i);
	return temp;
}

int node::getNumofFol() {
	return followers.size();
}

void node::setNumofFol(int i) {
	numOfFol = i;
}

int node::getNumFollowing() {
	return following.size();
}

int node::getActNum()
{
	return numOfFol;
}

//vector<string> node::getFollowers()
//{
//	return followers;
//}
//
//vector<string> node::getFollowing()
//{
//	return following;
//}

