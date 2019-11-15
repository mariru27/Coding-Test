#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include<algorithm> 
#include<queue>
#include<map>


using namespace std;


vector<string> getWords(string str) {
	vector<string> allWordsFromAStr;
	int i = 0, j = 0;

	while (str.size() != i) {
		i++;
		if (str[i] == ' ') {
			allWordsFromAStr.push_back(str.substr(j, i - j));
			j = i + 1;
		}
	}
	allWordsFromAStr.push_back(str.substr(j, str.size()));

	return allWordsFromAStr;
}

bool isDifferent(vector<string> myWords, string str) {
	for (int i = 0; i < myWords.size(); i++) {
		if (myWords[i] == str)
			return false;
	}

	return true;
}

bool findString(vector<string> mypath, string str) {
	for (int i = 0; i < mypath.size(); i++) {
		if (mypath[i] == str)
			return true;
	}

	return false;
}

int main() {
	ifstream filein;
	ifstream filein3;
	ofstream fileout1;
	ofstream fileout2;
	ofstream fileout3;

	filein.open("deps.in");
	filein3.open("computers.in");
	fileout1.open("task1.out");
	fileout2.open("task2.out");
	fileout3.open("task3.out");

	struct pack {
		string a, b;
	};
	pack package[100];
	vector <string> allP, allPackage;
	bool foundA = false, foundB = false;
	int k = 0;

	while (filein >> package[k].a >> package[k].b) {
		foundA = false;
		foundB = false;
		for (int i = 0; i < allP.size(); i++) {
			if (package[k].a == allP[i])
				foundA = true;
			if (package[k].b == allP[i])
				foundB = true;
		}
		if (package[k].a != package[k].b) {
			if (foundA == false)
				allP.push_back(package[k].a);
			if (foundB == false)
				allP.push_back(package[k].b);
		}
		k++;
	}

	allPackage = allP;
	map<string, map<string, int>> mymap;
	sort(allP.begin(), allP.end());

	for (int i = 0; i < allP.size(); i++) {
		fileout1 << allP[i] << endl;
	}

	//------------------task2----------------

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			mymap[allP[i]][allP[j]] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		mymap[package[i].a][package[i].b] = 1;
	}

	for (int i = 0; i < k; i++) {
		queue<string> path;
		vector<string> mypath;
		string currentStr;
		path.push(allP[i]);
		mypath.push_back(allP[i]);

		while (path.empty() == false) {
			currentStr = path.front();
			path.pop();
			for (int j = 0; j < k; j++) {
				if (mymap[currentStr][allP[j]] == 1) {
					path.push(allP[j]);
					if (findString(mypath, allP[j]) == false)
						mypath.push_back(allP[j]);
				}
			}
		}
		fileout2 << mypath[0] << " ";
		mypath.erase(mypath.begin());
		sort(mypath.begin(), mypath.end());

		for (int l = 0; l < mypath.size(); l++) {
			fileout2 << mypath[l] << " ";
		}
		fileout2 << endl;
	}

	//-------------task3----------

	string mystr;

	while (getline(filein3, mystr)) {
		vector<string> myWords = getWords(mystr);
		queue<string> path;
		vector<string> mypath;
		string currentStr;

		for (int i = 0; i < myWords.size(); i++) {
			path.push(myWords[i]);
		}
		while (path.empty() == false) {
			currentStr = path.front();
			path.pop();
			for (int i = 0; i < k; i++) {
				if (mymap[currentStr][allP[i]] == 1) {
					path.push(allP[i]);
					if (findString(mypath, allP[i]) == false && isDifferent(myWords, allP[i]) == true)
						mypath.push_back(allP[i]);
				}
			}
		}
		myWords.clear();
		sort(mypath.begin(), mypath.end());

		for (int i = 0; i < mypath.size(); i++) {
			fileout3 << mypath[i] << " ";
		}
		fileout3 << endl;
	}

	filein3.close();
	fileout3.close();
	fileout2.close();
	fileout1.close();
	filein.close();
	return 0;
}
