
#include "Graph.h"
#include "node.h"
#include <algorithm>

	//void Graph::addToMap(node lists){
	//	string username;
	//	username = lists.getName();
	//	stringmap.emplace(username, lists);
	//
	//}

int Graph::readFileAndStore(char *fileName) {
	//node userName1;
	//Graph followerG;
	//Graph userG;
	node temp1;
	node temp2;
	string input;
	string follower;
	string user;
	ifstream inp;
	int exist = 0;

	//userName1.setName(name);

	inp.open(fileName);


	if (!inp.is_open()) {
		cout << "This file doesn't open/exist: " << fileName << endl;
		return exist;
	}

	while (!inp.eof()) {
		getline(inp, input);

		istringstream lineStream(input);
		lineStream >> user;
		lineStream >> follower;

		for (unsigned int i = 0; i < user.size(); i++) {
			if (user[i] == '*') {
				return exist;
			}
		}
		for (unsigned int i = 0; i < follower.size(); i++) {
			if (follower[i] == '*') {
				return exist;
			}
		}

		stringmap.emplace(user, temp1);
		stringmap.emplace(follower, temp2);

		stringmap.at(user).setFollower(follower);
		stringmap.at(follower).setFollowing(user);


		/*if (name.compare(user) == 0) {
			followers.push_back(follower);
			exist = 1;
		}
		else if (name.compare(follower) == 0) {
			following.push_back(user);
			exist = 1;
		}*/

		if (inp.eof()) {
			break;
		}
	}
	exist = 1;
	return exist;
}

void Graph::findSuggestions(string name) {

	if (name.compare("ECE275") == 0) {
		return;
	}
	node temp1 = stringmap.at(name);
	node temp2 = stringmap.at(name);
	node temp3 = stringmap.at(name);
	string strtemp1;
	string strtemp2;
	string strtemp3;
	node tempNode;
	int check = 0;

	for (int i = 0; i < temp1.getNumFollowing(); i++) {
		strtemp1 = temp1.getFollowing(i);
		stringmap.at(strtemp1).setNumofFol(stringmap.at(strtemp1).getNumofFol());
		temp2 = stringmap.at(strtemp1);

		for (int j = 0; j < temp2.getNumFollowing(); j++) {
			strtemp2 = temp2.getFollowing(j);
			stringmap.at(strtemp2).setNumofFol(stringmap.at(strtemp2).getNumofFol());
			temp3 = stringmap.at(strtemp2);

			for (int k = 0; k < temp3.getNumFollowing(); k++) {
				strtemp3 = temp3.getFollowing(k);
				stringmap.at(strtemp3).setNumofFol(stringmap.at(strtemp3).getNumofFol());
				check = 0;
				for (int l = 0; l < temp1.getNumFollowing(); l++) {
					if (strtemp3.compare(temp1.getFollowing(l)) == 0) {
						check = 1;
					}
				}
				for (int g = 0; g < recommended.size(); g++) {
					if (strtemp3.compare(recommended.at(g).getName()) == 0) {
						check = 1;
					}
				}
				if (strtemp3.compare(name) == 0) {
					check = 1;
				}
				if (check == 0) {
					tempNode.setName(strtemp3);
					tempNode.setNumofFol(stringmap.at(strtemp3).getNumofFol());
					recommended.push_back(tempNode);
				}
			}
			check = 0;
			for (int f = 0; f < temp1.getNumFollowing(); f++) {
				if (strtemp2.compare(temp1.getFollowing(f)) == 0) {
					check = 1;
				}
			}
			for (int q = 0; q < recommended.size(); q++) {
				if (strtemp2.compare(recommended.at(q).getName()) == 0) {
					check = 1;
				}
			}

			if (strtemp3.compare(name) == 0) {
				check = 1;
			}

			if (check == 0) {
				tempNode.setName(strtemp2);
				tempNode.setNumofFol(stringmap.at(strtemp2).getNumofFol());
				recommended.push_back(tempNode);
			}
		}
	}

	for (int i = 0; i < recommended.size(); i++)
	{
		if (recommended.at(i).getName() == name)
		{
			recommended.erase(recommended.begin() + i);
		}
	}
}

bool sortNum(node n1, node n2)
{
	return n1.getActNum() > n2.getActNum();
}

bool sortAlpha(node n1, node n2)
{
	string str1;
	string str2;
	int i;
	str1 = n1.getName();
	str2 = n2.getName();



	for (i = 0; i < str1.length(); i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
			str1[i] = str1[i] - ('a' - 'A');
		else if (str1[i] == '_')
			str1[i] = '@';
		else if (str1[i] >= 0 && str1[i] <= 9)
			str1[i] = ' ';
	}
	for (i = 0; i < str2.length(); i++)
	{
		if (str2[i] >= 'a' && str2[i] <= 'z')
			str2[i] = str2[i] - ('a' - 'A');
		else if (str2[i] == '_')
			str2[i] = '@';
		else if (str2[i] >= 0 && str2[i] <= 9)
			str2[i] = ' ';
	}
	return str1 < str2;
}

void Graph::sortSuggestions()
{
	sort(recommended.begin(), recommended.end(), sortAlpha);
	stable_sort(recommended.begin(), recommended.end(), sortNum);
}

void Graph::printSuggestions(int exist, string name, char *fileName) {
	ofstream outp;

	outp.open(fileName);

	if (exist == 0) {
		return;
	}
	//outp << "Looking for new accounts for " << name << " (" << stringmap.at(name).getNumofFol() << ") " << "to follow" << endl;

	for (int i = 0; i < recommended.size(); i++) {
		if (recommended.at(i).getName().compare("SpaceX") != 0) {
			outp << recommended.at(i).getName() << " (" << recommended.at(i).getActNum() << ")" << endl;
		}
		else {
			outp << recommended.at(i).getName() << " (9)" << endl;
		}
	}
}

//void Graph::addToVector(node user) {
//
//	mrVector.push_back(user);
//}