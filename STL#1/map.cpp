
#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	ifstream in;
	in.open("places.in");
	unordered_map<string, string> Cities;
	string str;
	string place;

	while (in >> place >> str)
	{
		if (isdigit(str[0]))
		{
			int numberOfCities = stoi(str);
			string city;
			for (int i = 1; i <= numberOfCities; ++i)
			{
				in >> city;
				Cities[city] = place;
			}
		}
		else
		{
			Cities[str] = place;
		}

	}

	unordered_map<string, string>::iterator it = Cities.begin();
	bool solutionIsFound = false;
	string city;
	string previousCity;

	while (solutionIsFound == false && Cities.begin() != Cities.end())
	{
		previousCity = it->second;
		cout << "\nJudetul  " << previousCity << " are urmatoarele orase:\n";

		unordered_map<string, string>::iterator i1 = Cities.begin();
		unordered_map<string, string>::iterator i2 = Cities.begin();
		while (i1 != Cities.end())
		{
			if (i1->second == previousCity)
			{
				i2 = i1;
				++i1;
				cout << i2->first << " ";
				Cities.erase(i2);
			}
			else
			{
				++i1;
			}
		}
		it = Cities.begin();
	}

	in.close();
	return 0;
}