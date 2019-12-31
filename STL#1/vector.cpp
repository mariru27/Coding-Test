#include<iostream>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("animals.in");
	out.open("animals.out");

	vector<string> animals;
	unordered_map<string, int> frequencyMap;
	string animal, mostCommonAnimal;

	int maxAppearances = 0;

	while (in >> animal) {
		animals.push_back(animal);
		++frequencyMap[animal];
		if (maxAppearances < frequencyMap[animal]) {
			maxAppearances = frequencyMap[animal];
			mostCommonAnimal = animal;
		}
	}

	out << maxAppearances << endl << mostCommonAnimal << endl;
	sort(animals.begin(), animals.end());
	for (auto it = animals.begin(); it != animals.end(); ++it) {
		if (frequencyMap[*it] == 2) {
			for (auto i = it; i != animals.end() - 2; ++i) {
				*i = *(i + 2);
			}
			animals.resize(animals.size() - 2);
		}
	}

	for (auto it = animals.begin(); it != animals.end(); ++it) {
		out << *it << " ";
	}

	in.close();
	out.close();
	return 0;
}