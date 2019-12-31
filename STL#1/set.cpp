#include<iostream>
#include<fstream>
#include<set>
#include<string>

using namespace std;

int main()
{
	ifstream in;
	in.open("cities.in");
	
	set<string> setOfCities;
	set<string>::iterator i;
	string city;

	while (in >> city)
	{
		setOfCities.insert(city);
	}

	auto it = setOfCities.begin();
	while (it!=setOfCities.end())
	{
		city = (*it);
		i = it;
		++it;
		if (city[0] == 'T')
		{
			setOfCities.erase(i);
		}
	}

	int counter = 0;
	cout << "Number of cities ending in letter 'a':\n";
	for (auto it = setOfCities.begin(); it != setOfCities.end(); ++it)
	{
		city = *it;
		
		if (city[city.size() - 1] == 'a')
		{
			++counter;
		}
	}

	cout << counter;

	in.close();
	return 0;
}